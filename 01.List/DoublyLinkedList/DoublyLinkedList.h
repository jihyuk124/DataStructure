#pragma once

struct Node
{
	Node() : data(0), next(nullptr), prev(nullptr) {}
	int data;
	Node* next, * prev;
};

// ���� ���� ���� ����Ʈ�� ������ ����Ʈ
class List
{
public:
	List();
	~List();

	int front();
	int back();

	void insert(size_t pos, int val);
	void erase(size_t pos);
	bool isEmpty() { return (_size == 0); }
	size_t size() const { return _size;}

	void print();

private:
	Node* findNode(size_t pos);

private:
	Node* _head;
	size_t _size;
};

