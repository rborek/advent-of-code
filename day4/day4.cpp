#include <iostream>
#include <climits>
#include "md5.h"
using std::cout; using std::string; using std::endl; using std::to_string;

int GetLowestIntForNZeroes(string secret_key, int n) {
	string hash;
	for (int i = 0; i < INT_MAX; ++i){
		hash = md5(secret_key + to_string(i));
		for(int j = 0; j < n; ++j) {
			if (hash[j] != '0') {
				break;
			}
			if (j == n - 1) {
				return i;
			}
		}
	}
	return -1;
}

int main() {
	string secret_key = "bgvyzdsv";
	cout << GetLowestIntForNZeroes(secret_key, 5) << endl;
	cout << GetLowestIntForNZeroes(secret_key, 6) << endl;
}
