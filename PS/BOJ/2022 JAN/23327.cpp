/*
2차원 배열, 2차원 벡터로 풀려고 안간힘을 쓰다가 계속 메모리 초과가 나서
1부터 곱의 합을 계속해서 써 본 결과
multi[b] - multi[a - 1] - sum[a - 1] * (sum[b] - sum[a - 1])
라는 수식을 얻어냈다!
아주 많이 돌아왔다
*/

#include <iostream>
#define ll long long
using namespace std;

ll interest[100001], sum[100001], multi[100001];

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> interest[i];
        multi[i] += multi[i - 1] + sum[i - 1] * interest[i];
        sum[i] += sum[i - 1] + interest[i];
    }

    for (int j = 0, a, b; j < m; j++) {
        cin >> a >> b;
        cout << multi[b] - multi[a - 1] - sum[a - 1] * (sum[b] - sum[a - 1]) << '\n';
    }

    return 0;
}
