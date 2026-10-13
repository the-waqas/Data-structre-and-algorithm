#include<iostream>
#include<cstdlib>
using namespace std;
template<typename T>
class node{
public:
T data;
node<T>* next;
node(T val){data=val;next=NULL;}
};
template<typename T>
class link_list{
private:
node<T>* head;
public:
link_list(){head=NULL;}
void add_list(T val){
node<T>* newnode=new node<T>(val);
if(head==NULL){head=newnode;}
else{
node<T>* temp=head;
while(temp->next!=NULL){temp=temp->next;}
temp->next=newnode;
}}
void display_list(){
if(head==NULL){cout<<"List is empty.\n";}
else{
node<T>* temp=head;
cout<<"\n===(Link_List)===\n";
while(temp!=NULL){
cout<<"|"<<temp->data<<"|->";
temp=temp->next;
}
cout<<"NULL\n";
}}
bool exists(T val){
node<T>* temp=head;
while(temp!=NULL){
if(temp->data==val){return true;}
temp=temp->next;
}
return false;
}};
int main(){
link_list<int> l1;
cout<<"---Testing Integer List (l1)\n";
l1.add_list(10);
l1.add_list(20);
l1.add_list(30);
l1.display_list();
int search_val_1=20;
cout<<"Does"<<search_val_1<<"exist?"<<
(l1.exists(search_val_1)?"Yes":"No")<<endl;
int search_val_2=50;
cout<<"Does"<<search_val_2<<"exist?"
<<(l1.exists(search_val_2)?"Yes":"No")<<endl;
link_list<char> l2;
cout<<"\n---Testing Character List (l2)\n";
l2.add_list('a');
l2.add_list('b');
l2.add_list('c');
l2.display_list();
char search_char_1='b';
cout<<"Does'"<<search_char_1<<"'exist?"
<<(l2.exists(search_char_1)?"Yes":"No")<<endl;
char search_char_2='z';
cout<<"Does'"<<search_char_2<<"'exist?"
<<(l2.exists(search_char_2)?"Yes":"No")<<endl;}

