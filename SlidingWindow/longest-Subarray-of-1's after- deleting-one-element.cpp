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