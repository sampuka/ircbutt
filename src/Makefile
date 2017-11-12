IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -g -Wall -std=c++11 -pthread

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = Instance.hpp MSocket.hpp Message.hpp PING.hpp PRIVMSG.hpp JOIN.hpp PART.hpp MODE.hpp Badges.hpp USERSTATE.hpp ROOMSTATE.hpp Channel.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = ircbutt.o Instance.o MSocket.o Message.o PING.o PRIVMSG.o JOIN.o PART.o MODE.o Badges.o USERSTATE.o ROOMSTATE.o Channel.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

CHEAT_ARG := $(shell mkdir -p obj)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ircbutt: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 
