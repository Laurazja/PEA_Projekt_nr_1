#include "Solution.h"
#include "BruteForce.h"
#include "BranchAndBound.h"
#include "MeasureTime.h"
class pomiary
{
public:

	Solution lastSolution;
	MeasureTime time;
	long bfTime = 0;
	long bnbTime = 0;

	void pomiar();
};

