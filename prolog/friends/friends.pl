% Facts
likes(harsh, pizza).
likes(vanshika, pasta).
likes(ramesh, pizza).

% Rules
friends(X, Y) :- likes(X, Z), likes(Y, Z), X \= Y.
