#include <stack>
#include <iostream>
#include <istream>
#include <string>
using namespace std;

int main() {
	int num;
	cin >> num;
	cin.ignore();
	for (int j = 0; j < num; j++)
	{
		string str;
		stack<char> st1;
		getline(cin, str);
		for (int i = 0; i < size(str); i++)
		{
			if (str[i] == ' ') {
				while (!st1.empty()) {
					cout << st1.top();
					st1.pop();
				}
				cout << " ";
			}
			else {
				st1.push(str[i]);
			}
		}
		while (!st1.empty()) {
			cout << st1.top();
			st1.pop();
		}
		cout << endl;
	}
}