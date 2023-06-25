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

INC_DIR = ../../inc
SRC_DIR = ../../src

TARGET = utest
OBJS = utest.o point.o vector.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(SRC_DIR)/point.cpp $(SRC_DIR)/vector.cpp
clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean