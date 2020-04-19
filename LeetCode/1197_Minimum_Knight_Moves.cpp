class Solution {
private:
    unordered_map<int, int> memo;
    int _get(int x, int y) {
        if (x < 0) {
            x = -x;
        }
        if (y < 0) {
            y = -y;
        }
        if (x < y) {
            swap(x ,y);
        }
        if (memo.count(1000 * x + y)) {
            return memo[1000 * x + y];
        }
        memo[1000 * x + y] = min(_get(x - 2, y - 1), _get(x - 1, y - 2)) + 1;
        return memo[1000 * x + y];
    }
public:
    int minKnightMoves(int x, int y) {
        // x, y symmetric, so assume x >= y
        // 0, 0
        memo[1000 * 0 + 0] = 0;
        // 1, 0
        memo[1000 * 1 + 0] = 3;
        // 1, 1
        memo[1000 * 1 + 1] = 2;
        // 2, 0
        memo[1000 * 2 + 0] = 2;
        return _get(x, y);
    }
};
