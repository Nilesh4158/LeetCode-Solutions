class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> freqT;
        for (char c : t) {
            freqT[c]++;
        }

        int required = freqT.size();
        int left = 0, right = 0;
        int formed = 0;
        unordered_map<char, int> windowCounts;

        int minLength = -1;
        int minLeft = 0;

        while (right < s.length()) {
            char c = s[right];
            windowCounts[c]++;

            if (freqT.find(c) != freqT.end() && windowCounts[c] == freqT[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                c = s[left];
                if (minLength == -1 || right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }

                windowCounts[c]--;
                if (freqT.find(c) != freqT.end() && windowCounts[c] < freqT[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return minLength == -1 ? "" : s.substr(minLeft, minLength);
    }
};