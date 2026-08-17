// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int totalWater = 0;
//         for(int i = 0; i < n; i++){
//             int leftmax = 0;
//             int rightmax = 0;

//             for(int j = 0; j <= i; j++){
//                 leftmax = max(leftmax,height[j]);
//             }

//             for(int j = i; j < n; j++){
//                 rightmax = max(rightmax,height[j]);
//             }

//             totalWater += min(rightmax,leftmax) - height[i];
//         }
//         return totalWater;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int totalWater = 0;

        while(left <= right) {

            if(height[left] <= height[right]) {

                if(height[left] >= leftMax) {
                    leftMax = height[left];
                }
                else {
                    totalWater += leftMax - height[left];
                }

                left++;
            }

            else {

                if(height[right] >= rightMax) {
                    rightMax = height[right];
                }
                else {
                    totalWater += rightMax - height[right];
                }

                right--;
            }
        }

        return totalWater;
    }
};
