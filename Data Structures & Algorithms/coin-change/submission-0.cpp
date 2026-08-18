class Solution {
    int dfs(vector<int>& coins, int amount, unordered_map<int, int>& memo) {
        if (amount == 0) return 0;
        if (memo.count(amount)) {
            return memo[amount];
        }

        int res = INT_MAX;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                int sub = dfs(coins, amount - coin, memo);
                if (sub != INT_MAX) {
                    res = min(res, 1 + sub);
                }
            }
        }
        memo[amount] = res;
        return res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        int minCoins = dfs(coins, amount, memo);
        return (minCoins == INT_MAX) ? -1 : minCoins;
    }
};
