#  Prolog Program: Friendship Based on Common Interests

## File Name
`friends.pl`

---

## Description
This simple **SWI-Prolog** program defines a set of facts about who likes what food, and a rule to determine friendship between two people based on shared interests.

---

## Concepts Used
- **Facts:** Represent known truths in the knowledge base.  
- **Rules:** Define logical relationships based on the facts.  
- **Queries:** Questions asked to Prolog to infer new information.

---

## Program Code

```prolog
% Facts
likes(jatin, pizza).
likes(keshav, pasta).
likes(rahul, pizza).

% Rules
friends(X, Y) :- likes(X, Z), likes(Y, Z), X \= Y.
