# OpenMP-bench: makefile
#

# TODO: Googletest settings
GTEST_PATH =
GTEST_LIB =
GTESTFLAGS =

# Compiler settings
C++ = g++
WFLAGS = -Wall -pedantic
OPTFLAGS = -O3

# Profiling Setting
PROFLAGS =

# Directory settings
src = src
inc = inc
out = out
test = test

# Phonies
.PHONY = run bin clean

# Compilation: Benchmarks
run: bin
	benchRunner.exe
	
bin: $(out)/benchRunner.o
	$(C++) $< -o benchRunner.exe
	
$(out)/benchRunner.o: $(src)/benchRunner.cpp $(wildcard $(inc)/*.h)
	$(C++) $(PROFLAGS) $(OPTFLAGS) $(WFLAGS) -I$(inc) -o $@ -c $<
	
# Clean up
clean:
	del *.exe $(out)/*.o *.out
