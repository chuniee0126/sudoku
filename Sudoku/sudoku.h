/**
 * @file sudoku.h
 * @brief
 * @author Chunmyong Park, "", ""
 * @date October 4, 2017
 */
#ifndef SUDOKU_H
#define SUDOKU_H

/**
 * @brief Read user input file
 */
bool read_input(const char *str_input, int *a_input, FILE *input);

/**
 * @brief Create formula.txt file
 */
bool create_formula(int *a_input, FILE *formula);

/**
 * @brief Run dimacs program with formula.txt
 *        and create output array
 */
bool run_dimacs(FILE *formula, int *a_output);

/**
 * @brief Create Output.txt file
 */
bool create_output(FILE *output, int *result);

#endif  // ifndef SUDOKU_H
