#include"book.h"
#include<iostream>
#include<string.h>
using namespace std;
book::book(){
	 book_id=0;
	 strcpy(book_name,"not given");
	 strcpy(author_name,"not given");
	 price = 0;
	 rating = 0;
}
book::book(int i, char* bn, char *an,double p,double r){
	book_id=i;
//   this->book_id=i;
//   cout<<"id "<< this->book_id;
	strcpy(book_name,bn);
	strcpy(author_name,an);
	price = p;
	rating = r;
}
void book::setBid(int i){
	book_id=i;
}
int book::getBid(){
	return book_id;
}
void book::setBName(char* bn ){
	strcpy(book_name,bn);
}
char* book::getBName(){
	return book_name;
}
void book::setAuthor(char* an){
	strcpy(author_name,an);
}
char* book::getAuthor(){
	return author_name;
}
void book::setPrice(double p){
	price=p;
}
double book::getPrice(){
	return price;
}
void book::setRating(double r){
	rating=r;
}
double book::getRating(){
	return rating;
}
void book::display(){

	cout<<" book id "<<book_id;
	cout<<" book name "<<book_name;
	cout<<" author name "<<author_name;
	cout<<" price "<<price;
	cout<<" rating "<< rating;
	cout<<"\n";
}
void operator<<(ostream &o,book &b)
{
	b.display();
}
