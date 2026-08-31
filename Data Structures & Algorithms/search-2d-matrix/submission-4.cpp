// BRUTE FORCE
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& mat, int target) {
//         for(int i =0; i < mat.size(); i++){
//             for(int j = 0; j < mat[0].size(); j++){
//                 if(mat[i][j] == target){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// BETTER APPROACH
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& mat, int target) {
//         int n = mat[0].size();
//         for(int i = 0; i < mat.size(); i++){
//             if(mat[i][0] <= target && target <= mat[i][n-1]){
//                 int low = 0;
//                 int high = n-1;
//                 while(low <= high){
//                     int mid = low + (high - low) / 2;
//                     if(mat[i][mid] == target){
//                         return true;
//                     }

//                     else if(mat[i][mid] < target){
//                         low = mid + 1;
//                     }
//                     else{
//                         high = mid - 1;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };

// OPTIMAL APPROACH
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = m * n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int row = mid / n;
            int col = mid % n;

            if(mat[row][col] == target){
                return true;
            }

            else if(mat[row][col] < target){
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }
        return false;        
    }
};
