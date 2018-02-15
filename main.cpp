#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class myLog {

public:
	myLog() {}
	myLog(string name) :name(name){}
	~myLog() {}
	
	bool openExistingFile(string name) {
		fstream logFile;
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
private:
	string name;
	fstream logFile;	
};

int main () {
	myLog a;
	a.openExistingFile("Txt.txt");
}
