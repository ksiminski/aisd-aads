kompilator=g++
standard=-std=c++20
optymalizacja=-O3
errors=-pedantic-errors

# debug=-g
debug=



.PHONY : clean 

nieposortowane : osoby
	cat osoby

stabilne : osoby 
	cat osoby | sort -k2,2 | sort -s -k3,3

niestabilne : osoby
	cat osoby | sort -k2,2 | sort -k3,3

osoby : main
	./main
	
main.o : main.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -c -o $@ $^

main : main.o 
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -o $@ $^


clean : 
	rm main main.o osoby

