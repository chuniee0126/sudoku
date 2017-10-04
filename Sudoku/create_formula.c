#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "create_formula.h"

bool write_firstline(int * a_input, FILE * formula){
	int numNonzero = 0;
	int numStar = 0;
	int numClause = 0;

	// 연산 비용을 줄이기 위해 i,j 표기법보다, cell번호를 사용한다 (cell은 0번부터 시작)
	for(int i = 0; i < 81; i++) {
		if(a_input[i] != 0) {
			if(a_input[i] == '*')
				numStar++;
			else
				numNonzero++;
		}
	}

	//      non_zero value + CP1 + CP2 + CP3 + CP4
	numClause = numNonzero + 2916 + 81 + 81 + 81;
	// numNonzero와 CP1 계산법이 바뀔 수도 있음(CP1 함수가 달라짐에 따라서)

	if (numStar > 1) numClause += (numStar - 1) * 18;

	fprintf(formula, "p cnf 729 %d\n", numClause);

	return true;
}

bool write_inputvalue(int * a_input, FILE * formula){
	return true;
}

bool write_CP1(FILE * formula){

	// int count_for_check = 0;

	// 연산 비용을 줄이기 위해 i,j 표기법보다, cell번호를 사용한다 (cell은 0번부터 시작)
	for(int i = 0; i < 81; i++){
		// if(a_input[i] == 0 || a_input[i] == '*')
		// 위의 조건문이 false일 때는 inputvalue를 true로 하고, 나머지를 false로 만들어서 건당 약 27 line 절약 가능
		// write_inputvalue 함수 수정시 좀 더 직관적으로 프로그램을 바꿀 수 있음

		// 식 참고
		for(int n = 9*i + 1; n < 9*i + 9; n++){
			for (int m = n + 1; m <= 9*i + 9; m++){
				fprintf(formula, "-%d -%d 0\n", n, m);
				// count_for_check++;
			}
		}
	}

	// printf("%d\n", count_for_check);

	return true;
}

bool write_CP2(FILE * formula){
	return true;
}

bool write_CP3(FILE * formula){
	return true;
}

bool write_CP4(FILE * formula){
	int temp = 0;
	// int count_for_check = 0;

	// 식 참고
	for(int r = 0; r <= 2; r++){
		for(int s = 0; s <= 2; s++){
			for(int n = 1; n <= 9; n++){
				for(int i = 1; i <= 3; i++){
					for(int j = 1; j <=3; j++){
						temp = 81*(3*r + i - 1) + 9*(3*s + j - 1) + n;
						fprintf(formula, "%d ", temp);
					}
				}
				fprintf(formula, "0\n");
				// count_for_check++;
			}
		}
	}

	// printf("%d\n", count_for_check);

	return true;
}

bool write_CP5(int * a_input, FILE * formula) {
	int * sudoku = a_input;
	int pos[10]; //asterisk(*) position(store the index)
	int i, j, pos_count = 0;
	for (i = 0; i < 81; i++)
	{
		if (sudoku[i] == '*') //If the received value is asterisk(*)
		{
			pos[pos_count] = i;
			pos_count++;
		}
	}
	for (i = 0; i < pos_count - 1; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			fprintf(formula, "%d -%d 0\n", pos[i] * 9 + j, pos[i + 1] * 9 + j);
			fprintf(formula, "-%d %d 0\n", pos[i] * 9 + j, pos[i + 1] * 9 + j);
		}
	}

	return true;
}
