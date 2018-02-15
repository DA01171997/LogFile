#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printASD(fstream a){
	cout<< "ASD" << endl;
	a.writeLine(__LINE__, __func__, "function prints ASD");
}

int main(){
	cout<< "Checking openFile()" <<endl;
	myLog successLog = new myLog("Text.txt");
	myLog failLog = new myLog("DoesntExist.txt");
	
	cout<< endl << "Checking write using test function, ignore the ASD" << endl;
	printASD(successLog);
	
	system("pause");
}