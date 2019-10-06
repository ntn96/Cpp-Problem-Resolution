#include "AddTwoNumbers.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
 
ListNode::ListNode(int x) : val(x), next(nullptr) {}

ListNode * AddTwoNumbers::addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode* first = nullptr;
	int suma = 0, acarreo = 0;
	ListNode* actual = nullptr;
	while (l1 != nullptr && l2 != nullptr) {
		suma = l1->val + l2->val + acarreo;
		acarreo = suma / 10;
		suma %= 10;
		if (first == nullptr) {
			ListNode* node = new ListNode(suma);
			actual = node;
			first = node;
		}
		else {
			actual->next = new ListNode(suma);
			actual = actual->next;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	ListNode* rest = nullptr;
	if (l1 == nullptr && l2 == nullptr) {
		if (acarreo != 0) {
			actual->next = new ListNode(acarreo);
		}
		return first;
	}
	else if (l1 == nullptr) rest = l2;
	else if (l2 == nullptr) rest = l1;
	if (acarreo != 0) {
		while (acarreo != 0 && rest != nullptr) {
			suma = acarreo + rest->val;
			acarreo = suma / 10;
			suma %= 10;
			actual->next = new ListNode(suma);
			actual = actual->next;
			rest = rest->next;
		}
		if (acarreo != 0) actual->next = new ListNode(acarreo);
		else actual->next = rest;
	}
	else {
		actual->next = rest;
	}
	return first;
}

int main()
{
	ListNode node1(2);
	node1.next = &(ListNode(4));
	node1.next->next = &(ListNode(3));
	ListNode node2(5);
	node2.next = &(ListNode(6));
	node2.next->next = &(ListNode(4));
	ListNode* result = AddTwoNumbers::addTwoNumbers(&node1, &node2);
	while (result->next != nullptr) {
		cout << result->val << " -> ";
		result = result->next;
	}
	cout << result->val << endl;
	system("pause");
}

AddTwoNumbers::AddTwoNumbers()
{
}


AddTwoNumbers::~AddTwoNumbers()
{
}
