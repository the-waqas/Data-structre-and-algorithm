#include<iostream>
using namespace std;
template<typename T>
class node{
public:
T data;
node* next;
node(T val){
data=val;
next=NULL;}	};
template<typename T>
class link_list{
private:
node<T>* head;
public:
link_list(){
head=NULL;}
void add_list(int val);	};
template<typename T>
void link_list<T>::add_list(int val){
int choice;
node<T>* newnode=new node<T>(val);
cout<<"1: Insert at Head:\n";
cout<<"2: Insert at tail:\n";
cout<<"Enter you choice:";cin>>choice;
switch(choice){
case 1:
newnode->next=head;
head=newnode;
cout<<"List has been Added at Head\n"<<
"List: "<<newnode->data<<endl;
break;
case 2:	
if(head==NULL){
head=newnode;
cout<<"This list Has been added as Head:\n"
<<"List: "<<newnode->data<<endl;}
else{node<T>* temp=head;
while(temp->next!=NULL){
temp=temp->next;}
temp->next=newnode;
cout<<"List has been added:\n"<<
":List: "<<newnode->data<<endl;	}
		break;
		default:
			cout<<"This choice doesn't exist:\n";}	}
int main(){
cout<<"===(Integer List)===\n";
link_list<int> l1;
l1.add_list(10);
l1.add_list(20);
l1.add_list(30);
//Char List
cout<<"===(Char List)===\n";
link_list<char> l2;
l2.add_list('a');
l2.add_list('b');
l2.add_list('c');}
