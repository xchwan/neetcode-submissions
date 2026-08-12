class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0, r = m - 1;
        int u = 0, d = n - 1;

        while (u <= d) {

            int mid_n = u + (d - u) / 2;

            if (matrix[mid_n][l] <= target && matrix[mid_n][r] >= target ) {
                while(l <= r) {

                    int mid_m = l + (r - l) / 2;

                    if (matrix[mid_n][mid_m] == target) {
                        return true;
                    } else if (matrix[mid_n][mid_m] > target) {
                        r = mid_m - 1; 
                    } else {
                        l = mid_m + 1;
                    }

                }
            } else if (matrix[mid_n][l] > target) {
                d = mid_n - 1;
            } else {
                u = mid_n + 1;
            }
        }

        return false; 
    }
};
