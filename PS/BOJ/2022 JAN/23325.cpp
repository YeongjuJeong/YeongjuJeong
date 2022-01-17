#include <iostream>
#define INF 1e9
using namespace std;

int dp[200001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str; cin >> str;
	str = " +" + str;
	int len = str.length();
	fill(dp, dp + len + 1, -INF);
	dp[0] = 0;
	for (int i = 0; i < len; i++) {
		if (dp[i] == -INF) continue;
		if (str.substr(i + 1, 2) == "+-") // +1
			dp[i + 2] = max(dp[i + 2], dp[i] + 1);
		if (str.substr(i + 1, 2) == "++") // +10
			dp[i + 2] = max(dp[i + 2], dp[i] + 10);
		if (str.substr(i + 1, 3) == "++-") // +11
			dp[i + 3] = max(dp[i + 3], dp[i] + 11);
		if (str.substr(i + 1, 2) == "--") // -1
			dp[i + 2] = max(dp[i + 2], dp[i] - 1);
		if (str.substr(i + 1, 2) == "-+") // -10
			dp[i + 2] = max(dp[i + 2], dp[i] - 10);
		if (str.substr(i + 1, 3) == "-+-") // -11
			dp[i + 3] = max(dp[i + 3], dp[i] - 11);
	}

	cout << dp[len - 1] << '\n';
	
	return 0;
}
