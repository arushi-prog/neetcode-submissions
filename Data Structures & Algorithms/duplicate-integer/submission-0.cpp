// RUTE FORCE 
// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums) {
//         int size = nums.size();
//         for(int i = 0; i < nums.size(); i++){
//             for(int j = i+1; j < nums.size(); j++){
//                 if(nums[i] == nums[j]){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// USING SORTING
// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums) {
//         int size = nums.size();

//         sort(nums.begin(), nums.end());

//         for(int i = 0; i < size - 1; i++){
//             if(nums[i] == nums[i + 1]){
//                 return true;
//             }
//         }

//         return false;
//     }
// };

// OPTIMAL APPROACH -> USING HASHSETS
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num : nums){
            if(seen.count(num)){
                return true;
            }

            seen.insert(num);
        }
        return false;
    }
};