/* ------------------------------------------------------------------|
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	递归法
*
*	执行用时：8 ms, 在所有 C++ 提交中击败了92.43%的用户
*	内存消耗：16.5 MB, 在所有 C++ 提交中击败了93.36%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& ans) {
    if (!root) {
        return;
    }
    ans.emplace_back(root->val);
    if (root->val == sum && !root->left && !root->right) {
        res.emplace_back(ans);
    }

    dfs(root->left, sum - root->val, res, ans);
    dfs(root->right, sum - root->val, res, ans);
    ans.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> ans;
    if (!root) {
        return res;
    }

    dfs(root, sum, res, ans);
    return res;
}