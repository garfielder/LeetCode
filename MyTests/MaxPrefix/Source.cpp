/*
* https://leetcode.com/problems/container-with-most-water/#/description
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <assert.h>


using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		
		size_t maxSize = strs.begin()->size();
		vector<string>::iterator pCurStr = strs.begin() + 1;
		
		while (pCurStr != strs.end()) {
			int i(0); 
			int localSize(0);
			for (i = 0; i < maxSize; i++) {
				if ((*(pCurStr - 1))[i] == (*(pCurStr))[i]) {
					localSize++; 
					continue;
				}				
				else
					break;
			}
			maxSize = localSize;
			pCurStr++;
		}
	
		return strs[0].substr(0, maxSize);
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
				
				vector<string> inputVec;
				while (!ss.eof())
				{
					string tmpN; ss >> tmpN;
					inputVec.push_back(tmpN);
				}
				
				Solution sol;
				cout << "Case>  " << line << endl;
				cout << "Result: " << sol.longestCommonPrefix(inputVec) << endl;

				cout << endl << endl;
			}
		}
	}


}

int main()
{
	TestInput("input.txt");
}