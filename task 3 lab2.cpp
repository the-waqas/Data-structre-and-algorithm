#include<iostream>
using namespace std;
template<typename T>
class Most_class{
private:
T* arr;
int n;
public:
Most_class(int n1);
~Most_class();
void Enter_Data();
void Display_Data();
void repeated_var(); 
};
template<typename T>
Most_class<T>::Most_class(int n1){
    n=n1;
    arr=new T[n];
    for(int i=0;i<n;i++){
        arr[i]=0;
    }
}
template<typename T>
Most_class<T>::~Most_class(){
    delete[] arr;
    cout<<"Destructor\n";
}
template<typename T>
void Most_class<T>::Enter_Data(){
    cout<<"Enter array elements:\n";
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"]: ";
        cin>>arr[i];
    }
}
template<typename T>
void Most_class<T>::Display_Data(){
    cout<<"{";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" , ";
    }
    cout<<"}\n";
}
template<typename T>

void Most_class<T>::repeated_var(){
    int maxcount = 0;
    T most_var = arr[0];

    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>maxcount){
            maxcount=count;
            most_var=arr[i];
        }
    }

    if(maxcount == 1) {
        cout << "All elements are unique. No repetition found.\n";
    } else {
        cout << "Most Occurred element is: " << most_var << endl;
        cout << "It appears " << maxcount << " times in given array.\n";
    }
}

int main(){
int size;
cout<<"Enter size of arrays:";
cin>>size;
Most_class<int> m1(size);
Most_class<double> m2(size);
cout<<"===(Int array)===\n";
m1.Enter_Data();
m1.Display_Data();
m1.repeated_var();
cout<<"===(double array)===\n";
m2.Enter_Data();
m2.Display_Data();
m2.repeated_var();

system("pause");
return 0;
}
