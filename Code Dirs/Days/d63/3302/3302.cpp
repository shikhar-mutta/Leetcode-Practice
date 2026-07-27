// Link: https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n+m), SC: O(m)
// Approach: Precompute last[j] = the latest index in word1 from which
// word2[j..] can still be matched as a subsequence exactly (no mismatch),
// scanning word1 backward. Then greedily build the answer left to right,
// preferring an exact character match; if a mismatch is still allowed
// (flag not yet used) and either this is word2's last needed char or the
// remaining suffix can still be completed after using this mismatch
// (last[j+1] >= i+1), consume the one allowed mismatch here.
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word2.size();

        vector<int>last(n,-1);
        int j = n-1;
        for(int i = word1.size()-1; i>=0 ; i--){
            if(j >= 0 && word2[j] == word1[i]){
                last[j] = i;
                j--;
            }
        }

        j = 0;
        int flag = 1;
        vector<int>ans;

        for(int i = 0; i< word1.size() ; i++) {
            if(j < n){
                if((word2[j] == word1[i]) || (flag == 1 && (j == n-1 || last[j+1] >= i+1))){
                    if(word2[j] != word1[i]) flag = 0;
                    j++;
                    ans.push_back(i);

                }
            }

        }
        return j == n ? ans : vector<int>();
    }
};
