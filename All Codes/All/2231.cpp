// Link: https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n) + O(n) ~ O(nlogn). SC: O(n).
    int largestInteger(int num)
    {
        string s = to_string(num);
        int n = s.length();
        vector<int> parity(n, 0), even, odd;
        for (int i = 0; i < n; i++)
        {
            parity[i] = (s[i] - '0') % 2;
            if (parity[i])
                odd.push_back(s[i] - '0');
            else
                even.push_back(s[i] - '0');
        }
        sort(even.rbegin(), even.rend());
        sort(odd.rbegin(), odd.rend());
        int evenIdx = 0, oddIdx = 0, idx = 0;
        while (idx < n)
        {
            if (parity[idx] == 0)
                s[idx] = even[evenIdx++] + '0';
            else
                s[idx] = odd[oddIdx++] + '0';
            idx++;
        }
        return stoi(s);
    }
};
