#include<iostream>
using namespace std;
class Rectangle{
	private:
		float Length;
		float Width;
		public:
			void setDimension(float,float);
			float get_Area();
};
void Rectangle::setDimension(float l,float w){
	this->Length=l;
	this->Width=w;
}
float Rectangle::get_Area(){
	return Length*Width;
}
main(){
	Rectangle r1;
	float q1,q2;
	cout<<"==(Rectangle)==\n";
	cout<<"Enter Length:";cin>>q1;
	cout<<"Enter Width:";cin>>q2;
	r1.setDimension(q1,q2);
	cout<<"Area: "<<r1.get_Area()<<"m^2\n";
	return 0;
}
