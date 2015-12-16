#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <math.h>
using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

array<int, 2> GetTwoNums(string str) {
	array<int, 2> nums;
	int split_index;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ',') {
			split_index = i;
		}
	}
	nums[0] = stoi(str.substr(0, split_index + 1));
	nums[1] = stoi(str.substr(split_index + 1));
	return nums;
}


void ChangeLights(vector<vector<int>>* lights, int value, int startX, int startY, int endX, int endY) {
	for (int i = startX; i <= endX; ++i) {
		for (int j = startY; j <= endY; ++j) {
			(*lights)[i][j] += value;
			if ((*lights)[i][j] < 0) {
				(*lights)[i][j] = 0;
			}
		}
	}
}


int NumLightsOn(vector<vector<int>>* lights) {
	int sum = 0;
	for (int i = 0; i < lights->size(); ++i) {
		for (int j = 0; j < (*lights)[i].size(); ++j) {
			sum += (*lights)[i][j];
		}
	}
	return sum;
}

int main() {
	string line;
	ifstream input_file("input.txt");
	vector<vector<int>> lights(1000, vector<int>(1000));
	if (input_file.is_open()) {
		vector<string> instructions;
		while (getline(input_file, line)) {
			instructions = split(line, ' ');
			if (instructions[0] == "turn") {
				int value = -1;
				if (instructions[1] == "on") {
					value = 1;
				}
				array<int, 2> startNums = GetTwoNums(instructions[2]);
				array<int, 2> endNums = GetTwoNums(instructions[4]);
				ChangeLights(&lights, value, startNums[0], startNums[1], endNums[0], endNums[1]);
			} else {
				array<int, 2> startNums = GetTwoNums(instructions[1]);
				array<int, 2> endNums = GetTwoNums(instructions[3]);
				ChangeLights(&lights, 2, startNums[0], startNums[1], endNums[0], endNums[1]);
			}
			
		}
	}
	cout << NumLightsOn(&lights) << endl;
	return EXIT_SUCCESS;
}
