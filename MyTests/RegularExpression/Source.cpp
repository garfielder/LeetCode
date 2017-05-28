/*
* https://leetcode.com/problems/regular-expression-matching/#/description
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <assert.h>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
	enum STATE {START, NORMAL, STAR, PASS, FAIL, END};

	Solution()		
	{_state = START; }

	void Start(int& i, int& j ) {
		_state = NORMAL;
	}

	void Normal(int& i, int& j) {
		if (IsEnd(i, j))
			_state = END;
		else if (IsLoopPos(j)) {  // go to  star
			_state = STAR;
		}
		else if (char_equal(s[i], p[j])) {
			i = NextI(i);
			j = NextJ(j);
		}
		else if (!char_equal(s[i], p[j])) {
			if (_stack.empty())
				_state = FAIL;
			else {
				i = _stack.top().first;
				j = _stack.top().second;
				_stack.pop();
				_state = STAR;
			}
		}
		else {
			assert(0);
		}
	}

	void Star (int &i, int &j) {
		assert(p[j+1] == '*');
		char pre = p[j];

		// Can be self-looped
		if (IsEnd(i, j))
		{	
			_state = END;
		}
		else {
			if (char_equal(s[i], p[j]))
				_stack.push(make_pair(i + 1, j));
			_state = NORMAL;
			j = NextJ(j);
		}

	}

	void End(int& i, int& j)
	{
		if ((s.size() == i) && (p.size() == j))
			_state = PASS;
		else if ((s.size() != i) && (p.size() == j)) {
			 Revisit(i, j);
		}
		else if ((s.size() == i) && (p.size() != j))
		{
			while (IsLoopPos(j) && (j < p.size())) j = NextJ(j);

			if (p.size() == j) _state = PASS;
			else {

				Revisit(i, j);
			}
		}
	}
	bool isMatch(string ss, string pp) {
		_state = START;  
		this->s = ss;
		this->p = pp;
		int i(0), j(0);
		// Main loop
		while ((_state != PASS) && (_state != FAIL) )
		{
			switch (_state)
			{
			case START:
				Start(i, j);
				break;
			case NORMAL:
				Normal(i, j);
				break;
			case STAR:
				Star(i, j);
				break;
			case END:
				End(i, j);
				break;
			default:
				assert(0);
			}
		}

		return PASS == _state;
	}

	void Revisit(int& i, int& j) {
		if (_stack.empty())
			_state = FAIL;
		else {
			i = _stack.top().first;
			j = _stack.top().second;
			_stack.pop();
			_state = STAR;
		}
	}

private:
	inline bool char_equal(char ch, char reCh) {
		if ('.' == reCh) 
			return true;
		else
			return ch == reCh;
	}


	int NextI(int i) { return i + 1; }
	int NextJ(int j) {
		if (IsLoopPos(j))
			return j + 2;
		else
			return j + 1;

	}
	bool IsLoopPos(int j){
		return (j + 1 < p.size()) && ('*' == p[j + 1]);
	}

	bool IsEnd(const int i, const int j) {
		return (i >= s.size()) || (j >= p.size());
	}


private:
	STATE _state;
	std::string s;
	std::string p;
	stack<pair< int, int> > _stack;
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
				if ("BLANK" == str) str = "";

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