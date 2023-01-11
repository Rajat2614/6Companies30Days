void get_elements(TreeNode* root, vector<int> &arr) {
    if (root == NULL){
        return;
    }
    
    get_elements(root->left,arr);
    arr.push_back(root->val);
    get_elements(root->right,arr);
}
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> l,r;
        
        get_elements(root1,l);
        get_elements(root2,r);
        
        // Here l and r are already sorted because we are doing an Inorder Traversal
		// of a Binary Search Tree.
		// Now we only need to merge l and r into vector ans in O(n) 
		
        vector<int> ans;
        int i = 0,j = 0;
        while (i<l.size() && j < r.size()){
            if (l[i] <= r[j]){
                ans.push_back(l[i]);
                i++;
            }
            else {
                ans.push_back(r[j]);
                j++;
            }
        }
        while (ans.size() < l.size() + r.size()) {
            if (i<l.size()){
                ans.push_back(l[i]);
                i++;
            }
             else {
                ans.push_back(r[j]);
                j++;
            }
            
        }
        return ans;
    }
};
