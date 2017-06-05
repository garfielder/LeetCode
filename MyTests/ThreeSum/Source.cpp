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
	typedef vector<int>::iterator IntItr;
	vector<vector<int>> threeSum(vector<int>& nums) {
		map<IntItr, IntItr> twoSum;

		sort(nums.begin(), nums.end());
		 vector<vector<int>> res;

		if (nums.empty()) return res;
		for (auto first = nums.begin();  first < nums.end() - 1; first++)
		{
			if (*first > 0) break;

			for (auto second = first + 1; second < nums.end(); second++)
			{
				if (*first + *second > 0)
					break;
				else {
					auto third = lower_bound(second + 1, nums.end(), -(*first + *second));
					if ((third != nums.end()) && (*first + *second + *third == 0))
					{
						vector<int> tmp{ *first, *second, *third };
						if (find(res.begin(), res.end(), tmp) == res.end())
							res.push_back(tmp);
					}
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
				getline(ifs, line);
				stringstream ss; ss << line;
				
				vector<int> inputVec;
				while (!ss.eof())
				{
					int tmpN; ss >> tmpN;
					inputVec.push_back(tmpN);
				}
				
				Solution sol;
				vector<vector<int>> res = sol.threeSum(inputVec);
				cout << "Case>  " << line << endl;

				cout << "Result: " << endl;
				for (const vector<int>& item : res)
				{
					cout << "\t[ ";
					for (int n : item)
						cout << n << "  ";
					cout << "]" << endl;

				}
				cout << endl << endl;
			}
		}
	}


}

int main()
{
	TestInput("input.txt");
}