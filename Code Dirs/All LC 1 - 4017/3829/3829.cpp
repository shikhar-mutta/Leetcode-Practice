// Link: https://leetcode.com/problems/design-ride-sharing-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(n)
//  Approach: Maintain vectors for riders and drivers. Match them in order,
//  skipping cancelled riders.
//  Note: This implementation is not optimal for large inputs, as it uses linear search to find and remove riders. A more efficient approach would be to use a queue or a set to manage riders and drivers.
class RideSharingSystem
{
public:
    vector<int> rider;
    vector<int> driver;
    RideSharingSystem() {}

    void addRider(int riderId) { rider.push_back(riderId); }

    void addDriver(int driverId) { driver.push_back(driverId); }

    vector<int> matchDriverWithRider()
    {
        if (rider.size() == 0 || driver.size() == 0)
            return {-1, -1};
        vector<int> ans = {driver[0], rider[0]};
        driver.erase(driver.begin());
        rider.erase(rider.begin());
        return ans;
    }

    void cancelRider(int riderId)
    {
        auto f = find(rider.begin(), rider.end(), riderId);
        if (f != rider.end())
        {
            rider.erase(f);
        }
    }
};
