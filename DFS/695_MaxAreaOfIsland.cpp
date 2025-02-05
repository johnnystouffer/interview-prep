#include <vector>

using namespace std;

/**
 * 695. Max Area of an Island
 * 
 * This is one of my favorites as well because it is
 * basically the same however you have to be careful with
 * cause you cannot do the same thing as before
 */

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid.at(0).size(); x++) {
                if (grid.at(y).at(x) == 1) {
                    maxArea = max(maxArea, dfs(x, y, grid));
                }
            }
        }
        return maxArea;
    }

    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || y < 0 || x >= grid.at(0).size() || y >= grid.size()) {
            return 0;
        }

        if (grid.at(y).at(x) == 1) {
            grid.at(y).at(x) = 0;
            return 1 + dfs(x+1, y, grid) + dfs(x, y+1, grid) + dfs(x-1, y, grid) + dfs(x, y-1, grid);
        }
        
        return 0;
    }
};
