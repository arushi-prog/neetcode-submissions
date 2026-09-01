// BRUTE FORCE
// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int maxPile = *max_element(piles.begin(),piles.end());

//         for(int i = 1; i <= maxPile; i++){
//             int hours = 0;
//             for(int pile : piles){
//                 hours += ceil((double)pile / (double)i);
//             }

//             if(hours <= h){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

//OPTIMAL APPROACH
// BRUTE FORCE
class Solution {
public:
    int maxElem(vector<int>& piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }

    int calculateTotalHours(vector<int>& piles, int hourly){
        int totalH = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            totalH += ceil((double)piles[i] / (double)hourly);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxElem(piles);
        while(low <= high){
            int mid = low + (high - low) / 2;

            int totalH = calculateTotalHours(piles,mid);

            if(totalH <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};