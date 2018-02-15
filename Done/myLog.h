//File:myLog.h
//Author: Duy Do, Jason Lieu
//Git :https://github.com/jasonlieu/LogFile
//Last Edit: 2/15/2018 2:00PM

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <time.h>
#include <algorithm>
using namespace std;

#ifndef MYLOG_H
#define	MYLOG_H
class myLog{
public:
	myLog();
	myLog(string name);
	~myLog();
	bool openFile(string name);
	bool openConfig();
	void closeMylog();
	void writeLine(int LineNumber, string functionName);
	void readLine(int number);
	void manFlush();
	string getType(int number);
	void setCodeNumber(int i);
private:
	string name;
	int CodeNumber;
	fstream logFile;
	fstream configFile;
};
#endif