#include<iostream>
using namespace std;
template<typename T>
class Max_class{
	private:
	int n;
	T* arr;
	public:
		Max_class(int n1);
		~Max_class();
		void Enter_data();
		void display_data();
		void max_number();
};
//Parameterized Constructor
template<typename T>
Max_class<T>::Max_class(int n1){
	n=n1;
	arr=new T[n];
	for(int i=0;i<n;i++){
		arr[i]=0;
	}
}
//Destructor
template<typename T>
Max_class<T>::~Max_class(){
	delete[] arr;
	cout<<"Destructor:"<<endl;
}
template<typename T>
void Max_class<T>::Enter_data(){
	cout<<"Enter Array:\n";
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]: ";
		cin>>arr[i];
	}	
}

template<typename T>
void Max_class<T>::display_data(){
	cout<<"{ ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" , ";
	}
	cout<<"}\n";
}

template< typename T>
void Max_class<T>::max_number(){
	T maxnum=arr[0];
	for(int i=0;i<n;i++){
	if(maxnum<arr[i]){
		maxnum=arr[i];
	}
}
	cout<<"Maximum Number is:"<<maxnum<<endl;
}
int main(){
	int size1;
	cout<<"Enter size of array:";
	cin>>size1;
		Max_class<int> a1(size1);
		Max_class<double> b1(size1);
		cout<<"===(int Array)===\n";
		a1.Enter_data();
		a1.display_data();
		a1.max_number();
		cout<<"===(double Array)===\n";
      b1.Enter_data();
      b1.display_data();
      b1.max_number();
      return 0;
}
