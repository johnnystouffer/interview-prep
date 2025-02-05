#include <vector>

using namespace std;

/**
 * 200. Number of Islands
 * 
 * My favorite!! because it is self explanatory
 * and it teaches a more "advanced" (not really )
 * concept
 */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid.at(y).size(); x++) {
                if (grid.at(y).at(x) == '1') {
                    dfs(grid, x, y);
                    count += 1;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || y < 0 || y >= grid.size() || x >= grid.at(0).size()) {
            return;
        }

        if (grid.at(y).at(x) == '1') {
            grid.at(y).at(x) = '0';

            dfs(grid, x+1, y);
            dfs(grid, x, y+1);
            dfs(grid, x-1, y);
            dfs(grid, x, y-1);
        }
        return;
    }
};