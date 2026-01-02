# Shunting Yard with Min/Max

This C++ program converts an infix mathematical expression containing `min` and `max` functions into postfix notation (Reverse Polish Notation) using the **Shunting Yard Algorithm**. The implementation adheres to the specified requirements, including a custom Stack ADT.

## Problem Statement

You are given a correctly formatted mathematical expression in **infix notation**. The expression may include:

- Single-digit decimal numbers (0–9)
- Basic arithmetic operators: `+`, `-`, `*`, `/`
- Parentheses: `(`, `)`
- Two-argument functions: `min(arg1, arg2)` and `max(arg1, arg2)`

All tokens in the input are separated by spaces.

The task is to convert the expression to **postfix notation** using a stack-based Shunting Yard algorithm, ensuring that:

- All operations are left-associative.
- Operator precedence is respected: `min`, `max` (highest), then `*`, `/`, then `+`, `-`.
- The Stack ADT is implemented as an abstract class (`myStack`) with a concrete implementation (`StackinArray`).

### Key Steps:

1. **Tokenization**: The input string is split by spaces.
2. **Stack ADT**:
   - Abstract class `myStack` defines the interface.
   - `StackinArray` implements the stack using a `std::vector`.
3. **Shunting Yard Logic**:
   - Numbers are directly added to the output.
   - Operators are pushed onto the stack according to precedence and associativity.
   - Parentheses and commas (used in `min`/`max`) are handled to manage function arguments.
   - Left-associativity is enforced by popping operators with equal or higher precedence.
4. **Output**: The resulting postfix tokens are printed, separated by spaces.

## Examples

| Input               | Output              |
| ------------------- | ------------------- |
| `1 + 2 + 3 + 4 + 5` | `1 2 + 3 + 4 + 5 +` |
| `1 * 2 / 3 * 4 / 5` | `1 2 * 3 / 4 * 5 /` |
| `3 - 2 - 1`         | `3 2 - 1 -`         |
