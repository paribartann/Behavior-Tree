CXX = g++
CXXFLAGS = -Wall -g -std=c++14
bt: main.o tree.o node.o action.o condition.o selector.o selectorstar.o sequence.o sequencestar.o

	$(CXX) $(CXXFLAGS) -o bt main.o tree.o node.o action.o condition.o selector.o selectorstar.o sequence.o sequencestar.o

main.o: main.cpp tree.h 
tree.o: tree.cpp tree.h 
node.o: node.cpp node.h
action.o: action.cpp action.h 
condition.o: condition.cpp condition.h
selector.o: selector.cpp selector.h
selectorstar.o: selectorstar.cpp selectorstar.h
sequence.o: sequence.cpp sequence.h
sequencestar.o: sequencestar.cpp sequencestar.h

TARGET = bt tree.o node.o action.o condition.o sequence.o sequencestar.o selector.o selectorstar.o

all: $(TARGET)

clean:
	$(RM) $(TARGET)
