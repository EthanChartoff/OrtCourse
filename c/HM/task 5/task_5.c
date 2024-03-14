#include <stdio.h>

// Function to calculate the length of a C-string (strlen)
int strlen(char *str) {
  // Initialize a character pointer to point to the beginning of the string
  char *ch = str;
  // Initialize a counter to keep track of the string length
  int count = 0;

  // Loop through the string until the null terminator is encountered
  while (*ch != '\0') {
    // Increment the counter for each character
    count++;
    // Move the pointer to the next character
    ch++;
  }

  // Return the final length of the string
  return count;
}

// Function to copy a C-string from source to destination (strcpy)
char *strcpy(char *destination, const char *source) {
  // Check if the destination pointer is NULL (no memory allocated)
  if (!destination) {
    return NULL; // Return NULL if destination is invalid
  }

  // Point a character pointer to the beginning of the destination string
  char *ptr = destination;

  // Loop through the source string until the null terminator is encountered
  while (*source != '\0') {
    // Copy the character from source to destination
    *destination = *source;
    // Move both pointers to the next characters
    destination++;
    source++;
  }

  // Add the null terminator at the end of the destination string
  *destination = '\0';

  // Return the original destination pointer (standard strcpy behavior)
  return ptr;
}

// Function to concatenate two C-strings (strcat)
char *strcat(char *destination, char *source) {
  // Find the end of the destination string
  char *ptr = destination + strlen(destination);

  // Loop through the source string until the null terminator is encountered
  while (*source != '\0') {
    // Copy the character from source to the end of the destination
    *ptr++ = *source++;
  }

  // Add the null terminator at the end of the concatenated string
  *ptr = '\0';

  // Return the original destination pointer (standard strcat behavior)
  return destination;
}

// Function to compare two C-strings (strcmp)
int strcmp(char *str1, char *str2) {
  // Loop through the characters of both strings until a difference is found or null terminators are encountered
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    // If the characters are different, return -1 indicating strings are not equal
    if (str1[i] != str2[i]) {
      return -1;
    }
    i++;
  }

  // If both strings reach their null terminators at the same time, they are equal (return 0)
  if (str1[i] == '\0' && str2[i] == '\0') {
    return 0;
  } else {
    // If one string ends before the other, they are not equal (return -1)
    return -1;
  }
}

// Function to find the first occurrence of a character in a C-string (strchr)
char *strchr(char *str, char c) {
  // Loop through the characters of the string until the target character is found or null terminator is encountered
  int i = 0;
  while (str[i] != '\0') {
    // If the character is found, return a pointer to its location
    if (str[i] == c) {
      return &str[i];
    }
    i++;
  }

  // If the character is not found, return NULL
  return NULL;
}


// Function to replace occurrences of a substring with another substring
void replace(char *str, char *t1, char *t2) {
    int i, j, t; // Declare variables for loop counters and temporary index

    // Loop through each character in the string
    for (i = 0; str[i] != '\0'; i++) {
        // Check if current character matches the first character of the substring to replace
        if (str[i] == t1[0]) {
            t = i; // Store the index of the potential match
            j = 0; // Reset the counter for the replacement substring

            // Compare characters in both strings until null terminator or mismatch is found
            while (str[i] != '\0' && t1[j] != '\0' && str[i] == t1[j]) {
                i++;
                j++;
            }

            // If the entire replacement substring matches, replace characters in the original string
            if (t1[j] == '\0') {
                int k = 0; // Counter for the replacement substring
                // Copy characters from the replacement substring to the original string
                while (t != i) {
                    str[t] = t2[k];
                    k++;
                    t++;
                }
            } else { // If not a full match, continue iterating
                i = t + 1;
            }
        }
    }
}

// Function to convert a string to an integer
int atoi(char *str) {
    int i = 0, num = 0; // Declare variables for loop counter and result

    // Loop through each character in the string
    while (str[i] != '\0') {
        // Ensure the character is a digit, then convert it to an integer and adjust the existing number
        if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
        }
        i++;
    }

    return num; // Return the converted integer
}

// Function to convert a string to a float
float atof(char *str) {
    int i = 0, num = 0, flag = 0; // Declare variables for loop counter, integer part, decimal flag
    float f = 0.0; // Declare variable for fractional part

    // Loop through each character in the string
    while (str[i] != '\0') {
        // If encountering a decimal point, set the flag and skip to the next character
        if (str[i] == '.') {
            flag = 1;
            i++;
            continue;
        }

        // If before the decimal point, accumulate digits into the integer part
        if (flag == 0) {
            num = num * 10 + (str[i] - '0');
        } else { // If after the decimal point, accumulate digits into the fractional part
            f = f * 10 + (str[i] - '0');
        }
        i++;
    }

    // Convert the fractional part to its correct decimal position
    while (f > 1) {
        f /= 10;
    }

    return num + f; // Return the sum of the integer and adjusted fractional parts
}

// Function to find the maximum element in a 2D array and its row and column indices
void find_max(int m[5][5], int *mRow, int *mCol) {
  int max_i = 0, max_j = 0; // Initialize indices for maximum element
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      // Check if current element is greater than the current maximum
      if (m[i][j] > m[max_i][max_j]) {
        max_i = i; // Update row index
        max_j = j; // Update column index
      }
    }
  }
  // Assign the indices of the maximum element to the output pointers
  *mRow = max_i;
  *mCol = max_j;
}

// Function to calculate the number of paths from (ax, ay) to (bx, by) in a grid
int find_up_right(int ax, int ay, int bx, int by) {
  if (ax == bx || ay == by) {
    return 1;
  } else {
    return find_up_right(ax + 1, ay, bx, by) + find_up_right(ax, ay + 1, bx, by);
  }
}

// Function to solve a maze represented by a 2D character array
void solve_maze(char maze[5][5], int x, int y) {
  // Mark the current position visited
  maze[x][y] = '$';

  // Check for exit conditions
  if ((x == 0 && y == 3) || (x == 3 && y == 4)) {
    // Print the solved maze
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        printf("%c, ", maze[i][j]);
      }
      printf("\n");
    }
    printf("\n");
    return;
  }

  // Recursively explore unvisited paths
  if (maze[x + 1][y] == '-') {
    solve_maze(maze, x + 1, y);
  }
  if (maze[x][y + 1] == '-') {
    solve_maze(maze, x, y + 1);
  }
  if (maze[x - 1][y] == '-') {
    solve_maze(maze, x - 1, y);
  }
  if (maze[x][y - 1] == '-') {
    solve_maze(maze, x, y - 1);
  }
}

// Recursive binary search function
int rec_bin_search(int array[], int startIndex, int endIndex, int element) {
  if (endIndex >= startIndex) {
    int middle = startIndex + (endIndex - startIndex) / 2;
    if (array[middle] == element) {
      return middle;
    }
    if (array[middle] > element) {
      return rec_bin_search(array, startIndex, middle - 1, element);
    }
    return rec_bin_search(array, middle + 1, endIndex, element);
  }
  return -1; // Element not found
}

// Function to calculate the nth element in the kth row of Pascal's triangle
int pascal_tri(int n, int k) {
  // Base cases: first and last element in a row are always 1
  if (k == 0 || k == n) {
    return 1;
  }
  // Recursive formula for calculating Pascal's triangle
  return pascal_tri(n - 1, k - 1) + pascal_tri(n - 1, k);
}


void printpascal_tri(int n)
{
    if (n == 0)
        return;
    printpascal_tri(n - 1);
    int i = 0;
    for (i = 0; i < n; i++)
        printf("%d ", pascal_tri(n - 1, i));
    printf("\n");
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}