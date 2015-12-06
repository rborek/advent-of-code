#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include "position.h"
using namespace std;

int main() {
	string line;
	ifstream input_file("input.txt");
	vector<position> visited;
	position santa{ 0, 0 };
	position robo_santa{ 0, 0 };
	visited.push_back(position{ santa.x, santa.y });
	if (input_file.is_open()) {
		while (getline(input_file, line)) {
			position* mover;
			for (string::size_type i = 0; i < line.size(); ++i) {
				if (i % 2 == 0) {
					mover = &santa;
				} else {
					mover = &robo_santa;
				}
				if (line[i] == '^') {
					mover->y++;
				} else if (line[i] == 'v') {
					mover->y--;
				} else if (line[i] == '<') {
					mover->x--;
				} else if (line[i] == '>') {
					mover->x++;
				}
				bool new_house = true;
				for (vector<position>::size_type i = 0; i < visited.size(); ++i) {
					if (mover->x == visited[i].x && mover->y == visited[i].y) {
						new_house = false;
					}
				}
				if (new_house) {
					visited.push_back(position{ mover->x, mover->y });
				}
			}
		}
	}
	cout << visited.size() << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}
