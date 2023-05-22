kompilator=g++
standard=-std=c++20
optymalizacja=-O3
errors=-pedantic-errors

# debug=-g
debug=


.PHONY : clean 


#	valgrind --leak-check=yes ./main

auto : auto.exe
	./$^
hetman-queens : hetman-queens.exe
	./$^
kolko-krzyzyk-noughts-and-crosses : kolko-krzyzyk-noughts-and-crosses.exe
	./$^
sudoku : sudoku.exe
	./$^ sudoku-1.in sudoku-1.out
	./$^ sudoku-2.in sudoku-2.out

talia : talia.exe
	./$^
zalka : zalka.exe
	./$^



auto.exe : auto.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -o $@ $^
hetman-queens.exe : hetman-queens.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors)  -o $@ $^
kolko-krzyzyk-noughts-and-crosses.exe : kolko-krzyzyk-noughts-and-crosses.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors)  -o $@ $^
sudoku.exe : sudoku.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors)  -o $@ $^
talia.exe : talia.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors)  -o $@ $^
zalka.exe : zalka.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors)  -o $@ $^


clean : 
	rm *.exe *.out

