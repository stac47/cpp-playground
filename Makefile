# My template for basic C++ projects
# Author: Laurent Stacul

# Global settings
CC=g++
CFLAGS=-Wall -std=c++11 -O
CFLAGS_TEST=-DBOOST_TEST_DYN_LINK
LDFLAGS=

# Dependencies
DLIBS=
DLIBS_TEST=boost_unit_test_framework

# Source code
SRC_DIR=src
TEST_DIR=test
SRC:=$(wildcard $(SRC_DIR)/*.cpp)
HEADERS:=$(wildcard $(SRC_DIR)/*.h)
SRC_TEST:=$(wildcard $(TEST_DIR)/*.cpp)
OBJ:=$(SRC:.cpp=.o)
OBJ_TEST:=$(SRC_TEST:.cpp=.o)
EXEC=main
EXEC_TEST=main_test

all: $(EXEC_TEST)

$(EXEC): $(OBJ)
	$(CC) -l $(DLIBS) -o $@ $^ $(LDFLAGS)

$(EXEC_TEST): $(OBJ) $(OBJ_TEST)
	$(CC) -l $(DLIBS_TEST) -o $@ $^ $(LDFLAGS)

%.o: $(HEADERS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) -I $(SRC_DIR) -o $@ -c $< $(CFLAGS) $(CFLAGS_TEST)

clean:
	rm -f $(SRC_DIR)/*.o
	rm -f $(TEST_DIR)/*.o

mrproper: clean
	rm -f $(EXEC)
	rm -f $(EXEC_TEST)
	rm -f core

.PHONY:force

debug: force
	$(info $(SRC))
	$(info $(HEADERS))
	$(info $(OBJ))
	$(info $(SRC_TEST))
	$(info $(OBJ_TEST))
