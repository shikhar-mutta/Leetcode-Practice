// Link: https://leetcode.com/problems/find-array-given-subset-sums/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^n)  SC: O(2^n)
// Approach: Use a map to store the counts of each sum. The smallest sum is always 0, and the next smallest sum is either x or -x, where x is an element of the original array. We can find x by taking the difference between the two smallest sums. Then we can partition the sums into two groups: those that include x and those that don't. We can repeat this process until we have found all elements of the original array.
struct Sortmap
{
    array<int, 20001> next{};
    array<int, 20001> counts{};
    int tail{0};
};
class Solution
{
public:
    vector<int> recoverArray(int n, vector<int> &sums)
    {
        vector<int> ans{};
        Sortmap a{};
        Sortmap b{};
        for (const int &sum : sums)
        {
            ++a.counts[sum + 10000];
        }
        for (int i{0}; i < 20001; ++i)
        {
            if (a.counts[i])
            {
                a.next[i] = -1;
                a.next[a.tail] = i;
                a.tail = i;
            }
        }
        b.next[0] = -1;
        while (ans.size() < n)
        {
            const int smallest = (a.counts[0]) ? 0 : a.next[0];
            int cur{0};
            if (a.counts[smallest] > 1)
            {
                const int zeros = log(a.counts[smallest]) / log(2);
                const int div = (a.counts[smallest] % 2)
                                    ? a.counts[smallest] - 1
                                    : a.counts[smallest];
                ans.insert(ans.end(), zeros, 0);
                while (cur >= 0)
                {
                    a.counts[cur] /= div;
                    cur = a.next[cur];
                }
            }
            else
            {
                int term = a.next[smallest] - smallest;
                cur = 0;
                a.tail = cur;
                while (a.next[cur] >= 0)
                {
                    if (a.counts[cur])
                    {
                        a.next[a.tail] = cur;
                        a.tail = cur;
                        a.counts[cur + term] -= a.counts[cur];
                        b.counts[cur + term] = a.counts[cur];
                        b.next[cur + term] = -1;
                        b.next[b.tail] = cur + term;
                        b.tail = cur + term;
                    }
                    else
                    {
                        a.next[a.tail] = a.next[cur];
                    }
                    cur = a.next[cur];
                }
                if (b.counts[10000])
                {
                    swap(a, b);
                    term *= -1;
                }
                cur = 0;
                b.tail = 0;
                int temp{};
                while (cur >= 0)
                {
                    b.counts[cur] = 0;
                    temp = b.next[cur];
                    b.next[cur] = 0;
                    cur = temp;
                }
                b.next[0] = -1;
                ans.push_back(term);
            }
        }
        return ans;
    }
};