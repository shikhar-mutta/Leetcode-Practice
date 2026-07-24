// Link: https://leetcode.com/problems/throne-inheritance/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach:
//    1. We will maintain a tree structure to represent the family hierarchy.
//    2. Each person will have a name, a boolean indicating if they are dead, and a list of children.
//    3. We will use a hash map to quickly access each person by their name.
//    4. For the getInheritanceOrder function, we will perform a depth-first search (DFS) starting from the king, adding names to the result list if they are not dead, and recursively visiting their children in order of birth.
//    5. The birth function will add a new child to the parent's list of children and update the hash map.
class ThroneInheritance
{
private:
    struct Person
    {
        std::string name;
        bool isDead;
        std::vector<Person *> children;

        Person(const std::string &n) : name(n), isDead(false) {}
    };

    std::unordered_map<std::string, Person *> nameToPerson;
    Person *king;

    void dfs(Person *node, std::vector<std::string> &result)
    {
        if (!node->isDead)
        {
            result.push_back(node->name);
        }
        for (Person *child : node->children)
        {
            dfs(child, result);
        }
    }

public:
    ThroneInheritance(std::string kingName)
    {
        king = new Person(kingName);
        nameToPerson[kingName] = king;
    }

    void birth(std::string parentName, std::string childName)
    {
        Person *parent = nameToPerson[parentName];
        Person *child = new Person(childName);
        parent->children.push_back(child);
        nameToPerson[childName] = child;
    }

    void death(std::string name) { nameToPerson[name]->isDead = true; }

    std::vector<std::string> getInheritanceOrder()
    {
        std::vector<std::string> result;
        dfs(king, result);
        return result;
    }
};
