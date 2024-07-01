time_tests.exe : time_tests.o Time.o
	g++ -g time_tests.o Time.o -o time_tests.exe

time_tests.o : time_tests.cpp Time.h
	g++ -g -c -Wall -Wextra -pedantic -fdiagnostics-color=always time_tests.cpp

Time.o : Time.cpp Time.h
	g++ -g -c -Wall -Wextra -pedantic -fdiagnostics-color=always Time.cpp


clean:
	rm *.exe *.o

