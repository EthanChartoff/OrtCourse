unsigned int lucas(unsigned int i) {
    if(i == 0)
        return 2;
    else if(i == 1)
        return 1;
    return lucas(i-1) + lucas(i-2);
}