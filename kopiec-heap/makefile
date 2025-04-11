
#############################
# Generator plikow makefile #
# Krzysztof Siminski, 2023  #
#############################

# STALE:
kompilator=g++
standard=-std=c++23

optRelease=-O3
optDebug=

errors=-pedantic-errors

release=
debug=-g

#rownoleglosc=-fopenmp
rownoleglosc=

release_folder=_release
debug_folder=_debug

#############################

.PHONY : clean $(debug_folder) $(release_folder)

# opcje uruchomienia projektu:

output_file=$(release_folder)/output.dat

wykres : $(release_folder) $(release_folder)/main $(output_file)  
	pdflatex plot.tex

$(output_file) : $(release_folder) $(release_folder)/main
	./$(release_folder)/main $(output_file) 

# utworzenie folderow:

$(release_folder) : 
	mkdir -p $(release_folder)
 

# kompilacja zrodel:

$(release_folder)/main.o : main.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/clock.o : clock.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^

# linkowanie:

$(release_folder)/main : $(release_folder)/main.o $(release_folder)/clock.o 
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -o $@ $^


# usuniecie plikow skompilowanych:

clean : 
	if [ -d $(debug_folder)      ] ; then rm -r $(debug_folder)   ; fi
	if [ -d $(release_folder)    ] ; then rm -r $(release_folder) ; fi;
	if [ -f *.aux ] ; then rm *.aux ; fi 
	if [ -f *.log ] ; then rm *.log ; fi 
	if [ -f *.out ] ; then rm *.out ; fi 


