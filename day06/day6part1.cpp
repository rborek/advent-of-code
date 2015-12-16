#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <math.h>
using namespace std;

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


void SetLights(vector<vector<int>>* lights, int value, int startX, int startY, int endX, int endY) {
	for (int i = startX; i <= endX; ++i) {
		for (int j = startY; j <= endY; ++j) {
			(*lights)[i][j] = value;
		}
	}
}

void ToggleLights(vector<vector<int>>* lights, int startX, int startY, int endX, int endY) {
	for (int i = startX; i <= endX; ++i) {
		for (int j = startY; j <= endY; ++j) {
			(*lights)[i][j] = (*lights)[i][j] == 0 ? 1 : 0;
		}
	}
}

int NumLightsOn(vector<vector<int>>* lights) {
	int sum = 0;
	for (int i = 0; i < lights->size(); ++i) {
		for (int j = 0; j < (*lights)[i].size(); ++j) {
			if ((*lights)[i][j] == 1) {
				sum++;
			}
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
				int value = 0;
				if (instructions[1] == "on") {
					value = 1;
				}
				array<int, 2> startNums = GetTwoNums(instructions[2]);
				array<int, 2> endNums = GetTwoNums(instructions[4]);
				SetLights(&lights, value, startNums[0], startNums[1], endNums[0], endNums[1]);
			} else {
				array<int, 2> startNums = GetTwoNums(instructions[1]);
				array<int, 2> endNums = GetTwoNums(instructions[3]);
				ToggleLights(&lights, startNums[0], startNums[1], endNums[0], endNums[1]);
			}
			
		}
	}
	cout << NumLightsOn(&lights) << endl;
	return EXIT_SUCCESS;
}
