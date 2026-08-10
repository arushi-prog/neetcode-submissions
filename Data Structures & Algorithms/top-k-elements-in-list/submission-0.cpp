class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int n : nums){
            freq[n]++;
        }

        vector<pair<int,int>> arr;
        for(auto &pair : freq){
            arr.push_back({pair.second , pair.first});
        }

        sort(arr.rbegin() , arr.rend()); // in descending order
        
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(arr[i].second);
        }

        return result;
    }
};
