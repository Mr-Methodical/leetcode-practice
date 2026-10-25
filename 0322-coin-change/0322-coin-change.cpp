class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // we will have an array that how much it took to get to that amount
        vector<int> dp(amount + 1, 10001); // max the amount could be is 10^4
        for (int coin : coins) {
            if (coin <= amount) {
                dp[coin] = 1; // 1 coin to get there
            }
        }
        dp[0] = 0; // 0 coins to get to 0 amount
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    // this is one way that we could get here
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == 10001 ? -1 : dp[amount];
    }
};