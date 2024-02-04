#include"linklist.cpp"
////#include"book".cpp
//#include"node.cpp"
#include<iostream>
//#include<stdlib.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    int choice=0;
	LinkedList<book> lt;
	book b;
	lt.readFromFile("object.txt");
	while(choice!=5)
	{
		cout<<"\n\t\t1.Insert at position";
		cout<<"\n\t\t2.Delete from position";
		cout<<"\n\t\t3.Display";
		cout<<"\n\t\t4.Update";
		cout<<"\n\t\t5.Exit";
		cout<<"\n\t\t6.Top 3";
		cout<<"\n\t\t7.delete";
		cout<<"\n\t\t8.search";
		cout<<"\nEnter your choice";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
				
					int pos;
					int bid;
					char bname[20];
					char aname[20];
                    double price;
					double rating;
					cout<<"\n Enter book id ";
				    cin>>bid;
				    cout<<"\n Enter book name ";
				    fflush(stdin);
				    gets(bname);
				    
//                    cin>>bname;
				    cout<<"\n Enter author name ";
				    fflush(stdin);
                    gets(aname);
                    
//                    cin>>aname;
				    cout<<"\n Enter price ";
				    cin>>price;
				    cout<<"\n Enter rating ";
				    cin>>rating;
					book b(bid,bname,aname,price,rating);
					cout<<"\nEnter pos";
					cin>>pos;
					lt.insertPos(b,pos);
			    }
				break;
			
			case 2:
				{
					int pos;
					cout<<"\nEnter position";
					cin>>pos;
					lt.deletePos(pos);
				}
				break;
			
			case 3:
				lt.display();
			    break;
			
			case 4:
				    int id;
					cout<<"\n Enter book id ";
					cin>>id;
					lt.updateBook(id);
					break;
			case 6:				 
                  
				    lt.top3Book();
			        break;
			        
			case 7:
			       lt.deleteLL();
				   break;   
			case 8:
			       lt.search();
				   break;	        
			case 5:
				
				
				cout<<"thank you";
				
		        break;
				
				
	}

	
}
return 0;
}

