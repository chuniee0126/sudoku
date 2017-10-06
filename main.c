#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

#include "Sudoku/sudoku.h"

int main(int argc, char const *argv[]) {

	FILE * input;
	//char temp;
	int temp;
	FILE * formula;
	FILE * output;

	int * a_input = (int *)malloc(sizeof(int) * 81); // array of input
	int * a_output = (int *)malloc(sizeof(int) * 81); // array of output

	// read_input data
	input = fopen("input.txt", "r");

	// input 파일 존재 여부 체크
	if (input == NULL) {
		printf("There is no input.txt file! \n");
		return -1;
	}

	// input file validation check(expected)

	// // create_array of input matrix
	// for(int i = 0; i < 9; i++) {
	// 	for(int j = 0; j < 9; j++){
	// 		temp = fgetc(input);
	// 		if(temp == '*')
	// 			a_input[i*9 + j] = '*';
	// 		else
	// 			a_input[i*9 + j] = temp - 48;
	// 	}
	// 	fgetc(input);
	// }

	// create_array of input matrix
	// for input.txt that have space_bar between each cell
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++){
			temp = fgetc(input);
			if(temp == '*')
				a_input[i*9 + j] = '*';
			else
				a_input[i*9 + j] = temp - 48;
			fgetc(input); // reason why space_bar and Enter
		}
	}

	// print input matrix
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(a_input[i*9 + j] == '*')
				printf("* ");
			else
				printf("%d ", a_input[i*9 + j]);
		}
		printf("\n");
	}

	printf("\n");

	fclose(input);
	// ~read_input data

	// create_formula
	formula = fopen("formula.txt", "w"); // 기존에 파일이 있어도 처음부터 작성

	create_formula(a_input, formula);

	fclose(formula);
	// ~create_formula

	// run_dimacs and create_output
	output = fopen("output.txt", "w"); // 기존에 파일이 있어도 처음부터 작성

	run_dimacs(formula, a_output);

	create_output(output, a_output);

	fclose(output);
	// ~run_dimacs and create_output

	free(a_output);
	free(a_input);

	return 0;
}
