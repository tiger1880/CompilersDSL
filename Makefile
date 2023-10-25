#Flags and variables
CC = gcc
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
parser: y.tab.c lex.yy.c
	$(CC) -o $(TARGET) y.tab.c lex.yy.c $(LIBS)

# Build the yacc file
y.tab.c: parser.y
	$(YACC) -d parser.y

# Build the lex file 
lex.yy.c: lexer.l
	$(LEX) lexer.l

# Clean target: remove the target executable
clean:
	rm -f $(TARGET) lex.yy.c y.tab.c y.tab.h

# Run target: build and run the target executable
run: $(TARGET)
	./$(TARGET)

# Test target: run tests for the lexer and parser
test: $(TEST)
	./$(TEST)


 