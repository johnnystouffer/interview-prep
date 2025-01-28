#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 217. Contains Duplicates
 * 
 * Using a unordered set vs an ordered one
 * so ordered in C++ when it comes to sets
 * and maps are not actually hash... crazy
 * ik. They are actually red black trees
 * 
 * 
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> newNums;

        for (int num : nums) {
            if (newNums.find(num) != newNums.end()) {
                return true;
            }
            newNums.insert(num);
        }
        return false;
    }
};