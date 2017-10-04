#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "create_formula.h"

bool write_firstline(int * a_input, FILE * formula){
	return true;
}

bool write_inputvalue(int * a_input, FILE * formula){
	return true;
}

bool write_CP1(FILE * formula){
	return true;
}

bool write_CP2(FILE * formula){
	return true;
}

bool write_CP3(FILE * formula){
	return true;
}

bool write_CP4(FILE * formula){
	return true;
}

bool write_CP5(FILE * input, FILE * formula) {
	// int * sudoku = a_input;
	// int pos[10]; //asterisk(*) position(store the index)
	// int i, j, pos_count = 0;
	// for (i = 0; i < 81; i++)
	// {
	// 	if (sudoku[i] == '*') //If the received value is asterisk(*)
	// 	{
	// 		pos[pos_count] = i;
	// 		pos_count++;
	// 	}
	// }
	// for (i = 0; i < pos_count - 1; i++)
	// {
	// 	for (j = 1; j <= 9; j++)
	// 	{
	// 		fprintf(formula, "%d -%d 0\n", pos[i] * 9 + j, pos[i + 1] * 9 + j);
	// 		fprintf(formula, "-%d %d 0\n", pos[i] * 9 + j, pos[i + 1] * 9 + j);
	// 	}
	// }

	return true;
}
