#include"node.h"
///////////////////////
template <class T>
Node<T>::Node(book&d)
//Node::Node(book &d)
{
	data = d;
	next = NULL;
}
///////////////////////
template <class T>
book& Node<T>::getData()
//book& Node::getData()
{
	return data;
}
///////////////////////
template <class T>

//Node *Node::getNext()
Node<T> *Node<T>:: getNext()
{
	return next;
}
///////////////////////
template <class T>
void Node<T>::setData(book &d)
{
	data = d;
}
///////////////////////
template <class T>
void Node<T>::setNext(Node *nt)
//void Node::setNext(Node *nt)
{
	next = nt;
}
///////////////////////


