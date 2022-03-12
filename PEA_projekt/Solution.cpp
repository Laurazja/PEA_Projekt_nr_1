#include "Solution.h"

Solution::Solution() {
	numberOfCities = 0;
	minCost = INT32_MAX;
	minPath.resize(numberOfCities);
	minCost = INT32_MAX;
	time = 0;
	typeOfsolution = 0;
	
}

Solution::~Solution() {
	
	numberOfCities = 0;
	matrix.clear();
	minPath.clear();
	minCost = 0;
	typeOfsolution = 0;
	time = 0;
}


void Solution::readFromFile(string fileName) {

	fileName = "C:\\Users\\jaski\\Desktop\\" + fileName + ".txt";

	ifstream file;

	file.open(fileName, ios::in);

	if (file.is_open()) {

		file >> numberOfCities;

		if (file.good()) {
			matrix.resize(numberOfCities);

			for (int i = 0; i < numberOfCities; i++) {
				matrix[i].resize(numberOfCities);
			}

			while (!file.eof()) {
				for (int i = 0; i < numberOfCities; i++) {
					for (int j = 0; j < numberOfCities; j++) {
						file >> matrix[i][j];
					}
				}
			}
		}
		else {
			cout << "Blad przy odczycie z pliku" << endl;
		}

		file.close();

	}
	else {
		cout << "Blad przy otwarciu pliku" << endl;
	}

	minPath.clear();
	minCost = 0;
	typeOfsolution = 0;
	time = 0;


}


void Solution::random() {
	cout << endl << "Podaj ilosc miast: ";
	cin >> numberOfCities;
	matrix.resize(numberOfCities);

	for (int i = 0; i < numberOfCities; i++) {
		matrix[i].resize(numberOfCities);
	}

	for (int i = 0; i < numberOfCities; i++) {
		for (int j = 0; j < numberOfCities; j++) {
			if (i != j) {
				matrix[i][j] = rand() % 100;
			}
			else {
				matrix[i][j] = -1;
			}
		}
	}

	minPath.clear();
	minCost = 0;
	typeOfsolution = 0;
	time = 0;
}


void Solution::display() {
	cout << "Ostatnio wprowadzone dane i otrzymane wyniki:" << endl;

	cout << "Liczba miast: " << numberOfCities << endl;

	cout << "Odleglosci miedzy miastami: " << endl << "    ";
	for (int i = 0; i < numberOfCities; i++) {
		if (i < 9) {
			cout << i << "  ";
		}
		else {
			cout << i << " ";
		}
	}

	cout << endl;

	for (int i = 0; i < numberOfCities; i++) {

		if (i < 10) {
			cout << i << "  ";
		}
		else {
			cout << i << " ";
		}
		for (int j = 0; j < numberOfCities; j++) {
			if (matrix[i][j] < 10 && matrix[i][j] != -1) {
				cout << matrix[i][j] << "  ";
			}
			else {
				cout << matrix[i][j] << " ";
			}
		}

		cout << endl;
	}

	if (!minPath.empty()) {

		cout << "Algorytm: ";

		if (typeOfsolution == 'b') {
			cout << "Brute Force";
		}

		if (typeOfsolution == 'p') {
			cout << "Branch and Bound";
		}

		cout << endl << "Sciezka:" << endl;

		cout << minPath[numberOfCities - 1] << " -> ";

		for (int i = 0; i < numberOfCities - 1; i++) {
			cout << minPath[i] << " -> ";
		}

		cout << minPath[numberOfCities - 1] << endl;

		cout << "Minimalny koszt: " << minCost << endl;

		cout << "Czas: " << time << " ms" << endl;

	}
}

