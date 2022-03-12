#include "BranchAndBound.h"

BranchAndBound::BranchAndBound(Solution solution) {
	givenMatrix = solution.matrix;
	numberOfCities = solution.numberOfCities;
	minCost = INT32_MAX;
	minPath.clear();
	lowerBound = 0;
	upperBound = INT32_MAX;

}

BranchAndBound::~BranchAndBound() {
	givenMatrix.clear();
	minPath.clear();
	minCost = 0;
	numberOfCities = 0;
}


Node* newNode(vector<vector<int>> matrix, vector<pair<int, int>> path, int numberOfvisitedCities, int from, int to, int numberOfCities) {

	Node* node = new Node;

	node->path = path;

	if (numberOfvisitedCities != 0) {
		node->path.push_back(make_pair(from, to));
	}

	node->reducedMatrix = matrix;

	for (int i = 0; (numberOfvisitedCities != 0) && (i < numberOfCities); i++) {
		node->reducedMatrix[from][i] = INT32_MAX;
		node->reducedMatrix[i][to] = INT32_MAX;
	}

	node->reducedMatrix[to][0] = INT32_MAX;

	node->numberOfVisitedCities = numberOfvisitedCities;
	node->currentCity = to;

	return node;
}


int BranchAndBound::findMin(vector<int> row) {
	int min = INT32_MAX;

	for (int i = 0; i < row.size(); i++) {
		if ((row[i] < min) && (row[i] != -1)) {
			min = row[i];
		}
	}

	return min;
}


int BranchAndBound::reduction(vector<vector<int>>& matrix) {

	int reduced = 0;

	for (int i = 0; i < numberOfCities; i++) {
		int min = findMin(matrix[i]);

		if ((min != 0) && (min != INT32_MAX)) {
			reduced += min;
			for (int j = 0; j < numberOfCities; j++) {

				if ((matrix[i][j] != -1) && (matrix[i][j] != 0) && (matrix[i][j] != INT32_MAX)) {
					matrix[i][j] -= min;
				}

			}
		}
	}

	for (int i = 0; i < numberOfCities; i++) {
		vector<int> column;

		for (int j = 0; j < numberOfCities; j++) {
			column.push_back(matrix[j][i]);
		}

		int min = findMin(column);

		if ((min != 0) && (min != INT32_MAX)) {
			reduced += min;
			for (int j = 0; j < numberOfCities; j++) {

				if ((matrix[j][i] != -1) && (matrix[j][i] != 0) && (matrix[j][i] != INT32_MAX)) {
					matrix[j][i] -= min;
				}
			}
		}
	}

	return reduced;
}


void BranchAndBound::makePath(vector<pair<int, int>> const& path)
{
	for (int i = 0; i < path.size(); i++) {
		minPath.push_back(path[i].second);
	}

}


void BranchAndBound::BranchAndBoundSolution() {

	MeasureTime time;
	time.start();

	vector<vector<int>> matrix = givenMatrix;

	for (int i = 0; i < numberOfCities; i++) {
		matrix[i][i] = INT32_MAX;
	}

	setUpperBound(matrix);

	priority_queue<Node*, vector<Node*>, cmp> priorityQueue;
	vector<pair<int, int>> way;

	Node* root = newNode(matrix, way, 0, -1, 0, numberOfCities);

	root->currentCost = reduction(root->reducedMatrix);
	lowerBound = root->currentCost;

	priorityQueue.push(root);

	while (!priorityQueue.empty()) {

		Node* min = priorityQueue.top();

		priorityQueue.pop();

		int currentCity = min->currentCity;

		if (min->numberOfVisitedCities == numberOfCities - 1) {
			min->path.push_back(make_pair(currentCity, 0));
			minCost = min->currentCost;

			makePath(min->path);

			return;
		}

		for (int i = 0; i < numberOfCities; i++) {

			if ((min->reducedMatrix[currentCity][i] != INT32_MAX) && (currentCity != i)) {
				
				Node* next = newNode(min->reducedMatrix, min->path, min->numberOfVisitedCities + 1, currentCity, i, numberOfCities);
				
				next->currentCost = min->currentCost + min->reducedMatrix[currentCity][i] + reduction(next->reducedMatrix);

				if ((next->numberOfVisitedCities == numberOfCities - 1) && (next->currentCost < upperBound)) {
					upperBound = next->currentCost;
				}

				if (next->currentCost > upperBound) {
					delete next;
				}
				else {
					priorityQueue.push(next);
				}
			}
		}

		delete min;
		time.stop();
		if (time.totalTime() > 300000000) {
			cout << "Przekroczono maksymalny czas wykonywania algorytmu (5 minut)" << endl;
			minPath.clear();
			minCost = 0;
		}
	}

	minPath = upperBoundPath;

}

void BranchAndBound::setUpperBound(vector<vector<int>> matrix) {

	int visitedCitires = 0;
	int currentCity = 0;

	while (visitedCitires < numberOfCities) {

		int min = INT32_MAX;
		int minIndex = 0;

		for (int i = 0; i < numberOfCities; i++) {
			if ((matrix[currentCity][i] < min) && (matrix[currentCity][i] != -1)) {
				min = matrix[currentCity][i];
				minIndex = i;
			}
		}

		for (int i = 0; i < numberOfCities; i++) {
				matrix[currentCity][minIndex] = INT32_MAX;
				matrix[minIndex][currentCity] = INT32_MAX;
				matrix[minIndex][0] = INT32_MAX;
		}

		upperBoundPath.push_back(minIndex);
		//currentCity = minIndex;
		minCost += min;
		visitedCitires++;
	}

	upperBound = minCost;
}
