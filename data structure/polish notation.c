#include <stdio.h>
#include<ctype.h>
#include<math.h>
#include"stack.h"
void display(StackElement e)
{
    printf("%f ",e);
}
int precedent(char operation1 , char operation2)
{
    if(operation1 == '^')
        return 1;
    if(operation1 == '*'|| operation1 == '/')
        return operation2 != '^';
    if( operation1 == '+' || operation1 == '-')
        return operation2 != '^' && operation2 != '*' && operation2 != '/';

        return 0;
}
double operation(char c , double operand1 , double operand2)
{
    switch(c){
    case '+' :
         return operand1 + operand2;
         break;
    case '-' :
        return operand1 - operand2;
        break;
    case '*' :
        return operand1 * operand2;
        break;
    case '/' :
        return operand1 / operand2;
        break;
    case '^' :
        return  pow(operand1 , operand2);
        break;
    }
return 0;
}
void infixToPostFix(const char inFix [] , char postFix [])
{
    int i , j;
    char operation , c;
    Stack s;
    initializeStack(&s);
    for(i = 0 , j = 0; (c = inFix[i]) != '\0'; i++)
    {
        if(isdigit(c))
            postFix[ j++ ] = c;
        else
        {
            while(!stackEmpty(&s) && precedent(operation = stackTop(&s) , c))
            {
                operation = pop(&s);
                postFix[ j++ ] = operation;
            }
            push(c , &s);
        }
    }
    while (!stackEmpty(&s))
    {
        operation = pop(&s);
        postFix[ j++ ] = operation;
    }
    postFix[ j ] = '\0';
}
double EvaluatePostfix(char postFix[])
{
    int i;
    char c;
    double operand1 , operand2 , result;
    Stack s;
    initializeStack(&s);
    for(i = 0; (c = postFix[i]) != '\0'; i++)
    {
        if(isdigit(c))
            push((double)(c - '0') , &s);
        else
        {
            operand2 = pop(&s);
            operand1 = pop(&s);
            result = operation(c , operand1 , operand2);
            push(result , &s);
        }
    }
    return pop(&s);
}
int main()
{
   char inFix[100] = "1+2*3^4/5-6";
   char postFix[100];
   infixToPostFix(inFix,postFix);
   printf("%s\n",postFix);
   printf("%f" , EvaluatePostfix(postFix));


    return 0;
}
