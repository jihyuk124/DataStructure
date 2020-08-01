#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
    node(int data) : data(data), left(nullptr), right(nullptr), height(0) {}
    int data;
    node* left;
    node* right;
    int height;
};

class BST
{
public:
    BST();
    ~BST();
    
    void insert(int x);
    void remove(int x);

    void display();

private:
    void destroy(node* t);

    int height(node* t);
    int getBalance(node* t);

    node* insert(int x, node* t);
    node* remove(int x, node* t);

    // select successor node (2-child node remove case)
    node* findMin(node* t); 
    node* findMax(node* t);

    // rotate operation
    node* singleRightRotate(node*& t);
    node* singleLeftRotate(node*& t);
    node* doubleLeftRotate(node*& t);
    node* doubleRightRotate(node*& t);

    void inorder(node* t);

private:
    node* root;
};

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    destroy(root);
}

void BST::insert(int x)
{
    root = insert(x, root);
}

void BST::remove(int x)
{
    root = remove(x, root);
}

void BST::display()
{
    inorder(root);
    cout << endl;
}

void BST::destroy(node* t)
{
    if (t == NULL)
        return;
    destroy(t->left);
    destroy(t->right);
    delete t;
}

int BST::height(node* t)
{
    return (t == NULL ? -1 : t->height);
}

int BST::getBalance(node* t)
{
    if (t == NULL)
        return 0;
    else
        return height(t->left) - height(t->right);
}

node* BST::insert(int x, node* t)
{
    if (t == NULL)
    {
        t = new node(x);
    }
    else if (x < t->data)
    {
        t->left = insert(x, t->left);
        if (height(t->left) - height(t->right) == 2)
        {
            if (x < t->left->data)
                t = singleRightRotate(t);
            else
                t = doubleRightRotate(t);
        }
    }
    else if (x > t->data)
    {
        t->right = insert(x, t->right);
        if (height(t->right) - height(t->left) == 2)
        {
            if (x > t->right->data)
                t = singleLeftRotate(t);
            else
                t = doubleLeftRotate(t);
        }
    }

    t->height = max(height(t->left), height(t->right)) + 1;
    return t;
}


node* BST::remove(int x, node* t)
{
    node* temp;

    // Element not found
    if (t == nullptr)
        return nullptr;

    // Searching for element
    else if (x < t->data)
        t->left = remove(x, t->left);
    else if (x > t->data)
        t->right = remove(x, t->right);

    // Element found
    // With 2 children
    else if (t->left && t->right)
    {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
    }
    // With one or zero child
    else
    {
        temp = t;
        if (t->left == nullptr)
            t = t->right;
        else if (t->right == nullptr)
            t = t->left;
        delete temp;
    }
    if (t == nullptr)
        return t;

    t->height = max(height(t->left), height(t->right)) + 1;

    // If node is unbalanced
    // If left node is deleted, right case
    if (height(t->left) - height(t->right) == 2)
    {
        // right right case
        if (height(t->left->left) - height(t->left->right) == 1)
            return singleLeftRotate(t); // BF = 1
        // right left case
        else
            return doubleLeftRotate(t); // BF = -1
    }
    // If right node is deleted, left case
    else if (height(t->right) - height(t->left) == 2)
    {
        // left left case
        if (height(t->right->right) - height(t->right->left) == 1)
            return singleRightRotate(t); // BF = 
        // left right case
        else
            return doubleRightRotate(t);
    }
    return t;
}

node* BST::findMin(node* t)
{
    if (t == nullptr)
        return nullptr;
    else if (t->left == nullptr)
        return t;
    else
        return findMin(t->left);
}

node* BST::findMax(node* t)
{
    if (t == nullptr)
        return nullptr;
    else if (t->right == nullptr)
        return t;
    else
        return findMax(t->right);
}

node* BST::singleRightRotate(node*& t)
{
    node* u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    u->height = max(height(u->left), t->height) + 1;
    return u;
}

node* BST::singleLeftRotate(node*& t)
{
    node* u = t->right;
    t->right = u->left;
    u->left = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    u->height = max(height(t->right), t->height) + 1;
    return u;
}

node* BST::doubleLeftRotate(node*& t)
{
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
}

node* BST::doubleRightRotate(node*& t)
{
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}

void BST::inorder(node* t)
{
    if (t == nullptr)
        return;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}

int main()
{
    BST t;

    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.insert(5);
    t.insert(35);
    t.insert(67);
    t.insert(43);
    t.insert(21);
    t.insert(10);
    t.insert(89);
    t.insert(38);
    t.insert(69);
    t.insert(69);
    t.display();

    t.remove(5);
    t.remove(35);
    t.remove(65);
    t.remove(89);
    t.remove(43);
    t.remove(88);
    t.remove(20);
    t.remove(38);
    t.display();
}