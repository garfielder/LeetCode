#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {

		return "";
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
			if ("" == line) {
				cout << "New Test case " << endl;
				string first;
				getline(ifs, first);

				Solution sol;

				cout << "Result: " << sol.longestPalindrome(first) << endl;

				cout << endl;
			}
		}
	}


}

int main()
{
	TestInput("input.txt");
}