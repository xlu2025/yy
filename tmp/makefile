CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o organism.o ant.o queen_ant.o doodlebug.o simulation.o

all: simulation

simulation: $(OBJS)
	$(CXX) $(CXXFLAGS) -o simulation $(OBJS)

main.o: main.cpp simulation.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

organism.o: organism.cpp organism.hpp
	$(CXX) $(CXXFLAGS) -c organism.cpp

ant.o: ant.cpp ant.hpp organism.hpp
	$(CXX) $(CXXFLAGS) -c ant.cpp

queen_ant.o: queen_ant.cpp queen_ant.hpp ant.hpp organism.hpp
	$(CXX) $(CXXFLAGS) -c queen_ant.cpp

doodlebug.o: doodlebug.cpp doodlebug.hpp organism.hpp
	$(CXX) $(CXXFLAGS) -c doodlebug.cpp

simulation.o: simulation.cpp simulation.hpp
	$(CXX) $(CXXFLAGS) -c simulation.cpp

clean:
	rm -f $(OBJS) simulation

