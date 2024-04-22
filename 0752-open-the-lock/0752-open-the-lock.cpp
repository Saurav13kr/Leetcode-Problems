class Solution {
public:
    static int openLock(const vector<string>& deadends, const string& starget) {
        int target = std::stoi(starget);
        std::array<bool, 10000> visited = {};
        for (const std::string& deadend : deadends) {
            visited[std::stoi(deadend)] = true;
        }
        if (visited[0]) {
            return -1;
        }
        if (target == 0) {
            return 0;
        }

        std::vector<int> stack = {0};
        int length = 0;
        
        while (!stack.empty()) {
            ++length;
            std::vector<int> nextStack;
            for (int value : stack) {
                for (int base : {1, 10, 100, 1000}) {
                    int posValue = (value / base) % 10;
                    
                    for (int nextPosValue : {(posValue + 1) % 10, (posValue + 9) % 10}) {
                        int nextValue = value + (nextPosValue - posValue) * base;
                        if (nextValue == target) {
                            return length;
                        }
                        if (visited[nextValue]) {
                            continue;
                        }
                        visited[nextValue] = true;
                        nextStack.push_back(nextValue);
                    }
                }
            }
            stack = std::move(nextStack);
        }
        return -1;
    }
};