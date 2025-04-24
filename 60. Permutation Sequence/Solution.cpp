#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        vector<int> factorial(n + 1, 1);
        string result;
        
        // Precompute factorials from 0! to n!
        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
            numbers.push_back(i);
        }
        
        // Decrement k to convert to 0-based index
        k--;
        
        for (int i = 1; i <= n; ++i) {
            int index = k / factorial[n - i];
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k -= index * factorial[n - i];
        }
        
        return result;
    }
};