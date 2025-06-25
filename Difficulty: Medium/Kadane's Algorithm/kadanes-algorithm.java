class Solution {
    int maxSubarraySum(int[] arr) {
        // Initialize variables
        int maxSoFar = arr[0];  // Tracks maximum sum found
        int currMax = arr[0];   // Tracks maximum sum ending at current position
        
        // Start from second element
        for(int i = 1; i < arr.length; i++) {
            // Either start new subarray with current element
            // or extend existing subarray
            currMax = Math.max(arr[i], currMax + arr[i]);
            
            // Update maximum sum found so far
            maxSoFar = Math.max(maxSoFar, currMax);
        }
        
        return maxSoFar;
    }
}