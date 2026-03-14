class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;

        // Count total nodes
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        int midNode = (cnt/2) + 1;

        temp = head;
        while(temp != NULL){
            midNode--;
            if(midNode == 0){
                break;
            }
            temp = temp->next;
        }

        return temp;
    }
};