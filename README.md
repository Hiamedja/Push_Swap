# 📦 push_swap

`push_swap` is an algorithmic project from the 42 Network focused on sorting a stack of integers using a limited set of operations.  
The goal is to sort the data using the fewest possible moves, demonstrating optimization, algorithm design, and data structure management in C.

---

## 💡 What is Push_Swap?

Given a list of integers, the program generates a sequence of instructions to sort them using **two stacks (A and B)** and a restricted set of operations.

It is composed of two parts:

1. `push_swap`: generates the optimized sequence of instructions
2. `checker`: checks if a given sequence of instructions correctly sorts the stack

---

## 🎯 Objectives

- Implement a sorting algorithm that works within specific constraints
- Minimize the number of instructions used
- Handle all edge cases (duplicates, errors, already sorted input)
- Develop a clean and modular codebase

---

## 🛠 Allowed Operations

- `sa`, `sb`, `ss`: swap the top elements
- `pa`, `pb`: push from one stack to the other
- `ra`, `rb`, `rr`: rotate stack up
- `rra`, `rrb`, `rrr`: rotate stack down

---

## 🔧 My Implementation

- ✅ Custom data structure for stacks using linked lists
- ✅ Error handling (non-numeric inputs, duplicates, etc.)
- ✅ Parsing and validation of arguments
- ✅ Multiple sorting algorithms:
  - Mini sort (3 to 5 elements)
  - Radix sort for large stacks (binary-based)
  - Optimized sort for medium-sized inputs (insertion-based logic)
- ✅ Efficient instruction generation
- ✅ Checker program to validate instruction sequences

---

## 📊 Example

```bash
$ ./push_swap 3 2 1
sa
rra
