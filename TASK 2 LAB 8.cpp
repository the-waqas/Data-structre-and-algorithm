#include<iostream>
using namespace std;
class node{
	public:
string n;
int token;
node* next;
};
class queueLL{
public:
node *f,*r;
queueLL(){f=r=NULL;}
bool empty(){return f==NULL;}
void enq(string nm,int tk){
node* t=new node();
t->n=nm;
t->token=tk;
t->next=NULL;
if(empty()){
f=r=t;
}
else{
r->next=t;
r=t;}
}
void deq(){
if(empty()){cout<<"Queue empty\n";return;}
node* t=f;
cout<<"Serving:"<<t->n
<<" Token:"<<t->token<<"\n";
f=f->next;
if(f==NULL)r=NULL;
delete t;
}
void show(){
if(empty()){cout<<"Empty\n";return;}
node* t=f;
int c=0;
while(t!=NULL){
cout<<"===(REQUEST "<<(++c)<<")====\n";
cout<<"Name:"<<t->n<<endl;
cout<<"Token:"<<t->token<<endl;
t=t->next;
}}};
int main(){
queueLL premium,standard;
int ch,tk;
string nm;
do{
system("cls");
cout<<"====(Main Menu)====\n";
cout<<"1.Add Premium (ENQUEUE)\n";
cout<<"2.Add Standard (ENQUEUE)\n";
cout<<"3.Serve Next (DEQUEUE)\n";
cout<<"4.Display\n";
cout<<"5.Exit\n";
cout<<"Enter choice:";
cin>>ch;
if(ch==1){
cout<<"Name:";cin>>nm;
cout<<"Token:";cin>>tk;
premium.enq(nm,tk);
}
else if(ch==2){
cout<<"Name:";cin>>nm;
cout<<"Token:";cin>>tk;
standard.enq(nm,tk);
}
else if(ch==3){
cout<<"----Serving Request----\n";
if(!premium.empty()){
premium.deq();
}
else if(!standard.empty()){
standard.deq();
}
else{
cout<<"No pending requests.\n";
}
system("pause");
}
else if(ch==4){
cout<<"\n----Premium Queue----\n";
premium.show();
cout<<"\n----Standard Queue----\n";
standard.show();
cout<<endl;
system("pause");
}
else if(ch!=5){
cout<<"Invalid\n";
system("pause");}
}while(ch!=5);
return 0;
}
