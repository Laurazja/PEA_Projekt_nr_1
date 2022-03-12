#include<iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;

/*Klasa sluzaca do pomiaru czasu wykonywania algorytmu*/
class MeasureTime
{
public:
	high_resolution_clock::time_point startTime;
	high_resolution_clock::time_point stopTime;

	MeasureTime();
	~MeasureTime();

	void start();
	void stop();
	long long int totalTime();

};