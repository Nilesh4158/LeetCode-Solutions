#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int max_area = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            max_area = max(max_area, largestRectangleArea(heights));
        }
        
        return max_area;
    }
    
private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        int n = heights.size();
        int i = 0;
        
        while (i < n) {
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i);
                i++;
            } else {
                int top = st.top();
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                int area = heights[top] * width;
                max_area = max(max_area, area);
            }
        }
        
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            int width = st.empty() ? n : (n - st.top() - 1);
            int area = heights[top] * width;
            max_area = max(max_area, area);
        }
        
        return max_area;
    }
};