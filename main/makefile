CXX = g++
CC = $(CXX)

CPPFLAGS = -I$(INC_DIR)
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++14
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

INC_DIR = ../inc
SRC_DIR = ../src

TARGET = main
OBJS = main.o point.o vector.o ellipse.o circle.o helix.o curves_generator.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

main : main.cpp $(SRC_DIR)/point.cpp $(SRC_DIR)/vector.cpp $(SRC_DIR)/ellipse.cpp $(SRC_DIR)/circle.cpp $(SRC_DIR)/helix.cpp $(SRC_DIR)/curves_generator.cpp
clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean