#include <iostream>
#include <algorithm>
using namespace std;

string str[5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) cin >> str[i];

	int len = str[0].length();
	for (int i = 0; i < len; i++) {
		if (str[0][i] == '.') {
			if (str[1][i] != '.') { // 도약준비
				str[0][i] = 'o';
				str[1][i] = 'w';
				str[2][i] = 'l';
				str[3][i] = 'n';
				str[4][i] = '.';
			}
		}
		else { // 도약 중
			str[0][i] = '.';
			str[1][i] = 'o';
			str[2][i] = 'm';
			str[3][i] = 'l';
			str[4][i] = 'n';
		}
	}

	for (int i = 0; i < 5; i++) cout << str[i] << '\n';

	return 0;
}
