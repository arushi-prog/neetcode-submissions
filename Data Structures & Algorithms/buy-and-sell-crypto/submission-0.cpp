// BRUTE FORCE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int profit = prices[j] - prices[i];
                ans = max(ans,profit);
            }
        }
        return ans;
    }
};
