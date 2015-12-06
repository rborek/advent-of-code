#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
using namespace std;

array<int, 2> GetTwoLowest(array<int, 3> arr) {
	int highest_index = 0;
	int highest_num = arr[0];
	for (array<int, 3>::size_type i = 1; i < arr.size(); ++i) {
		if (arr[i] > highest_num) {
			highest_num = arr[i];
			highest_index = i;
		}
	}
	array<int, 2> new_array;
	int size = 0;
	for (array<int, 3>::size_type i = 0; i < arr.size(); ++i) {
		if (i != highest_index) {
			new_array[size++] = arr[i];
		}
	}
	return new_array;
}

int main() {
	string str;
	string split = "x";
	ifstream input_file("input.txt");
	int total_paper = 0;
	int total_ribbon = 0;
	vector<array<int, 3>> dimensions_list;
	
	// fill vector with arrays containing dimensions
	if (input_file.is_open()) {
		while (getline(input_file, str)) {
			array<int, 3> dimensions;
			for (string::size_type i = 0; i < 3; ++i) {
				int pos = str.find(split);
				string token = str.substr(0, pos);
				try {
					dimensions[i] = stoi(token);
				} catch (int e) {
					cout << "Failed to parse int. Exception " << e << " has occurred.";
				}
				str.erase(0, pos + 1);
			}
			dimensions_list.push_back(dimensions);
		}
	}

	for (vector<array<int,3>>::size_type i = 0; i < dimensions_list.size(); ++i) {
		int length = dimensions_list[i][0];
		int width = dimensions_list[i][1];
		int height = dimensions_list[i][2];
		int extra_paper = min(length * width, width * height);
		extra_paper = min(extra_paper, height * length);
		total_paper += (2 * length * width) + (2 * width * height) + (2 * height * length) + extra_paper;
		array<int, 2> lowest_dimensions = GetTwoLowest(dimensions_list[i]);
		total_ribbon += (2 * lowest_dimensions[0]) + (2 * lowest_dimensions[1]) + (length * width * height);
	}

	cout << "The elves must order " << total_paper << " square feet of wrapping paper." << endl;
	cout << "The elves must order " << total_ribbon << " feet of ribbon." << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}
