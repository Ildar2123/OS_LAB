CC := g++
FLAGS := -std=c++17 -Wall
SRC_DIR := src/
LAUNCHER := Lite_SH

.PHONY : all
all: compile

.PHONY : compile
compile:
	$(CC) $(FLAGS) $(wildcard $(SRC_DIR)*.cpp) -o $(LAUNCHER) -lstdc++fs

.PHONY : clean
clean:
	rm -r $(LAUNCHER)
