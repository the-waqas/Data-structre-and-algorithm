#include<iostream>
#include<string>
using namespace std;
struct Node{
char data;
Node*next;};
class Stack{
private:
Node*top;
public:
Stack(){
top=NULL;}
void push(char c){
Node*newNode=new Node();
newNode->data=c;
newNode->next=top;
top=newNode;}
char pop(){
if(top==NULL)return'\0';
char c=top->data;
Node*temp=top;
top=top->next;
delete temp;
return c;}
char peek(){
if(top==NULL)return'\0';
return top->data;}
bool isEmpty(){
return top==NULL;}};
int precedence(char op){
if(op=='^')return 3;
else if(op=='*'||op=='/')return 2;
else if(op=='+'||op=='-')return 1;
else return 0;}
bool isOperand(char c){
return(c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9');}
string infixToPostfix(string infix){
Stack st;
string postfix="";
for(int i=0;i<infix.length();i++){
char c=infix[i];
if(isOperand(c)){
postfix+=c;}
else if(c=='('){
st.push(c);}
else if(c==')'){
while(!st.isEmpty()&&st.peek()!='('){
postfix+=st.pop();}
st.pop();}
else{
while(!st.isEmpty()&&precedence(st.peek())>=precedence(c)){
postfix+=st.pop();}
st.push(c);}}
while(!st.isEmpty()){
postfix+=st.pop();}
return postfix;}
int main(){
string infix;
cout<<"Enter infix expression: ";
cin>>infix;
string postfix=infixToPostfix(infix);
cout<<"Postfix expression: "<<postfix<<endl;
return 0;}
