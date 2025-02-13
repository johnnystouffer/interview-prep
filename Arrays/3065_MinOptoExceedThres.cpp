#include "../libraries.h"

using namespace std;

/**
 * 3065. Minimum Operations to Exceed Threshold Value I
 */

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] < k) {
                    ++count;
                }
            }
            return count;
        }
    };