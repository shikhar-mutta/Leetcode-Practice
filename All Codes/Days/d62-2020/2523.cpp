// Link: https://leetcode.com/problems/closest-prime-numbers-in-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1e6 log log 1e6) one-time precompute, O(right - left) per query
// SC: O(1e6) for the prime list and the smallest-larger-prime index
// Approach: precompute every prime up to 1e6 once at load time (sieve,
// packed into a flat Primes[] array) plus, for every value i, the index
// of the smallest prime >= i. A query then just walks consecutive
// prime pairs starting from the smallest prime >= left, tracking the
// pair with the smallest gap until a prime exceeds right.
int Primes[78498];
int SmallestLargerPrimeIndex[1000001];

int init = []() {
    vector<bool> Numbers(1000000, true);
    Numbers[0] = false;
    int currentprime = 2;
    int num = currentprime;
    while(currentprime < 1000) {
        num += currentprime;
        if (num-1 < 1000000) {
            Numbers[num-1] = false;
        }
        else {
            currentprime++;
            if (currentprime >= 1000) break;
            while (!Numbers[currentprime-1]) {
                currentprime++;
                if (currentprime >= 1000) break;
            }
            num = currentprime;
        }
    }

    int index = 0;

    for (int i = 0; i < 1000000; i++) {
        if (Numbers[i]) {
            Primes[index++] = i+1;
        }
    }

    int j = 0;
    for (int i = 1; i <= 1000000; i++) {
        while (j < 78498 && Primes[j] < i) {
            j++;
        }

        if (j < 78498) {
            SmallestLargerPrimeIndex[i] = j;
        } else {
            SmallestLargerPrimeIndex[i] = 1000001;
        }
    }

    return 0;

}();


class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> res(2, -1);
        int prime1 = 0, prime2 = 0;
        int minn = 10000000;
        int ix = SmallestLargerPrimeIndex[left];

        while (prime2 <= right) {
            if (ix <= 78496) {
                prime1 = Primes[ix];
                prime2 = Primes[ix+1];
            }
            else {
                break;
            }

            if (prime2 <= right) {
                int diff = prime2-prime1;
                if (minn > diff) {
                    minn = diff;
                    res[0] = prime1;
                    res[1] = prime2;
                }
            }
            else {
                break;
            }
            ix++;
        }

        return res;
    }
};
