class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        // create it as the right products at first
        output[n - 1] = 1; // multiplicative identity
        for (int i = n - 2; i >= 0; --i) {
            output[i] = output[i + 1] * nums[i + 1];
        }
        int leftProduct = 1;
        for (int i = 1; i < n; ++i) {
            leftProduct *= nums[i - 1];
            output[i] *= leftProduct;
        }
        return output;
    }
};