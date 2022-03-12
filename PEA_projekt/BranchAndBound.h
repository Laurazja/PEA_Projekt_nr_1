#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "Solution.h"
#include "MeasureTime.h"

using namespace std;

/*Klasa umozliwajaca wykonanie algorytmu Branch and Bound do rozwiazania problemu komiwojazera*/
class BranchAndBound
{
public:
	vector<vector<int>> givenMatrix;
	vector<int> minPath;
	vector<int> upperBoundPath;
	int numberOfCities;
	int minCost;
	int lowerBound;
	int upperBound;

	BranchAndBound(Solution solution);
	~BranchAndBound();

	int findMin(vector<int> row);

	int reduction(vector<vector<int>>& matrix);
	void BranchAndBoundSolution();
	void makePath(vector<pair<int, int>> const& list);
	void setUpperBound(vector<vector<int>> matrix);

};

struct Node {
	vector<pair<int, int>> path;
	vector<vector<int>> reducedMatrix;
	int currentCost;
	int currentCity;
	int numberOfVisitedCities;
};

struct cmp {
	bool operator()(const Node* left, const Node* right) const {
		return left->currentCost > right->currentCost;
	}
};

