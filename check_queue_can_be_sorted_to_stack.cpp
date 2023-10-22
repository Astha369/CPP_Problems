// Check if a queue can be sorted into another queue using a stack


#include <bits/stdc++.h>
using namespace std;


bool checkSorted(int n, queue<int>& q)
{
	stack<int> st;
	int expected = 1;
	int fnt;


	while (!q.empty()) {
		fnt = q.front();
		q.pop();


		if (fnt == expected)
			expected++;

		else {

			if (st.empty()) {
				st.push(fnt);
			}

			else if (!st.empty() && st.top() < fnt) {
				return false;
			}


			else
				st.push(fnt);
		}

		while (!st.empty() && st.top() == expected) {
			st.pop();
			expected++;
		}
	}


	if (expected - 1 == n && st.empty())
		return true;

	return false;
}

// Driven Program
int main()
{
	queue<int> q;
	q.push(5);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	int n = q.size();

	(checkSorted(n, q) ? (cout << "Yes") :
						(cout << "No"));

	return 0;
}
