IDIR = include

SDIR = src
CC=g++
CFLAGS=-I$(IDIR) -g -Wall -std=c++11 -pthread

ODIR=$(SDIR)/obj
LDIR =../lib

LIBS=-lm

_DEPS = Instance.hpp MSocket.hpp Message.hpp PING.hpp PRIVMSG.hpp JOIN.hpp PART.hpp MODE.hpp Badges.hpp USERSTATE.hpp ROOMSTATE.hpp Channel.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = ircbutt.o Instance.o MSocket.o Message.o PING.o PRIVMSG.o JOIN.o PART.o MODE.o Badges.o USERSTATE.o ROOMSTATE.o Channel.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

ircbutt: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(SDIR)/*~ ircbutt $(IDIR)/*~
	rmdir $(ODIR)

$(shell mkdir -p $(ODIR))
