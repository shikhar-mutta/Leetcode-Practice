// Link: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the string s
// SC: O(1)
//  Approach: Greedy
//    1. Count the number of 1's and 0's at even and odd indices.
//    2. If the length of the string is even, return the minimum number of flips required to make the string alternating.
//    3. If the length of the string is odd, iterate through the string and for each character, swap the counts of 1's and 0's.
class Solution
{
public:
    int minFlips(string s)
    {
        int o1 = 0, o0 = 0, e1 = 0, e0 = 0;
        int cnt = 0;
        for (auto x : s)
        {
            if (cnt & 1)
            {
                if (x == '1')
                    o1++;
                else
                    o0++;
            }
            else
            {
                if (x == '1')
                    e1++;
                else
                    e0++;
            }
            cnt++;
        }
        // cout << e1 << " " << e0 << " " << o1 << " " << o0 << endl;
        int n = s.size();
        if (n % 2 == 0)
            return n - max(o1 + e0, e1 + o0);
        int ans = INT_MAX;
        // cout<<e1<<" "<<e0<<" "<<o1<<" "<<o0<<endl;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                swap(o1, e1);
                int temp = e0;
                e0 = 1 + o0;
                o0 = temp - 1;
                // cout << e1 << " " << e0 << " " << o1 << " " << o0 << endl;
            }
            else
            {
                swap(o0, e0);
                int temp = e1;
                e1 = 1 + o1;
                o1 = temp - 1;
            }

            ans = min(ans, n - max(o1 + e0, e1 + o0));
        }
        return ans;
    }
};
