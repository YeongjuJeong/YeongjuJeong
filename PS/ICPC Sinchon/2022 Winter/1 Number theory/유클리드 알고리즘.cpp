/*

gcd(a, b) = gcd(a + cb, b) 증명

gcd(a, b) = d라고 하고, gcd(a + cb, b) = d'이라고 한다.
1) a, b는 d의 배수이므로 a + cb, b 또한 d의 배수. 그런데 d'이 최대공약수이므로 d' >= d.
2) a + cb, b는 d'의 배수이므로 (a + cb) - c * b 또한 d'의 배수. 그런데 d가 최대공약수이므로 d >= d'.
따라서 d = d'.

gcd(a, b) = gcd(a % b, b)라고 생각하면 됨. (a % b는 a에서 b를 계속 빼줬다고 생각하면 됨. 그니까 cb랑 다름없음)

gcd(a, b)를 구하는 과정에서 max(a, b)가 절반 이하가 되므로 시간복잡도는 O(logn).

*/

#define ll long long

ll gcd(ll x, ll y) {
  if (!y) return x; // y가 0이면 x return
  return gcd(y, x % y);
}
