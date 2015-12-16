#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Reindeer.h"
using namespace std;

Reindeer* GetWinnerOfRace(int time_to_race, vector<Reindeer> racing_reindeer) {
	for (int i = 0; i < time_to_race; ++i) {
		for (int j = 0; j < racing_reindeer.size(); ++j) {
			racing_reindeer[j].race();
		}
	}
	Reindeer* winner = &racing_reindeer[0];
	for (int i = 1; i < racing_reindeer.size(); ++i) {
		if (racing_reindeer[i].distance_flown > winner->distance_flown) {
			winner = &racing_reindeer[i];
		}
	}
	return winner;
}

Reindeer* GetWinnerOfScoreRace(int time_to_race, vector<Reindeer> racing_reindeer) {
	for (int i = 0; i < time_to_race; ++i) {
		for (int j = 0; j < racing_reindeer.size(); ++j) {
			racing_reindeer[j].race();
		}
		Reindeer* in_lead = &racing_reindeer[0];
		for (int j = 1; j < racing_reindeer.size(); ++j) {
			if (racing_reindeer[j].distance_flown > in_lead->distance_flown) {
				in_lead = &racing_reindeer[j];
			}
		}
		in_lead->score++;
	}
	Reindeer* winner = &racing_reindeer[0];
	for (int i = 1; i < racing_reindeer.size(); ++i) {
		if (racing_reindeer[i].score > winner->score) {
			winner = &racing_reindeer[i];
		}
	}
	return winner;
}

int main() {
	string line;
	ifstream input_file("input.txt");
	int time_to_race = 2503;
	vector<Reindeer> racing_reindeer;
	if (input_file.is_open()) {
		while (getline(input_file, line)) {
			racing_reindeer.push_back(Reindeer(line));
		}
	}
	Reindeer* winner = GetWinnerOfRace(time_to_race, racing_reindeer);
	cout << winner->name << " flew " << winner->distance_flown << " km." << endl;
	winner = GetWinnerOfScoreRace(time_to_race, racing_reindeer);
	cout << winner->name << " scored " << winner->score << " points." << endl;
	return EXIT_SUCCESS;
}