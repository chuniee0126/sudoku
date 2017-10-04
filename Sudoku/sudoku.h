/**
 * @file sudoku.h
 * @brief
 * @author Chunmyong Park, "", ""
 * @date October 4, 2017
 */
#ifndef SUDOKU_H
#define SUDOKU_H

/**
 * @brief Create formula.txt file
 */
bool create_formula(FILE * input, FILE * formula);

/**
 * @brief Run dimacs program with formula.txt
 *        and create output array
 */
int* run_dimacs(FILE * formula, int * a_output);

/**
 * @brief Create Output.txt file
 */
bool create_output(FILE * output, int * result);

#endif
