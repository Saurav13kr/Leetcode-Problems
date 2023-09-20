class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(numCols, 0);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0; 
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        int i = 0;      
        while (i < heights.size()) {
            if (s.empty() || heights[i] >= heights[s.top()]) {
                s.push(i++);
            } else {
                int top = s.top();
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, heights[top] * width);
            }
        }
        while (!s.empty()) {
            int top = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, heights[top] * width);
        }       
        return maxArea;
    }
};