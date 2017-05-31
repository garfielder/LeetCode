/*
* https://leetcode.com/problems/container-with-most-water/#/description
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <assert.h>


using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		return 0;
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
				
				std::vector<int> inputVec;
				while (!ss.eof())
				{
					int tmpN; ss >> tmpN;
					inputVec.push_back(tmpN);
				}
				
				Solution sol;
				cout << "Case>  " << line << endl;
				cout << "Result: " << sol.maxArea(inputVec) << endl;

				cout << endl << endl;
			}
		}
	}


}

int main()
{
	TestInput("input.txt");
}