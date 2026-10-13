#include <iostream>
#include <string> // Added to use string class
using namespace std;

class CPU {
private:
	string model;
	float memory;
public:
	// Parameterized Constructor
	CPU(string, float);
	void showspeed();
};

CPU::CPU(string m, float o) {
	this->model = m;
	this->memory = o;
}

void CPU::showspeed() {
	cout << "Memory: " << memory << "GB" << endl;
	cout << "Model: " << model << endl; // Corrected "GB" to be just on memory line
}

class Computer {
private:
	int Ram;
public:
	CPU c1;
	// Initializer List
	Computer(int ram, string model, float memory) :
		Ram(ram), c1(model, memory) {}
	void specs();
};

void Computer::specs() {
	cout << "===(Computer Specs)====\n";
	c1.showspeed();
	cout << "Ram: " << Ram << "GB" << endl;
}

int main() { // Corrected "Main" to "int main()"
	Computer a1(8, "Lenovo", 500);
	a1.specs();
	return 0; // Added return statement
}
