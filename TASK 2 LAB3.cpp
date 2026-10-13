#include<iostream>
using namespace std;
template<typename T>
class node{	
public:
T data;
node* next;
node(T val){
data=val;
next=NULL;}};
template<typename T>
class link_list{
private:
node<T>* head;
public:
link_list(){
head=NULL;}
void add_list(int val){
node<T>* newnode=new node<T>(val);
if(head==NULL){
head=newnode;}
else{
node<T>* temp=head;
while(temp->next!=NULL){
temp=temp->next;}
temp->next=newnode;
cout<<"List has been added:"<<": "<<temp->data<<endl;	}}	
void display_list(){
if(head==NULL){
cout<<"List is empty:\n";}
else{
node<T>* temp=head;
cout<<"===(Link_List)===\n";
while(temp->next!=NULL){
cout<<"|"<<temp->data<<"|";
temp=temp->next;}
cout<<"NULL;";}}};
int main(){
cout<<"===(Integer List)===\n";
link_list<int> l1;
l1.add_list(10);
l1.add_list(20);
l1.add_list(30);
l1.display_list();
cout<<"===(Char List)===\n";
link_list<char> l2;
l2.add_list('a');
l2.add_list('b');
l2.add_list('c');
l2.display_list();
system("pause");}
