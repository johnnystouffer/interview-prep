#include <vector>

using namespace std;

/**
 * 74. Search A 2D Matrix
 * 
 * Binary search but slightly harder, not that much harder
 * though thankfull.
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int l = 0, r = n*m - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            int midY = mid / n;
            int midX = mid % n;

            int result = matrix.at(midY).at(midX);

            if (result == target) {
                return true;
            }
            else if (result > target) {
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }  
        
        }
        return false;
    }
    
};