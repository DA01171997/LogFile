default: testmyLog.exe

myLog.o: myLog.h myLog.cpp
	g++ -c myLog.cpp
testmyLog.o: testmyLog.cpp myLog.o
	g++ -c testmyLog.cpp
testmyLog.exe: testmyLog.o myLog.o
	g++ testmyLog.o myLog.o -o testmyLog.exe
clean:
	rm *.o *.exe

