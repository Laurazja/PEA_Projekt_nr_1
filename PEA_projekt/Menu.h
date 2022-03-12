#include "Solution.h"
#include "BruteForce.h"
#include "BranchAndBound.h"
//#include "MeasureTime.h"

/*Klasa zawierajaca proste menu*/
class Menu {

public:
	Solution lastSolution;
	MeasureTime time;

	void mainMenu();
};