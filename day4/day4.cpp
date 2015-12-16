#include <iostream>
#include <climits>
#include "md5.h"
using std::cout; using std::string; using std::endl; using std::to_string;

int GetLowestIntForNZeroes(string secret_key, int n) {
	string hash;
	for (int i = 0; i < INT_MAX; ++i){
		hash = md5(secret_key + to_string(i));
		for(int j = 0; j < n + 1; ++j) {
			if (hash[j] != '0') {
				if (j == n) {
					return i;
				}
				break;
			}
		}
	}
	return -1;
}

int main() {
	cout << GetLowestIntForNZeroes("bgvyzdsv", 5) << endl;
	cout << GetLowestIntForNZeroes("bgvyzdsv", 6) << endl;
}

