/*
* https://leetcode.com/problems/zigzag-conversion/#/description
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
	string convert(string s, int numRows) {

		if ( (s.size() == 0) || numRows == 1) return s;

		string res;
		int R = numRows;
		int T = 2 * R - 2;
		int numTile = (s.size() - 1) / T + 1;

		for (int r = 0; r < R; r++) {
			for (int t = 0; t < numTile; t++) {
				int ti = r;
				int globalTi = T * t + ti;
				if (globalTi < (int)s.size())  res = res + s[globalTi];

				if ((r != 0) && (r != R - 1)) {
					ti = 2 * R - 2 - r;
					assert(ti > 0);
					int globalTi = T * t + ti;
					if (globalTi < (int)s.size())  res = res + s[globalTi];
				}
			}
		}

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
				int Row(0);
				string s;

				ss >>  s >> Row;

				cout << "string > " << s << "  Size " << Row << endl;

				Solution sol;

				cout << "Result: " << sol.convert(s, Row) << endl;

				cout << endl;
			}
		}
	}


}

int main()
{
	TestInput("input.txt");
}