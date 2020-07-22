#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	Node() : value(0), left(nullptr), right(nullptr) {}
	Node(char value, Node* left, Node* right) : value(value), left(left), right(right) {}
	char value;
	Node* left;
	Node* right;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void destroy_tree();

	// tree traversal
	void preorder();
	void inorder();
	void postorder();
	void levelorder();

	int getCount();
	int getHeight();

	void set_root(Node* node);

private:
	void destroy_tree(Node* leaf);

	void preorder(Node* node);
	void inorder(Node* node);
	void postorder(Node* node);

	int getCount(Node* node);
	int getHeight(Node* node);

	Node* root;
};


BinaryTree::BinaryTree() : root(nullptr)
{
}

BinaryTree::~BinaryTree()
{
	destroy_tree();
}

void BinaryTree::destroy_tree()
{
	destroy_tree(root);
}

void BinaryTree::destroy_tree(Node* node)
{
	if (nullptr != node)
	{
		destroy_tree(node->left);
		destroy_tree(node->right);
		delete node;
	}
}

void BinaryTree::preorder()
{
	cout << "Preorder : ";
	preorder(root);
	cout << "\n";
}

void BinaryTree::preorder(Node* node)
{
	// V L R
	if (nullptr != node)
	{
		cout << node->value << ",";
		preorder(node->left);
		preorder(node->right);
	}
}

void BinaryTree::inorder()
{
	cout << "Inorder : ";
	inorder(root);
	cout << "\n";
}

void BinaryTree::inorder(Node* node)
{
	// L V R
	if (nullptr != node)
	{
		inorder(node->left);
		cout << node->value << ",";
		inorder(node->right);
	}
}

void BinaryTree::postorder()
{
	cout << "Postorder : ";
	postorder(root);
	cout << "\n";
}

void BinaryTree::postorder(Node* node)
{
	// L R V
	if (nullptr != node)
	{
		postorder(node->left);
		postorder(node->right);
		cout << node->value << ",";
	}
}

void BinaryTree::levelorder()
{
	cout << "Level order : ";

	if (nullptr == root)
	{
		return;
	}

	queue<Node*> q;
	q.push(root);

	while (false == q.empty())
	{
		Node* node = q.front();
		q.pop();

		cout << node->value << ",";

		if (nullptr != node->left)
			q.push(node->left);

		if (nullptr != node->right)
			q.push(node->right);
	}

	cout << "\n";
}

int BinaryTree::getCount()
{
	int count = getCount(root);
	printf("Tree node count : %d\n", count);
	return count;
}

int BinaryTree::getCount(Node* node)
{
	if (nullptr != node)
	{
		return 1 + getCount(node->left) + getCount(node->right);
	}

	return 0;
}


int BinaryTree::getHeight()
{
	int height = getHeight(root);
	printf("Tree height : %d\n", height);
	return height;
}

int BinaryTree::getHeight(Node* node)
{
	if (nullptr != node)
	{
		int left = getCount(node->left);
		int right = getCount(node->right);

		return 1 + (left < right ? right : left);
	}

	return 0;
}


void BinaryTree::set_root(Node* node)
{
	root = node;
}

int main()
{
	BinaryTree* tree = new BinaryTree();

	Node* d = new Node('D', nullptr, nullptr);
	Node* e = new Node('E', nullptr, nullptr);
	Node* b = new Node('B', d, e);
	Node* f = new Node('F', nullptr, nullptr);
	Node* c = new Node('C', f, nullptr);
	Node* a = new Node('A', b, c);

	tree->set_root(a);

	// 트리 순회(tree traversal)
	tree->preorder();
	tree->inorder();
	tree->postorder();
	tree->levelorder();

	tree->getCount();
	tree->getHeight();

	delete tree;
}