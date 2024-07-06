class Solution {
public:
    int passThePillow(int n, int time) {
        int pos = 1;  // Start with the pillow at the first position
        bool direction = true;  // true means moving right, false means moving left

        while (time--) {
            if (direction) 
            {
                pos++;  // Move the pillow to the next person to the right
            } 
            else {
                pos--;  // Move the pillow to the next person to the left
            }

            // Check if the pillow has reached the boundary and needs to change direction
            if (pos == n || pos == 1) {
                direction = !direction;  // Toggle the direction
            }
        }

        return pos;  // Return the final position of the pillow after the given time
    }
};
