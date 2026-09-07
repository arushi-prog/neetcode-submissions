// BRUTE FORCE
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans;

//         for(int i =0; i <= n - k; i++){
//             int maxi = INT_MIN;
//             for(int j = i; j < i + k; j++){
//                 maxi = max(maxi,nums[j]);
//             }
//             ans.push_back(maxi);
//         }
//         return ans;
//     }
// };

// OPTIMAL SOLUTION
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++) {

            // Remove elements outside the current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            // Add current index
            dq.push_back(i);

            // Start adding answers when window size becomes k
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};