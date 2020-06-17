#include<iostream>
#include<string>

using namespace std;

class Stack
{
public:
	Stack() : _top(nullptr), _size(0) {}
	~Stack()
	{
		while (!empty())
			pop();
	}

	void push(int x)
	{
		Node* newNode = new Node(x);
		newNode->next = _top;
		_top = newNode;
		++_size;
	}

	void pop()
	{
		Node* removeNode = _top;
		_top = _top->next;
		delete removeNode;
		--_size;
	}

	int top()
	{
		return _top->element;
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
	struct Node
	{
		Node(int val) : element(val), next(nullptr) {}

		int element;
		Node* next;
	};

	Node* _top;
	size_t _size;
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	Stack s;

	string instruction;

	while (N--)
	{
		cin >> instruction;
		if (0 == instruction.compare("push"))
		{
			int element;
			cin >> element;
			s.push(element);
		}
		else if (0 == instruction.compare("pop"))
		{
			if (s.empty()) cout << "-1\n";
			else
			{
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (0 == instruction.compare("size"))
		{
			cout << s.size() << "\n";
		}
		else if (0 == instruction.compare("empty"))
		{
			cout << static_cast<int>(s.empty()) << "\n";
		}
		else if (0 == instruction.compare("top"))
		{
			if (s.empty()) cout << "-1\n";
			else cout << s.top() << "\n";
		}
	}
}