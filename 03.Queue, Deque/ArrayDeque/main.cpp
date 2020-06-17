#include<iostream>
#include<string>

using namespace std;

class Deque
{
public:
	Deque() : _elems{ 0, }, _front(0), _rear(0), _size(0) {}
	~Deque() {}

	void push_front(int x)
	{
		0 < _front ? _front = _front - 1 : _front = MaxDequeSize - 1;

		_elems[_front] = x;
		
		++_size;
	}

	void push_back(int x)
	{
		_elems[_rear++] = x;
		if (MaxDequeSize <= _rear)
		{
			_rear = 0;
		}
		++_size;
	}

	void pop_front()
	{
		_front++;
		if (MaxDequeSize <= _front)
		{
			_front = 0;
		}
		--_size;
	}

	void pop_back()
	{
		0 < _rear ? _rear = _rear - 1 : _rear = MaxDequeSize - 1;
		--_size;
	}

	int front()
	{
		return _elems[_front];
	}

	int back()
	{
		if (0 < _rear)
			return _elems[_rear-1];
		else
			return _elems[MaxDequeSize - 1];
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
	static const size_t MaxDequeSize = 10000;
	size_t _front, _rear;
	int _elems[MaxDequeSize];

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