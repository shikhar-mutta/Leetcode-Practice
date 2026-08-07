// Link: https://leetcode.com/problems/reconstruct-itinerary/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E log E)  SC: O(E)
// Approach: Hierholzer's algorithm - build adjacency with destinations in a
// multiset (lexicographic order), DFS consuming edges, post-order gives the
// itinerary reversed
class Solution {
    unordered_map<string, multiset<string>> graph;
    vector<string> route;

    void visit(const string& airport) {
        while (!graph[airport].empty()) {
            string next = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            visit(next);
        }
        route.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets) graph[t[0]].insert(t[1]);
        visit("JFK");
        reverse(route.begin(), route.end());
        return route;
    }
};
