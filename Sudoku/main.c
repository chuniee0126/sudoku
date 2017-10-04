#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

#include "sudoku.h"

int main(int argc, char const *argv[]) {

	FILE * input;
	FILE * formula;
	FILE * output;

	int * a_output = (int *)malloc(sizeof(int) * 81); // array of output

	input = fopen("input.txt", "r");
	formula = fopen("formula.txt", "w"); // 기존에 파일이 있어도 처음부터 작성
	output = fopen("output.txt", "w"); // 기존에 파일이 있어도 처음부터 작성

	create_formula(input, formula);

	run_dimacs(formula, a_output);

	create_output(output, a_output);

	fclose(input);
	fclose(formula);
	fclose(output);
	free(a_output);

	return 0;
}
