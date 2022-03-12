#include "MeasureTime.h"

MeasureTime::MeasureTime() {

}

MeasureTime::~MeasureTime() {

}

void MeasureTime::start() {

	startTime = high_resolution_clock::now();

}

void MeasureTime::stop() {

	stopTime = high_resolution_clock::now();

}

long long int MeasureTime::totalTime() {

	long long time = duration_cast<microseconds>(MeasureTime::stopTime - MeasureTime::startTime).count();
	return time;
}
