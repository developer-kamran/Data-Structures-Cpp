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

ExpressionTreeNode *buildExpressionTree(string postfixExpression)
{
  for (int i = 0; i < postfixExpression.length(); i++)
  {
    char currChar = postfixExpression[i];
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

void postOrderTraversal(ExpressionTreeNode *root)
{
  if (root == NULL)
  {
    return;
  }
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->value << " ";
}

int main()
{
  string postfixExpression = "abcd-*+x<cy!xy+5<|&";
  string postfixEq2 = "abcd-*+x<cy!xy+5<|&";
  ExpressionTreeNode *root = buildExpressionTree(postfixEq2);
  postOrderTraversal(root);
}

