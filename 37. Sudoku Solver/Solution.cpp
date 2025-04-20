class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Initialize bitmasks for rows, columns, and boxes
        vector<int> rows(9, 0), cols(9, 0), boxes(9, 0);
        
        // Fill the bitmasks based on the initial board
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int boxIdx = (i / 3) * 3 + (j / 3);
                    rows[i] |= (1 << num);
                    cols[j] |= (1 << num);
                    boxes[boxIdx] |= (1 << num);
                }
            }
        }
        
        solve(board, rows, cols, boxes);
    }
    
    bool solve(vector<vector<char>>& board, vector<int>& rows, vector<int>& cols, vector<int>& boxes) {
        // Find the cell with the fewest possible numbers
        int minOptions = 10;
        int row = -1, col = -1;
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    int boxIdx = (i / 3) * 3 + (j / 3);
                    int used = rows[i] | cols[j] | boxes[boxIdx];
                    int options = 9 - __builtin_popcount(used);
                    
                    if (options < minOptions) {
                        minOptions = options;
                        row = i;
                        col = j;
                    }
                }
            }
        }
        
        // If no empty cells left, the board is solved
        if (minOptions == 10) {
            return true;
        }
        
        int boxIdx = (row / 3) * 3 + (col / 3);
        int used = rows[row] | cols[col] | boxes[boxIdx];
        
        // Try each possible number
        for (int num = 0; num < 9; ++num) {
            if (!(used & (1 << num))) {
                board[row][col] = '1' + num;
                rows[row] |= (1 << num);
                cols[col] |= (1 << num);
                boxes[boxIdx] |= (1 << num);
                
                if (solve(board, rows, cols, boxes)) {
                    return true;
                }
                
                // Backtrack
                board[row][col] = '.';
                rows[row] &= ~(1 << num);
                cols[col] &= ~(1 << num);
                boxes[boxIdx] &= ~(1 << num);
            }
        }
        
        return false;
    }
};