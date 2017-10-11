# Sudoku Solver

Sudoku.out is a 9 by 9 Sudoku matrix solving program that was developed by JeongHwan Kim(21400181), ChunMyung Park(21400337), HoYoon Choi(21600744)

Programming assignment #1 for Discrete Mathematics class, Handong University.

## Build status

| Windows x64 | 
| ----------- | 
 [![win64-badge](https://cz3.visualstudio.com/_apis/public/build/definitions/bf14bcc7-ebd4-4240-812c-5972fa59e0ad/7/badge)](https://cz3.visualstudio.com/Z3/_build/index?definitionId=7) | 

## Building Sudoku Solver on Windows using git bash

__Preparations to be made in advance__ : 
```
Set up Z3 program in the Windows environment variable
Prepare input.txt file
```

64-bit builds, start with ‘git bash’ (if you can use makefile):
```bash
$ make
```

or

64-bit builds, start with ‘git bash’ (if you cannot use makefile):
```bash
$ gcc -g -o Sudoku.out -std=gnu99 main.c Sudoku/sudoku.c Sudoku/create_formula.c
```

---------------------------------------

Excute Sudoku Solver:
```
$ ./Sudoku.out
```

or 

you have input file that name is not “input.txt” (The File Extension must be ".txt"):
```
$ ./Sudoku.out <input file name>
```
