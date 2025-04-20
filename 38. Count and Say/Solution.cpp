#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = "1";
        for (int i = 2; i <= n; ++i) {
            string current;
            int count = 1;
            for (int j = 1; j < prev.size(); ++j) {
                if (prev[j] == prev[j-1]) {
                    ++count;
                } else {
                    current += to_string(count) + prev[j-1];
                    count = 1;
                }
            }
            current += to_string(count) + prev.back();
            prev = current;
        }
        return prev;
    }
};