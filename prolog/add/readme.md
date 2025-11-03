# Prolog Program: Adding Two Numbers

##  File Name
`add.pl`

---

##  Description
This simple **SWI-Prolog** program demonstrates how to perform arithmetic operations in Prolog by defining a rule that adds two numbers.

---

##  Concepts Used
- **Rule:** Defines how two numbers can be added.
- **Arithmetic Operator (`is`):** Used to evaluate mathematical expressions.
- **Query:** Used to ask Prolog to compute the sum.

---

##  Program Code

```prolog
add(A, B, Sum) :-
    Sum is A + B.
