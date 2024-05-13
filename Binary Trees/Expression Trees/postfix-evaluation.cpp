#include <iostream>
#include <cstdlib> // For memory allocation and deallocation
#include <cctype>  // For isdigit function
#include <string>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *top = NULL;

void push(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        cout << "Memory allocation failed" << endl;
        exit(1);
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (!top) {
        cout << "Stack underflow" << endl;
        exit(1);
    }
    int value = top->data;
    Node *temp = top;
    top = top->next;
    free(temp);
    return value;
}

int evaluatePostfix(string postfixExp) {
   for (int i = 0; i < postfixExp.length(); ++i) {
    char c = postfixExp[i];
        if (isdigit(c))
            push(c - '0'); // Convert char to int
        else {
            int operand2 = pop();
            int operand1 = pop();
            switch (c) {
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                case '%':
                    push(operand1 % operand2);
                    break;
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '<':
                    push(operand1 < operand2);
                    break;
                case '>':
                    push(operand1 > operand2);
                    break;
                case '=':
                    push(operand1 == operand2);
                    break;
                case '!':
                    push(operand1 != operand2);
                    break;
                case '&':
                    push(operand1 && operand2);
                    break;
                case '|':
                    push(operand1 || operand2);
                    break;
                default:
                    break;
            }
        }
    }
    return pop();
}

int main() {
    string infixEq1 = "a+b*c/d*x-f*d";
    string postfixEq1 = "abc*d/x*+fd*-";
    // let values a = 2, b = 1, c = 3, d = 1, f = 2, x = 2
    //  int result = postfixEvaluation("213*1/2*+21*-");

    string infixEq2 = "a+b*(c-d)<x&(c!y|x+y<5)";
    string postfixEq2 = "abcd-*+x<cy!xy+5<|&";
    // let values a = 2, b= 1, c = 3, d = 1, x = 2, y = 4
    int result = evaluatePostfix("2131-*+2<34!24+5<|&");

    cout << "Answer is " << result << endl;
    cout << "Note: 1 and 0 also indicate true and false." << endl;

    return 0;
}

