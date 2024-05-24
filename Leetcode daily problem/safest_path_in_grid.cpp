
// class Solution {
// public:
// bool check_path(vector<vector<int>>& restore) {
//         int n = restore.size();
//         if (restore[0][0] == 0 || restore[n-1][n-1] == 0) {
//             return false;
//         }
        
//         vector<vector<bool>> visited(n, vector<bool>(n, false));
//         queue<pair<int, int>> q;
        
//         q.push({0, 0});
//         visited[0][0] = true;
        
//         int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
//         while (!q.empty()) {
//             int row = q.front().first;
//             int column = q.front().second;
//             q.pop();
            
//             if (row == n - 1 && column == n - 1) {
//                 return true;
//             }
            
//             for (int i = 0; i < 4; ++i) {
//                 int newRow = row + directions[i][0];
//                 int newCol = column + directions[i][1];
                
//                 if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && !visited[newRow][newCol] && restore[newRow][newCol] != 0) {
//                     q.push({newRow, newCol});
//                     visited[newRow][newCol] = true;
//                 }
//             }
//         }
        
//         return false;
//     }

//     int maximumSafenessFactor(vector<vector<int>>& grid) {
//         int n = grid.size();
//         queue<pair<int, int>> q;
        
//         // Enqueue all the cells with initial safeness factor 1
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] == 1) {
//                     q.push({i, j});
//                 }
//             }
//         }

//         vector<vector<int>> weight(n, vector<int>(n, INT_MAX));

//         // BFS to calculate minimum distances from 1s
//         while (!q.empty()) {
//             int row = q.front().first;
//             int column = q.front().second;
//             q.pop();

//             for (int i = 0; i < n; ++i) {
//                 for (int j = 0; j < n; ++j) {
//                     int to_fill = abs(row - i) + abs(column - j);
//                     if (weight[i][j] > to_fill) {
//                         weight[i][j] = to_fill;
//                     }
//                 }
//             }
//         }

//         // Maximum safeness factor
//         int max_safe = 0;
//         for (const auto& row : weight) {
//             for (int val : row) {
//                 max_safe = max(max_safe, val);
//             }
//         }

//         // Binary search for the highest safeness factor
//         int low = 0, high = max_safe;
//         while (low < high) {
//             int mid = (low + high + 1) / 2;
//             vector<vector<int>> restore = weight;
//             for (int i = 0; i < n; ++i) {
//                 for (int j = 0; j < n; ++j) {
//                     if (restore[i][j] < mid) {
//                         restore[i][j] = 0;
//                     }
//                 }
//             }
//             if (check_path(restore)) {
//                 low = mid;
//             } else {
//                 high = mid - 1;
//             }
//         }

//         return low;
//     }
// };

class Solution {
public:
    bool check_path(const vector<vector<int>>& restore) {
        int n = restore.size();
        if (restore[0][0] == 0 || restore[n-1][n-1] == 0) {
            return false;
        }
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        visited[0][0] = true;
        
        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        while (!q.empty()) {
            int row = q.front().first;
            int column = q.front().second;
            q.pop();
            
            if (row == n - 1 && column == n - 1) {
                return true;
            }
            
            for (int i = 0; i < 4; ++i) {
                int newRow = row + directions[i][0];
                int newCol = column + directions[i][1];
                
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && !visited[newRow][newCol] && restore[newRow][newCol] != 0) {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
        
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> weight(n, vector<int>(n, INT_MAX));

        // Enqueue all the cells with initial safeness factor 1 and set their weight to 0
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    weight[i][j] = 0;
                }
            }
        }

        // Directions for BFS
        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // BFS to calculate minimum distances from 1s
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int newRow = row + directions[i][0];
                int newCol = col + directions[i][1];
                
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                    int newWeight = weight[row][col] + 1;
                    if (weight[newRow][newCol] > newWeight) {
                        weight[newRow][newCol] = newWeight;
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        // Binary search for the highest safeness factor
        int low = 0, high = *max_element(weight[0].begin(), weight[0].end());
        for (int i = 1; i < n; ++i) {
            high = max(high, *max_element(weight[i].begin(), weight[i].end()));
        }

        while (low < high) {
            int mid = (low + high + 1) / 2;
            vector<vector<int>> restore = weight;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (restore[i][j] < mid) {
                        restore[i][j] = 0;
                    }
                }
            }
            if (check_path(restore)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
