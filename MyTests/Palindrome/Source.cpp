/*
* https://leetcode.com/problems/longest-palindromic-substring/#/description
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
	inline bool ValidIdx(const string& s, int idx) {
		return  (idx >= 0) && (idx < s.size());
	}

	string longestPalindrome(string s) {

		if (s.size() == 0) return "";

		int i(0);
		pair<int, int> maxIdx(0, 1);  // <start, size>
		while (ValidIdx(s, i)) {
			////
			// Check pattern 'aba'
			if (ValidIdx(s, i - 2) && (s[i - 2] == s[i])) {  // pattern hit
				int m = i - 1;  // middle point
				int j(1);
				while (ValidIdx(s, m - j) && ValidIdx(s, m + j) && s[m - j] == s[m + j]) j++;

				if (j > 1) j--;
						
				if (maxIdx.second  < 2 * j + 1) {
					maxIdx.first = m - j;
					maxIdx.second = 2 * j + 1;
				}
			}

			// Check pattern 'aa'
			if (ValidIdx(s, i - 1) && (s[i - 1] == s[i])) { // pattern hit
				// m, n are middle elements pair
				int m = i - 1;  
				int n = i;
				int j(0);
				while (ValidIdx(s, m - j) && ValidIdx(s, n + j) && (s[m - j] == s[n + j])) j++;
				if (j > 0) j--;

				if (maxIdx.second < 2 * j + 2) {
					maxIdx.first = m - j;
					maxIdx.second = 2 * j + 2;
				}
					

			}

			i++;
		}
		return s.substr(maxIdx.first, maxIdx.second);
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