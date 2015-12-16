#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string line;
	ifstream input_file("input.txt");
	bool entered_basement = false;
	int basement_entry = 0;
	int floor = 0;
	if (input_file.is_open()) {
		while (getline(input_file, line)) {
			for (string::size_type i = 0; i < line.size(); ++i) {
				if (line[i] == '(') {
					floor++;
				} else if (line[i] == ')') {
					floor--;
				}
				if (entered_basement == false && floor == -1) {
					basement_entry = i + 1;
					entered_basement = true;
				}
			}
		}
	}
	cout << "Santa ends up on floor " << floor << endl;
	cout << "Santa first entered the basement on movement " << basement_entry << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}
