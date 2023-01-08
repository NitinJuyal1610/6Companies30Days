class Solution {
public:
    //inorder
    void helper(vector<int>&v,TreeNode* root){
        if(root==NULL){
            return ;
        }
        helper(v,root->left);
        v.push_back(root->val);
        helper(v,root->right);
        return;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;
        helper(v1,root1);
        helper(v2,root2);
        vector<int>ans;
        int i=0,j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<v2[j]){
                ans.push_back(v1[i]);
                i++;
            }else {
                ans.push_back(v2[j]);
                j++;
            }
        }

        while(i<v1.size()){
            ans.push_back(v1[i]);
            i++;
        }
        while(j<v2.size()){
            ans.push_back(v2[j]);
            j++;
        }

        return ans;
        
    }
};