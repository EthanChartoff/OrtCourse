#define MAX_LENGTH 100  // Maximum size of the heap

typedef struct {
    int size;
    int data[MAX_LENGTH];
} Heap;

typedef Heap *HeapPtr;  // Pointer to a Heap struct

// Function prototypes (declarations without implementation)

void init_heap(HeapPtr heap_ptr);  // Initialize an empty heap

void heapify(HeapPtr heap_ptr, int index);  // Restore heap property at a given index

void insert_heap(HeapPtr heap_ptr, int value);  // Insert a value into the heap

int pop_heap(HeapPtr heap_ptr);  // Remove and return the maximum element

int top_heap(HeapPtr heap_ptr);  // Return the maximum element without removing it

int is_empty_heap(HeapPtr heap_ptr);  // Check if the heap is empty
