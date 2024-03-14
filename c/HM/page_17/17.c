#include <stdlib.h>
#include <stdio.h>

#include "17.h"

/**
 * Initializes an empty heap.
 *
 * @param heap_ptr Pointer to the heap structure.
 */
void init_heap(HeapPtr heap_ptr) {
    heap_ptr->size = 0;
}

/**
 * Restores heap property at a given index.
 *
 * @param heap_ptr Pointer to the heap structure.
 * @param index Index to start heapify operation from.
 */
void heapify(HeapPtr heap_ptr, int index) {
    int left = 2 * index + 1; // Left child
    int right = 2 * index + 2; // Right child
    int largest = index;         // Largest among index, left, and right

    if (left < heap_ptr->size && heap_ptr->data[left] < heap_ptr->data[largest]) { // If left child is smaller than root
        largest = left;
    }

    if (right < heap_ptr->size && heap_ptr->data[right] < heap_ptr->data[largest]) { // If right child is smaller than largest so far
        largest = right;
    }

    if (largest != index) { // If largest is not root
        int temp = heap_ptr->data[index]; // Swap
        heap_ptr->data[index] = heap_ptr->data[largest];
        heap_ptr->data[largest] = temp;
        heapify(heap_ptr, largest); // Recursively heapify the affected sub-tree
    }
}

/**
 * Inserts a value into the heap.
 *
 * @param heap_ptr Pointer to the heap structure.
 * @param value Value to be inserted into the heap.
 */
void insert_heap(HeapPtr heap_ptr, int value) {
    heap_ptr->data[heap_ptr->size] = value; // Insert the new element to the end of the array
    heap_ptr->size++;                        // Increase the size of the heap
    int index = heap_ptr->size - 1;           // Index of the inserted element
    int parent = (index - 1) / 2;           // Parent of the inserted element

    while (index > 0 && heap_ptr->data[parent] > heap_ptr->data[index]) {
        int temp = heap_ptr->data[index]; // Swap
        heap_ptr->data[index] = heap_ptr->data[parent];
        heap_ptr->data[parent] = temp;
        index = parent;
        parent = (index - 1) / 2; // Update the index and parent
    }
}

/**
 * Removes and returns the top element from the heap.
 *
 * @param heap_ptr Pointer to the heap structure.
 * @return Top element of the heap.
 */
int pop_heap(HeapPtr heap_ptr) {
    int value = heap_ptr->data[0];        // Save the top element
    heap_ptr->data[0] = heap_ptr->data[heap_ptr->size - 1]; // Replace the top element with the last element
    heap_ptr->size--;
    heapify(heap_ptr, 0);              // Heapify the heap
    return value;
}

/**
 * Returns the top element of the heap without removing it.
 *
 * @param heap_ptr Pointer to the heap structure.
 * @return Top element of the heap.
 */
int top_heap(HeapPtr heap_ptr) {
    return heap_ptr->data[0];
}

/**
 * Checks if the heap is empty.
 *
 * @param heap_ptr Pointer to the heap structure.
 * @return 1 if empty, 0 otherwise.
 */
int is_empty_heap(HeapPtr heap_ptr) {
    return heap_ptr->size == 0;
}

/**
 * Prints the elements of the heap.
 *
 * @param heap_ptr Pointer to the heap structure.
 */
void print_heap(HeapPtr heap_ptr) {
    for (int i = 0; i < heap_ptr->size; i++) {
        printf("%d ", heap_ptr->data[i]);
    }
    printf("\n");
}

/**
* Sorts an array using heap sort algorithm.
*
* @param arr Array to be sorted.
* @param length Length of the array.
*/
void heap_sort(int arr[], int length) {
   HeapPtr heap = (HeapPtr)malloc(sizeof(Heap));  // Create a heap
   init_heap(heap);
   for (int i = 0; i < length; i++) {  // Insert all elements into the heap
       insert_heap(heap, arr[i]);
   }
   for (int i = 0; i < length; i++) {  // Pop elements in sorted order
       arr[i] = pop_heap(heap);
   }
}

/**
* Returns the maximum element in an array.
*
* @param arr The array.
* @param n The length of the array.
* @return The maximum element in the array.
*/
int get_max(int arr[], int n) {
   int max_value = arr[0];
   for (int i = 1; i < n; i++) {
       if (arr[i] > max_value) {
           max_value = arr[i];
       }
   }
   return max_value;
}

// A function to do counting sort of arr[] according to the digit represented by exp.
void count_sort(int arr[], int n, int exp) {
   // Output array
   int output[n];
   int count[10] = {0};  // Initialize count array to 0

   // Store count of occurrences in count[]
   for (int i = 0; i < n; i++) {
       count[(arr[i] / exp) % 10]++;
   }

   // Change count[i] to contain actual position of this digit in output[]
   for (int i = 1; i < 10; i++) {
       count[i] += count[i - 1];
   }

   // Build the output array
   for (int i = n - 1; i >= 0; i--) {
       output[count[(arr[i] / exp) % 10] - 1] = arr[i];
       count[(arr[i] / exp) % 10]--;
   }

   // Copy the output array to arr[]
   for (int i = 0; i < n; i++) {
       arr[i] = output[i];
   }
}

// The main function to sort arr[] of size n using Radix Sort
void radix_sort(int arr[], int n) {
   int max_value = get_max(arr, n);

   // Do counting sort for every digit
   for (int exp = 1; max_value / exp > 0; exp *= 10) {
       count_sort(arr, n, exp);
   }
}
