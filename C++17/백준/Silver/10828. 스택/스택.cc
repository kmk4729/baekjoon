#include <stack>
#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	stack<int> stack1;
	string str;
	int data;
	for (int i = 0; i < num; i++)
	{
		cin >> str;
		if (str == "push") {
			cin >> data;
			stack1.push(data);
		}
		if (str == "top") {
			if (stack1.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << stack1.top() << endl;
			}
		}
		if (str == "size") {
			cout << stack1.size()<<endl;
		}
		if (str == "empty") {
			cout << stack1.empty() << endl;
		}
		if (str == "pop") {
			if (stack1.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout<<stack1.top()<<endl;
				stack1.pop();
			}
		}
		
	}
}
