// // BETTER APPROACH -> SORT THE ELEMENTS AND THEN SEE
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size() == 0) return 0;

//         int s = nums.size();
//         sort(nums.begin() , nums.end());
//         int count  = 0;
//         int lastSmaller = INT_MIN;
//         int longest = 1;

//         for(int i = 0; i < s; i++){
//             if((nums[i] - 1) == lastSmaller){
//                 count++;
//                 lastSmaller = nums[i];
//             }

//             else if(lastSmaller != nums[i]){
//                 count = 1;
//                 lastSmaller = nums[i];
//             }

//             longest = max(longest,count);
//         }
//         return longest;
//     }
// };

// OPTIMAL APPROACH
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int s = nums.size();

        if(s == 0) return 0;

        int longest = 1;

        unordered_set<int> st;

        for(int i = 0; i < s; i++){
            st.insert(nums[i]);
        }

        for(auto it : st){

            // Start only if it is the beginning of a sequence
            if(st.find(it - 1) == st.end()){

                int count = 1;
                int x = it;

                while(st.find(x + 1) != st.end()){
                    x++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};