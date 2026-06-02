// Link: https://leetcode.com/problems/defuse-the-bomb/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        if (k == 0)
            return vector<int>(code.size(), 0);

        int n = code.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            if (k > 0)
            {
                for (int j = 1; j <= k; j++)
                    sum += code[(i + j) % n]; // Circular indexing
            }
            else
            {
                for (int j = 1; j <= -k; j++)
                    sum += code[(i - j + n) % n]; // Circular indexing
            }
            ans[i] = sum;
        }
        return ans;
    }
};
