#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>

using namespace std;



class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int>& M = nums1;
		vector<int>& N = nums2;

		assert(!nums1.empty());
		assert(!nums2.empty());

		int mleft = 0; 
		int mright = M.size() - 1;

		int nleft = 0;
		int nright = N.size() - 1;

		while (1)
		{
			if ((mleft == mright) && (nleft == nright))
			{
				// both arrary has one item left
				return static_cast<double>(M[mleft] + N[nleft]) / 2;
			}

			int mMid = MidValue(M, mleft, mright);
			int nMid = MidValue(N, nleft, nright);

			int mShrink = (mright - mleft + 1) / 2;
			int nShrink = (nright - nleft + 1) / 2;
			int mnShrink = mShrink < nShrink ? mShrink : nShrink;

			if (mMid < nMid) {
				// Left shrink
				mleft += mnShrink;
				mright = mright;

				// right shrink
				nleft = nleft;
				nright -= mnShrink;
			}
			else if (mMid < nMid) {
				// right shrink
				mleft = mleft;
				mright -= mnShrink;

				nleft -= mnShrink;
				nright = nright; 
			}
			else {
				return static_cast<double>(mMid) / 2;
			}
		}

		return 0.0;
	}
private:
	int MidValue(vector<int> &vec, int left, int right)
	{
		assert(left <= right);
		// ÆæÊý
		if ((left + right) % 2 == 0)
			return vec[(left + right) / 2] * 2;
		else
			return vec[(left + right) / 2] + vec[(left + right) / 2 + 1];
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