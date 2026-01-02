# Arithmetic Expression Evaluator with min/max

## Problem Statement

The program evaluates arithmetic expressions given in infix notation with two special prefix functions: `min` and `max`. The expression can contain:

- Single-digit decimal numbers (0-9)
- Basic arithmetic operators: `+`, `-`, `*`, `/`
- Parentheses: `(`, `)`
- Functions: `min(arg1, arg2)` and `max(arg1, arg2)`

All tokens in the input are separated by spaces. The goal is to evaluate the expression and output the integer result.

The implementation must use the **Shunting Yard Algorithm** and include a **Stack ADT** (as an interface/abstract class and its concrete implementation). Optionally, a Queue ADT may be used.

## Solution Overview

The program consists of three main components:

1. **Stack ADT Implementation** – An abstract base class `myStack` and its concrete implementation `StackinArray` using a `std::vector`.
2. **Shunting Yard Algorithm** – Converts the infix expression to Reverse Polish Notation (postfix).
3. **Postfix Evaluator** – Evaluates the postfix expression using a stack.

### Key Features:

- Handles operator precedence: `min`, `max` (highest), then `*`, `/`, then `+`, `-`.
- Processes function calls (`min`, `max`) as operators with two arguments.
- Manages parentheses and commas as argument separators in functions.
- Uses integer arithmetic; division performs integer division.

## Algorithm Details

### 1. Shunting Yard Algorithm

The algorithm reads tokens from the infix expression and uses two data structures:

- **Output queue** (implemented as a vector) for the postfix expression.
- **Operator stack** for holding operators and parentheses.

Rules:

- Numbers are directly added to the output.
- Left parenthesis `(` is pushed onto the stack.
- For a comma `,`, pop operators from the stack to the output until a `(` is found.
- For a right parenthesis `)`, pop operators to the output until a `(` is found, then pop the `(`. If the top of the stack is a function (`min`/`max`), pop it to the output.
- For an operator, while the stack is not empty and the top operator has higher or equal precedence, pop it to the output. Then push the new operator.
- After reading all tokens, pop any remaining operators to the output.

### 2. Postfix Evaluation

The postfix expression is evaluated using a stack:

- Push numbers onto the stack.
- For an operator, pop the required number of operands, perform the operation, and push the result.
- For `min` and `max`, pop two operands and compute the minimum or maximum.
- For arithmetic operators, perform the corresponding integer operation.

## Code Structure

- **`myStack`**: Abstract class with virtual methods `push`, `pop`, `peek`, `isEmpty`.
- **`StackinArray`**: Concrete stack implementation using a vector.
- **`precedence`**: Returns the precedence level of an operator.
- **`isOperator`**: Checks if a token is an operator (including `min`/`max`).
- **`isNumber`**: Checks if a token is a single-digit number.
- **`shuntingYard`**: Converts infix string to a vector of tokens in postfix order.
- **`evaluatePostfix`**: Evaluates the postfix vector and returns the integer result.
- **`main`**: Reads input, calls the converter and evaluator, and prints the result.

## Limitations

- Only single-digit numbers are supported.
- Functions `min` and `max` are strictly two-argument.
- No error handling for invalid expressions (crashes or undefined behavior on invalid input).
