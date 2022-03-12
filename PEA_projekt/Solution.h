#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
//#include <random>
using namespace std;

/*Klasa przechowujaca informacje o ostatnio wygenerowanych danych oraz rozwiazaniu. Umozliwia wczytania danych z pliku,
wygenerowanie losowej instancji oraz wyswietlenie danych i wynikow */

class Solution
{
public:

	vector<vector<int>> matrix;
	int numberOfCities;
	vector<int> minPath;
	int minCost;
	char typeOfsolution;
	long time;

	Solution();
	~Solution();

	void readFromFile(string fileName);

	void random();

	void display();

};




