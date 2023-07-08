/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non - empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

*/



class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int zero = 0;
        int len = 0;
        int  i = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) {
                zero++;
            }
            while (zero > 1) {
                if (nums[j] == 0 and nums[i] == 0) {
                    zero--;
                }
                i++;
            }
            len = max(len, j - i);
        }
        return len;
    }
};