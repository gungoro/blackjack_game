# example makefile
#
# Notes:
# - the indents must be tabs
# - if you need to specify a non-standard compiler, then set CXX
#   (it defaults to g++)
# - if you need to pass flags to the linker, set LDFLAGS rather
#   than alter the ${TARGET}: ${OBJECTS} rule
# - to see make's built-in rules use make -p

# target executable name
TARGET = blackjack_game

# source files
SOURCES = main.cpp Game.cpp Card.cpp Hand.cpp GenericPlayer.cpp Player.cpp House.cpp Deck.cpp 

# work out names of object files from sources
OBJECTS = $(SOURCES:.cpp=.o)

# compiler flags (do not include -c here as it's dealt with by the
# appropriate rules; CXXFLAGS gets passed as part of command
# invocation for both compilation (where -c is needed) and linking
# (where it's not.)
CXXFLAGS = -Wall -Wextra -I.

# default target (to build all)
all: ${TARGET}

# clean target
clean:
	rm ${OBJECTS} ${TARGET}

# rule to link object files to create target executable
# $@ is the target, here $(TARGET), and $^ is all the
# dependencies separated by spaces (duplicates removed),
# here ${OBJECTS}
${TARGET}: ${OBJECTS}
	${LINK.cc} -o $@ $^

# no rule is needed here for compilation as make already
# knows how to do it

# header dependencies (in more complicated cases, you can
# look into generating these automatically.)

#product.o : product.h test1.h test2.h
