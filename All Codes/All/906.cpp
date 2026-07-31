// Link: https://leetcode.com/problems/super-palindromes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(10^5 * log(10^18))  SC: O(log(10^18))
// Approach: Generate all palindromes up to sqrt(r) and check if their squares are palindromes and in the range [l, r]. To generate palindromes, we can take a prefix and append its reverse to it. We can also take a prefix, remove the last digit, and append its reverse to it to generate odd-length palindromes.
// For each palindrome, we check if its square is a palindrome and in the range [l, r].
// We can check if a number is a palindrome by reversing it and comparing it to the original number.
typedef long long ll;
class Solution
{
public:
    bool isPalindrome(ll num)
    {
        ll rev = 0, temp = num;
        while (temp != 0)
        {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        return rev == num;
    }

    ll pal(ll prefix, ll suffix)
    {
        while (suffix > 0)
        {
            prefix = prefix * 10 + suffix % 10;
            suffix /= 10;
        }
        return prefix;
    }
    int superpalindromesInRange(string left, string right)
    {
        int ans = 0;
        ll l = stol(left), r = stol(right);
        ll sqrt_l = sqrt(l), sqrt_r = sqrt(r), num = 0;
        for (ll i = 1; num <= sqrt_r; i++)
        {
            num = pal(i, i);
            if (num >= sqrt_l && num <= sqrt_r && isPalindrome(num * num))
                ans++;
            num = pal(i, i / 10);
            if (num >= sqrt_l && num <= sqrt_r && isPalindrome(num * num))
                ans++;
        }
        return ans;
    }
};