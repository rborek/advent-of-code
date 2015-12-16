#include "Reindeer.h"
#include <sstream>
#include <vector>
using std::vector; using std::string; using std::stringstream;

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

Reindeer::Reindeer(const string str) {
	vector<string> information = split(str, ' ');
	name = information[0];
	speed = stoi(information[3]);
	fly_duration = stoi(information[6]);
	rest_duration = stoi(information[13]);
	rest_timer = 0;
	fly_timer = 0;
	distance_flown = 0;
	resting = false;
	score = 0;
}

void Reindeer::race() {
	if (resting) {
		rest_timer++;
		if (rest_timer >= rest_duration) {
			resting = false;
			rest_timer = 0;
		}
	} else {
		distance_flown += speed;
		fly_timer++;
		if (fly_timer >= fly_duration) {
			resting = true;
			fly_timer = 0;
		}
	}
}
