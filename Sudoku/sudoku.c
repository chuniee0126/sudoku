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

bool run_dimacs(FILE * formula, int * a_output){
	true;
}

bool create_output(FILE * output, int * result){
	true;
}
