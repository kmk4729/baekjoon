#include <iostream>

using namespace std;

int arr[1500000];

int main() {
	int num;
	cin >> num;

	arr[0] = 1e8;
	for (int i = 2; i <= num; i++)
	{
		arr[i] = 1e8;
		if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}
		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}
		arr[i] = min(arr[i], arr[i - 1] + 1);
	}
	cout << arr[num];
}