// calculates C(n , k) recursively, using the definition c(n, k) = c(n-1, k) + c(n-1, k-1).
// this algo is very slow, and there are faster ways of calculating c(n, k).
unsigned long choose(int n, int k) {
    if(k > n)
        return  0;
    else if(k == 0 || k == n)
        return 1;
    return(choose(n-1, k) + choose(n-1, k-1));
}