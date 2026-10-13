#include<iostream>
#include<string>
#include<cctype>
using namespace std;
struct Node{
char data;
Node* next;
};
class Stack{
Node* top;
public:
Stack(){top=NULL;}
void push(char c){
Node* newNode=new Node();
newNode->data=c;
newNode->next=top;
top=newNode;
}
char pop(){
if(top==NULL)return '\0';
char c=top->data;
Node* temp=top;
top=top->next;
delete temp;
return c;
}
char peek(){
if(top==NULL)return '\0';
return top->data;
}
bool isEmpty(){
return top==NULL;
}
};
class IntStack{
struct IntNode{
int data;
IntNode* next;
};
IntNode* top;
public:
IntStack(){top=NULL;}
void push(int val){
IntNode* newNode=new IntNode();
newNode->data=val;
newNode->next=top;
top=newNode;
}
int pop(){
if(top==NULL)return 0;
int val=top->data;
IntNode* temp=top;
top=top->next;
delete temp;
return val;
}
bool isEmpty(){
return top==NULL;
}
};
int precedence(char op){
if(op=='+'||op=='-')return 1;
if(op=='*'||op=='/')return 2;
return 0;
}
int applyOp(int a,int b,char op){
if(op=='+')return a+b;
if(op=='-')return a-b;
if(op=='*')return a*b;
if(op=='/')return a/b;
return 0;
}
string infixToPostfix(string infix){
Stack s;
string postfix="";
for(int i=0;i<infix.length();i++){
char c=infix[i];
if(isdigit(c)){
postfix+=c;
}else if(c=='('){
s.push(c);
}else if(c==')'){
while(!s.isEmpty()&&s.peek()!='('){
postfix+=s.pop();
}
s.pop();
}else{
while(!s.isEmpty()&&precedence(s.peek())>=precedence(c)){
postfix+=s.pop();
}
s.push(c);
}
}
while(!s.isEmpty()){
postfix+=s.pop();
}
return postfix;
}
int evaluatePostfix(string postfix){
IntStack s;
for(int i=0;i<postfix.length();i++){
char c=postfix[i];
if(isdigit(c)){
s.push(c-'0');
}else{
int b=s.pop();
int a=s.pop();
int result=applyOp(a,b,c);
s.push(result);
}
}
return s.pop();
}
int evaluatePrefix(string prefix){
IntStack s;
for(int i=prefix.length()-1;i>=0;i--){
char c=prefix[i];
if(isdigit(c)){
s.push(c-'0');
}else{
int a=s.pop();
int b=s.pop();
int result=applyOp(a,b,c);
s.push(result);
}
}
return s.pop();
}
int evaluateInfix(string infix){
string postfix=infixToPostfix(infix);
return evaluatePostfix(postfix);
}
int main(){
int choice;
string expr;
cout<<"Expression Evaluator\n";
cout<<"1. Evaluate Infix\n";
cout<<"2. Evaluate Prefix\n";
cout<<"3. Evaluate Postfix\n";
cout<<"Enter choice: ";
cin>>choice;
cout<<"Enter expression: ";
cin>>expr;
int result;
if(choice==1){
result=evaluateInfix(expr);
cout<<"Infix Result: "<<result<<endl;
}else if(choice==2){
result=evaluatePrefix(expr);
cout<<"Prefix Result: "<<result<<endl;
}else if(choice==3){
result=evaluatePostfix(expr);
cout<<"Postfix Result: "<<result<<endl;
}else{
cout<<"Invalid choice!"<<endl;
}
return 0;
}
