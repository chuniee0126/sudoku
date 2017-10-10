# Sudoku Solver

Sudoku.out은 9 by 9 Sudoku 매트릭스를 푸는 프로그램(Prover)으로, (from)김정환(21400181), 박천명(21400337), 김호윤(21600744)에 의해 개발되었습니다.

이는 한동대학교 이산수학 수업의 과제물입니다.

## Build status

| Windows x64 | 
| ----------- | 
 [![win64-badge](https://cz3.visualstudio.com/_apis/public/build/definitions/bf14bcc7-ebd4-4240-812c-5972fa59e0ad/7/badge)](https://cz3.visualstudio.com/Z3/_build/index?definitionId=7) | 

## Building Sudoku Solver on Windows using git bas

__사전 준비 사항__ : 
```
Z3 프로그램 윈도우 환경변수 설정
Input.txt 파일 준비
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

Then:
```
$ ./Sudoku.out
```

or 

you have input file that name is not “input.txt” (하지만 파일 확장자는 .txt 여야 한다):
```
$ ./Sudoku.out <input file name>
```
