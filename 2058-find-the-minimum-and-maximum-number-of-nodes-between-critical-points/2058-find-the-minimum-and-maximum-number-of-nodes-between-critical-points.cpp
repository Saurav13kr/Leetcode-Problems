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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        ListNode * prev = temp;

        int firstCP = 0, prevCP = 0, idx = 1, minDist = INT_MAX;

        while (temp->next) {
            idx++;

            int x = temp->val, y = prev->val, z = temp->next->val;

            if((x > y && x > z) || (x < y && x < z)){
                if(prevCP == 0){
                    firstCP = idx;
                    prevCP = firstCP;
                }
                else
                {
                    minDist = min(minDist, (idx - prevCP));
                    prevCP = idx;
                }
            }
            prev = temp;
            temp = temp->next;
        }

        int maxDist = prevCP - firstCP;

        if(maxDist == 0)
            return {-1,-1};

        return{minDist, maxDist};
    }
};