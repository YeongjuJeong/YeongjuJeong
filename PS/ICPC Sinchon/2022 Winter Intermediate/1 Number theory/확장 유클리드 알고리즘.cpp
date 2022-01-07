/*

확장 유클리드 알고리즘
a, b, c가 상수로 주어졌을 때, ax + by = c를 만족하는 두 정수 x, y를 구하는 알고리즘

우선 c가 gcd(a, b)의 배수가 아니면 해가 존재하지 않음

c가 gcd(a, b)의 배수라면 항상 해가 존재?
c가 gcd(a, b)의 배수라면 x와 y를 c/gcd(a, b)배 해주면 되기 때문에 ax + by = gcd(a, b)를 구하는 것과 동치

ax + by = gcd(a, b)
ax * c / gcd(a, b) + by * c / gcd(a, b) = c

최대공약수를 다루는 또 다른 표현
S = {ma + nb | m, n (삼지창) Z , ma, nb > 0} 인 집합 S의 최소 원소는 gcd(a, b)

S는 자명하게도 공집합이 아니고 S는 자연수 집합이므로 최소 원소가 존재.
이 최소 원소를 d라고 하고 d = gcd(a, b)임을 보인다

gcd(a, b) | d 이다. (gcd(a, b)가 d의 약수)
d = ma + nb 꼴이고, (gcd(a, b) | a), (gcd(a, b) | b)이므로 쉽게 알 수 있다.

d | gcd(a, b)를 보일건데, d | a, d | b 임을 이용해서 보이자.
a = dq + r로 둔다. (q는 몫, r은 나머지, 0 <= r < d)
r은 S에 들어가게 된다. (r = a - dq)
따라서 S의 최소 원소가 d라는 조건에 모순이므로 r = 0이고 이는 d | a 라는 뜻이다.
마찬가지고 d | b 도 유도해낼 수 있다.
따라서 gcd(a, b) = d 이다.

-> c가 gcd(a, b)의 배수라면 항상 해가 존재한다는 것이 증명되었음.

해가 항상 존재하는 것은 증명이 되었고, 확장 유클리드 알고리즘이 어떻게 동작해야 하는지를 살펴보자.
핵심적인 아이디어는 유클리드 호제법이랑 동일하다.
ax + by = 1이라는 문제를 풀어야 하는데
a = bq + r로 두면 (bq + r)x + by = 1이 되고, b(qx + y) + rx = 1 이 된다.
bx' + rx' = 1을 구하는 걸로 문제가 치환되는데, 절반 이상 줄어드므로 O(logn)이 성립한다.

*/

#define ll long long

// ax + by = 1의 값을 x, y에 저장해준다. gcd(a, b)를 return 해준다.
ll ex_gcd(ll a, ll b, ll& x, ll& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    ll ret = ex_gcd(b, a % b, x, y);
    ll temp = y;
    y = x - (a / b) * y;
    x = temp;
    if (x <= 0) {
        x += b;
        y -= a;
    }
    return ret;
}

/*

"a와 b가 법m으로 합동이다" 라는 의미는 a와 b를 m으로 나눈 나머지가 같다는 것이다.
기호로 a =(세줄) b (mod m)으로 나타낸다.
ax =(세줄) 1 (mod m)을 만족하는 x를 a의 modulo inverse라고 하고 유일하다. (중요!)

ax =(세줄) 1 (mod m)
m이 소수라고 하자. 그럼 a^(m - 2)가 modulo inverse이다. (증명은 일단 생략)
분할정복을 이용한 거듭제곱을 통해 O(logm)의 시간복잡도에 구할 수 있다.
m이 소수가 아닐 때는 확장 유클리드 호제법을 통해 구해주자.
ax =(세줄) 1이라는 것은 ax + my = 1을 만족하는 것과 동치이므로 확장 유클리드를 이용해서 x와 y를 구해주면 ㅗ딘다.

*/
