#include <vector>

using namespace std;

/**
 * 252. Meeting Rooms
 * 
 * Learn the STL Johnny!
 * 
 * Pretty easy one, sort it then see if the ending time every intersects with the start time.
 */

class Solution {
    public:
        bool canAttendMeetings(vector<vector<int>>& intervals) {
            if (intervals.empty()) {
                return true;
            }
    
            sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>&b) { return a[0] < b[0]; });
    
            int ind = 1;
            while (ind < intervals.size()) {
                if (intervals[ind-1][1] > intervals[ind][0]) {
                    return false;
                }
                ++ind;
            }
            return true;
        }
    };