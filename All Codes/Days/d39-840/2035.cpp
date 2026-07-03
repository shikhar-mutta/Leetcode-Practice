// Link: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^(n/2) * n/2) for generating all possible sums for one half of the array
// SC: O(2^(n/2)) for storing all possible sums for one half
// Approach: We can use a meet-in-the-middle approach to solve this problem.
// We can divide the array into two halves and generate all possible sums for each half.
// Then, we can use a two-pointer technique to find the minimum difference between
// the sums of the two halves.
class Solution
{

    // Class for accounting all possible sums for one of the halves
    class Handler
    {

        using val_t = int;
        using conf_t = unsigned int;
        using buff_t = vector<pair<val_t, conf_t>>;
        using iterator = vector<int>::iterator;

        static const conf_t ones = 0xFFFFFFFF;

        buff_t buffer, new_buffer; // Buffer containing pairs (sum, config)
                                   // Config is the index of the first element in right array
        vector<int> array;         // Stores the original array
        int neg_cnt;               // Counter of elenments in the right array (negative)
        int lower, upper;          // Min and max sums

    public:
        // The first case is then all numbers placed to the left array
        Handler(iterator begin, iterator end) : array(begin, end), buffer(1), neg_cnt(0)
        {
            val_t sum = 0;
            for (auto &x : array)
            {
                sum += x;
                x *= 2;
            }
            upper = lower = sum;
            buffer.front() = make_pair(sum, array.size());
        }

        // Move one number to the second array and evaluate sums
        void inc()
        {
            ++neg_cnt;
            new_buffer.clear();
            new_buffer.reserve(buffer.size() * (array.size() - neg_cnt + 1) / neg_cnt);
            lower = INT_MAX;
            upper = INT_MIN;
            for (auto &b : buffer)
            {
                val_t val = b.first;
                conf_t config = b.second;
                for (conf_t i = 0; i < config; i++)
                {
                    int new_val = val - array[i];
                    lower = min(lower, new_val);
                    upper = max(upper, new_val);
                    new_buffer.emplace_back(new_val, i);
                }
            }
            swap(buffer, new_buffer);
        }

        // Get sum value
        int operator[](int idx)
        {
            return buffer[idx].first;
        }

        // Get size
        int size() { return buffer.size(); }

        // Get vector containing the sums
        void get_vec(vector<int> &v)
        {
            v.clear();
            v.reserve(buffer.size());
            for (auto &b : buffer)
                v.push_back(b.first);
        }

        int get_min() { return lower; }
        int get_max() { return upper; }
    };

    // Record to store segment configuration
    struct Record
    {
        int begin1, n1;
        int begin2, n2;
        int min, max;
        Record() : begin1(0), n1(0), begin2(0), n2(0), min(INT_MAX), max(INT_MIN) {}
        Record(int _begin1, int _size1, int _begin2, int _size2, int _min, int _max) : begin1(_begin1), n1(_size1), begin2(_begin2), n2(_size2), min(_min), max(_max) {}
    };

    // Function to find the least difference
    static void get_min_dist(vector<int> &v1, vector<int> &v2, int &dist,
                             pair<int, int> minmax1 = {INT_MAX, INT_MIN},
                             pair<int, int> minmax2 = {INT_MAX, INT_MIN})
    {

        static vector<Record> segments;
        static stack<int> stack1, stack2;

        if (minmax1.first > minmax1.second)
            for (auto &val : v1)
            {
                minmax1.first = min(minmax1.first, val);
                minmax1.second = max(minmax1.second, val);
            }

        if (minmax2.first > minmax2.second)
            for (auto &val : v1)
            {
                minmax2.first = min(minmax2.first, val);
                minmax2.second = max(minmax2.second, val);
            }

        dist = min(dist, abs(minmax1.first - minmax2.second));
        dist = min(dist, abs(minmax2.first - minmax1.second));
        dist = min(dist, abs(minmax2.first - minmax1.first));
        dist = min(dist, abs(minmax2.second - minmax1.second));
        if (!dist || minmax1.first >= minmax2.second || minmax2.first >= minmax1.second)
            return;

        segments.push_back(Record(0, v1.size(), 0, v2.size(), minmax1.first, minmax1.second));

        // int counter = 0;
        while (v1.size() && v2.size() && dist)
        {
            Record old_segm = segments.back();
            segments.pop_back();

            // counter += max(v1.size() - old_segm.begin1, v2.size() - old_segm.begin2);

            int left = old_segm.min;
            int right = old_segm.max;

            int width = max(dist, (right - left + 1) / old_segm.n1);

            int section = segments.size();
            segments.resize(section + (right - left) / width + 1);

            // cout << "------------------------\n";
            // cout << "v1.size = " << v1.size() << ", v2.size = " <<  v2.size() <<", dist = " <<  dist << endl;
            // cout << "left = " << left << ", right = " << right << endl;
            // cout << "width = " << width << endl;
            // cout << "max segments size: " << section + (right - left)/width + 1 << endl;

            for (int i = old_segm.begin1; i < v1.size(); i++)
            {
                int val = v1[i];
                // cout << left << " | " << val << " | " << right << endl;
                auto &curr = segments[section + (val - left) / width];

                if (!curr.n1)
                {
                    curr.n1++;
                    curr.min = curr.max = val;
                }
                else if (curr.n1 == 1)
                {
                    curr.n1++;
                    if (val < curr.min)
                        curr.min = val;
                    else
                        curr.max = val;
                }
                else if (val < curr.min)
                {
                    curr.n1++;
                    stack1.push(curr.min);
                    curr.min = val;
                }
                else if (val > curr.max)
                {
                    curr.n1++;
                    stack1.push(curr.max);
                    curr.max = val;
                }
                else if (val > curr.min && val < curr.max)
                {
                    curr.n1++;
                    stack1.push(val);
                }
            }

            // cout << "New segment filled of v1\n";

            for (int i = old_segm.begin2; i < v2.size(); i++)
            {
                int val = v2[i];
                if (val < left)
                    dist = min(dist, left - val);
                else if (val > right)
                    dist = min(dist, val - right);
                else
                {
                    int idx = section + (val - left) / width;
                    auto &curr = segments[idx];

                    if (idx > section && segments[idx - 1].n1)
                        dist = min(dist, val - segments[idx - 1].max);
                    if (idx < segments.size() - 1 && segments[idx + 1].n1)
                        dist = min(dist, segments[idx + 1].min - val);
                    if (curr.n1)
                    {
                        dist = min(dist, abs(curr.min - val));
                        dist = min(dist, abs(val - curr.max));
                        if (val > curr.min && val < curr.max && curr.n1 > 2)
                        {
                            stack2.push(val);
                            ++curr.n2;
                        }
                    }
                }
                if (!dist)
                    break;
            }

            // cout << "New segment filled of v2\n";

            // if (stack1.size() != stack2.size())
            // cout << "stack1.size = " << stack1.size() << ", stack2.size = " << stack2.size() << endl;

            int pos1 = old_segm.begin1;
            int pos2 = old_segm.begin2;
            for (int i = section; i < segments.size(); i++)
            {
                auto &curr = segments[i];
                if ((curr.n1 -= 2) <= 0 || !curr.n2)
                    curr.n1 = curr.n2 = 0;
                curr.begin1 = pos1 += curr.n1;
                curr.begin2 = pos2 += curr.n2;
                curr.min = INT_MAX;
                curr.max = INT_MIN;
            }

            v1.resize(segments.back().begin1);
            v2.resize(segments.back().begin2);

            while (!stack1.empty())
            {
                int val = stack1.top();
                stack1.pop();
                auto &curr = segments[section + (val - left) / width];
                if (curr.n1)
                {
                    v1[--curr.begin1] = val;
                    curr.min = min(curr.min, val);
                    curr.max = max(curr.max, val);
                }
            }

            // cout << "v1 filled\n";

            while (!stack2.empty())
            {
                int val = stack2.top();
                stack2.pop();
                auto &curr = segments[section + (val - left) / width];
                if (curr.n2)
                    v2[--curr.begin2] = val;
            }

            // cout << "v2 filled\n";

            for (int i = section; i < segments.size(); i++)
            {
                if (segments[i].n1)
                {
                    segments[section] = segments[i];
                    section++;
                }
            }

            // cout << "new partition size: " << section << endl;
            segments.resize(section);
        }
        // cout << "counter = " << counter << ", dist = " <<  dist << "\n";

        segments.clear();
    }

public:
    int minimumDifference(vector<int> &nums)
    {
        // cout << "\n[";
        // for (auto& val : nums) cout << val << ", ";
        // cout << "]\n";

        int n = nums.size() / 2;

        Handler h1(nums.begin(), nums.begin() + n), h2(nums.begin() + n, nums.end());
        vector<int> v1, v2;

        // long long time1 = 0, time2 = 0, time3 = 0;

        int result = abs(h1[0] - h2[0]);
        for (int i = 0; i < n / 2; i++)
        {

            // clock_t start = clock();
            h1.inc();
            h1.get_vec(v1);
            h2.inc();
            h2.get_vec(v2);
            // time1 += clock() - start;

            // start = clock();
            get_min_dist(v1, v2, result,
                         make_pair(h1.get_min(), h1.get_max()),
                         make_pair(h2.get_min(), h2.get_max()));
            // time2 += clock() - start;
        }

        // cout << "Combining: " << time1*1000 / CLOCKS_PER_SEC << " ms" << endl;
        // cout << "Comparing: " << time2*1000 / CLOCKS_PER_SEC << " ms" << endl;

        return result;
    }
};