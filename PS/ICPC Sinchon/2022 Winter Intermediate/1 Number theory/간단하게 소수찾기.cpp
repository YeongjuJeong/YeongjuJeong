// 간단하게 n이 소수인지 O(root(n)) 정도에 알 수 있음
// n이 합성수라고 가정하면, a * b = n을 만족하는 (min(a, b) > 1)인 (a, b)가 존재하므로 min(a, b) <= root(n)을 만족한다
// root(n) * root(n) = n 이니까 min(a, b)는 root(n)보다 작거나 같기 때문임

#define ll long long

bool pr(ll x) {
  for (ll i = 2; i * i <= x; i++) if ((x % i) == 0) return false;
  return true;
}

/*
for문의 조건문이 i * i <= x인 이유가 뭘까?
i < x 보다 시간이 짧아질 것 같긴 하다 근데 왜 가능할까?

x = 2 일 때, x = 3 일 때
i * i <= x 라면 for문 통과.
i < x 라면 for문 통과.

x = 4 일 때
i * i <= x 라면 i = 2 일 때 return false
i < x 라면 i = 2 일 때 return false

x = 5 일 때
i * i <= x 라면 i = 2 return true
i < x 라면 i = 2, 3, 4 return true

x = 6 일 때
i * i <= x 라면 i = 2 return false
i < x 라면 i = 2 return false

x = 7 일 때
i * i <= x 라면 i = 2 return true
i < x 라면 i = 2, 3, 4, 5, 6 return true

x = 8 일 때
i * i <= x 라면 i = 2 return false
i < x 라면 i = 2 return false

x = 9 일 때
i * i <= x 라면 i = 2, 3 return false
i < x 라면 i = 2, 3 return false

x = 10 일 때
i * i <= x 라면 i = 2 return false
i < x 라면 i = 2 return false

-> 2 * 2 = 4 부터 3 * 3 = 9 이전까지 (8까지)는 2 혼자서도 체크 가능함
(ex) 3의 배수인 3 * 2 = 6)

2 3 -> 2, 3 prime number
4 5 6 7 8 -> 2의 배수를 제외한 5, 7 prime number
9 10 11 12 13 14 15 -> 2의 배수, 3의 배수를 제외한 11, 13 prime number
16 17 18 19 20 21 22 23 24 -> 2의 배수(4의 배수), 3의 배수를 제외한 17, 19, 23 prime number
25 26 27 28 29 30 31 32 33 34 35 -> 2의 배수(4의 배수), 3의 배수, 5의 배수를 제외한 29, 31 prime number
36

*/
