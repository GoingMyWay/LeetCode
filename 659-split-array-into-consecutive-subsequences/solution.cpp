class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, vector<vector<int>>> need;
        
        for (int v : nums) freq[v]++;
        
        for (int v : nums) {
            if (freq[v] == 0) {
                continue;
            }

            if (need.count(v) && need[v].size() > 0) {
                // v 可以接到之前的某个序列后面
                freq[v]--;
                // 随便取一个需要 v 的子序列
                vector<int> seq = need[v].back();
                need[v].pop_back();
                // 把 v 接到这个子序列后面
                seq.push_back(v);
                // 这个子序列的需求变成了 v + 1
                need[v + 1].push_back(seq);

            } else if (freq[v] > 0 && freq[v + 1] > 0 && freq[v + 2] > 0) {
                // 可以将 v 作为开头
                freq[v]--;
                freq[v + 1]--;
                freq[v + 2]--;
                // 新建一个长度为 3 的子序列 [v,v + 1,v + 2]
                vector<int> seq{v, v + 1, v + 2};
                // 对 v + 3 的需求加一
                need[v + 3].push_back(seq);

            } else {
                return false;
            }
        }
        
        // 打印切分出的所有子序列
        for (auto it : need) {
            for (vector<int>& seq : it.second) {
                for (int v : seq) {
                    cout << v << " ";
                }
                cout << endl;
            }
        }
        return true;
    }
};

// class Solution {
// public:
//     struct Compare {
//         bool operator()(array<int, 2> subsequence1, array<int, 2> subsequence2) {
//             if (subsequence1[1] == subsequence2[1]) {
//                 return (subsequence1[1] - subsequence1[0]) > (subsequence2[1] - subsequence2[0]);
//             }
//             return subsequence1[1] > subsequence2[1];
//         }
//     };

//     bool isPossible(vector<int> &nums) {
//         priority_queue<array<int, 2>, vector<array<int, 2>>, Compare> subsequences;

//         for (int num : nums) {
//             //Condition 1 - remove non qualifying subsequences
//             while (!subsequences.empty() && subsequences.top()[1] + 1 < num) {
//                 array<int, 2> currentSubsequence = subsequences.top();
//                 subsequences.pop();
//                 int subsequenceLength = currentSubsequence[1] - currentSubsequence[0] + 1;
//                 if (subsequenceLength < 3) {
//                     return false;
//                 }
//             }
//             //Condition 2 - create a new subsequence
//             if (subsequences.empty() || subsequences.top()[1] == num) {
//                 subsequences.push({num, num});
//             } else {
//                 //Condition 3 - add num to an existing subsequence
//                 array<int, 2> currentSubsequence = subsequences.top();
//                 subsequences.pop();
//                 subsequences.push({currentSubsequence[0], num});
//             }
//         }

//         //If any subsequence is of length less than 3 return false
//         while (!subsequences.empty()) {
//             array<int, 2> currentSubsequence = subsequences.top();
//             subsequences.pop();
//             int subsequenceLength = currentSubsequence[1] - currentSubsequence[0] + 1;
//             if (subsequenceLength < 3) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
