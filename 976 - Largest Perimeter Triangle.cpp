class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
         std::sort ( nums.begin(), nums.end(), std::greater<>() );
         for( int i = 2; i < nums.size(); ++i ) {
             const int a = nums[i - 2];
             const int b = nums[i - 1];
             const int c = nums[i - 0];
             if( a < ( b + c ) ) {
                 return ( a + b + c );
             }
         }
         return 0;
    }
};
