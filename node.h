#include"book.h"
///////////////////////////
template<class T>

class Node
{
	book data;
//	Node *next;
    Node *next;
	public:
		Node(book &);
        //T(book&);
		book& getData();
		Node *getNext();
        //T *getNext();
		void setData(book &);
		void setNext(Node *);
        //void setNext(T*);
};

