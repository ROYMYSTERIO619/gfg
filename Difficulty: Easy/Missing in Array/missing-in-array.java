class Solution {
    int missingNum(int arr[]) {
        int n = arr.length + 1;
        int xorAll = 0;
        for (int i = 1; i <= n; i++) {
            xorAll ^= i;
        }
        int xorArr = 0;
        for (int i = 0; i < arr.length; i++) {
            xorArr ^= arr[i];
        }
    
        return xorAll ^ xorArr;
    }
}