class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int matrixSize = matrix.size(); // Get the size of the matrix
        vector<int> prevRowCosts(matrixSize); // Initialize a vector to store cost of the previous row

        // Loop over all the rows of the matrix
        for (auto& row : matrix) {
            vector<int> currentRowCosts = prevRowCosts; // Copy the previous row costs to the 
            for (int j = 0; j < matrixSize; ++j) {
                // Ensure we're not on the first element to avoid going out of bounds
                if (j > 0) {
                    currentRowCosts[j] = min(currentRowCosts[j], prevRowCosts[j - 1]); 
                }

                if (j + 1 < matrixSize) {
                    currentRowCosts[j] = min(currentRowCosts[j], prevRowCosts[j + 1]); // Take the smaller path from the right diagonal
                }

                currentRowCosts[j] += row[j]; // Add the current row's cost to the min cost found
            }

            prevRowCosts = move(currentRowCosts);
        }

        return *min_element(prevRowCosts.begin(), prevRowCosts.end());
    }
};
