class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort( arr1.begin(), arr1.end() );
        sort( arr2.begin(), arr2.end() );

        int count = 0;
        for( int i = 0; i < arr1.size(); ++i ) {
            int lo = 0;
            int hi = arr2.size() - 1;
            bool found = false;
            while( lo <= hi ) {
                int mid = ( hi + lo ) / 2;
                int diff = ( arr1[i] - arr2[mid] );
                if( abs( diff ) <= d ) {
                    found = true;
                    break;
                } else if( arr2[mid] > arr1[i] ) {
                    hi = mid - 1;
                } else if( arr2[mid] < arr1[i] ) {
                    lo = mid + 1;
                }
            }
            if( found == false ) {
                ++count;
            }
        }
        return count;
    }
};
