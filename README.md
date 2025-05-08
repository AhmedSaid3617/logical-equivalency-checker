# Logical Equivalency Checker

This project is a **Logical Equivalency Checker** implemented in C++. It evaluates whether two logical expressions are equivalent and checks their satisfiability. The program also attempts to modify the expressions to make them satisfiable if they are not.

## Features

- **Logical Expression Parsing**: Supports logical operators like `&` (AND), `|` (OR), and `~` (NOT).
- **Truth Table Generation**: Generates truth tables for the given logical expressions.
- **Equivalency Check**: Compares two logical expressions to determine if they are logically equivalent.
- **Satisfiability Check**: Determines if there exists a set of inputs that satisfies both expressions.
- **Expression Modification**: Suggests modifications to make the expressions satisfiable if they are not.

## Input Format

- Logical expressions must be written in C/C++ style.
- Example: `(a&b) | (b|c)&(b&c) | ~(b&c)&(b&c)`
- Variables must be single characters (e.g., `a`, `b`, `c`).

## How It Works

1. The program takes two logical expressions as input.
2. It converts the infix expressions to prefix notation using the `infixToPrefix` function.
3. It generates truth tables for both expressions.
4. It checks if the expressions are equivalent by comparing their truth table outputs.
5. It checks if the expressions are satisfiable by finding input combinations that satisfy both expressions.
6. If the expressions are not satisfiable, the program attempts to modify them to make them satisfiable.

## Usage

1. Clone the repository or copy the project files to your local machine.
2. Compile the program using a C++ compiler. For example:
   ```bash
   g++ main.cpp Expression.cpp Postfix.cpp -o logical_checker
   ```
3. Run the program:
    ```
    ./logical_checker
    ```
4. Follow the on-screen instructions to input logical expressions or use the default examples provided in the code.

## Example Output

    ```
    The input expressions must be in c/c++ form
    Given example: (a&b) | (b|c)&(b&c) | ~(b&c)&(b&c)
    Simplified version: b&(a|c)
    Or you can try any two logical expressions.
    The expressions can have any number of variables but must be an equal number
    All variables must be exactly one character.

    (a&b) | (b|c)&(b&c) | ~(b&c)&(b&c)
    **********************
    b&(a|c)
    Expressions are not equivalent
    Expressions are satisfiable.
    The inputs that make these expressions satisfiable are:
    a:1 b:1 c:0
    ```

## File Structure

- `main.cpp`: Contains the main logic for the program.
- `Expression.h` and `Expression.cpp`: Define and implement the `Expression` class and its derived classes for logical operations.
- `Postfix.h` and `Postfix.cpp`: Provide utility functions for converting infix expressions to prefix notation.
- `.gitignore`: Specifies files and directories to ignore in version control.
- `README.md`: Documentation for the project.

## Dependencies

- Standard C++ libraries: `<iostream>`, `<string>`, `<vector>`, `<stack>`, `<algorithm>`, `<cmath>`, `<cctype>`.

## License

This project is open-source and available under the MIT License.