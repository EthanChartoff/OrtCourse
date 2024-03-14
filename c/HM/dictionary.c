
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *word;
    int lineNumber;
    struct Node *next;
} Node;

// פונקציה להקצאת זיכרון ויצירת צומת חדש ברשימה
Node *createNode(char *word, int lineNumber) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->word = strdup(word);
    newNode->lineNumber = lineNumber;
    newNode->next = NULL;
    return newNode;
}

// פונקציה להוספת מילה חדשה לרשימה
void addWordToList(Node **head, char *word, int lineNumber) {
    Node *newNode = createNode(word, lineNumber);

    // אם הרשימה ריקה, הוסף את הצומת החדש כראש הרשימה
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // מצא את המקום המתאים להוספת הצומת החדש ברשימה
    Node *current = *head;
    while (current->next != NULL && strcmp(current->next->word, word) < 0) {
        current = current->next;
    }

    // הוסף את הצומת החדש לאחר הצומת הנוכחי
    newNode->next = current->next;
    current->next = newNode;
}

// פונקציה להדפסת רשימת המילים
void printList(Node *head) {
    while (head != NULL) {
        printf("%s: %d\n", head->word, head->lineNumber);
        head = head->next;
    }
}

// פונקציה לקריאת קובץ טקסט והוספת המילים בו לרשימה
void createIndex(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", fileName);
        return;
    }

    char line[1024];
    int lineNumber = 1;
    while (fgets(line, sizeof(line), file)) {
        // הפרדת המילים בשורה
        char *word = strtok(line, " ");
        while (word != NULL) {
            // המרת כל האותיות לאותיות קטנות
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            // הוספת המילה לרשימה
            addWordToList(&head, word, lineNumber);

            // קבלת המילה הבאה
            word = strtok(NULL, " ");
        }
        lineNumber++;
    }

    fclose(file);
}

// פונקציה לשחרור זיכרון שהוקצה עבור רשימת המילים
void freeList(Node *head) {
    while (head != NULL) {
        Node *next = head->next;
        free(head->word);
        free(head);
        head = next;
    }
}