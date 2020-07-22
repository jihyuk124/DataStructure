#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	Node() : key(0), left(nullptr), right(nullptr) {}
	Node(int key, Node* left = nullptr, Node* right = nullptr) : key(key), left(left), right(right) {}
	int key;
	Node* left;
	Node* right;
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	Node* search(int key);
	void insert(int key);
	void remove(int key);

	void preorder();
	void inorder();
	void postorder();
	void levelorder();

private:
	Node* makeNode(int key);
	void destroy(Node* node);

	void preorder(Node* node);
	void inorder(Node* node);
	void postorder(Node* node);

	Node* search_recursively(Node* node, int key); // recursive한 방법으로 탐색
	Node* search_iteratively(Node* node, int key);// iterative한 방법으로 탐색

	void insert_recursively(Node*& node, int key);
	void insert_iteratively(Node** node, int key);

	void remove(Node* parent, Node* removeNode);
	void replaceNode(Node* parent, Node* child, Node* newChildNode = nullptr);
	Node* findMin(Node*& parent, Node* node); // 오른쪽 서브 트리에서 가장 작은 값
	Node* findMax(Node*& parent, Node* node); // 왼쪽 서브 트리에서 가장 큰 값

private:
	Node* root;
};

BinarySearchTree::BinarySearchTree()
	: root(nullptr)
{
}

BinarySearchTree::~BinarySearchTree()
{
	destroy(root);
	root = nullptr;
}

Node* BinarySearchTree::makeNode(int key)
{
	return new Node(key);
}

void BinarySearchTree::destroy(Node* node)
{
	if (nullptr != node)
	{
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

void BinarySearchTree::preorder()
{
	cout << "Preorder : ";
	preorder(root);
	cout << "\n";
}

void BinarySearchTree::preorder(Node* node)
{
	// V L R
	if (nullptr != node)
	{
		cout << node->key << ",";
		preorder(node->left);
		preorder(node->right);
	}
}

void BinarySearchTree::inorder()
{
	cout << "Inorder : ";
	inorder(root);
	cout << "\n";
}

void BinarySearchTree::inorder(Node* node)
{
	// L V R
	if (nullptr != node)
	{
		inorder(node->left);
		cout << node->key << ",";
		inorder(node->right);
	}
}

void BinarySearchTree::postorder()
{
	cout << "Postorder : ";
	postorder(root);
	cout << "\n";
}

void BinarySearchTree::postorder(Node* node)
{
	// L R V
	if (nullptr != node)
	{
		postorder(node->left);
		postorder(node->right);
		cout << node->key << ",";
	}
}

void BinarySearchTree::levelorder()
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

		cout << node->key << ",";

		if (nullptr != node->left)
			q.push(node->left);

		if (nullptr != node->right)
			q.push(node->right);
	}

	cout << "\n";
}

Node* BinarySearchTree::search(int key)
{
	Node* searchNode = search_recursively(root, key);
	//Node* searchNode = search_iteratively(root, key);
	if (nullptr != searchNode)
	{
		cout << "search key : " << key << "\n";
	}
	else
	{
		cout << "can't search key : " << key << "\n";
	}
	
	return searchNode;
}

Node* BinarySearchTree::search_recursively(Node* node, int key)
{
	if (nullptr == node || key == node->key)
	{
		return node;
	}
	else if (key < node->key)
	{
		return search_recursively(node->left, key);
	}
	else
	{
		return search_recursively(node->right, key);
	}
}

Node* BinarySearchTree::search_iteratively(Node* node, int key)
{
	Node* currentNode = node;

	while (nullptr != currentNode)
	{
		if (key == currentNode->key)
		{
			return currentNode;
		}
		else if (key < currentNode->key)
		{
			currentNode = currentNode->left;
		}
		else
		{
			currentNode = currentNode->right;
		}
	}

	return currentNode;
}

void BinarySearchTree::insert(int key)
{
	insert_recursively(root, key);
	//insert_iteratively(&root, key);
}

void BinarySearchTree::insert_recursively(Node*& node, int key)
{
	if (nullptr == node)
	{
		node = new Node(key);
	}
	else if (key == node->key)
	{
		return;
	}
	else if(key < node->key)
	{
		insert_recursively(node->left, key);
	}
	else
	{
		insert_recursively(node->right, key);
	}
}

void BinarySearchTree::insert_iteratively(Node** node, int key)
{
	Node** currentNode = node;
	int currentKey;

	while (nullptr != (*currentNode))
	{
		currentKey = (*currentNode)->key;

		if (currentKey == key)
		{
			return;
		}
		else if (key > currentKey)
		{
			currentNode = &(*currentNode)->right;
		}
		else
		{
			currentNode = &(*currentNode)->left;
		}
	}

	*currentNode = makeNode(key);
}


void BinarySearchTree::remove(int key)
{
	Node* parent = nullptr;
	Node* removeNode = root;

	// find parent
	while (nullptr != removeNode && removeNode->key != key)
	{
		parent = removeNode;
		removeNode = key < removeNode->key ? removeNode->left : removeNode->right;
	}

	if (nullptr == removeNode)
	{
		cout << "can't remove key : " << key << "\n";
	}
	else
	{
		remove(parent, removeNode);
	}
		
}

void BinarySearchTree::remove(Node* parent, Node* removeNode)
{
	// case 1 : 0-child
	if (nullptr == removeNode->left && nullptr == removeNode->right)
	{
		cout << "0-child node remove : " << removeNode->key <<"\n";
		replaceNode(parent, removeNode);
	}
	// case 2 : 1-child 
	else if (nullptr == removeNode->right) // left child
	{
		cout << "0-child node remove : " << removeNode->key << "\n";
		if (root == removeNode)
		{
			root = removeNode->left;
		}
		else
		{
			replaceNode(parent, removeNode, removeNode->left);
		}
	}
	else if (nullptr == removeNode->left) // right child
	{
		cout << "1-child node remove : " << removeNode->key << "\n";
		if (root == removeNode)
		{
			root = removeNode->right;
		}
		else
		{
			replaceNode(parent, removeNode, removeNode->right);
		}
	}
	// case 3 : 2-child
	else 
	{
		cout << "2-child node remove : " << removeNode->key << "\n";
		Node* successorParent = removeNode;
		Node* successor = findMin(successorParent, removeNode->right);
		//Node* successor = findMax(successorParent, removeNode->left);

		if (successorParent->left == successor)
			successorParent->left = successor->right;
		else
			removeNode->right = successor->right; // == successorParent->right = successor->right

		/*
		// findMax 일때
		if (successorParent->right == successor)
			successorParent->right = successor->left;
		else
			removeNode->left = successor->left;
		*/

		removeNode->key = successor->key;
		removeNode = successor;
	}

	delete removeNode;
}

void BinarySearchTree::replaceNode(Node* parent, Node* child, Node* newChildNode)
{
	parent->left == child ? parent->left = newChildNode : parent->right = newChildNode;
}

Node* BinarySearchTree::findMin(Node*& parent, Node* node)
{
	while (nullptr != node->left)
	{
		parent = node;
		node = node->left;
	}

	return node;
}

Node* BinarySearchTree::findMax(Node*& parent, Node* node)
{
	while (nullptr != node->right)
	{
		parent = node;
		node = node->right;
	}

	return node;
}

int main()
{
	BinarySearchTree* tree = new BinarySearchTree();

	tree->insert(35);
	tree->insert(18);
	tree->insert(68);
	tree->insert(7);
	tree->insert(26);
	tree->insert(99);
	tree->insert(3);
	tree->insert(12);
	tree->insert(22);
	tree->insert(30);

	// 트리 순회(tree traversal)
	tree->preorder();
	tree->inorder();
	tree->postorder();
	tree->levelorder();

	tree->search(12);
	tree->search(25);

	tree->remove(100); // can't not find key
	tree->remove(30); // case1 : 0-child(leaf) node remove
	tree->remove(68); // case2 : 1-child node remove (left or right)
	tree->remove(7); // case3 : 2-child node remove

	tree->preorder();
	tree->inorder();
	tree->postorder();
	tree->levelorder();

	delete tree;
}