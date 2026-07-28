// Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;

// TC: O((n+m) * 9), SC: O(n*9) for the digit trie
// Approach: Insert every number from arr1 into a digit trie (most-significant
// digit first). For each number in arr2, walk the trie following its digits
// as far as a matching path exists; the walk length is that number's longest
// common prefix with some arr1 element. Track the max over all of arr2.
static int trie[500000][10];
static int nc;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        // Start with only root node
        nc = 1;

        // Clear root node
        memset(trie[0], 0, 40);

        /*
            STEP 1:
            Insert all numbers from arr1 into Trie
        */
        for (int val : arr1) {

            int curr = 0;

            // Store digits temporarily
            int digits[9], d = 0;

            // Extract digits in reverse order
            for (int v = val; v; v /= 10)
                digits[d++] = v % 10;

            // Insert digits in correct order
            // (most significant digit first)
            for (int i = d - 1; i >= 0; --i) {

                int dig = digits[i];

                // Create new node if path doesn't exist
                if (!trie[curr][dig]) {
                    memset(trie[nc], 0, 40);
                    trie[curr][dig] = nc++;
                }

                curr = trie[curr][dig];
            }
        }

        int ans = 0;

        /*
            STEP 2:
            Find longest matching prefix
            for each number in arr2
        */
        for (int val : arr2) {

            int digits[9], d = 0;

            // Extract digits
            for (int v = val; v; v /= 10)
                digits[d++] = v % 10;

            int curr = 0;
            int len = 0;

            // Traverse trie while digits match
            for (int i = d - 1; i >= 0; --i) {

                int dig = digits[i];

                // Stop if path doesn't exist
                if (!trie[curr][dig])
                    break;

                ++len;
                curr = trie[curr][dig];
            }

            // Update maximum prefix length
            ans = max(ans, len);
        }

        return ans;
    }
};
