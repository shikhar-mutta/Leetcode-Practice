// Link: https://leetcode.com/problems/find-the-first-player-to-win-k-games-in-a-row/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: Simulate the elimination chain: track the current champion p
// and their consecutive win streak cnt. Each challenger either loses (streak
// grows) or becomes the new champion with streak reset to 1. Return early
// once cnt reaches k; if k >= n, the loop finishes with p as the overall
// strongest player (guaranteed by the elimination invariant).
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
       // priority_queue<pair<int,int>> pq;
       int n=skills.size();
       int p=0;
       int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(skills[i]<skills[p])
            {
                cnt++;
               // p=i;
            }
            else{
                cnt=1;
                p=i;
            }
            if(cnt==k) return p;
        }
          if(cnt==k) return p;
          return p;
    }
};
