#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct QueueType {
    char PatientId[10];
    char PatientName[10];
    char PatientSickness[100];
    struct QueueType *Next;
} QUEUENODE;

QUEUENODE *Front = NULL;
QUEUENODE *Rear = NULL;

void enqueue(char id[], char name[], char sickness[]) {
    QUEUENODE *QN = (QUEUENODE *)malloc(sizeof(QUEUENODE));
    strcpy(QN->PatientId, id);
    strcpy(QN->PatientName, name);
    strcpy(QN->PatientSickness, sickness);
    QN->Next = NULL;

    // Case 1: Empty list
    if (!Rear) {
        Front = Rear = QN;
        return;
    }

    // Case 2: Non-empty list
    Rear->Next = QN;
    Rear = QN;
}

void dequeue() {
    // Case 1: Empty list
    if (!Rear) {
        printf("\n\U0001F625 Queue is empty!\n");
        return;
    }

    // Case 2: Only one element in list
    if (Front == Rear) {
        free(Front);
        Front = Rear = NULL;
        return;
    }

    // Case 3: Multiple elements in the list
    QUEUENODE *temp = Front;
    Front = Front->Next;
    free(temp);
}

void traverse() {
    // Case 1: Empty list
    if (!Rear) {
        printf("\n\U0001F625 No patients in the queue!\n");
        return;
    }

    // Case 2: Non-empty list
    QUEUENODE *temp = Front;
    printf("\n\U0001F468\u200D\U0001F3EB Patient Queue:\n");
    while (temp) {
        printf("- - - - - PATIENT DETAIL - - - - - - \n");
        printf("\U0001F464 ID: %s\n", temp->PatientId);
        printf("\U0001F468 Name: %s\n", temp->PatientName);
        printf("\U0001F912 Sickness: %s\n", temp->PatientSickness);
        printf("- - - - - - - - - - - - - - - - - - - \n");
        temp = temp->Next;
    }
}

int main() {
    int choice;
    char id[10], name[10], sickness[100];

    do {
        printf("\n\U0001F4DC Hospital Queue Management\n");
        printf("\U0001F3C1 1. Enqueue Patient\n");
        printf("\U0001F68C 2. Dequeue Patient\n");
        printf("\U0001F50D 3. Display Queue\n");
        printf("\U0001F6AA 4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Patient ID: ");
                scanf("%s", id);
                printf("Enter Patient Name: ");
                scanf("%s", name);
                printf("Enter Patient Sickness: ");
                scanf("%s",sickness);
                enqueue(id, name, sickness);
                printf("\n\U0001F917 Patient added to the queue!\n");
                break;

            case 2:
                dequeue();
                printf("\n\U0001F607 Patient removed from the queue!\n");
                break;

            case 3:
                traverse();
                break;

            case 4:
                printf("\n\U0001F44B Exiting... Have a nice day!\n");
                break;

            default:
                printf("\n\U0001F632 Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

