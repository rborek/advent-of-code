#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
using namespace std;

struct position {
	int x;
	int y;
};

int main() {
	string line;
	ifstream input_file("input.txt");
	vector<position> visited;
	position santa{ 0, 0 };
	visited.push_back(position{ santa.x, santa.y });
	if (input_file.is_open()) {
		while (getline(input_file, line)) {
			for (string::size_type i = 0; i < line.size(); ++i) {
				if (line[i] == '^') {
					santa.y++;
				} else if (line[i] == 'v') {
					santa.y--;
				} else if (line[i] == '<') {
					santa.x--;
				} else if (line[i] == '>') {
					santa.x++;
				}
				bool new_house = true;
				for (vector<position>::size_type i = 0; i < visited.size(); ++i) {
					if (santa.x == visited[i].x && santa.y == visited[i].y) {
						new_house = false;
					}
				}
				if (new_house) {
					visited.push_back(position{ santa.x, santa.y });
				}
			}
		}
	}
	cout << visited.size() << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}
