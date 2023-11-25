# Angle

## Table of contents

- Running
- Testing
- make Commands
- Authors

## Running
To run the parser:

1. Clone this repository.
2. Navigate to the project directory.
3. Use the command `make run` to compile and run the parser.

## Testing
Testing the lexer and parser:

1. Use the command `make test` to execute the tests for the lexer and parser.


## make Commands
This project utilizes a `Makefile` for ease of compilation and testing. Here's a list of available commands:

- `make all`: Builds the `parser` executable.
- `make parser`: Builds the parser from the yacc and lex files.
- `make clean`: Removes generated files including the `parser` executable.
- `make run`: Compiles and runs the parser.
- `make test`: Runs the tests using the `testall.sh` script.

## Authors - Team 7
- Tejal Kulkarni    - CS21BTECH11058
- Nitya Bhamidipaty - CS21BTECH11041
- Deepshikha        - CS21BTECH11016
- Muskan Jaiswal    - CS21BTECH11037

/*
Ignore 
    1) testing some parts is left in Line
    2) replace with loop and check .. Maybe should start properly => angle bisector
    3) Test the extension fo 6 cases => change so that if initial points are outofRange update Range, => Depends on our set Range
    4) Have to display midpoint ? 
    5) we will have to use new update constructors properly and delete in main after MainLoop
*/
