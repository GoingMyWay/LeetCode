/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 注意：cpp 代码由 chatGPT\U0001f916 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码已经通过力扣的全部测试用例，可直接粘贴提交。

class Solution {
private:
    // 存储 inorder 中值到索引的映射
    unordered_map<int, int> valToIndex;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i ++) {
            valToIndex[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
    }

    /*
       定义：
       中序遍历数组为 inorder[inStart..inEnd]，
       后序遍历数组为 postorder[postStart..postEnd]，
       构造这个二叉树并返回该二叉树的根节点
    */
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd) return nullptr;
        
        // root 节点对应的值就是后序遍历数组的最后一个元素
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // 递归构造左右子树
        // rootVal 在中序遍历数组中的索引
        int index = valToIndex[rootVal];
        // 左子树的节点个数
        int leftSize = index - inStart;
        root->left  = build(inorder,   inStart,   index - 1,
                            postorder, postStart, postStart + leftSize - 1);
        root->right = build(inorder,   index + 1,            inEnd,
                            postorder, postStart + leftSize, postEnd - 1);
        return root;
    }
};
