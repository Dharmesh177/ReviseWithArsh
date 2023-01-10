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
class Solution {
public:
    
    void preorder(TreeNode* root,vector<int> &pre){
        if(root==NULL)return;
        preorder(root->left,pre);
        pre.push_back(root->val);
        
        preorder(root->right,pre);
    }
    void merge(vector<int> pre1,vector<int> pre2,vector<int> &ans){
         int i = 0, j = 0, k = 0;
  int n1=pre1.size();
  int n2=pre2.size();
    // Traverse both array
    while (i<n1 && j <n2)
    {
        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array
        if (pre1[i] < pre2[j])
           { 
            ans.push_back(pre1[i++]);
            // ans[k++] = pre1[i++];
            k++;
           }
        else
           { 
             ans.push_back(pre2[j++]);
            // ans[k++] = pre1[i++];
            k++;
            // ans[k++] = pre2[j++];}
    }
    }
  
    // Store remaining elements of first array
    while (i < n1)
        { 
            ans.push_back(pre1[i++]);
            // ans[k++] = pre1[i++];
            k++;
           }
  
    // Store remaining elements of second array
    while (j < n2)
         { 
             ans.push_back(pre2[j++]);
            // ans[k++] = pre1[i++];
            k++;
            // ans[k++] = pre2[j++];}
    }
    
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> pre1;
        preorder(root1,pre1);
        vector<int> pre2;
        preorder(root2,pre2);
        vector<int> ans;
        merge(pre1,pre2,ans);
        return ans;
    }
};