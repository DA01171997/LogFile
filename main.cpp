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
	myLog(string name) :name(name) {}
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
				logFile << "Line\t" << "Time\t\t" << "Date\t\t" << "FunctionName\t" << "Description\n";
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
	void writeLine(int LineNumber, string functionName, string input) {						//write to log
		logFile << LineNumber << "\t" << __TIME__ << "\t" << __DATE__ << "\t" << functionName << "() \t" << input << endl;
		fflush(stdout);
	}
	void readLine(int number) {						//print line, given line number
		string line;
		int currentLine = 0;
		logFile.seekg(0, logFile.beg);					//jump to beginning
		for (int i = 0; i < number; i++) {				//loop through lines until number
			currentLine++;
			getline(logFile, line);
		}
		cout << line << endl;							//print line
	}
	void manFlush() {								//manual flush
		fflush(stdout);
	}
private:
	string name;
	fstream logFile;
};

void printASD(myLog &a) {
	cout << "ASD ";
	a.writeLine(__LINE__, __func__, "function prints ASD");
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

	cout << endl << "Checking readLine()" << endl;
	successLog.readLine(1);
	successLog.readLine(2);
	successLog.readLine(3);
	successLog.readLine(4);
	cout << endl;

	system("pause");
}