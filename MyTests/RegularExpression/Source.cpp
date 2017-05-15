/*
* https://leetcode.com/problems/regular-expression-matching/#/description
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
	bool isMatch(string s, string p) {
		return true;
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
				
				std::string str, pattern; ss >> str >> pattern;
				
				cout << "Input String " << str << "  pattern " << pattern << endl;
				
				Solution sol;

				cout << "Result: " << sol.isMatch(str, pattern) << endl;

				cout << endl << endl;
			}
		}
	}


}

int main()
{
	TestInput("input.txt");
}