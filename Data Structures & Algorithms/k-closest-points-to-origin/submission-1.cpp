class Solution {
    double dist(double x1, double y1) {
        return sqrt((x1 * x1) + (y1 * y1));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<double>> pq;

        for (vector<int>& p : points) {
            double x1 = p[0];
            double y1 = p[1];
            double pDist = dist(x1, y1);
            pq.push({pDist, x1, y1});
        }

        while (pq.size() > k) {
            pq.pop();
        }

        vector<vector<int>> res;

        for (int i = 0; i < k; ++i) {
            vector<double> subpq = pq.top();
            int x1 = subpq[1];
            int y1 = subpq[2];
            res.push_back({x1, y1});
            pq.pop();
        }

        return res;
    }
};
