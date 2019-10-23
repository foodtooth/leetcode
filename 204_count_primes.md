https://leetcode.com/problems/count-primes/

## Idea
[Sieve of Eratosthenes(埃拉托斯特尼筛法)](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)

## Code

```cpp
class Solution {
 public:
  int countPrimes(int n) {
    if (n < 3) return 0;

    std::vector<bool> is_prime(n, true);
    int count{0};

    for (int i = 2; i * i < n; ++i) {
      if (!is_prime[i]) continue;
      // Find the first one x that is prime, mark x*x, ..., x*x + nx as
      // non-prime
      for (int j = i * i; j < n; j += i) {
        if (is_prime[j]) {
          is_prime[j] = false;
          ++count;
        }
      }
    }
    return n - count - 2;
  }
};
```