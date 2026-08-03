// Link: https://leetcode.com/problems/reconstruct-itinerary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(E log E) where E is the number of edges in the graph.
    // SC: O(V + E) where V is the number of vertices in the graph.
    // Approach: We can model the problem as a graph where each airport is a vertex and each ticket is a directed edge from the departure airport to the arrival airport. We can use Hierholzer's algorithm to find an Eulerian path in the graph, which will give us the desired itinerary. We will use a stack to perform a depth-first search (DFS) and construct the itinerary in reverse order. Finally, we will reverse the itinerary to get the correct order of airports.

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, multiset<string>> graph;
        // Build the graph using a multiset to store the destinations in lexicographical order
        for (auto &t : tickets)
            graph[t[0]].insert(t[1]);

        //
        vector<string> route;
        stack<string> st;
        st.push("JFK");
        while (!st.empty())
        {
            string cur = st.top();
            auto &dests = graph[cur];
            if (dests.empty())
            {
                route.push_back(cur);
                st.pop();
            }
            else
            {
                string next = *dests.begin();
                dests.erase(dests.begin());
                st.push(next);
            }
        }
        reverse(route.begin(), route.end());
        return route;
    }
};
