#include <queue>
#include <iostream>
using namespace std;

int main() {
	queue<int> q1;
	int num1;
	int num2;
	int ind = 0;
	cin >> num1 >> num2;
	for (int i = 0; i < num1; i++)
	{
		q1.push(i + 1);
	}
	cout << "<";
	while (!q1.empty()) {
		ind++;
		int item = q1.front();
		q1.pop();
		if (ind % num2 != 0) {
			q1.push(item);
		}
		else {
			cout << item;
			if (!q1.empty()) {
				cout << ", ";
			}
		}
	}
	cout << ">";
}
