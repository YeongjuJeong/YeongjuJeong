// 에라토스테네스의 체를 이용하면 1 ~ n 까지의 모든 수에 대한 소수 판정을 O(nlog(logn)) 정도에 할 수 있음.
// 대신 공간복잡도가 O(n)
// 하나의 소수판정은 에라토스테네스의 체가 더 느리다

#define ll long long

ll sieve[101010];

bool init() {
    for (ll i = 2; i < 101010; i++) {
        if (sieve[i]) continue; // sieve[i]가 0이 아니면 합성수
        for (ll j = i + i; j < 101010; j += i) sieve[j] = 1;
        // for (ll j = i * i; j < 101010; j += i) sieve[j] = 1; 이걸로 하면 nloglogn
    }
}

/*

i = 2
j = 4, 6, 8, ...

i = 3
j = 9, 12, 15, ...

i = 4 continue

i = 5
j = 25, 30, 35, ...

i = 6 continue

i = 7
j = 49, 56, 63, ...

...

*/

/*

nloglogn은 어디서 나왔을까?

바깥 for문: n

i = 2
j = 4, 6, 8, ...

i = 3
j = 9, 12, 15, ...

i = 4

i = 5
j = 25, 30, 35, ...

2 이후로 i가 짝수일 때는 continue 이므로,
j는 n의 절반 이하로 실행됨 -> log(안쪽 반복문에서의 반복 횟수)
j가 실행 될 때 반복이 절반 이하로 일어남 -> logn
-> n log (log n)

*/
