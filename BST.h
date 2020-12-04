// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

#include <iostream>
#include "Node.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

template <class T>
class BST
{
	public:
		BST<T>();
		~BST<T>();
		void insert(T d);
		Node<T>* search(T data);
		Node<T>* searchAdv(T data, Node<T>* node);
		bool deleteN(T data);
		Node<T>* getSucc(Node<T>* d);
		void print(Node<T>* node);
		void printTree();
		Node<T>* getRoot();
		Node<T>* root;
};

template <class T>
BST<T>::BST()
{
	root = NULL;
}

template <class T>
BST<T>::~BST()
{

}

template <class T>
void BST<T>::print(Node<T> *node)
{
	if (node == NULL)
		return;
	else
	{
		print (node->left);
		cout << node->data;
		print (node->right);
	}
}

template <class T>
void BST<T>::printTree()
{
	print(root);

}

template <class T>
Node<T>* BST<T>::searchAdv(T data, Node<T>* node)
{
	if (data == node->getData())
	{
		return node;
	}

	else if (data < node->getData())
	{
		return searchAdv(data, node->left);

	}
	else
		return searchAdv(data, node->right);
}

template <class T>
Node<T> * BST<T>::search(T data)
{
	return searchAdv(data, root);
}

template <class T>
void BST<T>::insert(T d)
{
	Node<T> * data = new Node<T>(d);
	if (root == NULL)
	{
		root = data;

	}
	else
	{
		Node<T>* curr = root;

		Node<T>* parent;
		while(true)
		{
			parent = curr;
			if (data->getData() < curr->getData())
			{
				cout << "going left" << endl;
				curr = curr->left;
				if(curr == NULL)
				{
					parent ->left = data;
					cout << "left" << endl;
					break;
				}
			}
			else
			{
				cout << "going right" << endl;
				curr = curr->right;
				if (curr == NULL)
				{
					parent->right = data;
					cout << "right" << endl;
					break;
				}
			}
		}
	}
}

template <class T>
Node<T> * BST<T>::getSucc(Node<T>* d)
{
	Node<T>* success=d;
	Node<T>* successor = d;
	Node<T>* current = d->right;


	while (current != NULL)
	{
		success = successor;
		successor = current;
		current = current->left;
	}
	return successor;

}

template <class T>
bool BST<T>::deleteN(T data)
{
	if (root == NULL)
	{
		return false;

	}
	Node<T>* parent = root;
	Node<T>* current = root;
	bool isLeft = true;

	while (current->getData() != data)
	{
		parent = current;
		if (data < current->getData())
		{
			isLeft = true;
			current = current->left;

		}
		else
		{
			isLeft = false;
			current = current->right;

		}
		if(current == NULL)
		{
			return false;

		}
	}


	if(current->left == NULL && current->right == NULL)
	{
		if (current->getData() == root->getData())
		{
			root = NULL;
		}
		else if(isLeft)
		{
			parent->left= NULL;
		}
		else
		{
			parent->right = NULL;
		}

	}
	else if(current->left == NULL)
	{
		if (current->getData() == root->getData())
		{
			root = current->right;

		}
		else if (isLeft)
		{
			parent->left=current->right;

		}
		else if(!isLeft)
		{
			parent->right=current->right;

		}
	}
	else if(current->right == NULL)
	{
		if (current->getData() == root->getData())
		{
			root = current->left;

		}
		else if(isLeft)
		{
			parent->left = current->left;

		}
		else
		{
			parent->right = current->left;
		}
	}
}
