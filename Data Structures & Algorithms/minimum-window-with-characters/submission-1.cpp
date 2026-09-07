// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int n = s.size();

//         vector<int> need(128, 0);

//         for (char c : t)
//             need[c]++;

//         int minLen = INT_MAX;
//         int start = -1;

//         for (int i = 0; i < n; i++) {

//             vector<int> freq(128, 0);

//             for (int j = i; j < n; j++) {

//                 freq[s[j]]++;

//                 bool valid = true;

//                 for (int k = 0; k < 128; k++) {
//                     if (freq[k] < need[k]) {
//                         valid = false;
//                         break;
//                     }
//                 }

//                 if (valid && (j - i + 1) < minLen) {
//                     minLen = j - i + 1;
//                     start = i;
//                 }
//             }
//         }

//         if (start == -1)
//             return "";

//         return s.substr(start, minLen);
//     }
// };

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> freq(128, 0);

        // Store required frequency of characters in t
        for (char c : t)
            freq[c]++;

        int l = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        int start = -1;

        for (int r = 0; r < n; r++) {

            // If s[r] is required, it contributes to cnt
            if (freq[s[r]] > 0)
                cnt++;

            freq[s[r]]--;

            // Window contains all characters of t
            while (cnt == m) {

                // Update minimum window
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // Remove s[l] from window
                freq[s[l]]++;

                // If frequency becomes positive,
                // we have removed a required character
                if (freq[s[l]] > 0)
                    cnt--;

                l++;
            }
        }

        if (start == -1)
            return "";

        return s.substr(start, minLen);
    }
};