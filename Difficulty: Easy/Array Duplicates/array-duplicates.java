class Solution {
    public List<Integer> findDuplicates(int[] arr) {
        // Initialize result list
        List<Integer> result = new ArrayList<>();
        
        // Use HashMap to store frequency of elements
        HashMap<Integer, Integer> freq = new HashMap<>();
        
        // Count frequency of each element
        for (int num : arr) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        
        // Add elements with frequency > 1 to result
        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            if (entry.getValue() > 1) {
                result.add(entry.getKey());
            }
        }
        
        // Sort the result to ensure consistent output (optional, based on problem requirements)
        Collections.sort(result);
        return result;
    }
}