#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};

struct StackNode {
    TreeNode* data;
    StackNode* next;
};

StackNode* topStack = NULL;

void pushStack(TreeNode* treeNode) {
    StackNode* newNode = new StackNode;
    newNode->data = treeNode;
    newNode->next = topStack;
    topStack = newNode;
}

TreeNode* popStack() {
    if (topStack == NULL) {
        cout << "Stack underflow\n";
        return NULL;
    }
    TreeNode* treeNode = topStack->data;
    StackNode* temp = topStack;
    topStack = topStack->next;
    delete temp;
    return treeNode;
}

bool isEmptyStack() {
    return topStack == NULL;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '>');
}

int precedence(char op) {
    if (op == '^') return 7;
    if (op == '*' || op == '/' || op == '%') return 6;
    if (op == '+' || op == '-') return 5;
    if (op == '<' || op == '>' || op == '<' || op == '>') return 4;
    if (op == '=' || op == '!') return 3;
    if (op == '&') return 2;
    if (op == '|') return 1;
    return 0;
}

string infixToPrefix(string infix) {
    string prefix = "";
    stack<char> opStack;

    for (int i = infix.length() - 1; i >= 0; i--) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            prefix = ch + prefix;
        } else if (ch == '(') {
            while (!opStack.empty() && opStack.top() != ')') {
                prefix = opStack.top() + prefix;
                opStack.pop();
            }
            if (!opStack.empty())
                opStack.pop(); // Pop the '('
        } else {
            while (!opStack.empty() && precedence(ch) <= precedence(opStack.top())) {
                prefix = opStack.top() + prefix;
                opStack.pop();
            }
            opStack.push(ch);
        }
    }

    while (!opStack.empty()) {
        prefix = opStack.top() + prefix;
        opStack.pop();
    }

    return prefix;
}

TreeNode* constructExpressionTree(string postfix) {
    stack<TreeNode*> nodeStack;

    for (char ch : postfix) {
        if (isOperator(ch)) {
            TreeNode* newNode = new TreeNode;
            newNode->data = ch;
            newNode->right = nodeStack.top();
            nodeStack.pop();
            newNode->left = nodeStack.top();
            nodeStack.pop();
            nodeStack.push(newNode);
        } else {
            TreeNode* newNode = new TreeNode;
            newNode->data = ch;
            newNode->left = NULL;
            newNode->right = NULL;
            nodeStack.push(newNode);
        }
    }
    return nodeStack.top();
}

void preorderTraversal(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    string infixExpression;
    cout << "Enter any expression: ";
    getline(cin, infixExpression);
    cout << "Infix Expression: " << infixExpression << endl;
    string prefix = infixToPrefix(infixExpression);
    cout << "Prefix Expression: " << prefix << endl;
    TreeNode* root = constructExpressionTree(prefix);
    cout << "Preorder traversal of the constructed expression tree:\n";
    preorderTraversal(root);
    cout << endl;

    return 0;
}

