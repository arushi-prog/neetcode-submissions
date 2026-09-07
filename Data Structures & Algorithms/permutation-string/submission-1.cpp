// BRUTE FORCE 
// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int n = s2.size();
//         int m = s1.size();

//         if(m > n) return false;

//         for(int i = 0; i <= n - m; i++){
//             vector<int> freq1(26,0);
//             vector<int> freq2(26,0);

//             for(char c : s1){
//                 freq1[c - 'a']++;
//             }

//             for(int j = i; j < i + m; j++){
//                 freq2[s2[j] - 'a']++;
//             }

//             if(freq1 == freq2){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// OPTIMAL APPROACH
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if(m>n) return false;

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(char c : s1){
            freq1[c - 'a']++;
        }

        int l = 0;
        for(int r = 0; r < n; r++){
            freq2[s2[r] - 'a']++;

            if(r-l+1 > m){
                freq2[s2[l] - 'a']--;
                l++;
            }

            if(freq1 == freq2){
                return true;
            }
        }
        return false;
    }
};
