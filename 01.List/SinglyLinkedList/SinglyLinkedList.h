#pragma once

struct Node
{
	Node() : data(0), next(nullptr) {}
	int data;
	Node* next;
};

// ���� ���� ���� ����Ʈ�� ������ ����Ʈ
class List
{
public:
	List();
	~List();

	void insert(int val);
	void erase();
	bool isEmpty() { return (_size == 0); }
	size_t size() const { return _size;}

	void print();
	void reverse();

private:
	Node* findNode(size_t pos);

private:
	Node* _head, *_tail;
	size_t _size;
};

