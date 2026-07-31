// Link: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: Use Manacher's algorithm to find the longest palindromic substring centered at each character. Then, for each index, we can find the longest palindromic substring to the left and right of that index, and calculate the product of their lengths. We keep track of the maximum product found during this process and return it as the final answer.
class Solution
{

    vector<int> manacher(const char *s, int n)
    {
        vector<int> radii(n);
        int l = 0;
        int r = 0;
        for (int c = 0; c < n; c++)
        {
            int dist = r - c;
            // if c inside earlier palindrime, use mirror trick
            if (c < r)
                radii[c] = min(dist, radii[l + dist]);

            // set L, R to edges of current palindrome
            int L = c - radii[c];
            int R = c + radii[c];
            // increase L,R while still palindrome
            while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
            {
                radii[c]++;
                L--;
                R++;
            }
            // if grown beyond prev palindrome, grow
            if (R > r)
            {
                l = L;
                r = R;
            }
        }
        return radii;
    }

public:
    long long maxProduct(string s)
    {
        vector<int> radii = manacher(s.data(), s.length());
        int n = s.size();

        // store biggest palindrome as (r, c)
        vector<int> max_L(n);
        vector<int> max_R(n);

        for (int i = 1; i < n; i++)
        {
            int r = max_L[i - 1];
            // possibly bigger if a bigger one at i-r;
            max_L[i] = r + (radii[i - r - 1] > r);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            int r = max_R[i + 1];
            // possibly bigger if a bigger one at i-r;
            max_R[i] = r + (radii[i + r + 1] > r);
        }

        long long answer = 0;
        for (int i = 0; i < n - 1; i++)
        {
            long long d_L = 2 * max_L[i] + 1;
            long long d_R = 2 * max_R[i + 1] + 1;
            long long prod = d_L * d_R;
            answer = (prod > answer) ? prod : answer;
        }

        return answer;
    }
};
