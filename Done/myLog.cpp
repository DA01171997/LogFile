//File:myLog.cpp
//Author: Duy Do, Jason Lieu
//Git :https://github.com/jasonlieu/LogFile
//Last Edit: 2/15/2018 2:00PM

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <time.h>
#include <algorithm>
#include "myLog.h"
using namespace std;

myLog::myLog() { CodeNumber = 0; }
myLog::myLog(string name) :name(name), CodeNumber(0){}
myLog::~myLog() { closeMylog(); }
bool myLog::openFile(string name) {
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
bool myLog::openConfig() {

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
void myLog::closeMylog() {
		if (logFile.is_open()) {
			logFile.close();
			std::cout << "* " << name << " * MYLOG IS CLOSED" << std::endl;
		}
		else {
			std::cout << "* " << name << " * MYLOG DIDN'T NOT GET OPENED" << std::endl;
		}
	}
void myLog::writeLine(int LineNumber, string functionName) {						//write to log
		logFile << LineNumber << "\t" << __TIME__ << "\t" << __DATE__ << "\t" << functionName << "() \t" << getType(CodeNumber) << endl;
		fflush(stdout);
	}
void myLog::readLine(int number) {						//print line, given line number
		string line;
		logFile.seekg(0, logFile.beg);					//jump to beginning
		for (int i = 0; i < number; i++) {				//loop through lines until number
			getline(logFile, line);
		}
		cout << line << endl;							//print line
	}
void myLog::manFlush() {								//manual flush
		fflush(stdout);
	}
string myLog::getType(int number) {
		string line;
		configFile.seekg(0, configFile.beg);
		for (int i = 0; i < number + 2; i++) {
			getline(configFile, line);
		}
		return line;
	}
void myLog::setCodeNumber(int i) {
		CodeNumber = i;
	}
