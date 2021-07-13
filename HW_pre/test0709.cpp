#include<queue>
#include<vector>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> tmp;
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                tmp.push_back(cur -> val);
                if (cur -> left) {
                    q.push(cur -> left);
                }
                if (cur -> right) {
                    q.push(cur -> right);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
