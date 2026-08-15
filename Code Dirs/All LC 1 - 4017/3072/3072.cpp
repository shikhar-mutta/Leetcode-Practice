// Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct BIT {
        vector<int> tree;
        int n;
        BIT(int n) : n(n), tree(n + 1, 0) {}
        void update(int i) {
            for (i++; i <= n; i += i & (-i)) tree[i]++;
        }
        int query(int i) { // count of elements with rank <= i
            int s = 0;
            for (i++; i > 0; i -= i & (-i)) s += tree[i];
            return s;
        }
    };

    vector<int> resultArray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        auto rank = [&](int x) {
            return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
        };
        int sz = sorted.size();

        vector<int> a = {nums[0]}, b = {nums[1]};
        BIT bitA(sz), bitB(sz);
        bitA.update(rank(nums[0]));
        bitB.update(rank(nums[1]));

        for (int i = 2; i < (int)nums.size(); i++) {
            int x = nums[i];
            int r = rank(x);
            int countA = a.size() - bitA.query(r); // elements > x in a
            int countB = b.size() - bitB.query(r);
            if (countA > countB || (countA == countB && a.size() <= b.size())) {
                a.push_back(x);
                bitA.update(r);
            } else {
                b.push_back(x);
                bitB.update(r);
            }
        }
        for (int x : b) a.push_back(x);
        return a;
    }
};
