#include <stdio.h>
#include <stdlib.h>

/* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
                                                Rayaan Pasha 🌟  
            Date? 🌹 aaj raat @ Persian Terrace? aa rahe ho ki excuse de rahe ho phir? 😉
= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =*/

// = = = = = = = = = = = = = DATA TYPE CREATIONS = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
typedef struct Node {
    int Data;             // Data ka daba.
    struct Node *Next;    // Agla pointer (chain banane ke liye)
} Node;

typedef struct Stack {
    struct Node *Head;    // Stack ke pehle bhai
    struct Node *Top;     // Stack ke sabse upar wala item
} Stack;

// = = = = = = = = = = = = = FUNCTION PROTOTYPING = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
Stack *Stack_INIT();      // Stack banane ki factory
void push(Stack *s, int data); // Stack mein item ghusaao
void pop(Stack *s);       // Stack se item nikaalo
void cleanup(Stack *s);   // Sab kuch free karo, yaani memory clean-up


// = = = = = = = = = = = = = MAIN DADDY CODE! 💪💻  = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
int main() {
    Stack *s = Stack_INIT(); // Stack ka naya baccha ban raha hai
    int choice, data;

    while (1) {
        printf("\n🤔 ARRE BHAIYA, KYA KARNA HAIN STACK KE SAATH? 🤔\n");
        printf("1: Stack mein kuch GHUSAAO (Push karna hai)\n");
        printf("2: Stack se kuch NIKALWAO (Pop karna hai)\n");
        printf("3: Stack ko FULL CLEAN-UP de do (memory free karo)\n");
        printf("4: CHAL NIKAL AB, NAUTANKI BAND KAR! 👋\n");
        printf("Tereko kya chahiye?: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("DEKH, DATA DO (int type): ");
            scanf("%d", &data);
            push(s, data);
        } else if (choice == 2) {
            pop(s);
        } else if (choice == 3) {
            cleanup(s);
            s = Stack_INIT(); // Start a new stack
        } else if (choice == 4) {
            printf("\nBHAI, BOHOT MAZA AAYA. AB CHAL, NEXT TIME IAS YA SDE BANKE AANA! 😎👋\n");
            break;
        } else {
            printf("\nKYA BAKWAAS INPUT HAI YE BC?! SUDHAR LE! 😡\n");
        }
    }

    cleanup(s); // Safai
    return 0;
}

// = = = = = = = = = = = = = FUNCTION DEFINITIONS 💡 = = = = = = = = = = = = = = = = = = = = = = = = = = 

// Stack banane ki factory
Stack *Stack_INIT() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->Head = NULL;
    s->Top = NULL;
    printf("➡️ NAYA STACK READY HO GAYA BHAI! 🚀\n");
    return s;
}

// Push karne ka kaam
void push(Stack *s, int data) {
    Node *n = (Node *)malloc(sizeof(Node)); // Ek naye bhaiya ban gaye
    n->Data = data;
    n->Next = NULL;

    if (!s->Head) { // Agar stack khaali hai toh nayi shuruaat
        s->Head = n;
        s->Top = n;
    } else { // Varna nayi value ko upar le jao
        s->Top->Next = n;
        s->Top = n;
    }
    printf("✅ DATA STACK MEIN GHUS GAYA HAI: %d\n", data);
}

// Pop karne ka kaam
void pop(Stack *s) {
    if (!s->Head) { // Agar stack khaali hai toh kya hi nikaaloge?
        printf("❌ STACK KHAALI HAI BC, KUCH HAI HI NAHI! 🤦‍♂️\n");
        return;
    }

    if (s->Head == s->Top) { // Sirf ek item hai stack mein
        printf("🗑️ DELETE HO GAYA: %d\n", s->Top->Data);
        free(s->Top);
        s->Head = s->Top = NULL;
    } else { // Last item delete karo
        Node *temp = s->Head;
        while (temp->Next != s->Top) { // Top ke pehle waale tak jao
            temp = temp->Next;
        }
        printf("🗑️ DELETE HO GAYA: %d\n", s->Top->Data);
        free(s->Top);
        s->Top = temp;
        s->Top->Next = NULL;
    }
}

// Sab kuch free karo
void cleanup(Stack *s) {
    while (s->Head) { // Jab tak stack khaali na ho
        pop(s);
    }
    free(s);
    printf("🚮 STACK FULL CLEAN HO GAYA, AB SHANTI MILI! 🙏\n");
}
