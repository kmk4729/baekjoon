#include <queue>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int qsize;
		int qind;
		cin >> qsize >> qind;
		int data;
		int count = 0;
		queue<int> q1;
		for (int j = 0; j < qsize; j++)
		{
			cin >> data;
			q1.push(data);
		}
		bool finish = false;
		
		while (!finish) {
			int maxval = q1.front();
			for (int k = 0; k < q1.size(); k++)
			{
				if (q1.front() >= maxval) {
					maxval = q1.front();
				}
				q1.push(q1.front());
				q1.pop();
			}
			if (q1.front() == maxval) {
				count++;
				q1.pop();
				qind--;
				if (qind == -1) {
					cout << count << endl;
					for (int l = 0; l < q1.size(); l++)
					{
						q1.pop();
					}
					finish = true;
				}
			}
			else {
				q1.push(q1.front());
				q1.pop();
				qind--;
				if (qind == -1) {
					qind += q1.size();
				}
			}
		}
	}
}