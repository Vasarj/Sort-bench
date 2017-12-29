# OpenMP-bench: makefile
#

# Googletest settings
GTEST_PATH = ${GOOGLE_TEST_PATH}
GTEST_LIB = gtest
GTESTOPT = --gtest_repeat=10 --gtest_break_on_failure
GTESTFLAGS = -L$(GTEST_PATH) -l$(GTEST_LIB) -lpthread

# Compiler settings
C++ = g++
WFLAGS = -Wall -pedantic
OPTFLAGS = -O3

# Profiling setting
PROFLAGS =

# Directory settings
src = src
inc = inc
out = out
test = gtest

# Phonies
.PHONY = unit test run bin clean

# Compilation: Benchmark
run: bin
	benchRunner.exe
	
bin: $(out)/benchRunner.o
	$(C++) $< -o benchRunner.exe
	
$(out)/benchRunner.o: $(src)/benchRunner.cpp $(wildcard $(inc)/*.h)
	$(C++) $(PROFLAGS) $(OPTFLAGS) $(WFLAGS) -I$(inc) -o $@ -c $<

	
# Compilation: Unit Testing
test: unit
	testRunner.exe $(GTESTOPT)

unit: $(out)/test_main.o
	$(C++) -o testRunner.exe $< $(GTESTFLAGS)
   
$(out)/test_main.o: $(test)/test_main.cpp $(wildcard $(inc)/*.h)
	$(C++) $(WFLAGS) -o $@ -c $<

	
# Clean up
clean:
	del *.exe $(out)/*.o *.out
