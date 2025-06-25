class Solution {
    static ArrayList<Integer> leaders(int[] arr) {
        ArrayList<Integer> ans = new ArrayList<>();
        int n = arr.length;
        
        // Handle empty array case
        if (n == 0) {
            return ans;
        }
        
        // Rightmost element is always a leader
        int maxFromRight = arr[n - 1];
        ans.add(maxFromRight);
        
        // Scan from right to left
        for (int i = n - 2; i >= 0; i--) {
            // If current element is >= max seen from right
            if (arr[i] >= maxFromRight) {
                ans.add(arr[i]);
                maxFromRight = arr[i];
            }
        }
        
        // Reverse the list to maintain original order
        Collections.reverse(ans);
        return ans;
    }
}