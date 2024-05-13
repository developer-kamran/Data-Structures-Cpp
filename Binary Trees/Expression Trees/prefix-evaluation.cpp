#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct StackNode {
    int data;
    StackNode* next;
};

StackNode* top = NULL;

void push(int value) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL)
        return -1;
    int value = top->data;
    StackNode* temp = top;
    top = top->next;
    free(temp);
    return value;
}

string reverseString(string str) {
    string reversedStr;
    for (int i = 0; i < str.length(); i++) {
        reversedStr = str[i] + reversedStr;
    }
    return reversedStr;
}

int evaluatePrefixExpression(string prefixExp) {
    string reversedPrefixExp = reverseString(prefixExp);
    for (int i = 0; i < reversedPrefixExp.length(); i++) {
        char currChar = reversedPrefixExp[i];
        if (isdigit(currChar)) {
            int value = currChar - '0';
            push(value);
        } else {
            int operand1 = pop();
            int operand2 = pop();
            int result;
            switch (currChar) {
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '%':
                    result = operand1 % operand2;
                    break;
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '<':
                    result = operand1 < operand2;
                    break;
                case '>':
                    result = operand1 > operand2;
                    break;
                case '=':
                    result = operand1 == operand2;
                    break;
                case '!':
                    result = operand1 != operand2;
                    break;
                case '&':
                    result = operand1 && operand2;
                    break;
                case '|':
                    result = operand1 || operand2;
                    break;
                default:
                    break;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    string infixEq1 = "a+b*c/d*x-f*d";
    string prefixEq1 = "-+a*/*bcdx*fd";
    // let values a = 2, b = 1, c = 3, d = 1, f = 2, x = 2
    // int result = evaluatePrefixExpression("-+2*/*1312*21");

    string infixEq2 = "a+b*(c-d)<x&(c!y|x+y<5)";
    string prefixEq2 = "&<+a*b-cdx|!cy<+xy5";
    // let values a = 2, b= 1, c = 3, d = 1, x = 2, y = 4
    int result = evaluatePrefixExpression("&<+2*1-312|!34<+245");

    cout << "Answer is " << result << endl;
    cout << "Note: 1 and 0 also indicate true and false." << endl;

    return 0;
}

