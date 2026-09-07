// BRUTE FORCE
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.length();
//         int maxlen = 0;

//         for(int i = 0; i < n; i++){
//             vector<int> freq(26,0);
//             int maxfreq = 0;
//             for(int j = i; j < n; j++){
//                 freq[s[j] - 'A']++;

//                 maxfreq = max(maxfreq, freq[s[j] - 'A']);

//                 int len = j - i + 1;
//                 int changes = len - maxfreq;
                
//                 if(changes <= k){
//                     maxlen = max(maxlen, len);
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//         return maxlen;
//     }
// };

// BETTER APPROACH
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;
        int maxFreq = 0;

        vector<int> hash(26, 0);

        while (r < n) {
            hash[s[r] - 'A']++;

            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k) {
                hash[s[l] - 'A']--;

                maxFreq = 0;
                for (int i = 0; i < 26; i++)
                    maxFreq = max(maxFreq, hash[i]);

                l++;
            }

            maxLen = max(maxLen, r - l + 1);

            r++;
        }

        return maxLen;
    }
};
