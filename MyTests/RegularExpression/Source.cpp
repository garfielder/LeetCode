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
	enum STATE {START, NORMAL, STAR, PASS, FAIL};

	Solution() :
		_state(START),
		_i(0),
		_j(0) {}

	void Start(const string s, const string p ) {
		if ('*' == p[_j])
			_state = FAIL;
		else {
			_state = NORMAL;
		}
	}

	void Normal(const string s, const string  p) {
		if ((s.size() == _i) && (p.size() == _j))
			_state = PASS;	
		else if ((_j+1 < p.size()) && (p[_j+1] == '*') ) {
			_state = STAR;
			_j++;
		}
		else if (s.size() == _i) // s ends
			_state = FAIL;
		else if (!char_equal(s[_i], p[_j])) {
			if (_stack.empty())  // nothing to recover
				_state = FAIL;
			else {
				_i = _stack.top().first;
				_j = _stack.top().second;
				_stack.pop();
				_state = STAR;
			}
		}

		else{ // my action
			assert(char_equal(s[_i], p[_j]));
			_i++;
			_j++;
		}
	}

	void Star (const string s, const string  p) {
		assert(p[_j] == '*');
		char pre = p[_j - 1];

		if (_j + 1 == p.size()) {
			if (char_equal(s[_i], pre)) _state = PASS;
			else _state = FAIL;

		}
			
		else {
			char next = p[_j + 1];
			if (s.size() == _i)
			{
				_state = FAIL;
			}
			else if (matchNext(s, p, _j) > _j)
			{
				// push into stack
				_state = NORMAL;
				
				if ( (_i +1 < s.size()) && char_equal(s[_i], pre)) 
					_stack.push(make_pair(_i+1, _j));
				_j = matchNext(s, p, _j);
			}
			else if (char_equal(s[_i], pre)){
				// Keep star
				_i++;
			}
			else { // mismatch
				_j++;
				_state = NORMAL;
			}
		}

	}
	bool isMatch(string s, string p) {
		_state = START;  
		int i(0); // index of string
		int j(0); // index of pattern

		// Main loop
		while ((_state != PASS) && (_state != FAIL) )
		{
			switch (_state)
			{
			case START:
				Start(s, p);
				break;
			case NORMAL:
				Normal(s, p);
				break;
			case STAR:
				Star(s, p);
				break;
			default:
				assert(0);
			}
		}

		return PASS == _state;
	}
private:
	inline bool char_equal(char ch, char reCh) {
		if ('.' == reCh) 
			return true;
		else
			return ch == reCh;
	}

	int  matchNext(string s, string p, int j) {
		while ((j + 1 < p.size()) && (s[_i] != p[j+1]))
		{
			if ((j + 2 < p.size()) && p[j + 2] == '*')
				j = j + 2;
			else
				return -1;
		}
		if (j + 1 == p.size()) return -1;
		else return j + 1;
	}
private:
	STATE _state;
	int   _i;
	int   _j;
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