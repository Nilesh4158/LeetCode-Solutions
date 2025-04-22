#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (const string& str : strs) {
            string key = getKey(str);
            anagramGroups[key].push_back(str);
        }
        
        vector<vector<string>> result;
        for (const auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
    
private:
    string getKey(const string& str) {
        int count[26] = {0};
        for (char c : str) {
            count[c - 'a']++;
        }
        
        string key;
        for (int i = 0; i < 26; ++i) {
            key += to_string(count[i]) + '#';
        }
        return key;
    }
};