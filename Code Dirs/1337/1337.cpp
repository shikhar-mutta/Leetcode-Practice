// Link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int rows = mat.size(), i = 0;
        vector<pair<int, int>> ans;
        for (int i = 0; i < k; i++)
        {
            int cnt1 = 0;
            for (auto it : mat[i]) // count number of 1's in the row
                if (it)
                    cnt1++;

            ans.push_back({i, cnt1}); // store the row index and the count of 1's

            int ind = i;
            while (ind >= 1) // insertion sort to maintain the order of weakest rows
            {
                if (ans[ind].second < ans[ind - 1].second)
                {
                    swap(ans[ind], ans[ind - 1]);
                }
                else
                    break;

                ind--;
            }
        }

        for (int i = k; i < rows; i++)
        {
            int cnt1 = 0;
            for (auto it : mat[i]) // count number of 1's in the row
                if (it)
                    cnt1++;

            if (cnt1 < ans[k - 1].second) // current row is weaker than the last row in  ans
            {
                ans[k - 1] = {i, cnt1}; // replace the last row in ans with the current row

                int ind = k - 1;
                while (ind >= 1) // insertion sort to maintain the order of weakest rows
                {
                    if (ans[ind].second < ans[ind - 1].second)
                    {
                        swap(ans[ind], ans[ind - 1]);
                    }
                    else
                        break;

                    ind--;
                }
            }
        }

        vector<int> res;
        for (auto &p : ans) // extract the row indices from ans and store them in res
            res.push_back(p.first);
        return res;
    }
};
