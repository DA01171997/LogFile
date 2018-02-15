#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <time.h>
#include <algorithm>
using namespace std;
class myLog {

public:
	myLog() { errorNumber = 0; }
	myLog(string name) :name(name) {
		errorNumber = 0;
	}
	~myLog() { closeMylog(); }

	bool openFile(string name) {
		this->name = name;
		try {
			logFile.open(name.c_str());
			if (!logFile) {
				throw std::runtime_error("* " + name + " *CAN'T OPEN INFILE OR INFILE DOESN'T EXISTS");
			}
			else {
				std::cout << "* " << name << " * INPUT MYLOG IS OPENED" << std::endl;
				logFile << "Line\t" << "Time\t\t" << "Date\t\t" << "FunctionName\t" << "Type\t" << "Description\n";
				openConfig();
				return true;
			}
		}
		catch (std::runtime_error &e) {
			std::cout << e.what() << std::endl;
			return false;
		}
	}
	bool openConfig() {

		try {
			configFile.open("config.txt");
			if (!configFile) {
				throw std::runtime_error(" *CAN'T OPEN configFile OR configFile DOESN'T EXISTS");
			}
			else {
				std::cout << "* configFile IS OPENED" << std::endl;
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
	void writeLine(int LineNumber, string functionName) {						//write to log
		logFile << LineNumber << "\t" << __TIME__ << "\t" << __DATE__ << "\t\t" << functionName << "() \t\t" << getType(errorNumber) << endl;
		fflush(stdout);
	}
	void readLine(int number) {						//print line, given line number
		string line;
		logFile.seekg(0, logFile.beg);					//jump to beginning
		for (int i = 0; i < number; i++) {				//loop through lines until number
			getline(logFile, line);
		}
		cout << line << endl;							//print line
	}
	void manFlush() {								//manual flush
		fflush(stdout);
	}
	string getType(int number) {
		string line;
		configFile.seekg(0, configFile.beg);
		for (int i = 0; i < number + 2; i++) {
			getline(configFile, line);
		}
		return line;
	}
	void setErrNumber(int i) {
		errorNumber = i;
	}
private:
	string name;
	int errorNumber;
	fstream logFile;
	fstream configFile;
};

void printASD(myLog &a) {
	cout << "ASD ";
	a.writeLine(__LINE__, __func__);
}
void failFunc(myLog &a) {
	cout << "This function should fail" << endl;
	a.setErrNumber(1);
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

	//system("pause");
}