// Link: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogk) SC: O(k)
// Approach: We can use two priority queues to keep track of the free servers and the busy servers. The free servers will be stored in a min-heap based on their server id, and the busy servers will be stored in a min-heap based on their finish time. For each request, we will first check if any busy servers have finished their requests and move them to the free servers heap. Then, we will assign the request to the next available free server (if any) and update its finish time in the busy servers heap. Finally, we will keep track of the number of requests handled by each server and return the servers that handled the most requests.
class Solution
{
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
    {
        vector<int> requestsHandled(k, 0);
        priority_queue<int, vector<int>, greater<int>> freeServers;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            busyServers;
        for (int server = 0; server < k; server++)
        {
            freeServers.push(server);
        }
        for (int i = 0; i < arrival.size(); i++)
        {
            int currentTime = arrival[i];
            while (!busyServers.empty() &&
                   busyServers.top().first <= currentTime)
            {
                auto [finishTime, serverId] = busyServers.top();
                busyServers.pop();
                int modifiedId = i + ((serverId - (i % k) + k) % k);
                freeServers.push(modifiedId);
            }
            if (freeServers.empty())
            {
                continue;
            }
            int serverId = freeServers.top() % k;
            freeServers.pop();
            requestsHandled[serverId]++;
            busyServers.push({currentTime + load[i], serverId});
        }

        int maxRequests =
            *max_element(requestsHandled.begin(), requestsHandled.end());

        vector<int> answer;
        for (int server = 0; server < k; server++)
        {
            if (requestsHandled[server] == maxRequests)
            {
                answer.push_back(server);
            }
        }
        return answer;
    }
};