// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

#include <iostream>
#include "ListNode.h"

using namespace std;
template <class T>
class DoublyLinkedList
{
	private:
		ListNode<T> *front;
		ListNode<T> *back;
		int size;

	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		void insertFront(T d);
		void insertBack(T d);
		T removeFront();
		T removeBack();
		T getFront();
		int remove(int key);
		int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	size=0;
	front=NULL;
	back=NULL;

}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d)
{
	ListNode<T> *node= new ListNode<T>(d);
	//checking not empty
	if(size==0)
		back=node;
	else
	{
		front->prev=node;
		node->next=front;
	}
	front=node;
	size++;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d)
{
	ListNode<T> *node= new ListNode<T>(d);

	if(size==0)
	{
		front=node;
		back=node;
	}
	else
	{
		node->prev=back;
		node->prev->next=node;
		back=node;
	}
	size++;
}

template <class T>
//removeFront
T DoublyLinkedList<T>::removeFront()
{
	ListNode<T> *node=front;
	if(front->next == NULL)
	{
		back=NULL;
	}
	else
	{
		front->next->prev=NULL;
	}
	front=front->next;
	node->next=NULL;
	T temp=node->data;
	delete node;

	--size;
	return temp;
}

template <class T>
//removeBack
T DoublyLinkedList<T>::removeBack()
{
	ListNode<T> *node=back;
	if(back->prev==NULL)
	{
		front=NULL;
	}
	else
	{
		back->prev->next=NULL;
	}
	back=back->prev;
	back->prev=NULL;

	T temp=node->data;
	delete node;

	--size;
	return temp;
}

template <class T>
int DoublyLinkedList<T>::remove(int key)
{
	ListNode<T> *current = front;

	while(current->data != key)
	{
		current=current->next;

		if(current==NULL)
			return 0;
	}

	if(current==front)
	{
		front=current->next;
	}
	else
	{
		current->prev->next=current->next;

	}

	if(current==back)
	{
		back=current->prev;
	}
	else
	{
		current->next->prev=current->prev;
	}

	current->next=NULL;
	current->prev=NULL;

	int temp = current->data;
	delete current;
	--size;

	return temp;
}

template <class T>
int DoublyLinkedList<T>::getSize()
{
	return size;
}

template<class T>
T DoublyLinkedList<T>::getFront()
{
	return front->data;
}
