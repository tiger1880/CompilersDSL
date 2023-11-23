#Flags and variables
CC = g++
YACC = bison
LEX = lex
LIBS = -lfl # for flex

# <basename>.y for bison
FILENAME = parser

# Define the target executable
TARGET = parser

#Define the test-cases bash script
TEST = testall.sh

# Default target: build the executable
all: $(TARGET)

# Rule to build the target executable
parser: $(FILENAME).tab.c lex.yy.c utils
	$(CC) -o $(TARGET) utils $(FILENAME).tab.c lex.yy.c $(LIBS)

# Build the yacc file
$(FILENAME).tab.c: $(FILENAME).y
	$(YACC) -d $(FILENAME).y

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
	rm -f $(TARGET) lex.yy.c $(FILENAME).tab.c $(FILENAME).tab.h error.txt seq_token.txt utils translated.cpp

# Clean specification latex log files
clean_latex:
	rm -f ./specs/*.log ./specs/*.toc ./specs/*.fls ./specs/*.aux ./specs/*.fdb_latexmk ./specs/*.synctex.gz 

# Run target: build and run the target executable
run: $(TARGET)
	./$(TARGET)

# Test target: run tests for the lexer and parser
test: $(TEST)
	bash $(TEST)


 