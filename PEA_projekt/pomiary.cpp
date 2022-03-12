#include "pomiary.h"

void pomiary::pomiar() {
	int n = 0;
	cout << "Podaj ilosc miast: ";
	cin >> n;
	
	for (int i = 0; i < 100; i++) {
		lastSolution.random2(n);
		BruteForce bf(lastSolution);
		time.start();
		bf.bruteForceSolution();
		time.stop();
		bfTime += time.totalTime();

		BranchAndBound bnb(lastSolution);
		time.start();
		bnb.BranchAndBoundSolution();
		time.stop();
		bnbTime += time.totalTime();
		cout << i;
		
	}

	cout << "Czas bf: " << bfTime / 100<<endl;
	cout << "Czas bnb: " << bnbTime / 100 << endl;

}