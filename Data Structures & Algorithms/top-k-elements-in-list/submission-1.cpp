// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int> freq;

//         for(int n : nums){
//             freq[n]++;
//         }

//         vector<pair<int,int>> arr;
//         for(auto &pair : freq){
//             arr.push_back({pair.second , pair.first});
//         }

//         sort(arr.rbegin() , arr.rend()); // in descending order
        
//         vector<int> result;
//         for(int i = 0; i < k; i++){
//             result.push_back(arr[i].second);
//         }

//         return result;
//     }
// };


// USING BUCKET SORT -> OPTIMAL APPROACH
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;

        for(int n : nums){
            count[n]++;
        }

        vector<vector<int>> freq(nums.size() + 1);

        for(auto &pair : count){
            int number = pair.first;
            int frequency = pair.second;

            freq[frequency].push_back(number);
        }

        vector<int> result;
        for(int i = freq.size() - 1; i >=0 ; i--){
            for(int number : freq[i]){
                result.push_back(number);

                if(result.size() == k){
                    return result;
                }
            }
        }
        return result;

    }
};
