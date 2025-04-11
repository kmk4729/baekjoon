#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;
int result;
int fir, sec;
vector<int> normal[501];
vector<int> reversed[501];
int dist[501];
int visited[501];
void init() {
    cin >> N >> M;
    result = 0;
    memset(dist, 0, sizeof(dist));
    memset(normal, 0, sizeof(normal));
    memset(reversed, 0, sizeof(reversed));
    for (int i = 0; i < M; i++)
    {
        cin >> fir >> sec;
        normal[fir].push_back(sec);
        reversed[sec].push_back(fir);
    }

}

int bfs(int st) {
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    int counta = 1;
    q.push(st);
    visited[st] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int k : normal[now]) {
            if (visited[k])continue;
            visited[k] = 1;
            q.push(k);
            counta++;
        }
    }
    return counta;
}
int bfs_reverse(int st) {
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    int counta = 1;
    q.push(st);
    visited[st] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int k : reversed[now]) {
            if (visited[k])continue;
            visited[k] = 1;
            q.push(k);
            counta++;
        }
    }
    return counta;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    //freopen("sample_input.txt", "r", stdin);


    std::ios::sync_with_stdio(false);


    cin >> T;

    for (test_case = 1; test_case <= T; test_case++)
    {

        init();
        for (int i = 1; i <= N; i++)
        {
            dist[i]+=bfs(i);
            dist[i] += bfs_reverse(i);
        }
        for (int i = 1; i <= N; i++)
        {
            if (dist[i] == N + 1)result++;
        }
        cout << "#" << test_case << " " << result << endl;
    }

    return 0;
}
