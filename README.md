# In LINUX
```
$ make
$ ./Sudoku.out (open output file)
$ gdb Sudoku (debugging system)
```

# If you cannot use makefile (In LINUX)
```
$ gcc -g -o Sudoku.out -std=gnu99 main.c Sudoku/sudoku.c Sudoku/create_formula.c
$ ./Sudoku.out (open output file)
$ gdb Sudoku (debugging system)
```

# IN WINDOW
```
$ gcc -g -o Sudoku.out -std=gnu99 main.c Sudoku/sudoku.c Sudoku/create_formula.c
$ Sudoku.out (open output file)
$ gdb Sudoku.out (debugging system)
```

### We need to add some introduction of this Programming Assignment repository
### we need to do refactoring (throw and catch or error detector, etc.)
### we need to change the method name '_popen()' to 'popen()' that used by Sudoku\sudoku.c ... run_dimacs() function.
