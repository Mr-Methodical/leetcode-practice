class Solution {
public:
    int fun(vector<int>& piles, int i) {
        // i is the rate that we are trying out to see if it is good
        // we will check is this our correct one
        // and we want the ceiling
        int curr_hours = 0;
        for (int j = 0; j < piles.size(); ++j) {
            curr_hours += (piles[j] + i - 1) / i;
        }
        return curr_hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // they seem to allow us to do n^2 algo
        // let's start with inefficient approach
        // the best we can do is the max element
        int m = *max_element(piles.begin(), piles.end());
        // going over m would not help us anymore
        // let's do binary search instead because it will also allow us to find the minimum
        int lo = 1;
        int hi = m;
        while (lo < hi) {
            int mid = lo + ((hi - lo) / 2);
            int curr_hours = fun(piles, mid);
            if (curr_hours <= h) {
                // this is our smallest and goign up will only hurt us more
                hi = mid; // it may very well be this one
                // this is our new best, it might be this or it may be lower
            } else {
                // curr_hours is greater than h, our rate must be higher
                lo = mid + 1;
            }
        }   
        return hi;
    }
};