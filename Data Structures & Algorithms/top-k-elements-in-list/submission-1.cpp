class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); ++i) {
            ++freq[nums[i]];
        }

        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;

        for (auto& [key, val] : freq) {
            pq.push({val, key});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
