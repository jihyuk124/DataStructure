#include<iostream>
#include<string>

using namespace std;

class Stack
{
public:
	Stack() : _elems{0,}, _size(0) {}

	void push(int x)
	{
		_elems[_size++] = x;
	}

	void pop()
	{
		--_size;
	}

	int top()
	{
		return _elems[_size - 1];
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
	int _elems[10000];
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