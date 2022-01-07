// 시간 복잡도 : O(root n)

#define ll long long
#include <vector>

void f(ll n) {
    vector<ll> v; // 소인수 분해 결과 저장

    for (ll i = 2; i * i <= n; i++) {
        if (n % i) continue;
        while ((n % i) == 0) { // n이 i로 나눠떨어지는동안 계속 나눠준다
            v.push_back(i);
            n /= i;
        }
    }

    if (n != 1) v.push_back(n);
    for (auto nxt : v) cout << nxt << ' ';
}

/*

if (n != 1) v.push_back(n); 이라는 조건문이 달려있는 이유
n이 11일 때를 생각해보면 된다!

*/
