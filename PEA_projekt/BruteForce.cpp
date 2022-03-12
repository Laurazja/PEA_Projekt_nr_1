#include "BruteForce.h"

BruteForce::BruteForce(Solution solution) {
	matrix = solution.matrix;
	numberOfCities = solution.numberOfCities;
	path.resize(solution.numberOfCities);
	costOfPath = INT32_MAX;
}

BruteForce::~BruteForce() {
	costOfPath = 0;
	path.clear();
}


void BruteForce::permutation(vector<int> currentPath, int beginning, int ending) {

	int city = 0;

	if (beginning == ending) {
		int currentCost = 0;
		int currentCity = city;

		for (int i = 0; i < numberOfCities - 1; i++) {
			currentCost += matrix[currentCity][currentPath[i]];
			currentCity = currentPath[i];
		}

		currentCost += matrix[currentCity][city];

		if (costOfPath > currentCost) {
			costOfPath = currentCost;
			path = currentPath;
		}
	}
	else {
		int buffor;
		for (int i = beginning; i < ending; i++) {
			buffor = currentPath[beginning];
			currentPath[beginning] = currentPath[i];
			currentPath[i] = buffor;
			permutation(currentPath, beginning + 1, ending);
			buffor = currentPath[beginning];
			currentPath[beginning] = currentPath[i];
			currentPath[i] = buffor;
		}
	}
}


void BruteForce::bruteForceSolution() {

	vector<int> currentPath;

	for (int i = 0; i < numberOfCities - 1; i++) {
		currentPath.push_back(i + 1);

	}
	path.resize(currentPath.size());
	permutation(currentPath, 0, numberOfCities - 1);

	path.push_back(0);
}
