
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

release : $(release_folder) $(release_folder)/main
	./$(release_folder)/main

debug : $(debug_folder) $(debug_folder)/main
	valgrind --leak-check=yes ./$(debug_folder)/main

# utworzenie folderow:

$(release_folder) : 
	mkdir -p $(release_folder)
$(debug_folder) : 
	mkdir -p $(debug_folder)

# kompilacja zrodel:

$(release_folder)/selection-sort.o : selection-sort.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/selection-sort.o : selection-sort.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/heapsort.o : heapsort.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/heapsort.o : heapsort.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/pivot_middle.o : pivot_middle.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/pivot_middle.o : pivot_middle.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/pivot_random.o : pivot_random.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/pivot_random.o : pivot_random.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/pivot_selector.o : pivot_selector.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/pivot_selector.o : pivot_selector.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/main.o : main.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/main.o : main.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/quicksort.o : quicksort.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/quicksort.o : quicksort.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/gaps_shell.o : gaps_shell.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/gaps_shell.o : gaps_shell.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/sorter.o : sorter.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/sorter.o : sorter.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/gaps_frank.o : gaps_frank.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/gaps_frank.o : gaps_frank.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/bubblesort.o : bubblesort.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/bubblesort.o : bubblesort.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/insertion-sort.o : insertion-sort.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/insertion-sort.o : insertion-sort.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/mergesort.o : mergesort.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/mergesort.o : mergesort.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/clock.o : clock.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/clock.o : clock.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/pivot_median_of_3.o : pivot_median_of_3.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/pivot_median_of_3.o : pivot_median_of_3.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/pivot_last.o : pivot_last.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/pivot_last.o : pivot_last.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/pivot_first.o : pivot_first.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/pivot_first.o : pivot_first.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/shellsort.o : shellsort.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/shellsort.o : shellsort.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/gap_generator.o : gap_generator.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/gap_generator.o : gap_generator.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/pivot_median_of_3_medians_of_3.o : pivot_median_of_3_medians_of_3.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/pivot_median_of_3_medians_of_3.o : pivot_median_of_3_medians_of_3.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^

# linkowanie:

$(release_folder)/main : $(release_folder)/selection-sort.o $(release_folder)/heapsort.o $(release_folder)/pivot_middle.o $(release_folder)/pivot_random.o $(release_folder)/pivot_selector.o $(release_folder)/main.o $(release_folder)/quicksort.o $(release_folder)/gaps_shell.o $(release_folder)/sorter.o $(release_folder)/gaps_frank.o $(release_folder)/bubblesort.o $(release_folder)/insertion-sort.o $(release_folder)/mergesort.o $(release_folder)/clock.o $(release_folder)/pivot_median_of_3.o $(release_folder)/pivot_last.o $(release_folder)/pivot_first.o $(release_folder)/shellsort.o $(release_folder)/gap_generator.o $(release_folder)/pivot_median_of_3_medians_of_3.o 
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -o $@ $^

$(debug_folder)/main : $(debug_folder)/selection-sort.o $(debug_folder)/heapsort.o $(debug_folder)/pivot_middle.o $(debug_folder)/pivot_random.o $(debug_folder)/pivot_selector.o $(debug_folder)/main.o $(debug_folder)/quicksort.o $(debug_folder)/gaps_shell.o $(debug_folder)/sorter.o $(debug_folder)/gaps_frank.o $(debug_folder)/bubblesort.o $(debug_folder)/insertion-sort.o $(debug_folder)/mergesort.o $(debug_folder)/clock.o $(debug_folder)/pivot_median_of_3.o $(debug_folder)/pivot_last.o $(debug_folder)/pivot_first.o $(debug_folder)/shellsort.o $(debug_folder)/gap_generator.o $(debug_folder)/pivot_median_of_3_medians_of_3.o 
	$(kompilator) $(standard) $(debug) $(optDebug) $(rownoleglosc) $(errors) -o $@ $^

# usuniecie plikow skompilowanych:

clean : 
	if [ -d $(debug_folder)      ] ; then rm -r $(debug_folder)   ; fi
	if [ -d $(release_folder)    ] ; then rm -r $(release_folder) ; fi;


