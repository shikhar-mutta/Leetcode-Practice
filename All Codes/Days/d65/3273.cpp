// Link: https://leetcode.com/problems/minimum-amount-of-damage-dealt-to-bob/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the length of the damage array
// SC: O(n) where n is the length of the damage array
// Approach: We can use a greedy approach to solve this problem. We can sort the damage array in descending order and then iterate through the damage array and calculate the total damage dealt to Bob. We can keep track of the total damage dealt to Bob and the total damage dealt to Alice. We can return the total damage dealt to Bob as the result.
class Solution
{
public:
#define ll long long

    long long minDamage(int power, vector<int> &damage, vector<int> &health)
    {

        int n = damage.size();

        vector<pair<ll, ll>> v;

        ll totalDamage = 0;

        for (int i = 0; i < n; i++)
        {
            ll t = (health[i] + power - 1) / power;
            v.push_back({damage[i], t});
            totalDamage += damage[i];
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b)
             { return a.first * b.second > b.first * a.second; });

        ll ans = 0;

        for (auto &[d, t] : v)
        {
            ans += totalDamage * t;
            totalDamage -= d;
        }

        return ans;
    }
};