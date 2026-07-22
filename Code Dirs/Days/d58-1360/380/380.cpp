// Link: https://leetcode.com/problems/insert-delete-getrandom-o1/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) for insert, remove and getRandom operations. The insert and remove operations use an unordered_map to store the indices of the elements in the vector, allowing for constant time lookups. The getRandom operation uses the rand() function to generate a random index, which can be done in constant time.
// SC: O(n) where n is the number of elements in the set. The unordered_map and vector both store the elements in the set, resulting in linear space complexity.
// Approach:
// 1. We can use an unordered_map to store the indices of the elements in the vector, allowing for constant time lookups. The key of the unordered_map is the element value, and the value is its index in the vector.
// 2. We can use a vector to store the elements in the set, allowing for constant time access to the elements. The vector is used to store the elements in the order they were inserted, and the unordered_map is used to keep track of their indices in the vector.
// 3. For the insert operation, we check if the element is already present in the unordered_map. If it is not present, we add it to the unordered_map and the vector, and return true. If it is already present, we return false.
// 4. For the remove operation, we check if the element is present in the unordered_map. If it is present, we get its index from the unordered_map, swap it with the last element in the vector, and remove it from both the unordered_map and the vector. We also update the index of the last element in the unordered_map to reflect its new position in the vector. If the element is not present, we return false.
// 5. For the getRandom operation, we generate a random index using the rand() function and return the element at that index in the vector. Since the vector stores the elements in the order they were inserted, this ensures that each element has an equal probability of being selected.
class RandomizedSet
{
public:
    unordered_map<int, int> umpp;
    vector<int> vec;
    int index;
    RandomizedSet()
    {
        index = 0;
    }
    bool insert(int val)
    {
        if (umpp.find(val) == umpp.end())
        {
            umpp[val] = index;
            vec.push_back(val);
            index++;
            return true;
        }
        else
            return false;
    }
    bool remove(int val)
    {
        if (umpp.find(val) != umpp.end())
        {
            int pos = umpp[val];
            int ele2 = vec.back();
            vec[pos] = ele2;
            vec.back() = val;
            vec.pop_back();
            umpp[ele2] = pos;
            umpp.erase(val);
            index--;
            return true;
        }
        else
            return false;
    }
    int getRandom()
    {
        int ind = rand() % index;
        return vec[ind];
    }
};