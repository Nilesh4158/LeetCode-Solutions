#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;
        
        int word_len = words[0].size();
        int total_len = word_len * words.size();
        if (s.size() < total_len) return result;
        
        unordered_map<string, int> word_count;
        for (const string& word : words) {
            word_count[word]++;
        }
        
        for (int i = 0; i < word_len; ++i) {
            unordered_map<string, int> current_count;
            int left = i;
            int count = 0;
            
            for (int j = i; j <= s.size() - word_len; j += word_len) {
                string current_word = s.substr(j, word_len);
                
                if (word_count.find(current_word) != word_count.end()) {
                    current_count[current_word]++;
                    count++;
                    
                    while (current_count[current_word] > word_count[current_word]) {
                        string left_word = s.substr(left, word_len);
                        current_count[left_word]--;
                        count--;
                        left += word_len;
                    }
                    
                    if (count == words.size()) {
                        result.push_back(left);
                        string left_word = s.substr(left, word_len);
                        current_count[left_word]--;
                        count--;
                        left += word_len;
                    }
                } else {
                    current_count.clear();
                    count = 0;
                    left = j + word_len;
                }
            }
        }
        
        return result;
    }
};