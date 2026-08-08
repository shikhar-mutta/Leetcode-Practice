// Link: https://leetcode.com/problems/maximum-number-of-eaten-apples/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // {expiryDay, count}
        int n = apples.size();
        int eaten = 0;
        int day = 0;
        while (day < n || !pq.empty()) {
            if (day < n && apples[day] > 0) {
                pq.push({day + days[day], apples[day]});
            }
            while (!pq.empty() && pq.top().first <= day) pq.pop();
            if (!pq.empty()) {
                auto [exp, cnt] = pq.top(); pq.pop();
                eaten++;
                cnt--;
                if (cnt > 0) pq.push({exp, cnt});
            }
            day++;
        }
        return eaten;
    }
};
