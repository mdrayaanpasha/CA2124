/* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

                                        Postfix.c
                                        Rayaan pasha
                                        07-03-25

= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


#define SIZE 6

// = = = = = = = = = = = = USER DEFINED VARIABLES = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct{
    int Top;
    float operand[SIZE];
}STACK;

STACK S;
// = = = = = = = = = = = = USER DEFINED FUNCTIONS = = = = = = = = = = = = = = = = = = = = = = = =
float pop();
void push(float num);
void initStack();
void process(char operator);
float EvalPostfix(char postfix[]);
int isEmpty();

// = = = = = = = = = = = = MAIN = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
void main(){
    char postfix[SIZE];
    float Result;
    initStack();
    printf("THIS PROGRAMME IS TO EVALUATE POSTFIX EXPRESSIONS..\n");
    printf("Gimme an expression: \n");
    scanf("%s",postfix);
    Result=EvalPostfix(postfix);
    printf("THE EVALUATION RESULTS IN: \n %0.5f",Result);

}


// = = = = = = = = = = = = UDF definition = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 

void initStack(){
    S.Top=0;
}

void push(float num){

    //case 1: stack is full.
    if(S.Top == SIZE - 1){
        printf("STACK OVERFLOW!!\n");
        return;
    }

    //case 2: non empty stack..

    S.operand[++S.Top]=num;

}


float pop(){
    float num;
    //case 1: empty stack
    if(S.Top == 0){
        printf("Stack Underflow!!\n");
        return -1;
    }

    //case 2: stack is non empty
    
    return S.operand[S.Top--];
}

int isEmpty(){
    if(S.Top == 0){
        return 1;
    }else{
        return 0;
    }
}

void process(char operator){
    float Num2 = pop();
    float Num1 = pop();
    float Res;

    switch (operator)
    {
    case '+':
        Res = Num1 + Num2;
        break;
    case '-':
        Res = Num1 - Num2;
        break;
    case '*':
        Res = Num1 * Num2;
        break;
    case '/':
        if(Num2 == 0){
            printf("Error Dividing with 0..\n");
            return;
        }
        Res = Num1 / Num2;
        break;
    case '^':
        Res = pow(Num1, Num2);
        break;
    default:
        break;
    }
    push(Res);
}


float EvalPostfix(char postfix[]){
    int i = 0;
    char ch;
    float Res,num;
    while((ch=postfix[i++]) != '\0'){
        if(ch >='0' && ch <= '9' ){
            num=ch - '0';
            push(num);
        }else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            process(ch);
        } else {
            printf("ERROR: Invalid character '%c' in expression\n", ch);
            return -1;
        }

    }
    Res = pop();
    return Res;
}
