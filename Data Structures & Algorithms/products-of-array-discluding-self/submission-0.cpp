// IF DIVISION APPROACH WAS ALLOWED
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {

//         int s = nums.size();
//         int zeroCount = 0;
//         int product = 1;

//         // Count zeros and calculate product of non-zero elements
//         for(int i = 0; i < s; i++) {

//             if(nums[i] == 0) {
//                 zeroCount++;
//             }
//             else {
//                 product *= nums[i];
//             }
//         }

//         vector<int> result;

//         // More than one zero
//         if(zeroCount > 1) {
//             return vector<int>(s, 0);
//         }

//         // Exactly one zero
//         if(zeroCount == 1) {

//             for(int i = 0; i < s; i++) {

//                 if(nums[i] == 0) {
//                     result.push_back(product);
//                 }
//                 else {
//                     result.push_back(0);
//                 }
//             }

//             return result;
//         }

//         // No zeros
//         for(int i = 0; i < s; i++) {
//             result.push_back(product / nums[i]);
//         }

//         return result;
//     }
// };

// USING PREFIX POSTFIX APPROACH 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int s = nums.size();
        
        vector<int> result(s,1);

        int prefix = 1;

        for(int i = 0; i < s; i++){
            result[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;

        for(int i = s - 1; i >=0; i--){
            result[i] *= postfix;
            postfix *= nums[i];
        }

        return result;
    }
};