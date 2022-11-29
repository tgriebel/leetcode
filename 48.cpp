class Solution {
public:
    void swap(int& num0, int& num1) {
        int t = num0;
        num0 = num1;
        num1 = t;
    }
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        for( int j = 0; j < N; ++j ) {
            for( int i = j; i < N; ++i ) {
                swap(matrix[j][i], matrix[i][j]);
            }
        }
        for( int j = 0; j < N; ++j ) {
            for( int i = 0; i < N / 2; ++i ) {
                swap(matrix[j][i], matrix[j][N - i - 1]);
            }
        }
    }
};
