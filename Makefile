CXX=g++
CXXFLAGS=--std=c++11 -Wall -pedantic-errors -Werror -DNDEBUG
OBJS=Card.o Mtmchkin.o Player.o test.o utilities.o
EXEC=mtmchkin

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

Card.o: Card.cpp Card.h Player.h utilities.h
	$(CXX) $(CXXFLAGS) -c Card.cpp

Mtmchkin.o: Mtmchkin.cpp Mtmchkin.h Card.h Player.h utilities.h
	$(CXX) $(CXXFLAGS) -c Mtmchkin.cpp

Player.o: Player.cpp Player.h utilities.h
	$(CXX) $(CXXFLAGS) -c Player.cpp

test.o: test.cpp Player.h utilities.h Card.h Mtmchkin.h
	$(CXX) $(CXXFLAGS) -c test.cpp

utilities.o: utilities.cpp utilities.h
	$(CXX) $(CXXFLAGS) -c utilities.cpp

clean:
	rm -f $(OBJS) $(EXEC)
