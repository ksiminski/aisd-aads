
.PHONY : clean

__start__ : nawiasowanie
	./nawiasowanie 100 1 100 1 100 1 100 > wyniki1.txt
	./nawiasowanie 1 100 1 100 1 100 1   > wyniki2.txt
	./nawiasowanie 2 10 100 50 20 1      > wyniki3.txt
	./nawiasowanie 2 10 100 50 20 1 45 63 12 1 765  89 45 31     > wyniki4.txt
	./nawiasowanie 2 10 100 50 20 1 9 45 31 1000 4 35 1000       > wyniki5.txt
	./nawiasowanie 2 10 100 1 10         > wyniki6.txt
	./nawiasowanie 20 10 1 100 10        > wyniki7.txt
	./nawiasowanie 20 1 100 2 50 10      > wyniki8.txt
	./nawiasowanie 20 1 100 2 50         > wyniki9.txt

nawiasowanie : nawiasowanie.cpp
	g++ nawiasowanie.cpp -o nawiasowanie   
	
	
clean : 
	rm *.txt nawiasowanie

