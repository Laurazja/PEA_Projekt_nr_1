#pragma once
#include<iostream>
#include<vector>
#include <algorithm>
#include "Solution.h"
using namespace std;

/*Klasa umozliwiajaca wykonanaie algorytmu brute force do rozwiazania problemu komiwojazera*/

class BruteForce
{
public:
	vector<vector<int>> matrix;
	int numberOfCities;
	vector<int> path;
	int costOfPath;

	BruteForce(Solution solution);
	~BruteForce();

	void  permutation(vector<int> currentPath, int beginning, int ending);
	void bruteForceSolution();

};



