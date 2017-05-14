/*
* https://leetcode.com/problems/palindrome-number/#/description
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		
		long long N(1);
		while (x > N * 10) {
			N = N * 10;
		}

		while (x) {
			if (x / N == x % 10) {
				x = x % N;
				x = x / 10;
				N = N / 100;
			}
			else {
				break;
			}
		}



		return x == 0;
	}
};

void TestInput(string fname)
{
	std::ifstream ifs(fname.c_str());
	if (ifs.fail()) {
		cerr << "cannot open " << fname << endl;
		return;
	}
	else {
		std::string line;
		while (std::getline(ifs, line))
		{
			if ("---" == line) {
				cout << "New Test case " << endl;
				getline(ifs, line);
				stringstream ss; ss << line;
				
				int n;
				ss >> n;
				cout << "Test number:  " << n << endl;
				
				Solution sol;

				cout << "Result: " << sol.isPalindrome(n) << endl;

				cout << endl << endl;
			}
		}
	}


}

int main()
{
	TestInput("input.txt");
}