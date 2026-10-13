#include<iostream>
using namespace std;
template<typename T>
class Array{
private:
int n;
T *arr;
public:
Array(int);
~Array();
void EnterData();
void display_data();
void average();
};
template<typename T>
Array<T>::Array(int size){
	n=size;
	arr=new T[n];
for(int i=0;i<n;i++){
    arr[i]=0;
}
}
template<typename T>
Array<T>::~Array(){
	delete[] arr;
cout<<"Varibles are Destroyed:";
}
template<typename T>
void Array<T>::EnterData(){
    cout<<"Enter NUmbers of array:\n";
    for(int i=0;i<n;i++){
        cout<<"arr["<<i<<"]:";
        cin>>arr[i];
    }}
template <typename T>
    void Array<T>::display_data(){
    	
    //	system("cls");
        cout<<"Array:\n";
        cout<<"{ ";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" , ";
        }
        cout<<"}";
    }
template< typename T>
void Array<T>::average(){
	double sum=0;
	for(int i=0;i<n;i++){
	sum+=arr[i];	
	}
	double avg=static_cast<double>(sum)/n;
	cout<<"\nSum of Numbers: "<<sum<<endl;
	cout<<"Average of Numbers:"<<avg<<endl;
}
int main(){
	int size1;
    cout<<"Enter size of Array:";
    cin>>size1;
    Array<int> s(size1); //For int array
    Array<double> f1(size1); //For double array
    
    cout<<"===(For integer Array)===\n";
    s.EnterData();
    s.display_data();
    s.average();
    cout<<"===(For double Array)===\n";
    f1.EnterData();
    f1.display_data();
    f1.average();
    
    return 0;}
