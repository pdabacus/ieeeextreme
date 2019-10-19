# Makefile for a.out
# usage: make [FLAGS=<flags>]
# make test : compares expected to actual output
# make cov  : rebuilds project and tests line coverage

BIN     		=
SOURCES 		= main.cpp
HEADERS 		=
TARGET  		= a.out

CXX     		= g++
GXXOPTS 		= -Wall -ansi -std=c++11
LDLIBS  		=
CXXOPTS 		= $(GXXOPTS) $(FLAGS)

RM      		= rm -rf

OBJ     		= $(patsubst %.cpp,$(BIN)%.o,$(SOURCES))

all:    		$(TARGET)
				@./$(TARGET) < i

# compile .cpp source files to objects (.o)
$(BIN)%.o: 		%.cpp $(HEADERS)
				$(CXX) $(CXXOPTS) -o $@ -c $<

# link executable
$(TARGET):		$(OBJ) $(COBJ)
				$(CXX) $(CXXOPTS) -o $@ $^ $(LDLIBS)
				@echo "binary compiled: '$(TARGET)'"

# remove objects and executable
clean:
				$(RM) $(TARGET) $(OBJ)
