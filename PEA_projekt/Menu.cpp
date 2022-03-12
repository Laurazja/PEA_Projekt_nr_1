#include "Menu.h"

void Menu::mainMenu() {
	
	char option = 0;
	string fileName = "";

	while (option != 'e') {

		cout << "Wybierz opcje: " << endl
			<< "1. Wczytaj dane z pliku" << endl
			<< "2. Generuj losowe dane" << endl
			<< "3. Rozwiaz przy pomocy Brute Force" << endl
			<< "4. Rozwiaz przy pomocy Branch and Bound" <<endl
			<< "5. Wyswietl ostatnio wczytane dane i rozwiazanie" << endl
			<< "e. Wyjdz" << endl;
		cin >> option;

		switch (option) {
		case '1':
			cout << "Podaj nazwe pliku: ";
			cin >> fileName;
			lastSolution.readFromFile(fileName);
			lastSolution.display();
			break;
		case '2':
			lastSolution.random();
			lastSolution.display();
			break;
		case '3':
			if (!lastSolution.matrix.empty()) {
				BruteForce bruteForce(lastSolution);
				time.start();
				bruteForce.bruteForceSolution();
				time.stop();
				lastSolution.minCost = bruteForce.costOfPath;
				lastSolution.minPath = bruteForce.path;
				lastSolution.typeOfsolution = 'b';
				lastSolution.time = time.totalTime();
				lastSolution.display();
			}
			else {
				cout << "Brak danych do wykonania algorytmu" << endl;
			}
			break;
		case '4':
			if (!lastSolution.matrix.empty()) {
				BranchAndBound bnb(lastSolution);
				time.start();
				bnb.BranchAndBoundSolution();
				time.stop();
				lastSolution.minCost = bnb.minCost;
				lastSolution.minPath = bnb.minPath;
				lastSolution.typeOfsolution = 'p';
				lastSolution.time = time.totalTime();
				lastSolution.display();
			}
			else {
				cout << "Brak danych do wykonania algorytmu" << endl;
			}
			break;
		case '5':
			lastSolution.display();
			break;
		case 'e':
			cout << "Zakonczenie programu" << endl;
			break;
		default:
			cout << "Zle oznaczenie opcji" << endl;
			break;
		}
	}
}
