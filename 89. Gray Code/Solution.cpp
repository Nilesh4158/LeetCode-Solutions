class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        if (n == 0) return result;
        
        for (int i = 0; i < n; ++i) {
            int size = result.size();
            for (int j = size - 1; j >= 0; --j) {
                result.push_back(result[j] | (1 << i));
            }
        }
        
        return result;
    }
};