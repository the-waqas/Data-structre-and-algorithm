#include<iostream>
using namespace std;
class Account{
	private:
		float Balance;
		public:
			//Paramterized Constructot
			//Declaration
			Account(float);
			//Destructor
			~Account();
			//Function to Take balance fron user
			void Enter_Balance();
			void Display_Balance();
};

//Constructor DEfination
Account::Account(float b1){
	Balance=b1;
}
Account::~Account(){
	cout<<"Destroyed:"<<endl;
}
void Account::Display_Balance(){
	cout<<"Total Balance:"<<Balance<<"$"<<endl;
}
int main(){
	Account* a=new Account(2000);
	a->Display_Balance();
	//Destructor is called when object is destroyed
	delete a;
}
