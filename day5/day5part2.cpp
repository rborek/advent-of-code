#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsNice(string str) {
	bool has_spaced_repeat = false;
	for (string::size_type i = 0; i < str.size() - 2; ++i) {
		if (str[i] == str[i+2]) {
			has_spaced_repeat = true;
		}
	}
	if (has_spaced_repeat == false) {
		return false;
	}
	for (string::size_type i = 0; i < str.size() - 3; ++i) {
		string couple = string(1, str[i]) + string(1, str[i+1]);
		string to_search_first = str.substr(0, i);
		string to_search_second = str.substr(i+2, str.size());
		if (to_search_first.find(couple) != string::npos || to_search_second.find(couple) != string::npos) {
			return true;
		}
	}
	return false;
}

int main() {
	string line;
	ifstream input_file("input.txt");
	int nice_words = 0;
	if (input_file.is_open()) {
		while (getline(input_file, line)) {
			if (IsNice(line)) nice_words++;
		}
	}
	cout << nice_words << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}
