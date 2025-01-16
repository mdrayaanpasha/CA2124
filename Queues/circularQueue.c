/* = = = = = = = = = = = = = = = = = = = = = = = 
                Rayaan Pasha
                circularQueue.c
                10-Jan-2025
 = = = = = = = = = = = = = = = = = = = = = = = */
#include<stdio.h>
#include<stdlib.h>

// = = = = = DATA TYPE CREATION = = = = = = = = =
typedef struct LIST_TYPE{
    int Data;
    struct LIST_TYPE* Next;
}LIST_NODE;

// = = = = = = GLOBAL VAR = = = = = = = = = = = =
LIST_NODE *Front = NULL, *Rear = NULL;

// = = = = = = CIRCULAR QUEUE VAR = = = = = = = = =
int size = 0, maxSize = 5; // Circular queue size and max size

// = = = = = = PROTOTYPES = = = = = = = = = = = =
void init();
void Enqueue(int num);
int Dequeue();
void Traverse();

// = = = = = = MAIN = = = = = = = = = = = = =
void main()
{
    int choice, num, res;
    while (1) {
        printf("\n= = = = = QUEUES [🧑,🧑,🧑,🧑] = = = = =\n");
        printf("1️⃣ Enqueue (📥 Add an element)\n");
        printf("2️⃣ Dequeue (📤 Remove an element)\n");
        printf("3️⃣ Display Queue (👀 View all elements)\n");
        printf("4️⃣ Exit (🚪 Leave the program)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to enqueue: ");
                scanf("%d", &num);
                Enqueue(num);
                printf("✅ %d has been added to the queue.\n", num);
                break;
            case 2:
                res = Dequeue();
                if(res != -1){
                    printf("✅ %d has been removed\n", res);
                }
                break;
            case 3:
                printf("🌀 The queue elements are:\n");
                Traverse();
                break;
            case 4:
                printf("👋 Exiting the program. See you soon!\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Please try again.\n");
        }
    }
}

// = = = = = FUNCTION DEFINITIONS = = = = = =

void Enqueue(int num) {
    if (size == maxSize) {
        printf("⚠️ Queue is full! Cannot enqueue.\n");
        return;
    }

    LIST_NODE *newNode = (LIST_NODE *)malloc(sizeof(LIST_NODE));
    newNode->Data = num;
    newNode->Next = NULL;

    if (Rear == NULL) {
        Front = Rear = newNode;
    } else {
        Rear->Next = newNode;
        Rear = newNode;
    }
    Rear->Next = Front; // Circular link
    size++;
}

int Dequeue() {
    int num;
    
    if (size == 0) {
        printf("⚠️ Queue is empty! Nothing to dequeue.\n");
        return -1;
    }

    num = Front->Data;
    if (Front == Rear) {
        free(Front);
        Front = Rear = NULL;
    } else {
        LIST_NODE *temp = Front;
        Front = Front->Next;
        Rear->Next = Front;
        free(temp);
    }
    size--;
    return num;
}

void Traverse() {
    if (size == 0) {
        printf("⚠️ Queue is empty! Nothing to display.\n");
        return;
    }

    LIST_NODE *current = Front;
    do {
        printf("%d -> ", current->Data);
        current = current->Next;
    } while (current != Front);
    printf("NULL\n");
}
