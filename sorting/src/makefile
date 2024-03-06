
############################################
# Prosty generator plikow makefile dla g++ #
# Simple generator of makefiles for g++    #
#          Krzysztof Siminski, 2024        #
############################################

# [PL] OPCJE:
# [EN] OPTIONS:

compiler=g++
standard=-std=c++23

# [PL] optymalizacja [EN] optimisation
optRelease=-O3
optDebug=

errors=-pedantic-errors

release=
#debug=-g
# [PL] opcja -pg dla profilowania:
# [EN] -pg option for profiling:
debug=-pg

#parallel=-fopenmp
parallel=

release_folder=_release
debug_folder=_debug

#sanitizer=-fsanitize=address
#libasan=-static-libasan
sanitizer=
libasan=

#############################

.PHONY : clean $(debug_folder) $(release_folder)

# [PL] opcje uruchomienia projektu:
# [EN] project run options:

release : $(release_folder) $(release_folder)/main
	./$(release_folder)/main

debug : $(debug_folder) $(debug_folder)/main
	valgrind --leak-check=yes ./$(debug_folder)/main
#	./$(debug_folder)/main

# [PL] profilowanie [EN] profiling
gprof : $(debug_folder) $(debug_folder)/main
	./$(debug_folder)/main
	gprof ./$(debug_folder)/main gmon.out
	rm gmon.out

# [PL] utworzenie folderow:
# [EN] create directories:

$(release_folder) : 
	mkdir -p $(release_folder)
$(debug_folder) : 
	mkdir -p $(debug_folder)

# [PL] kompilacja zrodel:
# [EN] source compilation:

$(release_folder)/n2-sorting-selection-sort.o : n2-sorting/selection-sort.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/n2-sorting-selection-sort.o : n2-sorting/selection-sort.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/n2-sorting-bubblesort.o : n2-sorting/bubblesort.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/n2-sorting-bubblesort.o : n2-sorting/bubblesort.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/n2-sorting-insertion-sort.o : n2-sorting/insertion-sort.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/n2-sorting-insertion-sort.o : n2-sorting/insertion-sort.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/main.o : main.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/main.o : main.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/sorter.o : sorter.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/sorter.o : sorter.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/nlogn-sorting-heapsort.o : nlogn-sorting/heapsort.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/nlogn-sorting-heapsort.o : nlogn-sorting/heapsort.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/nlogn-sorting-quicksort.o : nlogn-sorting/quicksort.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/nlogn-sorting-quicksort.o : nlogn-sorting/quicksort.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/nlogn-sorting-mergesort.o : nlogn-sorting/mergesort.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/nlogn-sorting-mergesort.o : nlogn-sorting/mergesort.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/nlogn-sorting-pivots-pivot_middle.o : nlogn-sorting/pivots/pivot_middle.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/nlogn-sorting-pivots-pivot_middle.o : nlogn-sorting/pivots/pivot_middle.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/nlogn-sorting-pivots-pivot_random.o : nlogn-sorting/pivots/pivot_random.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/nlogn-sorting-pivots-pivot_random.o : nlogn-sorting/pivots/pivot_random.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/nlogn-sorting-pivots-pivot_selector.o : nlogn-sorting/pivots/pivot_selector.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/nlogn-sorting-pivots-pivot_selector.o : nlogn-sorting/pivots/pivot_selector.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/nlogn-sorting-pivots-pivot_median_of_3.o : nlogn-sorting/pivots/pivot_median_of_3.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/nlogn-sorting-pivots-pivot_median_of_3.o : nlogn-sorting/pivots/pivot_median_of_3.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/nlogn-sorting-pivots-pivot_last.o : nlogn-sorting/pivots/pivot_last.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/nlogn-sorting-pivots-pivot_last.o : nlogn-sorting/pivots/pivot_last.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/nlogn-sorting-pivots-pivot_first.o : nlogn-sorting/pivots/pivot_first.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/nlogn-sorting-pivots-pivot_first.o : nlogn-sorting/pivots/pivot_first.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/nlogn-sorting-pivots-pivot_median_of_3_medians_of_3.o : nlogn-sorting/pivots/pivot_median_of_3_medians_of_3.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/nlogn-sorting-pivots-pivot_median_of_3_medians_of_3.o : nlogn-sorting/pivots/pivot_median_of_3_medians_of_3.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/shellsort-gaps-gaps_shell.o : shellsort/gaps/gaps_shell.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/shellsort-gaps-gaps_shell.o : shellsort/gaps/gaps_shell.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/shellsort-gaps-gaps_frank.o : shellsort/gaps/gaps_frank.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/shellsort-gaps-gaps_frank.o : shellsort/gaps/gaps_frank.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/shellsort-gaps-gap_generator.o : shellsort/gaps/gap_generator.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/shellsort-gaps-gap_generator.o : shellsort/gaps/gap_generator.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/shellsort-shellsort.o : shellsort/shellsort.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/shellsort-shellsort.o : shellsort/shellsort.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^
$(release_folder)/clock.o : clock.cpp
	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -c -o $@ $^
$(debug_folder)/clock.o : clock.cpp
	$(compiler) $(standard) $(debug) $(optyDebug) $(parallel) $(errors) $(sanitizer) -c -o $@ $^

# [PL] linkowanie:
# [EN] linking:

$(release_folder)/main : \
$(release_folder)/clock.o \
$(release_folder)/n2-sorting-insertion-sort.o \
$(release_folder)/nlogn-sorting-pivots-pivot_first.o \
$(release_folder)/nlogn-sorting-pivots-pivot_median_of_3.o \
$(release_folder)/shellsort-gaps-gap_generator.o \
$(release_folder)/shellsort-gaps-gaps_shell.o \
$(release_folder)/nlogn-sorting-heapsort.o \
$(release_folder)/n2-sorting-selection-sort.o \
$(release_folder)/shellsort-shellsort.o \
$(release_folder)/nlogn-sorting-pivots-pivot_last.o \
$(release_folder)/nlogn-sorting-quicksort.o \
$(release_folder)/nlogn-sorting-pivots-pivot_median_of_3_medians_of_3.o \
$(release_folder)/main.o \
$(release_folder)/nlogn-sorting-pivots-pivot_selector.o \
$(release_folder)/nlogn-sorting-pivots-pivot_random.o \
$(release_folder)/shellsort-gaps-gaps_frank.o \
$(release_folder)/nlogn-sorting-pivots-pivot_middle.o \
$(release_folder)/sorter.o \
$(release_folder)/n2-sorting-bubblesort.o \
$(release_folder)/nlogn-sorting-mergesort.o \

	$(compiler) $(standard) $(release) $(optRelease) $(parallel) $(errors) -o $@ $^

$(debug_folder)/main : \
$(debug_folder)/clock.o \
$(debug_folder)/n2-sorting-insertion-sort.o \
$(debug_folder)/nlogn-sorting-pivots-pivot_first.o \
$(debug_folder)/nlogn-sorting-pivots-pivot_median_of_3.o \
$(debug_folder)/shellsort-gaps-gap_generator.o \
$(debug_folder)/shellsort-gaps-gaps_shell.o \
$(debug_folder)/nlogn-sorting-heapsort.o \
$(debug_folder)/n2-sorting-selection-sort.o \
$(debug_folder)/shellsort-shellsort.o \
$(debug_folder)/nlogn-sorting-pivots-pivot_last.o \
$(debug_folder)/nlogn-sorting-quicksort.o \
$(debug_folder)/nlogn-sorting-pivots-pivot_median_of_3_medians_of_3.o \
$(debug_folder)/main.o \
$(debug_folder)/nlogn-sorting-pivots-pivot_selector.o \
$(debug_folder)/nlogn-sorting-pivots-pivot_random.o \
$(debug_folder)/shellsort-gaps-gaps_frank.o \
$(debug_folder)/nlogn-sorting-pivots-pivot_middle.o \
$(debug_folder)/sorter.o \
$(debug_folder)/n2-sorting-bubblesort.o \
$(debug_folder)/nlogn-sorting-mergesort.o \

	$(compiler) $(standard) $(debug) $(optDebug) $(parallel) $(errors) $(sanitizer) $(libasan) -o $@ $^

# [PL] usuniecie plikow skompilowanych:
# [EN] remove compiled files:

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

