
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        stack<int>st;

        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }

        temp=head;
        while(!st.empty()){
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }
};