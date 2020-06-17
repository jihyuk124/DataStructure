#include<iostream>
#include<string>

using namespace std;

class Queue
{
public:
	Queue() : _elems{ 0, }, _front(0), _rear(0), _size(0) {}
	~Queue() {}

	void push(int x)
	{
		_elems[_rear++] = x;
		if (MaxQueueSize <= _rear)
		{
			_rear = _rear % MaxQueueSize;
		}
		++_size;
	}

	void pop()
	{
		++_front;
		if (MaxQueueSize <= _front)
		{
			_front = _front % MaxQueueSize;
		}
		--_size;
	}

	int front()
	{
		return _elems[_front];
	}

	int back()
	{
		return _elems[_rear - 1];
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
	static const size_t MaxQueueSize = 2000000;
	size_t _front, _rear;
	int _elems[MaxQueueSize];

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