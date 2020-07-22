#include <iostream>
#include <queue>

using namespace std;

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	// tree treaversal
	void preorder();
	void inorder();
	void postorder();
	void levelorder();

	int getCount();
	int getHeight();

	void insert_node(int idx, char value);

private:
	void preorder(int idx);
	void inorder(int idx);
	void postorder(int idx);

	int getCount(int idx);
	int getHeight(int idx);

private:
	static const int MAX = 100;

	char values[MAX];
	int size;
};


BinaryTree::BinaryTree() : values{ 0 }
{
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::preorder()
{
	cout << "Preorder : ";
	preorder(0);
	cout << "\n";
}

void BinaryTree::preorder(int idx)
{
	// V L R
	if (0 != values[idx])
	{
		cout << values[idx] << ",";
		preorder(2 * idx + 1);
		preorder(2 * idx + 2);
	}
}

void BinaryTree::inorder()
{
	cout << "Inorder : ";
	inorder(0);
	cout << "\n";
}

void BinaryTree::inorder(int idx)
{
	// L V R
	if (0 != values[idx])
	{
		inorder(2 * idx + 1);
		cout << values[idx] << ",";
		inorder(2 * idx + 2);
	}
}

void BinaryTree::postorder()
{
	cout << "Postorder : ";
	postorder(0);
	cout << "\n";
}

void BinaryTree::postorder(int idx)
{
	// L R V
	if (0 != values[idx])
	{
		postorder(2 * idx + 1);
		postorder(2 * idx + 2);
		cout << values[idx] << ",";
	}
}

void BinaryTree::levelorder()
{
	cout << "Level order : ";

	if (0 == values[0])
	{
		return;
	}

	int idx = 0;

	using queueType = queue<pair<int, char>>;

	queueType q;
	q.push(queueType::value_type(0, values[idx]));

	while (false == q.empty())
	{
		int idx = q.front().first;
		int val = q.front().second;

		q.pop();

		cout << val << ",";

		int left = 2 * idx + 1;
		int right = 2 * idx + 2;

		if (0 != values[left])
			q.push(queueType::value_type(left, values[left]));

		if (0 != values[right])
			q.push(queueType::value_type(right, values[right]));
	}

	cout << "\n";
}

int BinaryTree::getCount()
{
	int count = getCount(0);
	printf("Tree node count : %d\n", count);
	return count;
}

int BinaryTree::getCount(int idx)
{
	if (0 != values[idx])
	{
		int left = 2 * idx + 1;
		int right = 2 * idx + 2;

		return 1 + getCount(left) + getCount(right);
	}

	return 0;
}


int BinaryTree::getHeight()
{
	int height = getHeight(0);
	printf("Tree height : %d\n", height);
	return height;
}

int BinaryTree::getHeight(int idx)
{
	if (0 != values[idx])
	{
		int left = getCount(2 * idx + 1);
		int right = getCount(2 * idx + 2);

		return 1 + (left < right ? right : left);
	}

	return 0;
}

void BinaryTree::insert_node(int idx, char value)
{
	values[idx] = value;
}

int main()
{
	BinaryTree* tree = new BinaryTree();

	tree->insert_node(0, 'A');
	tree->insert_node(1, 'B');
	tree->insert_node(2, 'C');
	tree->insert_node(3, 'D');
	tree->insert_node(4, 'E');
	tree->insert_node(5, 'F');

	// 트리 순회(tree traversal)
	tree->preorder();
	tree->inorder();
	tree->postorder();
	tree->levelorder();

	tree->getCount();
	tree->getHeight();

	delete tree;
}