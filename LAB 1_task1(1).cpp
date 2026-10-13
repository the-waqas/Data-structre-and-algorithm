#include<iostream>
using namespace std;
class Book{
	private:
		string Title;
		int Pages;
		public:
			Book(string,int);
			void showinfo();
};
//Parameterized Constructor
Book::Book(string t,int p){
	Title =t;
	Pages=p;}
	void Book::showinfo(){
		cout<<"Book's Title"<<Title<<endl;
		cout<<"Book's Pages"<<Pages<<endl;
	}
	int main(){
		Book b("Python",210);
		b.showinfo();
	}
