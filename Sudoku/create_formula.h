/**
 * @file create_formula.h
 * @brief Write formula.txt file that use on z3 SAT solver program for solving sudoku problems
 * @author Jeonghwan Kim, Chunmyong Park, Ho Yoon Choi
 * @date October 4, 2017
 */
#ifndef CREATE_FORMULA_H
#define CREATE_FORMULA_H

/**
 * @brief Write formula.txt file (all function related with this task)
 */
bool write_firstline(int *a_input, FILE *formula);

bool write_inputvalue(int *a_input, FILE *formula);

bool write_CP1(FILE *formula);

bool write_CP2(FILE *formula);

bool write_CP3(FILE *formula);

bool write_CP4(FILE *formula);

bool write_CP5(int *a_input, FILE *formula);

#endif  // ifndef CREATE_FORMULA_H
