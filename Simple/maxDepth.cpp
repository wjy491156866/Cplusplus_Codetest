//104. 二叉树的最大深度
//给定一个二叉树，找出其最大深度。
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//说明: 叶子节点是指没有子节点的节点。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) { //深度优先搜索
        if (root == NULL) return 0;
        int left = maxDepth(root -> left);  //左节点往下
        int right = maxDepth(root -> right);    //右节点往下
        int depth = ((left > right) ? left : right);    //两数之间找最大的数
        return depth + 1;   //最后返回加上根节点一层
    }
};
