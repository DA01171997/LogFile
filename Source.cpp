#include <iostream>
#include <string>
#include <fstream>
#include <istream>
using namespace std;

class Log {
private:
	fstream logFile;
public: 
	Log(){}
	~Log() {										//destructor
		logFile.close();
	}
	void openExistingFile(string name) {			//opens existing file given file name
		//test if file is here
		logFile.open(name);
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
		cout << currentLine<< ": "<<line<<endl;
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
	void writeToFile(string input, string date, string time) {				//write input at the end of file
		logFile.seekg(0, logFile.end);					//jump to end
		logFile << date<<" "<<time<< " "<< input << endl;						//write
	}
	void flushLog() {
		logFile.flush();
	}
};


int main() {
	Log *test = new Log();
	test->openExistingFile("Text.txt");
	test->writeToFile("TEST8", "2/13/2018", "5:23");
	

	//test->readLine(5);


	system("pause");
}