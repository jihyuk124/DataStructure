#include<iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main(void)
{
	List ll;

	ll.insert(1);
	ll.insert(2);
	ll.insert(3);
	ll.insert(4);
	ll.insert(5);

	ll.erase();
	ll.erase();

	ll.print();
	printf("\n");
	ll.reverse();

	ll.print();
}