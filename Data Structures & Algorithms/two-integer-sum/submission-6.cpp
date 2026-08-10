// BRUTE FORCE APPROACH
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int size = nums.size();
//         // int sum = 0
//         for(int i = 0; i < size; i++){
//             for(int j = i + 1; j < size; j++){
//                 int sum = nums[i] + nums[j];

//                 if(sum == target){
//                     return {i,j};
//                 }
//             }
//         }
//         return {};
//     }
// };

// BETTER APPROACH OR OPTIMAL ONE TOO -> USING HASHMAP
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int s = nums.size();
//         unordered_map<int,int> mp;

//         for(int i = 0; i < s; i++){
//             int diff = target - nums[i];

//             if(mp.find(diff) != mp.end()){
//                 return {mp[diff],i};
//             }

//             mp.insert({nums[i] ,i });
//         }

//         return {};
//     }
// };

// TO OPTIMIZE SPACE COMPLEXITY -> 2 POINTERS (SORTED ARRAY)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;

        int s = nums.size();

        for(int i = 0; i < s; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int low = 0;
        int high = s - 1;

        while(low < high) {
            int sum = arr[low].first + arr[high].first;

            if(sum == target) {
                int index1 = arr[low].second;
                int index2 = arr[high].second;

                return {min(index1, index2), max(index1, index2)};
            }

            if(sum < target) {
                low++;
            }
            else {
                high--;
            }
        }

        return {};
    }
};
