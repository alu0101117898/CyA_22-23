CC=g++
CCXFLAGS=-g -std=c++14 -Wall

OBJS= dfa_simulation.o dfa.o state.o Transition.o Alfabeto.o Symbol.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o dfa_simulation ${OBJS}

clean: 
	rm -rf *.o dfa_simulation