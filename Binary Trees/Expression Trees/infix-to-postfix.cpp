#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node *top = NULL;

void push(int value)
{
    Node* temp = new Node();
    temp->value = value;
    temp->next = top;
    top = temp;
}

int pop()
{
    if (top == NULL)
    {
        return -1;
    }

    int poppedvalue = top->value;
    Node* temp = top;
    top = top->next;
    delete temp;
    return poppedvalue;
}

int precedence(char op)
{
    if (op == '*' || op == '/' || op == '%')
        return 6;
    if (op == '+' || op == '-')
        return 5;
    if (op == '<' || op == '>')
        return 4;
    if (op == '<=' || op == '>=')
        return 4;
    if (op == '==' || op == '!=')
        return 3;
    if (op == '&&')
        return 2;
    if (op == '||')
        return 1;
    return 0;
}


string infixToPostfix(string infix)
{
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != NULL && top->value != '(')
            {
                postfix += top->value;
                pop();
            }
            if (top != NULL)
                pop();
        }
        else
        {
            while (top != NULL && precedence(ch) <= precedence(top->value))
            {
                postfix += top->value;
                pop();
            }
            push(ch);
        }
    }

    while (top != NULL)
    {
        postfix += top->value;
        pop();
    }

    return postfix;
}

struct StackNode {
    int data;
    StackNode* next;
};

StackNode* top1=NULL;

void stackPush(int value) {
    StackNode* newNode = new StackNode;
    newNode->data = value;
    newNode->next = top1;
    top1 = newNode;
}

int stackPop() {
    if (top1 == NULL) {
        cout << "Stack underflow\n";
        return -1; 
    }
    int data = top1->data;
    StackNode* temp = top1;
    top1 = top1->next;
    delete temp;
    return data;
}

bool isEmpty() {
    return top1 == NULL;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '>');
}

int postfixEvaluation(string postfix) {
    int result;
    for (int i=0;i<postfix.length();i++) {
        char ch= postfix[i];
        if (isOperator(ch)) {
            int temp; 
            int right = stackPop();
            int left = stackPop();
            switch (ch) {
                case '+':
                    temp = left + right;
                    break;
                case '-':
                    temp = left - right;
                    break;
                case '*':
                    temp = left * right;
                    break;
                case '/':
                    temp = left / right;
                    break;
                default:
                    break;
            }
            stackPush(temp);
        } else {
            stackPush(ch - '0'); 
        }
    }
    result = stackPop();
    return result;
}

int main()
{
    // Taking input
    string infixExpression;
    cout << "Enter Infix expression: ";
    getline(cin,infixExpression);

    // Converting into Postfix
    cout << "Infix Expression: " << infixExpression << endl;
    string postfix= infixToPostfix(infixExpression) ;
    cout<<  "Postfix Expression: " << postfix << endl;

    // Postfix Evaluation
    int postEvaluation =  postfixEvaluation(postfix); 
    cout << "Postfix Evaluation: " << postEvaluation << endl;
    
    return 0;
}
