#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <time.h>
#include <algorithm>
using namespace std;

class Log {
private:
	fstream logFile;
	string name;

public:
	Log() {}										//default constructor
	Log(std::string name) :name(name) {}
	~Log() {										//destructor
		logFile.close();
	}
	void openExistingFile(string name) {			//opens existing file given file name
		try {
			logFile.open(name);
			if (!logFile) {
				throw std::runtime_error("* " + name + " *CAN'T OPEN INFILE OR INFILE DOESN'T EXISTS");
			}
			else {
				std::cout << "* " << name << " * INPUT MYLOG IS OPENED" << std::endl;
			}
		}
		catch (std::runtime_error &e) {
			std::cout << e.what() << std::endl;
		}
	}
	void openNewFile(string name) {					//opens new file with name
		logFile.open(name);
	}
	void readLine(int number) {						//print current line
		string line;
		int currentLine = 0;
		logFile.seekg(0, logFile.beg);					//jump to beginning
		for (int i = 0; i < number; i++) {				//loop through lines until number
			currentLine++;
			getline(logFile, line);
		}
		cout << currentLine << ": " << line << endl;
	}
	void readLines(int from, int to) {				//read lines from given numbers. Inclusive
		string line;
		int currentLine = 0;
		logFile.seekg(0, logFile.beg);					//jump to beginning
		for (int i = 0; i < from; i++) {				//loop through lines until number
			currentLine++;
			getline(logFile, line);
		}
		for (int i = currentLine; i <= to; i++) {		//loops from from to to, print lines
			cout << currentLine << ": " << line << endl;
			currentLine++;
			getline(logFile, line);
		}
	}
	void writeToFile(string input, string timeDate) {				//write input at the end of file
		logFile.seekg(0, logFile.end);					//jump to end
		timeDate.erase(remove(timeDate.begin(), timeDate.end(), '\n'), timeDate.end());
		logFile << timeDate << " " << input << endl;						//write
	}
	void flushLog() {
		logFile.flush();
	}
	void closeMyLog() {
		if (logFile.is_open()) {
			logFile.close();
			std::cout << "* " << name << " * LOGFILE IS CLOSED" << std::endl;
		}
		else {
			std::cout << "* " << name << " * MYLOG DIDN'T NOT GET OPENED" << std::endl;
		}
	}
	void setTime() {

	}
};


int main() {
	Log *test = new Log();
	time_t currentTimeDate;
	time(&currentTimeDate);
	test->openExistingFile("Text.txt");

	test->writeToFile("TEST8", ctime(&currentTimeDate));


	//test->readLine(5);


	system("pause");
}