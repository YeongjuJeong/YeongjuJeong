#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll sieve[101010]; // sieve[j]에는 j의 가장 작은 소인수 저장
void f(ll n) {
    vector<ll> v;

    for (ll i = 2; i * i <= n; i++) sieve[i] = i; // sieve 배열의 원소 초기화
    for (ll i = 2; i * i <= n; i++) {
        if (sieve[i] != i) continue; // 이미 방문됐다면 continue
        for (ll j = i * i; j <= n; j += i) sieve[j] = min(sieve[j], i);
    }

    while (n != 1) {
        v.push_back(sieve[n]);
        n /= sieve[n];
    }

    for (auto nxt : v) cout << nxt << ' ';
}

/*

n = 12일 때
sieve[2] = 2, sieve[3] = 3, ..., sieve[12] = 12

i = 2
sieve[4] = min(4, 2) = 2
sieve[6] = min(6, 2) = 2
sieve[8] = min(8, 2) = 2
sieve[10] = min(10, 2) = 2
sieve[12] = min(12, 2) = 2

i = 3
sieve[9] = min(9, 3) = 3
sieve[12] = min(2, 3) = 2

while문
sieve[12] = 2 -> v에 저장
12 / 2 = 6
sieve[6] = 2 -> v에 저장
6 / 2 = 3
sieve[3] = 3 -> v에 저장
3 / 3 = 1
n == 1이므로 while문 탈출!

*/
