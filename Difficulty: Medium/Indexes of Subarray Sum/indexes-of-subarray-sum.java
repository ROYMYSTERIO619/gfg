
class Solution {
    static ArrayList<Integer> subarraySum(int[] arr, int target) {
        ArrayList<Integer> result  = new ArrayList<>();
        int currSum=0;
        int start=0;
        for(int end =0; end<arr.length;end++){
            currSum +=arr[end];
            while (currSum>target && start<=end){
                currSum-=arr[start];
                start ++;
            }
            
            if(currSum ==target){
                result.add(start+1);
                result.add(end+1);
                return result;
            }
        }
        
        result.add(-1);
        return result;
    }
}
