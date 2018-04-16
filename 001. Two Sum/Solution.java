public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=0; i < numbers.length; i ++){
            map.put(numbers[i], i);
        }
        int[] result = new int[2];
        for(int i = 0; i < numbers.length; i ++){
            int waitCal = target-numbers[i];
            if(map.get(waitCal) != null && map.get(waitCal) > i){
                result[0] = i;
                result[1] = map.get(waitCal);
                break;
            }
        }   
    return result;
    }
}