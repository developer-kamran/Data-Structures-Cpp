#include <iostream>
#include <cstdlib>
using namespace std;

struct ExpressionTreeNode
{
  char value;
  ExpressionTreeNode *left;
  ExpressionTreeNode *right;
};

struct StackNode
{
  ExpressionTreeNode *node;
  StackNode *next;
};

StackNode *top = NULL;

void push(ExpressionTreeNode *node)
{
  StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
  newNode->node = node;
  newNode->next = top;
  top = newNode;
}

ExpressionTreeNode *pop()
{
  if (top == NULL)
  {
    return NULL;
  }
  ExpressionTreeNode *node = top->node;
  StackNode *temp = top;
  top = top->next;
  free(temp);
  return node;
}

string reverseString(string str)
{
  string revStr;
  for (int i = 0; i < str.length(); i++)
  {
    revStr = str[i] + revStr;
  }
  return revStr;
}

ExpressionTreeNode *buildExpressionTree(string prefixExpression)
{
  string reversedPrefix = reverseString(prefixExpression);
  for (int i = 0; i < reversedPrefix.length(); i++)
  {
    char currChar = reversedPrefix[i];
    if ((currChar >= '0' && currChar <= '9') || (currChar >= 'a' && currChar <= 'z'))
    {
      ExpressionTreeNode *node = (ExpressionTreeNode *)malloc(sizeof(ExpressionTreeNode));
      node->value = currChar;
      node->left = node->right = NULL;
      push(node);
    }
    else
    {
      ExpressionTreeNode *node = (ExpressionTreeNode *)malloc(sizeof(ExpressionTreeNode));
      node->value = currChar;
      node->right = pop();
      node->left = pop();
      push(node);
    }
  }
  ExpressionTreeNode *root = pop();
  return root;
}

void preOrderTraversal(ExpressionTreeNode *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->value << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

int main()
{
  string prefixExpression = "-+a*/*bcdx*fd";
  ExpressionTreeNode *root = buildExpressionTree(prefixExpression);
  preOrderTraversal(root);
}

