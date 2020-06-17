#include<iostream>
#include<string>

using namespace std;

struct Node
{
	Node(int val) : data(val), next(nullptr), prev(nullptr) {}
	int data;
	Node* next, * prev;
};

class Deque
{
public:
	Deque()
		: _head(nullptr)
		, _size(0)
	{
		_head = new Node(0);
		_head->next = _head->prev = _head;
	}
	~Deque()
	{
		Node* currentNode = _head->next;
		for (size_t i = 0; i < _size; i++)
		{
			Node* removeNode = currentNode;
			currentNode = currentNode->next;
			delete removeNode;
		}
		delete _head;
	}

	void push_front(int x)
	{
		push(_head->next, x);
	}

	void push_back(int x)
	{
		push(_head, x);
	}

	void pop_front()
	{
		pop(_head->next);
	}

	void pop_back()
	{
		pop(_head->prev);
	}

	const Node* begin()
	{
		return _head->prev;
	}

	const Node* end()
	{
		return _head;
	}

	int front()
	{
		//empty()일때 오류 처리는 따로 하지 않음
		return _head->next->data;
	}

	int back()
	{
		//empty()일때 오류 처리는 따로 하지 않음
		return _head->prev->data;
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
	void push(Node* node, int x)
	{
		Node* newNode = new Node(x);

		newNode->next = node;
		newNode->prev = node->prev;

		node->prev->next = newNode;
		node->prev = newNode;

		++_size;
	}

	void pop(Node* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;

		delete node;

		--_size;
	}

private:
	Node* _head;
	size_t _size;
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	Deque deq;

	string instruction;

	while (N--)
	{
		cin >> instruction;
		if (0 == instruction.compare("push_front"))
		{
			int element;
			cin >> element;
			deq.push_front(element);
		}
		else if (0 == instruction.compare("push_back"))
		{
			int element;
			cin >> element;
			deq.push_back(element);
		}
		else if (0 == instruction.compare("pop_front"))
		{
			if (deq.empty()) cout << "-1\n";
			else
			{
				cout << deq.front() << "\n";
				deq.pop_front();
			}
		}
		else if (0 == instruction.compare("pop_back"))
		{
			if (deq.empty()) cout << "-1\n";
			else
			{
				cout << deq.back() << "\n";
				deq.pop_back();
			}
		}
		else if (0 == instruction.compare("size"))
		{
			cout << deq.size() << "\n";
		}
		else if (0 == instruction.compare("empty"))
		{
			cout << static_cast<int>(deq.empty()) << "\n";
		}
		else if (0 == instruction.compare("front"))
		{
			if (deq.empty()) cout << "-1\n";
			else cout << deq.front() << "\n";
		}
		else if (0 == instruction.compare("back"))
		{
			if (deq.empty()) cout << "-1\n";
			else cout << deq.back() << "\n";
		}
	}
}