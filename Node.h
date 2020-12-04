// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

template <class T>
class Node
{
	public:
		T data;
		T getData();
		Node *left;
		Node *right;

		Node<T>();
		~Node<T>();
		Node<T>(T d);

};

template <class T>
Node<T>::Node()
{
	data = NULL;
	left = NULL;
	right = NULL;
}

template <class T>
Node<T>::Node(T d)
{
	data = d;
	left = NULL;
	right = NULL;
}

template <class T>
T Node<T>::getData() //constructor
{
	return data;
}

template <class T> //destructor
Node<T>::~Node()
{

}
