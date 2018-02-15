//File:testmyLog.cpp
//Author: Duy Do, Jason Lieu
//Last Edit: 2/15/2018 2:00PM
//Git :https://github.com/jasonlieu/LogFile
//Require Files: testmyLog.cpp myLog.h myLog.cpp Test.txt config.txt

#include <iostream>
#include "myLog.h"
using namespace std;

void printASD(myLog &a) {
	cout << "ASD ";
	a.writeLine(__LINE__, __func__);
}
void failFunc(myLog &a) {
	cout << "This function should fail" << endl;
	a.setCodeNumber(1);
	a.writeLine(__LINE__, __func__);
}

int main() {
	cout << "Checking openFile()" << endl;
	myLog successLog("Text.txt");
	successLog.openFile("Text.txt");
	myLog failLog("DoesntExist.txt");

	cout << endl << "Checking write using test function, ignore the ASD" << endl;
	printASD(successLog);
	printASD(successLog);
	printASD(successLog);
	cout << endl << "Text.txt has been updated" << endl;

	cout << endl << "Checking Type with failFunc()" << endl;
	failFunc(successLog);

	cout << endl << "Checking readLine()" << endl;
	successLog.readLine(1);
	successLog.readLine(2);
	successLog.readLine(3);
	successLog.readLine(4);
	successLog.readLine(5);

	cout << endl;
}