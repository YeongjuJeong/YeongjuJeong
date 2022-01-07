/*

n/1 + n/2 + n/3 + ... + n/n = O(nlogn) (적분해보면 쉽게 알 수 있다.

위 사실을 이용하면 우리가 애매하게 알고 있었던 여러 문제들의 시간복잡도를 분석할 수 있다.
소수의 역수의 시간복잡도는 O(nloglogn)임이 잘 알려져 있다.

ai = [n / i]로 정의해보자. ([n / i]는 n을 i로 나눴을 때 정수 부분, 즉 몫)
n = 10일 때 ai = 10, 5, 3, 2, 2, 1, 1, 1, 1

수열 ai의 서로 다른 값은 O(root(n))개이다.
1 <= i <= root(n) 일 때 i가 root(n)개 이하이므로 ok.
root(n) < i <= n 일 때, ai <= root(n)이고 감소하므로 ok.

이를 이용하면 O(root(n)) 모든 값을 전부 다 확인할 수 있다.
따라서 몫의 합도 알 수 있다.

https://atcoder.jp/contests/abc230/tasks/abc230_e

*/

#define ll long long

void solve() {
    ll sum = 0;
    for (ll i = 1, j; i <= n; i = j + 1) {
        // n / i 라는 값을 가질 때
        j = n / (n / i);
        // j는 그러한 값을 가지는 최대 j
        sum = (n / i) * (j - i + 1);
    }
}
