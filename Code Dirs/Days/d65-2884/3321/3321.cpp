// Link: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(n)
// Approach: We can use a sliding window approach to solve this problem. We can maintain a set of pairs mx and rem to keep track of the maximum and remaining elements in the current window. We can also maintain a map mp to keep track of the frequency of each element in the current window. For each element in the input array, we can update the sets and map accordingly and calculate the sum of the x largest elements in the current window. Finally, we can return the result as a vector of long long integers.
class Solution
{
public:
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        set<pair<int, int>> mx, rem;
        unordered_map<int, int> mp;
        for (int i = 0; i < k; i++)
            mp[nums[i]]++;
        long long sum = 0;
        vector<long long> res;
        for (auto &it : mp)
        {
            mx.insert({it.second, it.first});
            sum += it.first * 1ll * it.second;
        }
        while (mx.size() > x)
        {
            auto [mf, me] = (*(mx.begin()));
            mx.erase(mx.begin());
            sum -= mf * 1ll * me;
            rem.insert({mf, me});
        }

        // now traversing in remaining subarrays
        for (int i = 0; i <= n - k; i++)
        {
            res.push_back(sum);
            if (i == n - k)
                break;
            int p = nums[i], nx = nums[i + k];
            // remove prev
            int fa, fb;
            if (mp.count(p))
                fb = mp[p];
            else
                fb = 0;
            fa = (fb == 0) ? 0 : fb - 1;
            mp[p]--;
            if (mp[p] == 0)
                mp.erase(p);
            if (mx.count({fb, p}))
            {
                mx.erase({fb, p});
                if (fa != 0)
                    mx.insert({fa, p});
                sum -= p;
                // now swapping

                while (rem.size() > 0 && mx.size() < x)
                {
                    auto [remf, reme] = (*(--rem.end()));
                    rem.erase(--rem.end());
                    mx.insert({remf, reme});
                    sum += remf * 1ll * reme;
                }
                while (rem.size() > 0 && mx.size() > 0)
                {
                    auto [mxf, mxe] = (*(mx.begin()));
                    auto [remf, reme] = (*(--rem.end()));
                    if ((remf > mxf) || (remf == mxf && reme > mxe))
                    {
                        sum -= mxf * 1ll * mxe;
                        sum += remf * reme;
                        mx.erase(mx.begin());
                        rem.erase(--rem.end());
                        mx.insert({remf, reme});
                        rem.insert({mxf, mxe});
                    }
                    else
                        break;
                }
            }
            else
            {
                if (rem.count({fb, p}))
                {
                    rem.erase({fb, p});
                    if (fa != 0)
                        rem.insert({fa, p});
                }
                else
                {
                    if (fa != 0)
                        rem.insert({fa, p});

                    while (rem.size() > 0 && mx.size() < x)
                    {
                        auto [remf, reme] = (*(--rem.end()));
                        rem.erase(--rem.end());
                        mx.insert({remf, reme});
                        sum += remf * 1ll * reme;
                    }
                    while (rem.size() > 0 && mx.size() > 0)
                    {
                        auto [remf, reme] = (*(--rem.end()));
                        auto [mxf, mxe] = (*(mx.begin()));
                        if ((remf > mxf) || (remf == mxf && reme > mxe))
                        {
                            sum -= mxf * 1ll * mxe;
                            sum += remf * 1ll * reme;
                            mx.erase(mx.begin());
                            rem.erase(--rem.end());
                            mx.insert({remf, reme});
                            rem.insert({mxf, mxe});
                        }
                        else
                            break;
                    }
                }
            }
            // add next
            if (mp.count(nx))
                fb = mp[nx];
            else
                fb = 0;
            fa = fb + 1;
            mp[nx]++;
            if (mx.count({fb, nx}))
            {
                mx.erase({fb, nx});
                if (fa != 0)
                    mx.insert({fa, nx});
                sum += nx;
            }
            else
            {
                if (rem.count({fb, nx}))
                {
                    rem.erase({fb, nx});
                    rem.insert({fa, nx});
                    // now swapping
                    while (rem.size() > 0 && mx.size() < x)
                    {
                        auto [remf, reme] = (*(--rem.end()));
                        rem.erase(--rem.end());
                        mx.insert({remf, reme});
                        sum += remf * 1ll * reme;
                    }
                    while (rem.size() > 0 && mx.size() > 0)
                    {
                        auto [remf, reme] = (*(--rem.end()));
                        auto [mxf, mxe] = (*(mx.begin()));
                        if ((remf > mxf) || (remf == mxf && reme > mxe))
                        {
                            sum -= mxf * 1ll * mxe;
                            sum += remf * 1ll * reme;
                            mx.erase(mx.begin());
                            rem.erase(--rem.end());
                            mx.insert({remf, reme});
                            rem.insert({mxf, mxe});
                        }
                        else
                            break;
                    }
                }
                else
                {

                    if (fa != 0)
                        rem.insert({fa, nx});
                    while (rem.size() > 0 && mx.size() > 0)
                    {
                        auto [remf, reme] = (*(--rem.end()));
                        auto [mxf, mxe] = (*(mx.begin()));
                        if ((remf > mxf) || (remf == mxf && reme > mxe))
                        {
                            sum -= mxf * 1ll * mxe;
                            sum += remf * 1ll * reme;
                            mx.erase(mx.begin());
                            rem.erase(--rem.end());
                            mx.insert({remf, reme});
                            rem.insert({mxf, mxe});
                        }
                        else
                            break;
                    }
                    while (rem.size() > 0 && mx.size() < x)
                    {
                        auto [remf, reme] = (*(--rem.end()));
                        rem.erase(--rem.end());
                        mx.insert({remf, reme});
                        sum += remf * 1ll * reme;
                    }
                    if (i == 0)
                    {
                        cout << rem.size() << " " << mx.size() << " " << sum << endl;
                    }
                }
            }
        }
        return res;
    }
};
