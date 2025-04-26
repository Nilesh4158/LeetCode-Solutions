#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;
        
        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].size();
            // Find the maximum words that can fit in the current line
            while (j < n && lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }
            
            int numWords = j - i;
            int totalSpaces = maxWidth - lineLength;
            
            string line;
            if (numWords == 1 || j == n) {
                // Left-justified for single word or last line
                line = words[i];
                for (int k = i + 1; k < j; k++) {
                    line += " " + words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                // Distribute spaces evenly
                int spaceBetween = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);
                
                line = words[i];
                for (int k = i + 1; k < j; k++) {
                    line += string(spaceBetween, ' ');
                    if (extraSpaces > 0) {
                        line += " ";
                        extraSpaces--;
                    }
                    line += words[k];
                }
            }
            
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};