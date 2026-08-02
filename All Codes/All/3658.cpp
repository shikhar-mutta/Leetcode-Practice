// Link: https://leetcode.com/problems/gcd-of-odd-and-even-sums/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
// Approach: sum of first n odd numbers = n^2, sum of first n even numbers
// = n*(n+1). gcd(n^2, n*(n+1)) = n*gcd(n,n+1) = n (consecutive integers
// are always coprime).
class Solution
{
public:
    int gcdOfOddEvenSums(int n)
    {
        return n;
    }
};
