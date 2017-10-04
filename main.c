#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

#include "Sudoku/sudoku.h"

int main(int argc, char const *argv[]) {

	FILE * input;
	char temp;
	FILE * formula;
	FILE * output;

	int * a_input = (int *)malloc(sizeof(int) * 81);
	int * a_output = (int *)malloc(sizeof(int) * 81); // array of output


	input = fopen("input.txt", "r");

	// input 파일 존재 여부 체크
	if (input == NULL) {
		printf("There is no input.txt file! \n");
		return -1;
	}

	// //input 파일 validation 검사
	// while((temp = fgetc(input)) != EOF) {
	// 	if(temp == '\n') count++;
	// }
	// printf("%d\n", count);


	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++){
			temp = fgetc(input);
			if(temp == '*')
				a_input[i*9 + j] = '*';
			else
				a_input[i*9 + j] = temp - 48;
		}
		fgetc(input);
	}

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			printf("%d", a_input[i*9 + j]);
		}
		printf("\n");
	}

	formula = fopen("formula.txt", "w"); // 기존에 파일이 있어도 처음부터 작성
	output = fopen("output.txt", "w"); // 기존에 파일이 있어도 처음부터 작성

	create_formula(a_input, formula);

	run_dimacs(formula, a_output);

	create_output(output, a_output);

	fclose(input);
	fclose(formula);
	fclose(output);
	free(a_output);
	free(a_input);

	return 0;
}
