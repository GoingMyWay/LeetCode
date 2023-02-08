class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        // 先把字符串转化成四进制的数字数组
        int[] nums = new int[s.length()];
        for (int i = 0; i < nums.length; i++) {
            switch (s.charAt(i)) {
                case 'A':
                    nums[i] = 0;
                    break;
                case 'G':
                    nums[i] = 1;
                    break;
                case 'C':
                    nums[i] = 2;
                    break;
                case 'T':
                    nums[i] = 3;
                    break;
            }
        }
        // 记录重复出现的哈希值
        HashSet<Integer> seen = new HashSet<>();
        // 记录重复出现的字符串结果
        HashSet<String> res = new HashSet<>();
        
        // 数字位数
        int L = 10;
        // 进制
        int R = 4;
        // 存储 R^(L - 1) 的结果
        int RL = (int) Math.pow(R, L - 1);
        // 维护滑动窗口中字符串的哈希值
        int windowHash = 0;
        
        // 滑动窗口代码框架，时间 O(N)
        int left = 0, right = 0;
        while (right < nums.length) {
            // 扩大窗口，移入字符，并维护窗口哈希值（在最低位添加数字）
            windowHash = R * windowHash + nums[right];
            right++;

            // 当子串的长度达到要求
            if (right - left == L) {
                // 根据哈希值判断是否曾经出现过相同的子串
                if (seen.contains(windowHash)) {
                    // 当前窗口中的子串是重复出现的
                    res.add(s.substring(left, right));
                } else {
                    // 当前窗口中的子串之前没有出现过，记下来
                    seen.add(windowHash);
                }
                // 缩小窗口，移出字符，并维护窗口哈希值（删除最高位数字）
                windowHash = windowHash - nums[left] * RL;
                left++;
            }
        }
        // 转化成题目要求的 List 类型
        return new LinkedList<>(res);
    }
}