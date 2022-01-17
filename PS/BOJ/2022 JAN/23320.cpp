#include <iostream>
#include <algorithm>
using namespace std;

int n, x, y, a = 0, b = 0;
int arr[101];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> x >> y;

	sort(arr, arr + n, greater<>());

	for (int i = 0; i < n; i++)
		if (++a >= n * x / 100) break;

	for (int i = 0; i < n; i++) {
		if (arr[i] < y) break;
		b++;
	}

	cout << a << ' ' << b << '\n';

	return 0;
}
