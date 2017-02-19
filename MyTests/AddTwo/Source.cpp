#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>

#include <direct.h>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy(0);
		ListNode* head = &dummy;
		ListNode* tail = head;

		head->next = l1;
		int carry(0);

		while (l1 && l2) {
			ListNode* pNode(l1);
			pNode->val = l1->val + l2->val + carry;

			if (10 <= pNode->val) {
				pNode->val = pNode->val % 10;
				carry = 1;
			}
			else {
				carry = 0;
			}

			tail = l1;
			l1 = l1->next;
			l2 = l2->next;
		}

		if (!l1) /* l1 reaches the end*/ {
			tail->next = l2;
		}

		while (carry) {
			if (!tail->next) {
				tail->next = new ListNode(1);
				carry = 0;
			}
			else {
				tail->next->val++;
				if (10 <= tail->next->val) {
					tail->next->val = tail->next->val % 10;
					carry = 1;
				}
				else {
					carry = 0;
				}
			}
			tail = tail->next;
		}

		return head->next;
	}
};



ListNode* GenList(int array[], int n)
{
	ListNode* head(NULL);
	ListNode* tail(NULL);

	for (int i(0); i < n; i++) {
		ListNode* pNode = new ListNode(array[i]);
		if (!head) head = pNode;
		if (tail) tail->next = pNode;

		tail = pNode;
	}
	return head;
}

void Display(ListNode* pNode, string msg = "")
{
	cout << msg;
	while (pNode)
	{
		cout << pNode->val << "  ";
		pNode = pNode->next;
	}
	cout << endl;
}

void StrToVec(string str, vector<int>& vec)
{
	vec.clear();
	stringstream ss(str);


	// copy(istream_iterator<int>(ss), istream_iterator<int>(), vec.begin());
	int val;
	while (ss >> val)
		vec.push_back(val);
	
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

				int* pFirst = firstVec.empty() ? NULL : &firstVec[0];
				int* pSecond = second.empty() ? NULL : &secondVec[0];

				ListNode* p1 = GenList(pFirst, firstVec.size());
				ListNode* p2 = GenList(pSecond, secondVec.size());
				cout << " ---------------------- " << endl;
				Display(p1, "first num: ");
				Display(p2, "second num: ");

				Solution sol;
				ListNode* pSum = sol.addTwoNumbers(p1, p2);


				Display(pSum, "result: ");
						
				cout << endl;
			}
		}
	}

	stringstream  ss;
	ss << "1 3 6  ";
	while(1)	{
		int a;
		ss >> a;

		if (ss.good())
			cout << a << endl;
		else
			break;
	}  
	
}
int main()
{
	std::cout << "Hello, vs2015" << std::endl;

	int a1[] = {2, 4, 6};
	int a2[] = { 5, 6, 4 };
	
	ListNode* p1 = GenList(a1, sizeof(a1)/sizeof(int));
	ListNode* p2 = GenList(a2, sizeof(a2) / sizeof(int));
	
	//Solution sol;
	//ListNode* pSum = sol.addTwoNumbers(p1, p2);
	//Display(pSum);

	//char* pwd;
	//pwd = _getcwd(NULL, 0);
	//cout << "cwd is " << pwd << endl;
	//free(pwd);
	TestInput("input.txt");
}