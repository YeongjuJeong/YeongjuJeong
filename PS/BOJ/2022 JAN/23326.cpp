#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, q, dohyun = 1; cin >> n >> q;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x) s.insert(i);
    }

    for (int i = 0, x, y; i < q; i++) {
        cin >> x;
        if (x == 1) {
            cin >> y;
            if (s.find(y) == s.end()) s.insert(y);
            else s.erase(y);
        }
        else if (x == 2) {
            cin >> y;
            dohyun = (dohyun + y - 1) % n + 1;
        }
        else {
            if (s.empty()) cout << "-1\n";
            else if (s.lower_bound(dohyun) == s.end())
                cout << *s.begin() + n - dohyun << '\n';
            else
                cout << *s.lower_bound(dohyun) - dohyun << '\n';
        }
    }

    return 0;
}
