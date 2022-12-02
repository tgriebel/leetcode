class Solution {
public:
    double average(vector<int>& salary) {
        int minSalary = INT_MAX;
        int maxSalary = INT_MIN;
        double sum = 0;
        for( int i = 0; i < salary.size(); ++i ) {
            const int currentSalary = salary[i];
            minSalary = min( minSalary, currentSalary );
            maxSalary = max( maxSalary, currentSalary );
            sum += currentSalary;
        }
        sum -= minSalary;
        sum -= maxSalary;
        return ( sum /  ( salary.size() - 2 ) );
    }
};
