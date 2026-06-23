#include <vector>
using namespace std;

class Solution {
public:
    // The Boundary Checker ---
    // This function ensures we don't accidentally step off the edge of the map.
    bool Valid(int i, int j, int n, int m) {
        // If the row (i) or column (j) is less than 0, or greater than/equal to the map size...
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return false; // ...it is outside the boundary, so return false.
        }
        return true; // Otherwise, it's a safe spot, so return true.
    }

    // The Explorer (DFS) ---
    // This function recursively visits all connected '1's of a single island.
    // Note: We use '&' to pass the grid and visited matrix by reference to save memory.
    void dfs(vector<vector<char>>& a, int n, int m, int i, int j, vector<vector<int>>& vis) {
        
        vis[i][j] = 1; // Step 1: Immediately mark the current cell as visited.

        // These two arrays define our 4 directions: Up, Down, Left, Right
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        // Loop exactly 4 times to check all 4 neighbors of the current cell
        for (int k = 0; k < 4; k++) {
            int row = i + x[k]; // Calculate the neighbor's row
            int col = j + y[k]; // Calculate the neighbor's column

            // The Triple Check:
            // 1. Is the neighbor inside the map boundaries? (Valid)
            // 2. Is the neighbor a piece of land? (a == '1')
            // 3. Have we NOT visited this piece of land yet? (vis == 0)
            if (Valid(row, col, n, m) && a[row][col] == '1' && vis[row][col] == 0) {
                // If all three are true, jump to that neighbor and keep exploring!
                dfs(a, n, m, row, col, vis);
            }
        }
    }

    //  The Main Scanner ---
    // This function sets up the tracking grid and triggers the explorers.
    int numIslands(vector<vector<char>>& a) {
        int n = a.size();    // Get the total number of rows
        if (n == 0) return 0; // Safety check: if the grid is entirely empty, return 0
        int m = a[0].size(); // Get the total number of columns
        
        int res = 0; // Initialize the island counter to 0

        // Create a 2D matrix called 'vis' of size n by m, filled completely with 0s
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Start scanning the map row by row, column by column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                // If we stumble upon a piece of land ('1') that we haven't visited yet (0)...
                if (a[i][j] == '1' && vis[i][j] == 0) {
                    
                    res++; // ...we found a brand new island! Add 1 to our count.
                    
                    // Send out the DFS explorer to map out the rest of this newly found island
                    // so we don't accidentally count it again later.
                    dfs(a, n, m, i, j, vis);
                }
            }
        }

        // After scanning the entire map, return the final count of islands.
        return res; 
    }
};