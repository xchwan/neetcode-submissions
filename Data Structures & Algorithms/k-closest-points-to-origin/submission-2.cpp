class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < (int)points.size(); ++i) {
            int pDist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({pDist, i});
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;

        for (int i = 0; i < k; ++i) {
            int idx = pq.top().second;
            pq.pop();
            res.push_back(points[idx]);
        }

        return res;
    }
};
