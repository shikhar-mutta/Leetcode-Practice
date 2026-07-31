// Link: https://leetcode.com/problems/count-pairs-of-nodes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m + q) where n is the number of nodes, m is the number of edges, and q is the number of queries
// SC: O(n + m) where n is the number of nodes and m is the number of edges
// Approach: We can use a stack to keep track of the cars that are still on the road. We will iterate through the cars from right to left and for each car, we will check if it will collide with the car in front of it. If it will, we will calculate the time it will take for the collision to happen and store it in the answer array. If it will not collide, we will pop the car from the stack and continue checking with the next car in the stack. We will continue this process until we have checked all the cars. Finally, we will return the answer array.
using cd = complex<double>;
class Solution_FFT
{
public:
    void fft(vector<cd> &arr, bool inverse = false)
    {
        int U = arr.size();
        if ((U & (U - 1)) != 0)
        {
            throw std::invalid_argument("U must be a power of 2");
        }
        int j = 0;
        for (int i = 1; i < U; i++)
        {
            int b = U >> 1;
            while (j & b)
            {
                j ^= b;
                b >>= 1;
            }
            j = j ^ b;
            if (j < i)
                swap(arr[i], arr[j]);
        }

        for (int l = 2; l <= U; l <<= 1)
        {
            int h = l / 2;
            cd w = polar(1.0, 2.0 * M_PI / l * (inverse ? -1 : 1));
            for (int blk = 0; blk < U; blk += l)
            {
                cd w_i = 1;
                for (int i = 0; i < h; i++)
                {
                    cd u = arr[blk + i];
                    cd v = w_i * arr[blk + i + h];
                    arr[blk + i] = u + v;
                    arr[blk + i + h] = u - v;
                    w_i *= w;
                }
            }
        }

        if (inverse)
        {
            for (int i = 0; i < U; i++)
            {
                arr[i] /= U;
            }
        }
    }
    vector<int> countPairs(int n, vector<vector<int>> &edges,
                           vector<int> &queries);
};
class Solution_Histogram
{
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges,
                           vector<int> &queries);
};
class Solution_Sort_Backtrack
{
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges,
                           vector<int> &queries);
};

class Solution
{
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges,
                           vector<int> &queries)
    {
        // auto s = Solution_FFT();
        auto s = Solution_Histogram();
        // auto s = Solution_Sort_Backtrack();
        return s.countPairs(n, edges, queries);
    }
};

vector<int> Solution_FFT::countPairs(int n, vector<vector<int>> &edges,
                                     vector<int> &queries)
{
    vector<int> deg(n + 1, 0);
    unordered_map<long long, int> shared;
    for (auto &e : edges)
    {
        deg[e[0]]++;
        deg[e[1]]++;
        if (e[1] < e[0])
            swap(e[0], e[1]);
        shared[1LL * e[1] * (n + 1) + e[0]]++;
    }

    size_t U = 1;
    size_t MX =
        max(*ranges::max_element(queries), 2 * *ranges::max_element(deg));
    while (U <= MX)
        U <<= 1;

    vector<cd> poly(U, 0);
    for (int i = 1; i <= n; i++)
    {
        poly[deg[i]] += 1;
    }
    fft(poly);
    for (int i = 0; i < U; i++)
    {
        poly[i] *= poly[i];
    }
    fft(poly, true);

    vector<long long> cnt(U, 0);
    for (int i = 0; i < U; i++)
    {
        cnt[i] = llround(poly[i].real());
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[deg[i] + deg[i]] -= 1;
    }
    for (int i = 0; i < U; i++)
    {
        cnt[i] /= 2;
    }

    for (auto &[ij, ij_c] : shared)
    {
        int i = ij / (n + 1);
        int j = ij % (n + 1);
        cnt[deg[i] + deg[j]] -= 1;
        cnt[deg[i] + deg[j] - ij_c] += 1;
    }

    vector<long long> S(U + 1, 0);
    for (int i = 0; i < U; i++)
    {
        S[i + 1] = S[i] + cnt[i];
    }

    vector<int> ans;
    for (auto &q : queries)
    {
        ans.push_back(S.back() - S[q + 1]);
    }
    return ans;
}
vector<int> Solution_Histogram::countPairs(int n, vector<vector<int>> &edges,
                                           vector<int> &queries)
{

    vector<int> deg(n + 1, 0);
    unordered_map<long long, int> ij_cnt;
    for (auto &e : edges)
    {
        deg[e[0]]++;
        deg[e[1]]++;
        if (e[0] > e[1])
            swap(e[0], e[1]);
        ij_cnt[1LL * (n + 1) * e[0] + e[1]]++;
    }

    unordered_map<int, int> freq;
    for (int i = 1; i <= n; i++)
    {
        freq[deg[i]]++;
    }
    size_t MX = *ranges::max_element(queries);
    MX = max(MX, 2 * edges.size());

    vector<long long> H(MX + 1, 0);
    for (auto &[d1, c1] : freq)
    {
        for (auto &[d2, c2] : freq)
        {
            if (d1 > d2)
                continue;
            H[d1 + d2] += (d1 == d2) ? (c1 * (c1 - 1)) / 2 : c1 * c2;
        }
    }

    for (auto &[ij, cnt] : ij_cnt)
    {
        int i = ij / (n + 1);
        int j = ij % (n + 1);
        H[deg[i] + deg[j]]--;
        H[deg[i] + deg[j] - cnt]++;
    }

    vector<long long> S(MX + 2, 0);
    for (int i = 0; i <= MX; i++)
    {
        S[i + 1] = S[i] + H[i];
    }

    vector<int> ans;
    for (auto &q : queries)
    {
        ans.push_back(S.back() - S[q + 1]);
    }
    return ans;
}

vector<int> Solution_Sort_Backtrack::countPairs(int n,
                                                vector<vector<int>> &edges,
                                                vector<int> &queries)
{
    vector<int> deg(n + 1, 0);
    unordered_map<long long, int> shared;
    for (auto &e : edges)
    {
        deg[e[0]]++;
        deg[e[1]]++;
        if (e[1] < e[0])
            swap(e[0], e[1]);
        shared[1LL * e[1] * (n + 1) + e[0]]++;
    }

    vector<int> sorted_deg(deg.begin() + 1, deg.end());
    ranges::sort(sorted_deg);

    vector<int> ans;
    for (auto &q : queries)
    {
        int l = 0;
        int r = n - 1;
        int cnt = 0;
        while (l < r)
        {
            if (sorted_deg[l] + sorted_deg[r] > q)
            {
                cnt += r - l;
                r--;
            }
            else
            {
                l++;
            }
        }

        for (auto &[s, c] : shared)
        {
            int u = s / (n + 1);
            int v = s % (n + 1);
            if (deg[u] + deg[v] > q && deg[u] + deg[v] - c <= q)
            {
                cnt--;
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}