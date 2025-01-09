/*========================================================
                    Rayaan Pasha
                    LinkedList.c
                    12/12/24
=========================================================*/
#include <stdlib.h>
#include <stdio.h>

//===============DATA TYPE CREATION=========================
typedef struct ListType {
    int Data;
    struct ListType *Next;
} LISTNODE;

//===============GLOBAL VARIABLE===========================
LISTNODE *Head;

//===============PROTOTYPES===============================
void init();
void Insert_LISTNODE(int num);
int Delete_Head_LISTNODE();
int Delete_Last_LISTNODE();
int Search_LISTNODE(int num);
void Print_LISTNODE();
void DeleteByNum_LISTNODE(int num);

//===============MAIN FUNCTION=============================
int main() {
    int Menu_Selection, input, search, Delete;

    init();

    while (1) {
        printf("\n=======WELCOME===========\n");
        printf(" PRESS 1 TO INSERT INTO THE LINKED LIST!\n");
        printf(" PRESS 2 TO DELETE HEAD_NODE\n");
        printf(" PRESS 3 TO DELETE LAST NODE \n");
        printf(" PRESS 4 TO SEARCH FOR A NUMBER \n");
        printf(" PRESS 5 TO PRINT CONTENT OF YOUR LIST! \n");
        printf(" PRESS 6 TO DELETE AN ELEMENT BY NUMBER\n");
        printf(" PRESS -1 TO QUIT/EXIT \n");

        scanf("%d", &Menu_Selection);

        switch (Menu_Selection) {
            case 1:
                printf("\nWhat Number Do You Want To Insert: \n");
                scanf("%d", &input);
                Insert_LISTNODE(input);
                break;

            case 2:
                Delete = Delete_Head_LISTNODE();
                if (Delete > -1) {
                    printf("\nDELETED: %d\n", Delete);
                }
                break;

            case 3:
                Delete = Delete_Last_LISTNODE();
                if (Delete > -1) {
                    printf("\nDELETED: %d", Delete);
                }
                break;

            case 4:
                printf("\nWhat Number Do You Want To Search: \n");
                scanf("%d", &input);
                search = Search_LISTNODE(input);
                if (search == 1) {
                    printf("\n Found\n");
                } else {
                    printf("\n not Found \n");
                }
                break;

            case 5:
                Print_LISTNODE();
                break;

            case 6:
                printf("\nWhat number do you want to delete? \n");
                scanf("%d", &input);
                DeleteByNum_LISTNODE(input);
                break;

            case -1:
                printf("\nTHANK YOU, Have A Nice Day :) \n");
                return 0;

            default:
                printf("\nINVALID OPTION!!\n");
                break;
        }
    }

    return 0;
}

//===============FUNCTION DECLARATION======================
void init() {
    Head = NULL;
}

void Insert_LISTNODE(int num) {
    LISTNODE *newNode, *curr, *prev;
    newNode = (LISTNODE*)malloc(sizeof(LISTNODE));
    newNode->Data = num;
    newNode->Next = NULL;

    // Case 1: List is empty!
    if (!Head) {
        Head = newNode;
        printf("\nINSERTED!!\n");
        return;
    }

    // Case 2: List is non-empty, insert in sorted order
    curr = Head;
    prev = NULL;
    while (curr && curr->Data < num) {
        prev = curr;
        curr = curr->Next;
    }

    if (prev == NULL) {  // Insert at the head
        newNode->Next = Head;
        Head = newNode;
    } else {  // Insert after the prev node
        prev->Next = newNode;
        newNode->Next = curr;
    }

    printf("\nINSERTED!!\n");
}

int Delete_Head_LISTNODE() {
    LISTNODE *Curr;
    int Num;

    // Case 1: List is empty
    if (!Head) {
        printf("\nLIST IS EMPTY!!!\n");
        return -1;
    }

    // Case 2: List is non-empty
    Curr = Head;
    Head = Head->Next;
    Num = Curr->Data;
    free(Curr);
    printf("\nDELETED!!\n");
    return Num;
}

int Delete_Last_LISTNODE() {
    LISTNODE *curr, *prev;
    int Num;

    // Case 1: List is empty
    if (!Head) {
        printf("\nLIST IS EMPTY!!!\n");
        return -1;
    }

    // Case 2: List is non-empty
    curr = Head;
    prev = NULL;
    while (curr->Next) {
        prev = curr;
        curr = curr->Next;
    }
    Num = curr->Data;
    if (prev) {
        prev->Next = NULL;
    } else {
        Head = NULL;  // If there was only one element
    }

    free(curr);
    printf("\nDELETED!!\n");
    return Num;
}

int Search_LISTNODE(int num) {
    LISTNODE *Curr;

    // Case 1: List is empty
    if (!Head) {
        printf("\nLIST IS EMPTY!!!\n");
        return -1;
    }

    // Case 2: List is non-empty
    Curr = Head;
    while (Curr) {
        if (Curr->Data == num) {
            return 1;  // Found
        }
        Curr = Curr->Next;
    }

    return -1;  // Not found
}

void Print_LISTNODE() {
    LISTNODE *Curr;

    // Case 1: List is empty
    if (!Head) {
        printf("\nLIST IS EMPTY!!!\n");
        return;
    }

    // Case 2: List is non-empty
    Curr = Head;
    while (Curr) {
        printf("%d\t", Curr->Data);
        Curr = Curr->Next;
    }
    printf("\n");
}

void DeleteByNum_LISTNODE(int num) {
    LISTNODE *curr, *prev;

    // Case 1: List is empty
    if (!Head) {
        printf("\nTHE LIST IS EMPTY\n");
        return;
    }

    // Case 2: Head has the data we want to delete
    if (num == Head->Data) {
        Head = Head->Next;
        printf("\nDELETED!!\n");
        return;
    }

    // Case 3: Data is somewhere in the middle
    curr = Head;
    prev = NULL;
    while (curr) {
        if (curr->Data == num) {
            prev->Next = curr->Next;
            printf("\nDELETED!!\n");
            break;
        }
        prev = curr;
        curr = curr->Next;
    }

    // If the node was found, free it
    if (curr) {
        free(curr);
    } else {
        printf("\nNumber not found!\n");
    }
}
