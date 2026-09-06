// BRUTE FORCE
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int ans = 0;

//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 int profit = prices[j] - prices[i];
//                 ans = max(ans,profit);
//             }
//         }
//         return ans;
//     }
// };

// OPTIMAL SOLUTION
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxprofit = 0;
        int n = prices.size();

        while(r < n){
            if(prices[r] > prices[l]){
                maxprofit = max(maxprofit , prices[r] - prices[l]);
            }
            else{
                l = r;
            }
            r++;
        }
        return maxprofit;
    }
};
