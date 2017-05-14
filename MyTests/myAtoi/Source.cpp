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
	inline int chartoi(char c)
	{
		if ((c >= '0') && (c <= '9'))
			return c - '0';
		//else if ((c >= 'a') && (c <= 'f'))
		//	return c - 'a' + 10;
		//else if ((c >= 'A') && (c <= 'F'))
		//	return c - 'A' + 10;
		else
			return -1; // invalid
	}
	int myAtoi(string str) {
		while ((str[0] == ' ') || (str[0] == '\t')) str.erase(0, 1);
		int  sign = (str[0] == '-') ? -1 : 1;
		if ( str[0] =='-' || (str[0] == '+'))
			str.erase(0, 1);
		
		long long res(0);
		for (char c : str) {
			if (chartoi(c) == -1) break;

			res = res * 10 + chartoi(c);
			if ( res * sign  >= INT_MAX) {  // exceed 32 bit
				res = INT_MAX;
				break;
			}
			if (res * sign <= INT_MIN)
			{
				res = -INT_MIN;
				break;
			};
		}

		if (-1 == sign) res = -res;
		return static_cast<int>(res);
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

				//stringstream ss(first);
				//string x;
				// ss >> x;
				
				//first.pop_back();
				string x = first;

				cout << "Input int is " << x << endl;

				Solution sol;

				cout << "Result: " << sol.myAtoi(x) << endl;

				cout << endl;
			}
		}
	}


}

int main()
{
	TestInput("input.txt");

	long long a = -2147483648LL;
	unsigned b = *(unsigned*)&a;

		std::cout << hex << b << std::endl;
}