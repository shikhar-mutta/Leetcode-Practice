// Link: https://leetcode.com/problems/sum-of-number-and-its-reverse/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(limit * d) one-time precompute (d = digit count, ~6), O(1) per query
// SC: O(limit) for the answer bitset
// Approach: precompute, at static-init time, every reachable sum i + reverse(i)
// for i in [0, limit] into a bitset, then each query is just a bit test.
static constexpr int limit = 100000;
static const std::bitset<limit + 1> answer =
    [] static noexcept -> std::bitset<limit + 1> {
    std::bitset<limit + 1> answer;
    for (int i = 0; i <= limit; ++i) {
        int x = i;
        int rev = 0;
        do {
            rev *= 10;
            rev += x % 10;
            x /= 10;
        } while (x);
        if (i + rev <= limit)
            answer.set(i + rev);
    }
    return answer;
}();

struct Solution {
    static constexpr bool sumOfNumberAndReverse(int num) noexcept {
        return answer.test(num);
    }
};
