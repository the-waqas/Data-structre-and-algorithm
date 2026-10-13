#include<iostream>
using namespace std;

struct node{
string n,country,cls;
int id;
node* next;
};

class queueLL{
public:
node *f,*r,*lb;
queueLL(){f=r=lb=NULL;}

bool empty(){return f==NULL;}

void enq(string nm,int i,string ct,string c){
node* t=new node();
t->n=nm;
t->id=i;
t->country=ct;
t->cls=c;
t->next=NULL;

if(empty()){
f=r=t;
if(c=="B")lb=t;
return;
}
if(c=="B"){
if(lb==NULL){
t->next=f;
f=t;
lb=t;}
else{
t->next=lb->next;
lb->next=t;
lb=t;
if(lb->next==NULL)r=lb;
}}
else{
r->next=t;
r=t;
}}
void deq(){
if(empty()){cout<<"queue empty\n";return;}
node* t=f;
cout<<"boarding:"<<t->n<<
" id:"<<t->id<<" "<<
t->country<<"("<<t->cls<<")\n";
f=f->next;
if(t==lb)lb=NULL;
if(f==NULL)r=NULL;
delete t;
}
void show(){
if(empty()){cout<<"empty\n";return;}
node* t=f;
int n=0;
while(t!=NULL){
cout<<"===(PASSENGER "<<(++n)
<<" CLASS: "<<t->cls<<")===="<<endl;
cout<<"Name: "<<t->n<<endl;
cout<<"ID_CARD:"<<t->id<<endl;
cout<<"Country "<<t->country<<endl;
cout<<"CLASS: "<<t->cls<<endl;
t=t->next;
}
cout<<"NULL\n";
}};
int main(){
queueLL q;
int ch,id;
string nm,ct,c;
do{
system("cls");
cout<<"====(Main Menu)====\n";
cout<<"1.Add business:(ENQUEUE)"<<endl;
cout<<"2:Add economy:(ENQUEUE)"<<endl;
cout<<"3:Board next(DEQUEUE):"<<endl;
cout<<"4:Display:"<<endl;
cout<<"5:exit\n";
cout<<"Enter choice:";
cin>>ch;
if(ch==1){
cout<<"name:";cin>>nm;
cout<<"id:";cin>>id;
cout<<"country:";cin>>ct;
q.enq(nm,id,ct,"B");
}
else if(ch==2){
cout<<"name:";cin>>nm;
cout<<"id:";cin>>id;
cout<<"country:";cin>>ct;
q.enq(nm,id,ct,"E");
}
else if(ch==3){
q.deq();
cout<<"Passenger has dequeued successfully:\n";
system("pause");
}
else if(ch==4){
q.show();
system("pause");
}
else if(ch!=5){
cout<<"invalid\n";
system("pause");
}
}while(ch!=5);
return 0;
}
