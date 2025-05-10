#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
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