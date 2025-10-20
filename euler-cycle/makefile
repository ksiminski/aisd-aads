
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

sanitizer=-fsanitize=addresslibasan=-static-libasan
#############################

.PHONY : clean $(debug_folder) $(release_folder)

# opcje uruchomienia projektu:

release : $(release_folder) $(release_folder)/main
	./$(release_folder)/main

debug : $(debug_folder) $(debug_folder)/main
	valgrind --leak-check=yes ./$(debug_folder)/main
#	./$(debug_folder)/main

# utworzenie folderow:

$(release_folder) : 
	mkdir -p $(release_folder)
$(debug_folder) : 
	mkdir -p $(debug_folder)

# kompilacja zrodel:

$(release_folder)/main.o : main.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/main.o : main.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) $(sanitizer) -c -o $@ $^

# linkowanie:

$(release_folder)/main : \
$(release_folder)/main.o \

	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -o $@ $^

$(debug_folder)/main : \
$(debug_folder)/main.o \

	$(kompilator) $(standard) $(debug) $(optDebug) $(rownoleglosc) $(errors) $(sanitizer) $(libasan) -o $@ $^

# usuniecie plikow skompilowanych:

clean : 
	if [ -d $(debug_folder)      ] ; then rm -r $(debug_folder)   ; fi
	if [ -d $(release_folder)    ] ; then rm -r $(release_folder) ; fi;


5-minutes:
	find $(release_folder)/ -maxdepth 1 -type f -mmin -5 -delete
	find $(debug_folder)/ -maxdepth 1 -type f -mmin -5 -delete

10-minutes:
	find $(release_folder)/ -maxdepth 1 -type f -mmin -10 -delete
	find $(debug_folder)/ -maxdepth 1 -type f -mmin -10 -delete

30-minutes:
	find $(release_folder)/ -maxdepth 1 -type f -mmin -30 -delete
	find $(debug_folder)/ -maxdepth 1 -type f -mmin -30 -delete

60-minutes:
	find $(release_folder)/ -maxdepth 1 -type f -mmin -60 -delete
	find $(debug_folder)/ -maxdepth 1 -type f -mmin -60 -delete

1-days:
	find $(release_folder)/ -maxdepth 1 -type f -mtime -1 -delete
	find $(debug_folder)/ -maxdepth 1 -type f -mtime -1 -delete

doxygen:
	doxygen doxyfile

