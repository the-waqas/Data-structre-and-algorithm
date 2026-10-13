#include<iostream>
using namespace std;
class hardware {
private:
string Body_Material;
float battery_capacity;
string Connectivity;
string storage_Derive;
public:
hardware(string h1, float h2, string h3, string h4) {
this->Body_Material = h1;
this->battery_capacity = h2;
this->Connectivity = h3;
this->storage_Derive = h4;}
// Getters
string getBodyMaterial(){ return Body_Material; }
float getBatteryCapacity(){ return battery_capacity; }
string getConnectivity(){ return Connectivity; }
string getStorageDerive(){ return storage_Derive; }};
class software {
private:
string operating_System;
string Productivity_Software;
string Graphic_Software;
string Utility_Software;
public:
software(string s1, string s2, string s3, string s4) {
this->operating_System=s1;
this->Productivity_Software=s2;
this->Graphic_Software=s3;
this->Utility_Software=s4;}
//Getters
string getOperatingSystem(){return operating_System; }
string getProductivitySoftware(){return Productivity_Software; }
string getGraphicSoftware(){ return Graphic_Software; }
string getUtilitySoftware(){ return Utility_Software; }};
class Devices {
private:
string Device_Name;
string Device_Function;
public:
hardware h1;
software s1;
// Initializer List
Devices(string d1, string d2,
string w1, float w2, string w3, string w4,
string w5, string w6, string w7, string w8)
:h1(w1, w2, w3, w4), s1(w5, w6, w7, w8) {
Device_Name = d1;
Device_Function = d2;}
~Devices(){}
void Device_Display();};
//Function Definition
void Devices::Device_Display() {
cout<<"Device Name: "<<Device_Name<<endl;
cout<<"Device Function: " <<Device_Function<<endl;
cout<<"\n==== (" << Device_Name << "'s Hardware)====\n";
cout<<"Body Material: "<< h1.getBodyMaterial()<<endl;
cout<<"Battery Capacity: "<< h1.getBatteryCapacity()<<endl;
cout<<"Connectivity: " <<h1.getConnectivity()<<endl;
cout<<"Storage Derive: " <<h1.getStorageDerive()<<endl;
cout<<"\n====("<< Device_Name<<"'s Software)====\n";
cout<<"Operating System: " <<s1.getOperatingSystem()<<endl;
cout<<"Productivity Software: "<<s1.getProductivitySoftware()<<endl;
cout<<"Graphic Software: " <<s1.getGraphicSoftware()<<endl;
cout<<"Utility Software: "<<s1.getUtilitySoftware()<<endl;}

// (Classes hardware, software, Devices are same as the fixed version I gave you)
int main() {
Devices d("Samsung Galaxy", "Multimedia",
"Aluminium", 4500, "Bluetooth", "HDD",
"Android", "MS Office", "Adobe Photoshop", "CCleaner");;
// Display device details
d.Device_Display();
cout << "\n";
// Dclare pointer and set it to nullptr
Devices* ptr = nullptr;
//Check if pointer is null
if (ptr == nullptr) {
cout << "Pointer is empty\n"<<endl;}
//Create a stack object
Devices d1("iPhone 17","Communication",
"Titanium", 5000, "Wireless","SSD",
"iOS", "Google Docs", "Nvidia Studio", "Disk Cleanup");
//Assign pointer to object
ptr = &d1;
//Call method through pointer
ptr->Device_Display();
return 0;}


