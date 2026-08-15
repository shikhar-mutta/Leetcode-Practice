// Link: https://leetcode.com/problems/threshold-majority-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((N + Q) * sqrt(N)) where N is the size of nums and Q is the number of queries
// SC: O(N) for frequency arrays and compressed nums
// Approach: The solution uses Mo's algorithm to efficiently answer the threshold majority queries. It first compresses the input numbers to reduce the range of values, then sorts the queries based on their left and right indices using block decomposition. For each query, it maintains a frequency array to count occurrences of each number in the current range and keeps track of the maximum frequency and corresponding element. If the maximum frequency meets or exceeds the threshold, it records the result; otherwise, it returns -1.
struct Query
{
    int L, R, threshold, id;
};
class Solution
{
public:
    vector<int> subarrayMajority(vector<int> &nums,
                                 vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        sorted_nums.erase(unique(sorted_nums.begin(), sorted_nums.end()),
                          sorted_nums.end());
        vector<int> cnums(n);
        for (int i = 0; i < n; i++)
            cnums[i] =
                lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) -
                sorted_nums.begin();
        int M = sorted_nums.size();
        vector<int> freq(M);
        vector<int> temp_f(M);
        int q_count = queries.size();
        vector<int> ans(q_count, -1);
        vector<Query> Q(q_count);
        for (int i = 0; i < q_count; i++)
            Q[i] = {queries[i][0], queries[i][1], queries[i][2], i};
        int block_size = max(1, (int)sqrt(n));
        sort(Q.begin(), Q.end(), [&](auto a, auto b)
             {
            int block_a = a.L / block_size;
            int block_b = b.L / block_size;
            if (block_a != block_b)
                return block_a < block_b;
            else
                return a.R < b.R; });
        // for (auto q : Q)
        //   cout << q.L << " " << q.R << " " << q.id << endl;
        int current_block = -1;
        int L_ptr, R_ptr;
        int max_f = -1, element = -1;
        for (auto q : Q)
        {
            if (current_block != q.L / block_size)
            {
                fill(freq.begin(), freq.end(), 0);
                current_block = q.L / block_size;
                max_f = -1;
                element = -1;
                R_ptr = min((current_block + 1) * block_size, n);
            }
            if (q.L / block_size == q.R / block_size)
            {
                fill(temp_f.begin(), temp_f.end(), 0);
                int element = -1;
                int max_f = -1;
                for (int i = q.L; i <= q.R; i++)
                {
                    int c = cnums[i];
                    temp_f[c]++;
                    if (temp_f[c] > max_f)
                    {
                        max_f = temp_f[c];
                        element = nums[i];
                    }
                    else if (temp_f[c] == max_f and nums[i] < element)
                        element = nums[i];
                }
                if (max_f >= q.threshold)
                    ans[q.id] = element;
                continue;
            }
            int B_right = min((current_block + 1) * block_size, n);
            L_ptr = B_right - 1;
            while (R_ptr <= q.R)
            {
                int c = cnums[R_ptr];
                freq[c]++;
                if (freq[c] > max_f)
                {
                    max_f = freq[c];
                    element = nums[R_ptr];
                }
                else if (freq[c] == max_f and nums[R_ptr] < element)
                    element = nums[R_ptr];
                R_ptr++;
            }
            int temp_max_f = max_f;
            int temp_element = element;
            while (q.L <= L_ptr)
            {
                int c = cnums[L_ptr];
                freq[c]++;
                if (freq[c] > temp_max_f)
                {
                    temp_max_f = freq[c];
                    temp_element = nums[L_ptr];
                }
                else if (freq[c] == temp_max_f and nums[L_ptr] < temp_element)
                    temp_element = nums[L_ptr];
                L_ptr--;
            }
            if (temp_max_f >= q.threshold)
                ans[q.id] = temp_element;
            L_ptr = B_right - 1;
            while (q.L <= L_ptr)
            {
                int c = cnums[L_ptr];
                freq[c]--;
                L_ptr--;
            }
        }
        return ans;
    }
};
