#include "SinglyLinkedList.h"
#include <iostream>

List::List()
	: _head(nullptr), _tail(nullptr), _size(0)
{
}

List::~List()
{
	Node* currentNode = _head;
	Node* removeNode = nullptr;
	for (size_t i = 0; i < _size; i++)
	{
		removeNode = currentNode;
		currentNode = currentNode->next;

		delete removeNode;
	}
}

void List::insert(int val)
{
	Node* newNode = new Node;
	newNode->data = val;

	if (0 == _size)
	{
		_head = _tail = newNode;;
	}
	else
	{
		_tail->next = newNode;
		_tail = newNode;
	}

	++_size;
}

void List::erase()
{
	if (_head)
	{
		Node* node = _head;
		_head = _head->next;
		delete node;

		--_size;
		if (isEmpty())
		{
			_tail = nullptr;
		}
	}
}

void List::print()
{
	Node* currentNode = _head;
	for (size_t i = 0; i < _size; i++)
	{
		std::cout << currentNode->data << "\n";
		currentNode = currentNode->next;
	}
}

void List::reverse()
{
	Node* current = _head;
	Node* prev = nullptr, * next = nullptr;

	while (current != nullptr) {
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}
	_head = prev;
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