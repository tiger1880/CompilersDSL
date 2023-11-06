#Flags and variables
CC = g++
YACC = yacc
LEX = lex
LIBS = -lfl # for flex

# Define the target executable
TARGET = parser

#Define the test-cases bash script
TEST = testall.sh

# Default target: build the executable
all: $(TARGET)

# Rule to build the target executable
parser: y.tab.c lex.yy.c utils
	$(CC) -o $(TARGET) utils y.tab.c lex.yy.c $(LIBS)

# Build the yacc file
y.tab.c: parser.y
	$(YACC) -d parser.y

# Build the lex file 
lex.yy.c: lexer.l
	$(LEX) lexer.l

#Build the utils file
utils: utils.cpp
	$(CC) -c utils.cpp -o utils

# Clean target: remove the target executable
clean:
	rm -f $(TARGET) lex.yy.c y.tab.c y.tab.h error.txt seq_token.txt utils

# Run target: build and run the target executable
run: $(TARGET)
	./$(TARGET)

# Test target: run tests for the lexer and parser
test: $(TEST)
	bash $(TEST)


 