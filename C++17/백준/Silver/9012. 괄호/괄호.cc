#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int num;
	cin >> num;
	stack<int> st1;
	for (int i = 0; i < num; i++)
	{
		string data;
		cin >> data;
		int result = 1;
		stack<int> st1;
		for (int j = 0; j < size(data); j++)
		{
			if (data[j] == '(') {
				st1.push(1);
			}
			if (data[j] == ')') {
				if (st1.size() == 0) {
					result *= 0;
				}
				else {
					st1.pop();
				}
			}
		}
		if (st1.size() != 0) {
			result *= 0;
		}

		if (result==1) {
			cout << "YES" << endl;
		}
		else if (result==0) {
			cout << "NO" << endl;
		}
	}
}