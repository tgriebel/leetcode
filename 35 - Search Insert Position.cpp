class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() -1;
        while(lo < hi) {
            int mid = (hi + lo) / 2;
            if( nums[mid] > target ) {
                hi = mid - 1;
            } else if( nums[mid] < target ) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }
        int mid = (hi + lo) / 2;
        if(nums[mid] < target) {
            return mid + 1;
        } else {
            return mid;
        }
    }
};
