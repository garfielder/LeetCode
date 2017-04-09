/*
* https://leetcode.com/problems/reverse-integer/#/description
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
	int reverse(int x) {
		long long res = 0;
		bool negative = (x < 0);

		if (negative) x = -x;

		while (x) {
			res = res * 10 + x % 10;
			x = x / 10;
		}
		
		if (res >> 31) res = 0;

		if (negative) res = -res;

		return res;
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
				string first;
				getline(ifs, first);

				stringstream ss(first);
				int x(0);
				ss >> x;
				

				cout << "Input int is " << x << endl;

				Solution sol;

				cout << "Result: " << sol.reverse(x) << endl;

				cout << endl;
			}
		}
	}


}

int main()
{
	TestInput("input.txt");
}