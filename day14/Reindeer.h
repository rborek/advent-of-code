#include <string>
class Reindeer {
	int speed;
	int fly_duration;
	int rest_duration;
	bool resting;
	int rest_timer;
	int fly_timer;
	public:
		std::string name;
		int distance_flown;
		int score;
		void race();
		Reindeer(const std::string str);


};