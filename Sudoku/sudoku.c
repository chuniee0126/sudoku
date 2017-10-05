#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "create_formula.h"
#include "sudoku.h"

bool create_formula(int * a_input, FILE * formula){

	write_firstline(a_input, formula);

	write_inputvalue(a_input, formula);

	write_CP1(formula);

	write_CP2(formula);

	write_CP3(formula);

	write_CP4(formula);

	write_CP5(a_input, formula);

	true;
}

bool run_dimacs(FILE * formula, int * a_output) {

	char * cmd = "z3 -dimacs formula.txt";
	char sat[5]; //receives the first line of the output: "sat"
	int * solution = (int*)malloc(sizeof(int) * 729); //Receives z3 output
	FILE * fp;
	int i = 0, j = 0, n = 0;

	if ((fp = _popen(cmd, "r")) == NULL) //Runs z3 -dimacs formula.txt
	{
		printf("Error with pipe.\n");
		return -1;
	}

	fscanf(fp, "%s", sat); //receives the first line of the output: "sat"

	for (i = 0; i < 81; i++)
	{
		for (j = 0; j < 9; j++)
		{
			fscanf(fp, "%d", &solution[j]);
			if (solution[j] > 0) //If the propositional variable = true
			{
				n = solution[j] - (i * 9); //Modification of P(N) = arr_idx*9 + n
				a_output[i] = n; //Interpreted result from the DIMACS output
			}
		}
		printf("%d ", a_output[i]); //Printing the output sudoku to standard output
		if ((i + 1) % 9 == 0)
			printf("\n");
	}

	return 0;

}

bool create_output(FILE * output, int * result){

	int i;
	for (i = 0; i < 81; i++)
	{
		fprintf(output, "%d ", result[i]); //Printing the output sudoku to output.txt
		if ((i + 1) % 9 == 0)
			fprintf(output, "\n");
	}

	true;
}
