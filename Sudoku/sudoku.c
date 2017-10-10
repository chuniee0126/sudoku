#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "create_formula.h"
#include "sudoku.h"

bool read_input(const char *str_input, int *a_input, FILE *input) {
    int temp = 0;

    // read_input data
    // check the existence of input.txt file
    if ((input = fopen(str_input, "r")) == NULL) {
        printf("Abort! in this directory have no input file! \n");
        exit(0);
    }

    // create_array of input matrix
    // for input.txt that have space_bar between each cell
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            temp = fgetc(input);

            if ((temp != '*') && ((temp < '0') || (temp > '9'))) {
                printf("Abort! There is unexpected character!\n");
                exit(0);
            } else {
                if (temp == '*') a_input[i * 9 + j] = '*';
                else a_input[i * 9 + j] = temp - 48;
            }

            // reason why space_bar
            if (j != 8) {
                if (fgetc(input) != ' '){
                    printf("Abort! There is unexpected character!\n");
                    exit(0);
                }
            }
        }
        for(int i = 1; true;){
            if (fgetc(input) == '\n'){
                break;
            }
            else if(i > 4){
                printf("Abort! There is unexpected character!\n");
                exit(0);
            }
            i++;
        }
    }
    // ~create_array of input matrix

    // print input matrix
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (a_input[i * 9 + j] == '*') printf("* ");
            else printf("%d ", a_input[i * 9 + j]);
        }
        printf("\n");
    }
    printf("\n");
    // ~print input matrix

    fclose(input);
    // ~read_input data

    return true;
}

bool create_formula(int *a_input, FILE *formula) {
    write_firstline(a_input, formula);

    write_inputvalue(a_input, formula);

    write_CP1(formula);

    write_CP2(formula);

    write_CP3(formula);

    write_CP4(formula);

    write_CP5(a_input, formula);

    return true;
}

bool run_dimacs(FILE *formula, int *a_output) {
    char cmd[] = "z3 -dimacs formula.txt";
    char  sat[5];    // receives the first line of the output: "sat"
    int  *solution = (int *)malloc(sizeof(int) * 729);    // Receives z3 output
    FILE *fp;
    int   n = 0;   // value of the cell: n (with formula)

    if ((fp = popen(cmd, "r")) == NULL) {  // Runs z3 -dimacs formula.txt
        printf("Abort! Error with pipe.\n");
        exit(0);
    }


    fscanf(fp, "%s", sat);  // receives the first line of the output: "sat"

    if (!strcmp(sat, "unsat")) {  // If there is no solution
        printf("No solution! system message : \"unsat\"\n");
        exit(0);
    }

    if (strcmp(sat, "sat") && strcmp(sat, "unsat")) {  // If the SAT solver(z3/minisat) is not there
        printf("Abort! SAT solver does not exist in the system.\n");
        exit(0);
    }

    for (int i = 0; i < 81; i++) {
        for (int j = 0; j < 9; j++) {
            fscanf(fp, "%d", &solution[j]);

            if (solution[j] > 0) {  // If the propositional variable = true
                n           = solution[j] - (i * 9);       // Modification of P(N) = arr_idx*9 + n
                a_output[i] = n;  // Interpreted result from the DIMACS output
            }
        }

        /*printf("%d ", a_output[i]); //Printing the output sudoku to standard output
         * if ((i + 1) % 9 == 0)
         *      printf("\n");*/
    }

    pclose(fp);

    return true;
}

bool create_output(FILE *output, int *result) {
    for (int i = 0; i < 81; i++) {
        fprintf(output, "%d ", result[i]);  // Printing the output sudoku to output.txt
        printf("%d ", result[i]);  // Printing the output sudoku to standard output

        if ((i + 1) % 9 == 0) {
            fprintf(output, "\n");
            printf("\n");
        }
    }

    return true;
}
