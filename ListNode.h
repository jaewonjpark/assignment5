// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5


template <class T>
class ListNode
{
	public:
		T data;
		ListNode *next;
		ListNode *prev;
		ListNode();
		ListNode(T d);
		~ListNode();
};

template <class T>
ListNode<T>::ListNode(T d)
{
	data = d;
	next = NULL;
	prev = NULL;
}

template <class T>
ListNode<T>::~ListNode()
{

}
