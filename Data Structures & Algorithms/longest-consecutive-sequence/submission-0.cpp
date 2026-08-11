// BETTER APPROACH -> SORT THE ELEMENTS AND THEN SEE
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int s = nums.size();
        sort(nums.begin() , nums.end());
        int count  = 0;
        int lastSmaller = INT_MIN;
        int longest = 1;

        for(int i = 0; i < s; i++){
            if((nums[i] - 1) == lastSmaller){
                count++;
                lastSmaller = nums[i];
            }

            else if(lastSmaller != nums[i]){
                count = 1;
                lastSmaller = nums[i];
            }

            longest = max(longest,count);
        }
        return longest;
    }
};
