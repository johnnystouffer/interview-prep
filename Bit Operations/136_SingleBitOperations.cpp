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


/**
 * UPDATE
 * 
 * Did this again on 3/17/25 (Happy Birthday Day!)
 * So here is the "I know C++ a lot better now" version
 * of this
 * 
 * Tadaaaaaa!! Shocker its the same but better syntax and no auto
 * plus there is a reference! so using significantly less memory! 
 * WOOO!
 */

class Solution {
 public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int& num : nums) { ans ^= num; }
        return ans;
    }
};

/** I GOT SCREWED BY GITHUB */