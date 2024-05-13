#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

bool search(Node* root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

Node* minValue(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

bool deleteNode(Node** root, int key) {
    if (*root == NULL) {
        return false;
    }
    if (key < (*root)->data) {
        return deleteNode(&(*root)->left, key);
    } else if (key > (*root)->data) {
        return deleteNode(&(*root)->right, key);
    } else {
        if ((*root)->left == NULL) {
            Node* temp = (*root)->right;
            free(*root);
            *root = temp;
        } else if ((*root)->right == NULL) {
            Node* temp = (*root)->left;
            free(*root);
            *root = temp;
        } else {
            Node* temp = minValue((*root)->right);
            (*root)->data = temp->data;
            return deleteNode(&(*root)->right, temp->data);
        }
        return true;
    }
}

void deleteTree(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main (){
    Node* root = NULL;
    int choice, value;
    
    while (true) {
        cout << "\n1. Insert node\n";
        cout << "2. Search node\n";
        cout << "3. Delete node\n";
        cout << "4. Delete Binary Tree\n";
        cout << "5. In-order Traversal\n";
        cout << "6. Pre-order Traversal\n";
        cout << "7. Post-order Traversal\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
         switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value)) {
                    cout << "Value found in the binary tree." << endl;
                } else {
                    cout << "Value not found in the binary tree." << endl;
                }
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                if (deleteNode(&root, value)) {
                    cout << "Value " << value << " deleted from the binary tree." << endl;
                } else {
                    cout << "Value " << value << " not found in the binary tree." << endl;
                }
                break;
            case 4:
                deleteTree(root);
                root = NULL;
                cout << "Binary tree deleted.\n";
                break;
            case 5:
                cout << "In-order Traversal: ";
                inOrderTraversal(root);
                cout << endl;
                break;
            case 6:
                cout << "Pre-order Traversal: ";
                preOrderTraversal(root);
                cout << endl;
                break;
            case 7:
                cout << "Post-order Traversal: ";
                postOrderTraversal(root);
                cout << endl;
                break;
            case 8:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}

