#include <iostream>
#define ll long long
using namespace std;

ll gcd(ll x, ll y) {
    if (!y) return x;
    return gcd(y, x % y);
}


int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    ll a, d, q, x, l, r;
    cin >> a >> d >> q;

    while (q--) {
        cin >> x >> l >> r;
        if (x == 1) {
            cout << (r - l + 1) * (2 * a + (l - 1) * d + (r - 1) * d) / 2 << '\n';
        }
        else { // x == 2
            if (l == r) cout << a + (l - 1) * d << '\n';
            else cout << gcd(a, d) << '\n';
            // gcd(a, a + d) = gcd(a, d)
        }
    }

    return 0;
}
