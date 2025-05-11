#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int map[200][200];
int br = 100;
int bc = 100;
int sc = 100;
int sr = 100;
int mr = 100;
int mc = 100;
int dir = 2;
int drow[4] = { -1,0,1,0 };  //상 우 하 좌 
int dcol[4] = { 0,1,0,-1 };
int main() {
	int N;
	cin >> N;
	char ch;
	map[mr][mc] = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> ch;
		if (ch == 'R') {
			dir = (dir + 1) % 4;
		}
		if (ch == 'L') {
			dir = (dir + 3) % 4;
		}
		if (ch == 'F') {
			mr += drow[dir];
			mc += dcol[dir];
			br = max(br, mr);
			bc = max(bc, mc);
			sr = min(sr, mr);
			sc = min(sc, mc);
			map[mr][mc] = 1;
		}
	}
	for (int i = sr; i <= br; i++)
	{
		for (int j = sc; j <= bc; j++)
		{
			if (map[i][j] == 1)cout << ".";
			else if (map[i][j] == 0)cout << "#";
		}
		cout << '\n';
	}
}