#include <vector>

using namespace std;

/**
 * 136. Single Number
 * 
 * Find the only duplicate in the array
 * constraint: only can have O(1) space complexity
 * so no hash tables
 * 
 * instead we can use bit operations
 * XOR every num with 0 and the only
 * one that is not a duplicate will be
 * saved
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto num : nums) {
            ans ^= num;
        }
        return ans;
    }
};