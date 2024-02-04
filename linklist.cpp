#include"linklist.h"
template <class T>
LinkedList<T>::LinkedList()
{
	book b;
	ifstream in("object.bin",ios_base::binary);
	start=NULL;
	while(in.read((char *)&b,sizeof(b)))
	{
		//Node<T> *temp= new Node(b);
		insertPos(b,1);
	}
}
template<class T>
void LinkedList<T>::display()
{
	if(start == NULL)
	{
		cout<<"\nNo nodes to display";
		return;
	}
	else
	{
		Node<T> *p=start;
	
		while(p!=NULL)
		{
			//p->getData() is an object
			
			cout<<p->getData();
			
//			cout<<" \n"; //cout<<e1
			//p->getData().display();
			p=p->getNext();
//			cout<<" \n";
		}
	}
}
/////////////////////////////////
template <class T>
void LinkedList<T>::insertPos(book &data,int pos)
{
//	Node *temp = new Node(data);
    Node<T>* temp = new Node<T>(data);
	if(start == NULL)
	{
		start = temp;
		return;
	}
	//Insert at beginning
	if(pos == 1)
	{
		temp->setNext(start);
		start = temp;
		return;
	}
	int i=1;
	Node<T> *p=start;
    
	while(i<pos-1 && p->getNext()!=NULL)
	{
		p=p->getNext();
		i++;
	}
	temp->setNext(p->getNext());
	p->setNext(temp);
}
///////////////////////////////////////
template <class T>
void LinkedList<T>::deletePos(int pos)
{
	if(start == NULL)
	{
		cout<<"\nNo nodes to delete";
		return;
	}
//	Node *p=start;
    Node<T> *p=start;
	if(pos == 1) //Delete from beg
	{
		start = start->getNext();
		p->getData().display();
		cout<<"\nDeleted..";
		delete p;
		return;
	}
	int i=1;
	while(i<pos-1 && p->getNext()!=NULL)
	{
		p=p->getNext();
		i++;
	}
	if(i==pos-1 && p->getNext()!=NULL)
	{
//		Node *q = p->getNext();
        Node<T> *q = p->getNext();
		p->setNext(q->getNext());
		q->getData().display();
		cout<<"\n is deleted";
		delete q;
		return;
	}
	else
	{
		cout<<"\nInvalid positon";
	}
}
//////////////////////////
//template <class T>
//LinkedList<T>::~LinkedList()
//{
//	ofstream out("bookData.dat",ios_base::binary);
//	while(start!=NULL)
//	{
//		Node<T> *p=start;
//		out.write((char *)(&(p->getData())),sizeof(p->getData()));
//		start=start->getNext();
//		delete p;
//	}	
//	out.close();
//}
////////////////////////////////////
template<class T>
void LinkedList<T>::updateBook(int id)
{
	if(start == NULL)
	{
		cout<<"\nNo nodes to update";
		return;
	}
	else
	{
		Node<T> *p=start;
        
		bool found=false;
		int choice;
		while(p!=NULL)
		{
			if(id == p->getData().getBid())
			{
				found = true;
				book &b = p->getData();
				cout<<"\n Book Found";
//				cout<<"\nEnter new book name";
//				char name[20];
//				cin>>name;
           
                cout<<"\n\t1.update price";
                cout<<"\n\t2.update rating";
                cout<<"\n Enter choice";
                cin>>choice;
                if(choice==1){
                	cout<<"\nEnter new price ";
				    double price;
				    cin>>price;
				    b.setPrice(price);
				}
				if(choice==2){
					double rating;
				    cout<<"\n Enter new rating ";
				    cin>>rating;
				    b.setRating(rating);
				}
				
				
				
				
			
			}
			p=p->getNext();
		}
	   if (found == false)
	   {
	   	cout<<"\nBook not found";
	   }
	
	}

}
template<class T>
void LinkedList<T>::search()
{
	int choice;
	cout<<"\n\t 1.search by id \n\t 2.search by book name \n\t 3.search by author name ";
	cout<<"\n enter choice ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			searchId();
			break;
		case 2:
			  searchBn();
		      break;
		case 3:
			  searchAn();
		      break;	  	
	}
	
}
template <class T>
void LinkedList<T>::searchId()
{
	int id;
	cout<<"enter id to search book";
	cin>>id;
		if(start == NULL)
	{
		cout<<"\nNo nodes to search";
		return;
	}
	else
	{
//		Node *p=start;
        Node<T> *p =start;
		bool found=false;
		int choice;
		while(p!=NULL)
		{
			if(id == p->getData().getBid())
			{
				found = true;
				cout<<" book is available details are below ";
				cout<<"\n";
				p->getData().display();
	        }
	        p=p->getNext();
	    }

		if(found==false)
		{
			cout<<"\n book is not available";
		}
	    
	
}
}
////////////////////////////////////
template <class T>
void LinkedList<T>::searchBn()
{

	char nm[20];
	cout<<"enter book name to search book ";
	fflush(stdin);
	gets(nm);
	if(start == NULL)
	{
		cout<<"\nNo nodes to search";
		return;
	}
	else{
		Node<T> *p=start;
        
		bool found=false;
		int count=0;
		
		int position;
		while(p!=NULL)        // p!=NULL
		{
		
			if(strcmp(p->getData().getBName(),nm)==0)
			{
				found = true;
                cout<<"book is available details are below";
                cout<<"\n";
                p->getData().display();
			}
			p=p->getNext();
        }
		if(found==false)
		{
			cout<<" book is not available ";
		  }  
    } 


}
template<class T>
void LinkedList<T>::searchAn()
{
	
	char an[20];
	cout<<"enter author name to search book ";
	fflush(stdin);
	gets(an);
	if(start == NULL)
	{
		cout<<"\nNo nodes to search";
		return;
	}
	else{
		Node<T> *p=start;
        
		bool found=false;
		int count=0;
		
		int position;
		while(p!=NULL)        // p!=NULL
		{
		
			if(strcmp(p->getData().getAuthor(),an)==0)
			{
				found = true;
                cout<<"book is available details are below";
                cout<<"\n";
                p->getData().display();
			}
			p=p->getNext();
        }
		if(found==false)
		{
			cout<<" book is not available ";
		  }  
    } 

	
}
template <class T>
void LinkedList<T>::deleteLL()
{
	int choice;
	cout<<"\n\t1. delete by using id \n\t2.delete by using book name \n\t3.delete by using author name ";
	cout<<"\n Enter choice ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			   deleteid();
			   break;
		case 2:
		       deletebknm();
			   break;	
		case 3:
		       deletebkan();
			   break;	   
			
	}
}
template<class T>
void LinkedList<T>::deleteid()
{

//{
	int id;
	cout<<"\n enter id to delete book ";
	cin>>id;
//	if(start == NULL)
//	{
//		cout<<"\nNo nodes to delete";
//		return;
//	}
//	else{
//		Node<T> *p=start;
//        
//		bool found=false;
//		int count=0;
//		
//		int position;
//		while(p!=NULL)        // p!=NULL
//		{
//			count++;
//			if(id == p->getData().getBid())
//			{
//				found = true;
//				position = count;
////				break;
//			}
//			p=p->getNext();
//        }       
//if(found==true)
//{
//	cout<<" deleting ...";
//	deletePos(position);
//}
//
//if(found==false)
//{
//	cout<<" book id not found ";
//	
//}
//
//}
bool found=false;
if(start == NULL)
	{
		cout<<"\nNo nodes to delete";
		return;
	}
 Node<T> *p= start;
 if(p->getData().getBid()== id)
 {
 	found=true;
 	start = p->getNext();
 	delete p;
 	return;
 }
 while(p->getNext()!=NULL)
 {
 	Node<T> *q=p->getNext();
 	if(q->getData().getBid()==id)
 	{
 		found=true;
 		p->setNext(q->getNext());
 		
 		delete q;
 		cout<<"\ndeleted";
 		return;
	 }
 }
 if(found==false){
 	cout<<" id not matched";
 }
}
template<class T>
void LinkedList<T>::deletebknm()
{
	char nm[20];
	cout<<"enter book name to delete book ";
	fflush(stdin);
	gets(nm);
	
//	else{
//		Node<T> *p=start;
//      
//		bool found=false;
//		int count=0;
//		
//		int position;
//		while(p!=NULL)        // p!=NULL
//		{
//			count++;
//			if(strcmp(p->getData().getBName(),nm)==0)
//			{
//				found = true;
//				position = count;
////				break;
//			}
//			p=p->getNext();
//        }       
//if(found==true)
//{
//	cout<<" deleting ...";
//	deletePos(position);
//}
//
//if(found==false)
//{
//	cout<<" book name not found ";
//	
//}
//
//}

/////////////////////////////////////////
bool found=false;
if(start == NULL)
	{
		cout<<"\nNo nodes to delete";
		return;
	}
 Node<T> *p= start;
 if(strcmp(p->getData().getBName(),nm)==0)
 {
 	found=true;
 	start = p->getNext();
 	cout<<"\n deleted";
 	delete p;
 	return;
 }
 while(p->getNext()!=NULL)
 {
 	Node<T> *q=p->getNext();
    if(strcmp(q->getData().getBName(),nm)==0)
 	{
 		found=true;
 		p->setNext(q->getNext());
 		
 		delete q;
 		cout<<"\ndeleted";
 		return;
	 }
 }
 if(found==false)
 {
 	cout<<" book name not found "; 
 }
}

template<class T>
void LinkedList<T>::deletebkan()
{
	char nm[20];
	cout<<"enter author name to delete book ";
	fflush(stdin);
	gets(nm);
	if(start == NULL)
	{
		cout<<"\nNo nodes to delete";
		return;
	}
	else{
    	Node<T> *p=start;
      
		bool found=false;
		int count=0;
		
		int position;
		while(p!=NULL)        // p!=NULL
		{
			count++;
			if(strcmp(p->getData().getAuthor(),nm)==0)
			{
				found = true;
				position = count;
//				break;
			}
			p=p->getNext();
        }       
if(found==true)
{
	cout<<" deleting ...";
	deletePos(position);
}

if(found==false)
{
	cout<<" book author not found ";
	
}

}




	
	
}
	
template <class T>
void LinkedList<T>::top3Book(){
	int choice;
	cout<<"\n\t 1.top3 by price";
	cout<<"\n\t 2.top3 by rating";
	cout<<"\n\tenter choice";
	cin>>choice;
	switch(choice)
	{
	
	 case 1:
		cout<<"\n----top3 by price-----";
		top3PriceBooks();
		break;
	
	 case 2:
	    cout<<"\n----top3 by rating------";
		top3Rating();
		break;
		
	
	
	
    }
}
template<class T>
void LinkedList<T>::top3PriceBooks(){
	
		
	
					
			int i,j;
	        book temp;
	        if(start==NULL)
	        {
		      cout<<"\n linkedlist is empty";
		      return;
	        }
	       else
	       {
		        LinkedList lt2;
		        Node<T> *p = start;
                
		        for(i=1;p!=NULL;i++)
		        {
			        lt2.insertPos(p->getData(),i);
			        p=p->getNext();
		        }
		        for( Node<T> *p=lt2.start;p->getNext()!=NULL;p=p->getNext())         //Node*
		       {
			       for(Node<T>* q=p->getNext();q!=NULL;q=q->getNext())
			       {
				        if(p->getData().getPrice() < q->getData().getPrice())
				        {
					        temp=p->getData();
					        p->setData(q->getData());
					        q->setData(temp);
					
				        }
			        }
		        }
	     
                i=0;
                p =lt2.start;
               while(i<3)
               {
     	          p->getData().display();
	              p=p->getNext();
	              i++;
	
               }

           }
}
	

	          


template<class T>
void LinkedList<T>::top3Rating()
{
	int i,j;
	book temp;
	if(start==NULL)
	{
		cout<<"\n linkedlist is empty";
		return;
	}
	else
	{
		LinkedList lt2;
		Node<T>* p = start;
		for(i=1;p!=NULL;i++)
		{
			lt2.insertPos(p->getData(),i);
			p=p->getNext();
		}
		for(Node<T>* p=lt2.start;p->getNext()!=NULL;p=p->getNext())
		{
			for(Node<T>* q=p->getNext();q!=NULL;q=q->getNext())
			{
				if(p->getData().getRating() < q->getData().getRating())
				
				{
					temp=p->getData();
					p->setData(q->getData());
					q->setData(temp);
					
				}
			}
		}
	     
         i=0;
         p =lt2.start;
         while(i<3)
         {
     	   p->getData().display();
	       p=p->getNext();
	       i++; 
	
         }

    }
}
template<class T>
void LinkedList<T>::readFromFile(const char* fileName)
{
	std::ifstream inFile(fileName,std::ios::binary);
	if(!inFile){
		std::cout<<"Error opening file for reading ."<<std::endl;
		return;
	}
	book b;
	while(inFile.read(reinterpret_cast<char*>(&b),sizeof(book)))
	{
		this->insertPos(b,1);
	}
	inFile.close();
	
}
template<class T>
void LinkedList<T>::writeToFile(const char* fileName)
{
	std::ofstream outFile(fileName,std::ios::binary);
	if(!outFile)
	{
		std::cout<<"Error opening file for writing "<<std::endl;
		return ;
	}
	Node<T> *p=start;
	while(p!=NULL)
	{
		outFile.write(reinterpret_cast<char*>(&p->getData()),sizeof(book));
		p= p->getNext();
	}
	outFile.close();
}
template <class T>
LinkedList<T>::~LinkedList()
{	Node<T> *p=start;
//	ofstream out("bookData.dat",ios_base::binary);
	while(start!=NULL)
	{
	//	Node<T> *p=start;
		//out.write((char *)(&(p->getData())),sizeof(p->getData()));
		start=start->getNext();
		delete p;
		p=start;
	}	
	//out.close();
}

