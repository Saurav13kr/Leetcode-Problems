class Solution {
public:
    int findLargestAreaInHistogram(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int leftsmall[n], rightsmall[n];
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty())
                leftsmall[i] = 0;
            else
                leftsmall[i] = st.top() + 1;
            st.push(i);
        }
        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                rightsmall[i] = n - 1;
            else
                rightsmall[i] = st.top() - 1;

            st.push(i);
        }
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int area = 0;
        vector<int> rowHistogram(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    rowHistogram[j]++;
                } 
                else {
                    rowHistogram[j] = 0;
                }
            }
            area = max(area, findLargestAreaInHistogram(rowHistogram));
        }
        return area;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();