#include <stdio.h>
#include "hanoi.h"

void hanoi(int n, tower from, tower to) {
    tower tmp = (A + B + C) - (from + to);

    if(n == 0) 
        return;;
    // move all but last disc to tmp
    hanoi(n-1, from, tmp);
    printf("move disc %d from %c to %c\n", n, 'A'+from, 'A'+to);
    // move all but last disc to to from tmp
    hanoi(n-1, tmp, to);
}

void constrained_hanoi(int n, tower from, tower to) {
    tower tmp = (A + B + C) - (from + to);

    if(n == 0)
        return;
    
    // from and to are close to each other
    if(tmp != B) {
        constrained_hanoi(n-1, from, tmp);
        printf("move disc %d from %c to %c\n", n, 'A'+from, 'A'+to);
        constrained_hanoi(n-1, tmp, to);
    }
    // from and to are close to each other 
    else {
        constrained_hanoi(n-1, from, to);
        printf("move disc %d from %c to %c\n", n, 'A'+from, 'A'+tmp);
        constrained_hanoi(n-1, to, from);
        printf("move disc %d from %c to %c\n", n, 'A'+tmp, 'A'+to);
        constrained_hanoi(n-1, from, to);
    }
}

void cyclic_hanoi(int n, tower from, tower to) {
    tower next = (from == C) ? A : from + 1;

    if(n == 0)
        return;

    // to tower is next to from
    if(to == next) {
        tower tmp = (A + B + C) - (from + to);
        cyclic_hanoi(n-1, from, tmp);
        printf("move disc %d from %c to %c\n", n, 'A'+from, 'A'+to);
        cyclic_hanoi(n-1, tmp, to);
    }
    // next divides from and to 
    else {
        cyclic_hanoi(n-1, from, to);
        printf("move disc %d from %c to %c\n", n, 'A'+from, 'A'+next);
        cyclic_hanoi(n-1, to, from);
        printf("move disc %d from %c to %c\n", n, 'A'+next, 'A'+to);
        cyclic_hanoi(n-1, from, to);
    } 
}  