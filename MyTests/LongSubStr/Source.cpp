#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {		
		int longestLen = 0;

		// lleft and lright defines local best indice
		int lleft(0), lright(0); 

		map<char, int> takenList; // deines char->pos of current local best sub-string

		// special case

		while (lright < (int)s.size())
		{
			if (takenList.find(s[lright]) == takenList.end()) // no confliction
			{
				takenList[s[lright]] = lright;
				if (lright - lleft + 1> longestLen) longestLen = lright - lleft + 1;
			}
			else { // local sub-string cannot grow
				// is local bettern than longestLen
				if (lright - lleft > longestLen) longestLen = lright - lleft;
					
				// lleft should move after the dupliacated one
				int preNewLeft = takenList[s[lright]];
				while (lleft <= preNewLeft)
				{
					takenList.erase(s[lleft]);
					lleft++;
				}
				takenList[s[lright]] = lright;
			}
			lright++;
		}

		return longestLen;
	}
};

void RunTests()
{
	Solution sln;
	ifstream ifs("input.txt");
	if (ifs.fail())
		throw "Cannot open  input.txt";
	string line;
	while (getline(ifs, line)) {
		cout << line  << "\t\t" << sln.lengthOfLongestSubstring(line) << endl; 
	}
}
int main()
{
	RunTests();

}