#include<iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main(void)
{
	List ll;

	ll.insert(0, 1);
	ll.insert(0, 2);
	ll.insert(1, 3);
	ll.insert(1, 4);
	ll.insert(2, 5);

	ll.erase(0);
	ll.erase(2);

	ll.print();
}