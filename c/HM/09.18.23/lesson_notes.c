/*
    memory is allocated on the start of the program so:
        int n = 10;
        int arr[n];
    is incorrect, because n is initialized at the start of the main function.  

    initializing int arr[10] without anything after will fill the array's values with trash.
    arr[10] = {1, 2} will be: 67, -9, 0, 0....
    arr[] = {1, 2} will be an array of length 2.

    sizeof(arr) is its length * n of bytes in type.

    #define happenes before compilation, replacing all values with the one defined.

    a pointer's number of bytes is dependent on its ISA. 
    in x86 a pointer has 4 bytes
    and in x86-64 a pointer has 8 bytes.

    we work with x86.

    initializing a string:
        char arr[] = {'a', 'b', 'c'}; // INCORRECT, because arr = {a, b, c}
        chat arr[] = "abc" // CORRECT, becuase arr = {a, b, c, \0}
*/


void main()
{
    
}