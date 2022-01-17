#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[100001];
pair<int, int> edge;
pair<long long, long long> cnt; // int로 계산했다가 틀렸음..
int visit[100001];

int bfs(int st, int en, long long& cnt) { // bfs로 순환 찾기
	queue<int> q;
	q.push(st);
	visit[st] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cnt++;

		if (cur == en) return 1;

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (!visit[next]) {
				visit[next] = 1;
				q.push(next);
			}
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1, a, b; i <= m; i++) {
		cin >> a >> b;
		if (i == k) edge = { a, b };
		else {
			v[a].push_back(b);
			v[b].push_back(a);
		}
	}

	if (bfs(edge.first, edge.second, cnt.first))
		cout << "0\n";
	else {
		bfs(edge.second, edge.first, cnt.second);
		cout << cnt.first * cnt.second << '\n';
	}
	
	return 0;
}
