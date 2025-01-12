/* = = = = = = = = = = = = = = = = = = = = = = = 
                Rayaan Pasha
                Queue.c
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

// = = = = = = PROTOTYPES = = = = = = = = = = = =
void init();
void Enqueue(int num);
int Dequeue();
void Traverse();

// = = = = = = MAIN = = = = = = = = = = = = =
void main()
{
    int choice, num,res;
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
                    printf("✅ %d has been  removed\n");
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
    LIST_NODE *newNode = (LIST_NODE *)malloc(sizeof(LIST_NODE));
    newNode->Data = num;
    newNode->Next = NULL;
    
    //case 1: if there is nothing in the queue
    if (Rear == NULL) {
        Front = Rear = newNode;
    } 
    //case 2: if Q is non-empty
    else {
        Rear->Next = newNode;
        Rear = newNode;
    }
}

int Dequeue() {
    
    int num;
    
    //case 1: queue is empty!
    if (Front == NULL) {
        printf("⚠️ Queue is empty! Nothing to dequeue.\n");
        return -1;
    }
    
    //case 2: there is only one elem.
    if(Front == Rear){
        num = Front->Data;
        Front=Rear=NULL;
        return num;
    }
    
    //case 2: its non empty!
    num = Front->Data;
    Front = Front->Next;
    
    return num;
}

void Traverse() {
    //case 1: empty queue!
    if (Front == NULL) {
        printf("⚠️ Queue is empty! Nothing to display.\n");
        return;
    }

    LIST_NODE *current = Front;
    while (current != NULL) {
        printf("%d -> ", current->Data);
        current = current->Next;
    }
    printf("NULL\n");
}

