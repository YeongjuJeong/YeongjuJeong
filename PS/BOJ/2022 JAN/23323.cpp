#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	long long n, m;
	
	while (t--) {
		cin >> n >> m;
		cout << (long long)(log10(n)/log10(2)) + m + 1 << '\n';
	}
	
	return 0;
}
