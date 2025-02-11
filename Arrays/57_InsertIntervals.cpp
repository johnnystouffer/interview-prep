#include <vector>

using namespace std;

/**
 * Insert Interval
 * 
 * TODO: REDO IT
 * 
 * This one was very difficult for me to do for some reason. I just could not wrap all the edge
 * cases in my head. I definitely want to try this again. Rip
 */
class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            // the final intervals we are doing
            vector<vector<int>> finalInterval;
            int ind = 0;
            int start = newInterval[0], end = newInterval[1];
    
            // loop through all intervals that contain numnbers less than the new interval
            // that we are inserting
            while (ind < intervals.size() && newInterval[0] > intervals[ind][1]) {
                finalInterval.push_back(intervals[ind]);
                ++ind;
            }
    
            // when we find a number where the second number is MORE than the first number
            // of our newInterval then we know to insert here
            while (ind < intervals.size() && newInterval[1] >= intervals[ind][0]) {
                start = min(start, intervals[ind][0]);
                end = max(end, intervals[ind][1]);
                ++ind;
            }
    
            // add the new start and end to the array
            // we do this outside of the loop just incase this is the first or last interval
            // to be inserted
            finalInterval.push_back({start, end});
    
            while (ind < intervals.size()) {
                finalInterval.push_back(intervals[ind]);
                ++ind;
            }
    
            return finalInterval;
        }
    };