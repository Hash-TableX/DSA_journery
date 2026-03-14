/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int>visited;
        ListNode* temp = head;
        while(temp!=NULL){
            if(visited[temp]==1){
                return true;
            }
            visited[temp]=1;
            temp=temp->next;
        }
        return false;
    }
};