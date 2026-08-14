// // BRUTE FORCE 
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string temp = "";
//         for(char c : s){
//             if(isalnum(c)){
//                 temp += tolower(c);
//             }
//         }

//         int left = 0;
//         int right = temp.length() - 1;

//         while(left <= right){
//             if(temp[left] != temp[right]){
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;
//     }
// };

// OPTIMAL APPROACH -> NO EXTRA MEMORY
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left <= right){
            while(!isalnum(s[left]) && left< right){
                left++;
            }
            while(!isalnum(s[right]) && left< right){
                right--;
            }

            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};
