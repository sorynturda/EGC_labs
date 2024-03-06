# main: main.cpp vec2.h vec3.h vec4.h vec2.cpp vec3.cpp vec4.cpp
#	g++ -Wall main.cpp vec2.cpp vec3.cpp vec4.cpp -o main -g

CPP_FILES=$(wildcard *.cpp)
OBJ_FILES=$(CPP_FILES:.cpp=.o)
DEP_FILES=$(CPP_FILES:.cpp=.d)

-include $(DEP_FILES)
%.o: %.cpp
	g++ -c -MMD -o $@ $<

main1: $(OBJ_FILES)
	g++ -o $@ $^

all: main1
