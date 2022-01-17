#include <iostream>
#include <algorithm>
using namespace std;

int n, k, sum = 0, day = 0;
int arr[2001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;

	cin >> arr[0];
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		int tmp = arr[i] - arr[0];
		sum += tmp;
		if (tmp) day++;
	}

	cout << sum << ' ' << day << '\n';

	return 0;
}
