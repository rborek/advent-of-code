#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsNice(string str) {
	if (str.find("ab") != string::npos || str.find("cd") != string::npos || 
		str.find("pq") != string::npos || str.find("xy") != string::npos) {
		return false;
	}
	bool has_repeat = false;
	int num_vowels = 0;
	for (string::size_type i = 0; i < str.size(); ++i) {
		if (i > 0 && str[i] == str[i-1]) {
			has_repeat = true;
		}
		switch(str[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': num_vowels++;
			default: break;
		}
	}
	return has_repeat && num_vowels >= 3;
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
