CPP_FILES=$(wildcard *.cpp)
OBJ_FILES=$(CPP_FILES:.cpp=.o)
DEP_FILES=$(CPP_FILES:.cpp=.d)

-include $(DEP_FILES)
%.o: %.cpp
	g++ -c -MMD -o $@ $<

main1: $(OBJ_FILES)
	g++ -o $@ $^

all: main1
