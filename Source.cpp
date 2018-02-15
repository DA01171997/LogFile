#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <time.h>
#include <algorithm>
using namespace std;

fstream openFile(string name) {
	fstream temp;
	temp.open(name);
	return temp;
};
void writeLine(fstream &a,/* int lineNumber, string functionName,*/ string input) {
	//a << lineNumber<<" "<< __TIME__<< " " << __DATE__ << " " << input <<endl;
	a << __func__ << " " << __TIME__ << " " << __DATE__ << " " << input << endl;
	fflush(stdout);
};
string read(fstream &a, int lineNumber) {
	string line;
	int currentLine = 0;
	a.seekg(0, a.beg);					//jump to beginning
	for (int i = 0; i < lineNumber; i++) {				//loop through lines until number
		currentLine++;
		getline(a, line);
	}
	return line;
};

int main() {
	fstream a = openFile("Text.txt");
	writeLine(a, "1");
	writeLine(a, "2");
	writeLine(a, "3");
	cout << read(a, 1) << endl;
	cout << read(a, 2) << endl;
	cout << read(a, 3) << endl;

	int asd = __LINE__;
	string d = __DATE__;
	string t = __TIME__;
	cout << endl << asd << endl << d << endl << t;





	//test->readLine(5);


	system("pause");
}



/*
class1.so
open				can place classes into /usr/local/lib
read				then include them in main program
write
close
flush

class2.so
creates the lines that are passed into class1

*/