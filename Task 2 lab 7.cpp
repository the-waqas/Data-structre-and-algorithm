#include<iostream>
#include<string>
using namespace std;
class Passenger{
public:
string name;
string passport;
string seat;
Passenger(){}
Passenger(string n,string p,string s){
name=n;
passport=p;
seat=s;}
};
template<typename T>
class Node{
public:
T data;
Node* next;
Node(T d){
data=d;
next=NULL;
}};
template<typename T>
class Queue{
private:
Node<T>* front;
Node<T>* rear;
int count;
public:
Queue(){
front=NULL;
rear=NULL;
count=0;
}
void enqueue(T );
void dequeue();
void display();
bool isempty();
bool search(string pass);
void clear();
int size();
};
template<typename T>
void Queue<T>::enqueue(T val){
Node<T>* n=new Node<T>(val);
if(front==NULL){
front=n;
rear=n;
cout<<"First passenger added:\n";
}
else{
rear->next=n;
rear=n;
cout<<"Passenger added:\n";
}
count++;
cout<<"PassengerAdded.\n";
}
template<typename T>
void Queue<T>::dequeue(){
if(front==NULL){
cout<<"QueueEmpty!\n";
return;
}
cout<<"===(Served Pasenger:)===\n"<<endl;
cout<<front->data.name;
cout<<"("<<front->data.passport<<")\n";
Node<T>* t=front;
front=front->next;
delete t;
count--;
if(front==NULL)rear=NULL;
}
template<typename T>
void Queue<T>::display(){
if(front==NULL){
cout<<"QueueEmpty!\n";
return;
}
Node<T>* t=front;
cout<<"-----PassengerList-----\n";
int n=0;
while(t!=NULL){
cout<<"====(Passenger "<<(++n)<<")====\n";
cout<<"Name:"<<t->data.name<<endl;
cout<<"Passport:"<<t->data.passport<<endl;
cout<<"Seat:"<<t->data.seat<<endl;
t=t->next;
}
}
template<typename T>
bool Queue<T>::isempty(){
return front==NULL;
}
template<typename T>
int Queue<T>::size(){
return count;
}
template<typename T>
bool Queue<T>::search(string pass){
Node<T>* t=front;
while(t!=NULL){
if(t->data.passport==pass){
cout<<"Found:"<<t->data.name
<<" Seat:"<<t->data.seat<<"\n";
return true;
}
t=t->next;
}
cout<<"NotFound!\n";
return false;
}
template<typename T>
void Queue<T>::clear(){
while(!isempty()){
dequeue();}
cout<<"AllCleared.\n";
}

int main(){
Queue<Passenger> business;
Queue<Passenger> economy;
int ch;
string name,passport,seat,cls;
while(true){
cout<<"======Airport Check-In======\n";
cout<<"1:Add Passenger\n";
cout<<"2:Serve Passenger\n";
cout<<"3:Show All\n";
cout<<"4:Search\n";
cout<<"5:Show Counts\n";
cout<<"6:Clear All\n";
cout<<"7:Exit\n";
cout<<"Enter:";
cin>>ch;
if(ch==1){
cout<<"Name:";cin>>name;
cout<<"Passport:";cin>>passport;
cout<<"Seat:";cin>>seat;
cout<<"Class(B/E):";cin>>cls;

Passenger p(name,passport,seat);
if(cls=="B"||cls=="b"){
business.enqueue(p);
cout<<"AddedToBusiness.\n";
}
else{
economy.enqueue(p);
cout<<"AddedToEconomy.\n";
}}
else if(ch==2){
if(!business.isempty()){
business.dequeue();}
else if(!economy.isempty())
{
economy.dequeue();}
else cout<<"NoPassenger!\n";}
else if(ch==3){
cout<<"---BusinessClass---\n";
business.display();
cout<<"---EconomyClass---\n";
economy.display();}
else if(ch==4){
cout<<"EnterPassportToSearch:";
cin>>passport;
if(!business.search(passport)){
economy.search(passport);
}}
else if(ch==5){
cout<<"BusinessCount:"<<business.size()<<endl;;
cout<<"EconomyCount:"<<economy.size()<<endl;
}
else if(ch==6){
business.clear();
economy.clear();
}
else if(ch==7){
return 0;}
else cout<<"Invalid!\n";
}}
