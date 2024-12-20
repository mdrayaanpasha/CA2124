/*=======================================================
                    Rayaan Pasha
                    20/12/24
                    LinkedList.c
=========================================================*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//===============DATA TYPE CREATION=========================
typedef struct ListType {
    char *Data;
    struct ListType *Next;
} LISTNODE;

//===============GLOBAL VARIABLE=========================
LISTNODE *Head;

//==============PROTOTYPES=================================
void init();
void Insert_LISTNODE(char *s);
void Traverse();

//================MAIN======================================
int main() {
    char *s = (char *)malloc(100 * sizeof(char));
    int i;
    init();
    printf("THIS PROGRAM TAKES 5 STRINGS & INSERTS THEM IN A LINKED LIST\n");

    for (i = 0; i < 5; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%99s", s);
        Insert_LISTNODE(s);
    }

    Traverse();

    free(s); 
    return 0;
}

//================FUNCTION DEFINITIONS======================
void init() {
    Head = NULL;
}

void Insert_LISTNODE(char *s) {
    LISTNODE *Node = (LISTNODE *)malloc(sizeof(LISTNODE));
    Node->Data = (char *)malloc(strlen(s) + 1); 
    strcpy(Node->Data, s);
    Node->Next = NULL;

    // Case 1: List is empty
    if (!Head) {
        Head = Node;
        return;
    }

    // Case 2: Insert at the head
    if (strcmp(s, Head->Data) < 0) {
        Node->Next = Head;
        Head = Node;
        return;
    }

    // Case 3: Insert in sorted position
    LISTNODE *curr = Head;
    LISTNODE *prev = NULL;
    while (curr && strcmp(curr->Data, s) <= 0) {
        prev = curr;
        curr = curr->Next;
    }

    prev->Next = Node;
    Node->Next = curr;
}

void Traverse() {
    LISTNODE *curr = Head;

    if (!Head) {
        printf("LIST IS EMPTY\n");
        return;
    }

    while (curr) {
        printf("%s\t", curr->Data);
        curr = curr->Next;
    }
    printf("\n");
}

