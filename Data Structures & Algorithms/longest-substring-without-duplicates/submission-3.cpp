// BRUTE FORCE
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();
//         int maxlen = 0;

//         for(int i = 0; i < n; i++){
//             unordered_set<char> st;

//             for(int j = i; j < n; j++){
//                 if(st.find(s[j]) != st.end())
//                 break;

//                 st.insert(s[j]);
//                 maxlen = max(maxlen , j - i + 1);
//             }
//         }
//         return maxlen;
//     }
// };

// OPTIMAL SOLUTION
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0;
        int r = 0;
        int maxlen = 0;

        unordered_map<char,int> mp;

        while(r < n){
            if(mp.find(s[r]) != mp.end()){
                if(mp[s[r]] >= l){
                    l = mp[s[r]] + 1;
                }
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);

            mp[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};
