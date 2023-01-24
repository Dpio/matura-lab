#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// New node creation
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return (node);
}

// Traverse Preorder
void traversePreOrder(struct node *temp)
{
    if (temp != NULL)
    {
        cout << " " << temp->data;
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
}

// Traverse Inorder
void traverseInOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traverseInOrder(temp->left);
        cout << " " << temp->data;
        traverseInOrder(temp->right);
    }
}

// Traverse Postorder
void traversePostOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout << " " << temp->data;
    }
}

void rysuj(node* root, int num, int N) {
    if (2 * num <= N)
    {
        root->left = newNode(2 * num);
        rysuj(root->left, 2 * num, N);
    }
    if (2 * num + 1 <= N)
    {
        root->right = newNode(2 * num + 1);
        rysuj(root->right, 2 * num + 1, N);
    }
}

//sprawdzenie
bool sprawdz(node* root, int szukana) {
    if(root->data == szukana) {
        return true;
    }
    
    bool lewy = false;
    bool prawy = false;
    if(root->left != NULL) {
        lewy = sprawdz(root->left, szukana);
    }

    if(root->right != NULL) {
        prawy = sprawdz(root->right, szukana);
    }

    return lewy || prawy;
}

node* znajdz(node* root, int szukana) {
    if(root->data == szukana) {
        return root;
    }
    
    node* odp = NULL;
    if(root->left != NULL) {
        node* lewy = znajdz(root->left, szukana);
        if(lewy != NULL)
        {
            odp = lewy;
        }
    }

    if(root->right != NULL) {
        node* prawy = znajdz(root->right, szukana);
        if(prawy != NULL)
        {
            odp = prawy;
        }
    }

    return odp;
}

void loadTree(int start, int end)
{
    struct node *root = newNode(1);
    rysuj(root, 1, end);

    node* startowy = znajdz(root, start);
    node* szukany = znajdz(startowy, end);
    if(szukany != NULL) {
        cout << start << " " << end << endl;
    }
    cout << "NIC" << endl;
}

int main()
{
    // nic
    loadTree(3, 5);
    loadTree(1, 5);
    loadTree(2, 5);
    loadTree(2, 4);
    loadTree(3, 4);
    loadTree(3, 5);
    loadTree(35922, 66803);
    // pokazac
    loadTree(1, 4);
    loadTree(47, 3044);
    loadTree(7650, 61204);
    loadTree(1, 245);
    loadTree(7, 63669);
    loadTree(9125, 18250);
    loadTree(5, 43246);

    return 0;
}