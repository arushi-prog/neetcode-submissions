// // BRUTE FORCE
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int s = numbers.size();
//         for(int i = 0; i < s; i++){
//             for(int j = i + 1; j < s; j++){
//                 if(numbers[i] + numbers[j] == target){
//                     return{i + 1, j + 1};
//                 }
//             }
//         }
//         return {};
//     }
// };

// OPTIMAL APPROACH -> 2 POINTERS
// BRUTE FORCE
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right){
            int sum = numbers[left] + numbers[right];

            if(sum == target){
                return{left + 1, right + 1};
            }

            else if(sum > target){
                right--;
            }

            else{
                left++;
            }
        }
        return{};
    }
};
