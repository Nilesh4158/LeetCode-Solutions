#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int n = s.length();
        
        // Skip leading whitespace
        while (i < n && isspace(s[i])) {
            i++;
        }
        
        // Check for optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            i++;
        }
        
        bool isNumeric = false;
        // Check digits before decimal point
        while (i < n && isdigit(s[i])) {
            i++;
            isNumeric = true;
        }
        
        // Check for decimal point and subsequent digits
        if (i < n && s[i] == '.') {
            i++;
            // Check digits after decimal point
            while (i < n && isdigit(s[i])) {
                i++;
                isNumeric = true;
            }
        }
        
        // Check for exponent
        if (isNumeric && i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            isNumeric = false; // exponent must be followed by digits
            // Check for optional sign in exponent
            if (i < n && (s[i] == '+' || s[i] == '-')) {
                i++;
            }
            // Check digits in exponent
            while (i < n && isdigit(s[i])) {
                i++;
                isNumeric = true;
            }
        }
        
        // Skip trailing whitespace
        while (i < n && isspace(s[i])) {
            i++;
        }
        
        return isNumeric && i == n;
    }
};