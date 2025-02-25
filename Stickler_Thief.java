class Solution {
    // Function to find the maximum money the thief can get.
    public int findMaxSum(int arr[]) {
        int n = arr.length;
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        int prev2 = 0; // Represents dp[i-2]
        int prev1 = arr[0]; // Represents dp[i-1]

        for (int i = 1; i < n; i++) {
            int take = arr[i] + prev2; // Take current house
            int skip = prev1; // Skip current house
            
            int curr = Math.max(take, skip); // Choose the better option
            
            prev2 = prev1; // Move dp[i-2] to dp[i-1]
            prev1 = curr; // Move dp[i-1] to current result
        }

        return prev1;
    }
}
