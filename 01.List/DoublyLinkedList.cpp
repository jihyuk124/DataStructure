#include "DoublyLinkedList.h"
#include <iostream>

List::List()
	: _head(nullptr), _size(0)
{
	_head = new Node; // 삽입 삭제 연산의 편의성을 위해 빈노드 생성
	_head->next = _head->prev = _head;
}

List::~List()
{
	Node* currentNode = _head->next;
	Node* removeNode = nullptr;
	for (size_t i = 0; i < _size; i++)
	{
		removeNode = currentNode;
		currentNode = currentNode->next;

		delete removeNode;
	}
	delete _head;
}

int List::front()
{
	if (0 == _size)
	{
		// error 처리 필요
		return 0;
	}
	return _head->next->data;
}

int List::back()
{
	if (0 == _size)
	{
		// error 처리 필요
		return 0;
	}
	return _head->prev->data;
}

Node* List::begin()
{
	if (0 == _size)
	{
		return nullptr;
	}
	return _head->next;
}

Node* List::end()
{
	if (0 == _size)
	{
		return nullptr;
	}
	return _head->prev;
}

void List::insert(size_t pos, int val)
{
	Node* node = findNode(pos);

	Node* newNode = new Node;
	newNode->data = val;

	newNode->next = node;
	newNode->prev = node->prev;

	node->prev->next = newNode;
	node->prev = newNode;

	++_size;
}

void List::erase(size_t pos)
{
	Node* node = findNode(pos);

	node->prev->next = node->next;
	node->next->prev = node->prev;

	delete node;

	--_size;
}

void List::print()
{
	Node* currentNode = _head->next;
	while (currentNode != _head)
	{
		std::cout << currentNode->data << "\n";
		currentNode = currentNode->next;
	}
}

Node* List::findNode(size_t pos)
{
	Node* node = _head->next;
	for (size_t i = 0; i < pos; i++, node = node->next)
	{
		if (nullptr == node)
		{
			break;
		}
	}
	return node;
}