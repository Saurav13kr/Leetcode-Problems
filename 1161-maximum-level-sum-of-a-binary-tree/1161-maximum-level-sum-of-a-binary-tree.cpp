class Solution {
public:
    int maxLevelSum(TreeNode *root) {
        TreeNode *level[2000], *nextLevel[2000], *currNode;
        int currPos = 1, nextPos, maxTot = INT_MIN, tot, res, levelCounter = 1;
        level[0] = root;
        // BFS routine
        
        while (currPos) 
        {
            tot = 0;
            nextPos = 0;

            for (int i = 0; i < currPos; i++) 
            {

                currNode = level[i];
                tot += currNode->val;
                if (currNode->left) nextLevel[nextPos++] = currNode->left;
                if (currNode->right) nextLevel[nextPos++] = currNode->right;
            }

            if (tot > maxTot) {
                res = levelCounter;
                maxTot = tot;
            }
            
            swap(level, nextLevel);
            swap(currPos, nextPos);
            nextPos = 0;
            levelCounter++;
        }
        
        return res;
    }
};