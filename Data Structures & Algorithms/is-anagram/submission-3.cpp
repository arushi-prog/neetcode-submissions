// USING SORTING
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int length_s = s.length();
//         int length_t = t.length();

//         if(length_s != length_t){
//             return false;
//         }

//         sort(s.begin() , s.end());
//         sort(t.begin() , t.end());

//             if(s == t){
//                 return true;
//             }

//         return false;
//     }
// };

// OPTIMAL APPROACH -> USING HASHMAPS
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int length_s = s.length();
//         int length_t = t.length();

//         if(length_s != length_t){
//             return false;
//         }

//         unordered_map<char,int> freq;

//         for(char c : s){
//             freq[c]++;
//         }

//         for(char c : t){
//             freq[c]--;

//             if(freq[c] < 0){
//             return false;
//         }

//         }

//         return true;
//     }
// };

// WE CAN SAVE THE SC BY USING AN ARRAY OF LENGTH 26 BECAUSE IN THE QUESTION IT IS GIVEN THAT WE ARE ONLY DEALING WITH LOWERCASE CHARACTERS
class Solution {
public:
    bool isAnagram(string s, string t) {
        int length_s = s.length();
        int length_t = t.length();

        if(length_s != length_t){
            return false;
        }

        int freq[26] = {0};

        for(char c : s){
            freq[c - 'a']++;
        }

        for(char c : t){
            freq[c - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }
};
