// Link: https://leetcode.com/problems/count-pairs-with-xor-in-a-range/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * 17)  SC: O(n * 17)
// Approach: binary trie of 15-bit numbers with subtree counts. countLess(x,limit)
// counts pairs whose xor with x is strictly less than limit, walking bit by bit
// and adding the subtree matching the bit-equal branch whenever limit's bit is 1.
// answer = countLess(high+1) - countLess(low), inserting nums incrementally.
class Solution {
    struct Node { int cnt = 0; Node* ch[2] = {nullptr, nullptr}; };
    Node* root;
    static const int BITS = 15;

    void insert(int x) {
        Node* cur = root;
        for (int b = BITS; b >= 0; b--) {
            int bit = (x >> b) & 1;
            if (!cur->ch[bit]) cur->ch[bit] = new Node();
            cur = cur->ch[bit];
            cur->cnt++;
        }
    }

    int countLess(int x, int limit) {
        Node* cur = root;
        int res = 0;
        for (int b = BITS; b >= 0 && cur; b--) {
            int xb = (x >> b) & 1;
            int lb = (limit >> b) & 1;
            if (lb == 1) {
                if (cur->ch[xb]) res += cur->ch[xb]->cnt;
                cur = cur->ch[xb ^ 1];
            } else {
                cur = cur->ch[xb];
            }
        }
        return res;
    }
public:
    int countPairs(vector<int>& nums, int low, int high) {
        root = new Node();
        int ans = 0;
        for (int x : nums) {
            ans += countLess(x, high + 1) - countLess(x, low);
            insert(x);
        }
        return ans;
    }
};
