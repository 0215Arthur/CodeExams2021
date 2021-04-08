
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 TreeNode* init(vector<int> arr, int index) {
     TreeNode* root = new TreeNode(arr[index] ->val);
     root -> left = init(arr, index + 1);
     root -> left = init(arr, index + 2);
 }

// TreeNode*  buildTree(TreeNode* root) {
//     queue<TreeNode*> q;
//     q.push(root);
//     bool flag = false;
//     while (!q.empty()) {
//         int s = q.size();
//         for (int i = 0; i < s; i++) {
//             TreeNode* cur = q.front();
//             q.pop();
//             if (!cur -> left && !cur -> right) {
//                 flag = true;
//             }
//             if (cur -> left && cur -> right) {
//                 if (!flag)  {
//                 q.push(cur -> left);
//                 q.push(cur -> right);
//                 }
//                 else {
//                     cur -> left = nullptr;
//                     cur -> right = nullptr;
//                 }
//                 continue;
//             }
//             if (cur -> left) {
//                     if (flag) {
//                         cur -> left = nullptr;
//                     }
//                 flag = true;
//             }
//             if (cur -> right) {
//                 cur -> right = nullptr;
//                 flag = true;
//             }
//         }
//     }
//     return root;
// }

TreeNode*  buildTree(TreeNode* root) {
    deque<TreeNode*> q;
    q.push_back(root);
    bool flag = false;
    while (!q.empty()) {
        int s = q.size();
        for (int i = 0; i < s; i++) {
            TreeNode* cur = q.front();
            q.pop_front();
            q.push_back(cur);
            if (!cur->left || !cur->right) {
                flag = true;
            }
            break;
        }
        if (flag) {
            for (int i = 0; i < s; i++) {
                TreeNode* cur = q.front();
                q.pop_front();
                cur -> left = nullptr;
                cur -> right = nullptr;
            }
            break;
        }
        else {
            for (int i = 0; i < s; i++) {
                TreeNode* cur = q.front();
                q.pop_front();
                q.push_back(cur->left);
                q.push_back(cur->right);
            }
        }
    }
    return root;
}