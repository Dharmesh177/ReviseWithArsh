/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
      ListNode* curr=head;
    vector<int> A;
    
    while(curr){
        A.push_back(curr->val);
        curr = curr->next;
    }
    
    int j, sum=0;
    for (auto i=0;i<A.size();i++){
        sum=0;
        for(j=i;j<A.size();j++){
            sum += A[j];
            if(sum==0)
                break;
        }            
        if(sum==0) {
            A.erase(A.begin()+i,A.begin()+j+1);
            i--;
        }
    }
    
    if(A.size()==0)
        return NULL;
    else
    {
        ListNode* root = new ListNode(A[0]);
        curr = root;
        for (auto i=1;i<A.size();i++)
        {
            ListNode* temp = new ListNode;
            temp->val=A[i];
            root->next=temp;
            root=root->next;
        }

        return curr;
    }
    }
};