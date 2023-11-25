typedef enum {
    A,
    B,
    C
} tower;

void hanoi(int n, tower from, tower to);
void constrained_hanoi(int n, tower from, tower to);
void cyclic_hanoi(int n, tower from, tower to);