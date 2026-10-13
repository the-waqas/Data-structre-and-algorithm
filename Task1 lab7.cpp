#include<iostream>
using namespace std;
class Car{
public:
int number;
string company;
string service;
Car(){}
Car(int n,string c,string s){
number=n;
company=c;
service=s;
}
};

template<typename T>
class Node{
public:
T data;
Node* next;
Node(T d){
data=d;
next=NULL;
}
};

template<typename T>
class Queue{
private:
Node<T>* front;
Node<T>* rear;
public:
Queue(){
front=NULL;
rear=NULL;
}
void enqueue(T val){
Node<T>* newNode=new Node<T>(val);
if(front==NULL){
front=newNode;
rear=newNode;
}
else{
rear->next=newNode;
rear=newNode;
}
cout<<"Car"<<val.number<<"added.\n";
}
void dequeue(){
if(front==NULL){
cout<<"QueueEmpty!\n";
return;
}
cout<<"Car"<<front->data.number<<"served.\n";
Node<T>* temp=front;
front=front->next;
delete temp;
if(front==NULL)rear=NULL;
}
void display(){
if(front==NULL){
cout<<"QueueEmpty\n";
return;
}
int n=1;
Node<T>* temp=front;
cout<<"Cars:\n";
while(temp!=NULL){
	cout<<"====(CAR "<<(n++)<<")====\n";
cout<<"No:"<<temp->data.number<<endl;
cout<<"Company:"<<temp->data.company<<endl;
cout<<"Service:"<<temp->data.service<<"\n";
cout<<"------------------\n";
temp=temp->next;
}
}
bool isempty(){
return front==NULL;
}
};
int main(){
Queue<Car> q;
int ch,num;
string comp,serv;
while(true){
cout<<"=====(MainMenu)=====\n";
cout<<"1:-Add\n2:-Serve\n";
cout<<"3:-Show\n4:-Exit\nEnter:";
cin>>ch;
if(ch==1){
cout<<"EnterCarNumber:";
cin>>num;
cout<<"EnterCompany:";
cin>>comp;
cout<<"EnterServiceType:";
cin>>serv;
Car c(num,comp,serv);
q.enqueue(c);}
else if(ch==2){
q.dequeue();}
else if(ch==3){
q.display();}
else if(ch==4){
return 0;}
else{
cout<<"Invalid\n";}}}

