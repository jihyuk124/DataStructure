#include<iostream>
#include<string>

using namespace std;

struct Node
{
	Node(int x) : data(x), next(nullptr) {}

	int data;
	Node* next;
};

class Queue
{
public:
	Queue() : _front(nullptr), _rear(nullptr), _size(0) {}
	~Queue() {}

	void push(int x)
	{
		if (!empty())
		{
			Node* newNode = new Node(x);
			_rear->next = newNode;
			_rear = newNode;
		}
		else
		{
			_front = _rear = new Node(x);
		}
		++_size;
	}

	void pop()
	{
		Node* removeNode = _front;
		_front = _front->next;
		delete removeNode;

		--_size;
		if (empty())
		{
			_rear = nullptr;
		}
	}

	int front()
	{
		return _front->data;
	}

	int back()
	{
		return _rear->data;
	}

	bool empty()
	{
		return (0 == _size);
	}

	size_t size()
	{
		return _size;
	}

private:
	Node *_front, *_rear;

	size_t _size;
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	Queue q;

	string instruction;

	while (N--)
	{
		cin >> instruction;
		if (0 == instruction.compare("push"))
		{
			int element;
			cin >> element;
			q.push(element);
		}
		else if (0 == instruction.compare("pop"))
		{
			if (q.empty()) cout << "-1\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (0 == instruction.compare("size"))
		{
			cout << q.size() << "\n";
		}
		else if (0 == instruction.compare("empty"))
		{
			cout << static_cast<int>(q.empty()) << "\n";
		}
		else if (0 == instruction.compare("front"))
		{
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (0 == instruction.compare("back"))
		{
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}
}