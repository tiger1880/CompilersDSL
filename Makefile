#Flags and variables
CC = g++
YACC = bison
LEX = lex
LIBS = -lfl # for flex

# <basename>.y for bison
FILENAME = test

# Define the target executable
TARGET = parser

#Define the test-cases bash script
TEST = testall.sh

# Default target: build the executable
all: $(TARGET)

# Rule to build the target executable
parser: $(TARGET).tab.c lex.yy.c utils
	$(CC) -o $(TARGET) utils $(TARGET).tab.c lex.yy.c $(LIBS)

# Build the yacc file
$(TARGET).tab.c: $(TARGET).y
	$(YACC) -d $(TARGET).y

# Build the lex file 
lex.yy.c: lexer.l
	$(LEX) lexer.l

#Build the utils file
utils: utils.cpp
	$(CC) -c utils.cpp -o utils

# Clean target: remove the target executable
clean:
	rm -f $(TARGET) lex.yy.c y.tab.c y.tab.h error.txt seq_token.txt utils

# Clean target: remove the itarget files BISON version
clean2: 
	rm -f $(TARGET) lex.yy.c $(TARGET).tab.c $(TARGET).tab.h error.txt seq_token.txt utils

# Run target: build and run the target executable
run: $(TARGET)
	./$(TARGET)

# Test target: run tests for the lexer and parser
test: $(TEST)
	bash $(TEST)


 