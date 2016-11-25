CC = g++
LFLAGS = -std=c++11
CFLAGS = -c -g -Wall -Werror -Wextra

EXECUTABLE_NAME = TextAnalyser
SOURCES = main.cpp TextAnalyser.cpp func.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJECTS)
	$(CC) -o $(EXECUTABLE_NAME) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE_NAME)
