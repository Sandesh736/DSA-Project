#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class book{
	int book_id;
	char book_name[20];
	char author_name[20];
	double price;
	double rating;

public:
book();
book(int,  char*, char*,double,double);
void setBid(int);
int getBid();
void setBName(char*);
char* getBName();
void setAuthor(char*);
char *getAuthor();
void setPrice(double);
double getPrice();
void setRating(double);
double getRating();
void display();
};
void operator<<(ostream &,book &);

