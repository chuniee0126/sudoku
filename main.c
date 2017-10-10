#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

#include "Sudoku/sudoku.h"

int main(int argc, char const *argv[]) {
    FILE *input = NULL;
    FILE *formula = NULL;
    FILE *output = NULL;

    int *a_input  = (int *)malloc(sizeof(int) * 81);    // array of input
    int *a_output = (int *)malloc(sizeof(int) * 81);  // array of output

    // strcpy(argv[1], "input.txt");

    // There is no explicit input or There is so many input
    if (argc == 1) {
        printf("we use \"input.txt\" as input sudoku file this time \n\n");
        // read_input data
        read_input("input.txt", a_input, input);
        // ~read_input data
    } else if (argc > 2) {
        printf("Abort! There is so many input! \n");
        return -1;
    }
    else{
        // if user give us explicit input file name

        // check, input file follow '.txt' filename extension
        if (strstr(argv[1], ".txt") == NULL) {
            printf("Abort! input file name is not followed '.txt' filename extension\n");
            return -1;
        }
        // ~check

        // read_input data
        read_input(argv[1], a_input, input);
        // ~read_input data
    }




    // create_formula
    formula = fopen("formula.txt", "w");  // Even if there is file, rewrite from first

    create_formula(a_input, formula);

    fclose(formula);
    // ~create_formula

    // run_dimacs and create_output
    run_dimacs(formula, a_output);

    output = fopen("output.txt", "w");  // Even if there is file, rewrite from first

    create_output(output, a_output);

    fclose(output);
    // ~run_dimacs and create_output

    free(a_output);
    free(a_input);

    return 0;
}
