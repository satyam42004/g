#include <iostream>
using namespace std;

// Struct for Height-Balanced Tree Node
struct HBTNode {
    int Key;
    char Mean[10];
    HBTNode *left;
    HBTNode *right;
} *Root;

// Function to create Height-Balanced Tree
void create_HBT() {
    int nodes;
    cout << "\nEnter the number of nodes to insert in HBT: ";
    cin >> nodes;
    for (int i = 0; i < nodes; i++) {
        HBTNode *Newnode = new HBTNode;
        cout << "\nEnter Keyword: ";
        cin >> Newnode->Key;
        cout << "Enter Meaning: ";
        cin >> Newnode->Mean;
        Newnode->left = NULL;
        Newnode->right = NULL;
        if (Root == NULL) {
            Root = Newnode;
        } else {
            HBTNode *current = Root;
            while (true) {
                if (Newnode->Key < current->Key) {
                    if (current->left == NULL) {
                        current->left = Newnode;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == NULL) {
                        current->right = Newnode;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }
}

// Function to display Height-Balanced Tree (Pre-order)
void display_HBT(HBTNode *root) {
    if (root) {
        cout << root->Key << " - " << root->Mean << "\n";
        display_HBT(root->left);
        display_HBT(root->right);
    }
}

// Function to display Sorted List of Keywords and Meanings
void Sorted_List(HBTNode *root) {
    if (root) {
        Sorted_List(root->left);
        cout << root->Key << " - " << root->Mean << "\n";
        Sorted_List(root->right);
    }
}

// Function to find keyword and display number of comparisons
void Find_Keyword(int key) {
    int comp = 0;
    int level = 0;
    HBTNode *current = Root;
    while (current) {
        if (key < current->Key) {
            current = current->left;
            level++;
            comp++;
        } else if (key > current->Key) {
            current = current->right;
            level++;
            comp++;
        } else {
            comp++;
            cout << "\nKey: " << key;
            cout << "\nFound at Level: " << level;
            cout << "\nNumber of Comparisons: " << comp << "\n";
            return;
        }
    }
    cout << "\nKeyword not found.\n";
}

int main() {
    cout << "\n*** A C++ Program to Implement Dictionary using Height-Balanced Tree ***\n";
    cout << "\n1. Store Keywords and Meanings in Height-Balanced Tree.";
    Root = NULL;
    create_HBT();
    cout << "\n2. Display Keywords and Meanings in Height-Balanced Tree (Pre-order):";
    display_HBT(Root);
    cout << "\n3. Display Sorted List of Keywords and Meanings:";
    Sorted_List(Root);
    cout << "\n4. Find a Keyword and Display Number of Comparisons Required.";
    int keyword;
    cout << "\nEnter keyword to find: ";
    cin >> keyword;
    Find_Keyword(keyword);
    return 0;
}

