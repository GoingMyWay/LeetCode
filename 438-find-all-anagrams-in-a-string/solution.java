public class Solution {  
    public List<Integer> findAnagrams(String s, String p) {  
        List<Integer> result = new ArrayList<>();  
        if(s == null||s.length() == 0||p == null||p.length()==0)  
            return result;  
        int[] hash = new int[256];  
        char[] pp = p.toCharArray();  
        for(char i:pp){  hash[i]++;  }
        
        int left = 0, right = 0, count = p.length();  
        while(right < s.length())  
        {  
            if(hash[s.charAt(right++)]-- > 0)  count--;  
            if(count == 0)  result.add(left);
            if(right - left == p.length() && hash[s.charAt(left++)]++ >= 0) count++;  
        }  
        return result;  
          
    }  
}  