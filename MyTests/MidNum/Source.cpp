#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <algorithm>

using namespace std;


// https://leetcode.com/problems/median-of-two-sorted-arrays/?tab=Solutions
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		// Make sure num(M) <= num(N)
		vector<int>& M = nums1.size() <= nums2.size() ? nums1 : nums2;
		vector<int>& N = nums1.size() > nums2.size() ? nums1 : nums2;

		if (M.empty()) {
			assert(!N.empty());
			if (N.size() % 2 == 0) {
				int  i = N.size() / 2;
				return (N[i] + N[i - 1]) / 2.0;
			}
			else {
				return N[N.size() / 2];
			}
		}

		const int m = M.size();
		const int n = N.size();



		int mleft = 0; 
		int mright = M.size();


		while (mleft <= mright)
		{
			int i = (mleft + mright) / 2;
			int j = (m + n + 1) / 2 - i;


			if ( (i<m) && (M[i] < N[j - 1]))
				mleft = mleft + 1;
			else if ( (i>0) && (N[j] < M[i - 1])) 
				mleft = mleft - 1;
			else {
				// result is found 
				int maxLeft;
				int minRight;

				if (i == 0) maxLeft = N[j - 1];
				else if (j == 0) maxLeft = M[i - 1];
				else maxLeft = max(M[i - 1], N[j - 1]);

				if ((m + n) % 2)
					return maxLeft;

				if (i == m) minRight = N[j];
				else if (j == n) minRight = M[i];
				else minRight = min(M[i], N[j]);

				return (maxLeft + minRight) / 2.0;
			}


 		}

		return 0.0;
	}

};

void StrToVec(string str, vector<int>& vec)
{
	vec.clear();
	stringstream ss(str);


	// copy(istream_iterator<int>(ss), istream_iterator<int>(), vec.begin());
	int val;
	while (ss >> val)
		vec.push_back(val);
}

void Display(vector<int>& vec, string msg)
{
	cout << msg;

	for (int i : vec)
		cout << "\t" << i;
	cout << endl;
}
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
				string first, second;
				getline(ifs, first);
				getline(ifs, second);

				vector<int> firstVec, secondVec;
				StrToVec(first, firstVec);
				StrToVec(second, secondVec);

	

				Solution sol;
				Display(firstVec, "M: ");
				Display(secondVec, "N:");
				cout << "Result: " << sol.findMedianSortedArrays(firstVec, secondVec) << endl;

				cout << "*\n*\n";

				cout << endl;
			}
		}
	}

	
}

int main()
{
	TestInput("input.txt");
}