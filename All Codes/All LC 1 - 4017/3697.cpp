// Link: https://leetcode.com/problems/compute-decimal-representation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n). SC: O(log n).
    vector<int> decimalRepresentation(int n)
    {
        vector<int> ans;
        int i = 0;
        while (n > 0)
        {
            if (n % 10 != 0)
                ans.push_back(n % 10 * pow(10, i));
            n /= 10;
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
