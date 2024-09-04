enum Direction { UP, DOWN, LEFT, RIGHT };

static Direction turn_left(Direction dir) {
    switch (dir) {
        case UP: return LEFT;
        case DOWN: return RIGHT;
        case LEFT: return DOWN;
        case RIGHT: return UP;
    }
}

static Direction turn_right(Direction dir) {
    switch (dir) {
        case UP: return RIGHT;
        case DOWN: return LEFT;
        case LEFT: return UP;
        case RIGHT: return DOWN;
    }
}

class Solution {
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        // Mapping x -> list of y obstacles, and y -> list of x obstacles
        unordered_map<int, vector<int>> x_obs, y_obs;

        for (auto &&obs: obstacles) {
            int x = obs[0], y = obs[1];
            x_obs[x].push_back(y);
            y_obs[y].push_back(x);
        }

        for (auto &[key, value] : x_obs) {
            sort(value.begin(), value.end());
        }
        for (auto &[key, value] : y_obs) {
            sort(value.begin(), value.end());
        }

        int x = 0, y = 0;
        int ans = 0;
        Direction dir = UP;

        for (auto command: commands) {
            if (command == -2) {
                dir = turn_left(dir);
            } else if (command == -1) {
                dir = turn_right(dir);
            } else {
                assert(command >= 1 && command <= 9);

                if (dir == UP) {
                    int start_y = y;
                    int end_y = y + command;

                    // Find obstacles along x = x and y increasing
                    if (x_obs.count(x)) {
                        auto &obs_y = x_obs[x];
                        auto it = lower_bound(obs_y.begin(), obs_y.end(), start_y + 1);
                        if (it != obs_y.end() && *it <= end_y && *it > start_y) {
                            end_y = *it - 1;
                        }
                    }
                    y = end_y;

                } else if (dir == DOWN) {
                    int start_y = y;
                    int end_y = y - command;

                    // Find obstacles along x = x and y decreasing
                    if (x_obs.count(x)) {
                        auto &obs_y = x_obs[x];
                        auto it = upper_bound(obs_y.begin(), obs_y.end(), start_y);
                        if (it != obs_y.begin() && *(--it) >= end_y && *it < start_y) {
                            end_y = *it + 1;
                        }
                    }
                    y = end_y;

                } else if (dir == LEFT) {
                    int start_x = x;
                    int end_x = x - command;

                    // Find obstacles along y = y and x decreasing
                    if (y_obs.count(y)) {
                        auto &obs_x = y_obs[y];
                        auto it = upper_bound(obs_x.begin(), obs_x.end(), start_x);
                        if (it != obs_x.begin() && *(--it) >= end_x && *it < start_x) {
                            end_x = *it + 1;
                        }
                    }
                    x = end_x;

                } else if (dir == RIGHT) {
                    int start_x = x;
                    int end_x = x + command;

                    // Find obstacles along y = y and x increasing
                    if (y_obs.count(y)) {
                        auto &obs_x = y_obs[y];
                        auto it = lower_bound(obs_x.begin(), obs_x.end(), start_x + 1);
                        if (it != obs_x.end() && *it <= end_x && *it > start_x) {
                            end_x = *it - 1;
                        }
                    }
                    x = end_x;
                }

                ans = max(ans, x * x + y * y);
            }
        }

        return ans;
    }
};