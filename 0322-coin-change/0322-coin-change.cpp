class Solution {
public:
    int INF;
    // dfs represents how much count to get to that amount with our coins
    int dfs(vector<int> &coins, int amount, vector<int> &memo) {
        if (amount == 0) return 0;
        if (amount < 0) return INF; // not possible
        if (memo[amount] != -1) return memo[amount];
        int lowest_coins = INF;
        for (int coin : coins) {
            lowest_coins = min(1 + dfs(coins, amount - coin, memo), lowest_coins);
        }
        // this is the best possible we can get with this amount
        return memo[amount] = lowest_coins;
    }
    int coinChange(vector<int>& coins, int amount) {
        INF = amount + 1;
        // -1 represents we haven't visited it yet
        vector<int> memo(amount + 1, -1); // how many coins to get to this amount
        memo[0] = 0;
        int cnt = dfs(coins, amount, memo);
        return cnt == INF ? -1 : cnt;
    }
};