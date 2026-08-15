// Link: https://leetcode.com/problems/count-mentions-per-user/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) + O(n) = O(nlogn)
// SC: O(n)
// Approach:
//   1. Sort the events based on timestamp and type of event.
//   2. Iterate through the events and for each event, check if it is a mention or an online event.
//   3. If it is a mention, check if the user is online or not. If the user is online, increment the mention count for that user.
//   4. If it is an online event, update the online status of the user.
//   5. Return the total mentions for each user.
class Solution
{
public:
    void findAndIncrementIds(string &allIds, int numberOfUsers, vector<int> &whenOnline, int timestamp, vector<int> &totalMentions)
    {

        int flagI = false;
        int flagD = false;
        int currId = 0;
        if (allIds[0] == 'H')
        {
            for (int i = 0; i < numberOfUsers; i++)
            {
                if (whenOnline[i] <= timestamp)
                {
                    totalMentions[i]++;
                }
            }
        }
        else if (allIds[0] == 'A')
        {
            for (int i = 0; i < numberOfUsers; i++)
            {
                totalMentions[i]++;
            }
        }
        else
        {
            for (char c : allIds)
            {
                if (c == 'i')
                {
                    flagI = true;
                    continue;
                }
                if (flagI && c == 'd')
                {
                    flagD = true;
                    continue;
                }
                if (flagI && flagD)
                {
                    if (c != ' ')
                    {
                        // fetchedId += c;
                        if (c >= '0' && c <= '9')
                        {
                            currId = currId * 10 + (c - '0');
                        }
                        continue;
                    }

                    totalMentions[currId]++;
                    flagI = false;
                    flagD = false;
                    currId = 0;
                    continue;
                }
            }
            totalMentions[currId]++;
        }
    }

    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>> &events)
    {

        sort(events.begin(), events.end(), [](const vector<string> &a, const vector<string> &b)
             {
            if(a[1].size() != b[1].size()){
                return a[1].size() < b[1].size();
            }
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            return a[0][0] > b[0][0]; });

        vector<int> whenOnline(numberOfUsers);
        vector<int> totalMentions(numberOfUsers);

        for (int i = 0; i < events.size(); i++)
        {
            // string typeOfEvent = events[i][0];
            // int timestamp = stoi(events[i][1]);
            // string allIds = events[i][2];

            if (events[i][0][0] == 'M')
            {
                findAndIncrementIds(events[i][2], numberOfUsers, whenOnline, stoi(events[i][1]), totalMentions);
            }
            else if (events[i][0][0] == 'O')
            {
                int id = stoi(events[i][2]);
                whenOnline[id] = (stoi(events[i][1]) + 60);
            }
        }
        return totalMentions;
    }
};