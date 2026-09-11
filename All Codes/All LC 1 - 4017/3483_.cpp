// Link: https://leetcode.com/problems/unique-3-digit-even-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(900) ~ O(1), SC: O(10) ~ O(1)
    int totalNumbers(vector<int> &digits)
    {
        vector<int> freq(10, 0); // Cnt freq of each digit
        for (int d : digits)
            freq[d]++;

        int cnt = 0;
        for (int num = 100; num <= 998; num += 2)
        {
            // Get the digits of the number
            int a = num / 100, b = (num / 10) % 10, c = num % 10;
            // Reduce freq for the digits of the number
            freq[a]--;
            freq[b]--;
            freq[c]--;
            // If all digits are available, count this number
            if (freq[a] >= 0 && freq[b] >= 0 && freq[c] >= 0)
                cnt++;
            // Restore freq for the digits of the number
            freq[a]++;
            freq[b]++;
            freq[c]++;
        }
        return cnt;
    }
};
