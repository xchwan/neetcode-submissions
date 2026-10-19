class Solution {
    vector<string> possiblelocks(string lock) {
        vector<string> res;
        for (int i = 0; i < 4; ++i) {
            for (int j : {1, -1}) {
                string next = lock;
                next[i] = (next[i] - '0' + j + 10) % 10 + '0';
                res.push_back(next);
            }
        }
        return res;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit(deadends.begin(), deadends.end());
        if (visit.count("0000")) return -1;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visit.insert("0000");

        while(!q.empty()) {
            auto [lock, turns] = q.front();
            q.pop();

            if (lock == target) return turns;
            for (string possiblelock : possiblelocks(lock)) {
                if (!visit.count(possiblelock)) {
                    visit.insert(possiblelock);
                    q.push({possiblelock, turns + 1});
                }
            }
        }
        return -1;
    }
};