#include<fstream>
#include"node.cpp"
//////////////////////////
template <class T>
class LinkedList
{
	Node<T> *start;

	public:
		LinkedList();
		void display();
		void insertPos(book&,int);
		void deletePos(int);
		void deleteLL();
		void deleteid();
		void deletebknm();
		void deletebkan();
		void updateBook(int);
		void search();
		void searchId();
		void searchBn();
		void searchAn();
		void top3Book();
		void top3PriceBooks();
		void top3Rating();
		void readFromFile(const char*);
		void writeToFile(const char*);
		~LinkedList();
};

