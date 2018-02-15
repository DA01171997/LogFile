#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <time.h>
#include <algorithm>
using namespace std;
class myLog {

public:
	myLog() {}
	myLog(string name) :name(name){}
	~myLog() {closeMylog();}
	
	bool openFile(string name) {
		this ->name = name;
		try {
			logFile.open(name.c_str());
			if(!logFile) {
				throw std::runtime_error("* "+ name +" *CAN'T OPEN INFILE OR INFILE DOESN'T EXISTS");
			}
			else {
				std::cout << "* "<<name << " * INPUT MYLOG IS OPENED" << std::endl;
				return true;
			}
		}
		catch (std::runtime_error &e) {
			std::cout << e.what() << std::endl;
			return false;
		}
	}
	void closeMylog() {
		if (logFile.is_open()) {
			logFile.close();
			std::cout << "* " << name << " * MYLOG IS CLOSED" << std::endl;
		}
		else {
			std::cout << "* " << name << " * MYLOG DIDN'T NOT GET OPENED" << std::endl;
		}
	}
	void writeLine(int LineNumber, string functionName, string input) {
		logFile << __func__ << " " << __TIME__ << " " << __DATE__ << " " << input << endl;
		fflush(stdout);
	}
private:
	string name;
	fstream logFile;	
};

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