/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if (topRight[0] < bottomLeft[0] || topRight[1] < bottomLeft[1] || !sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }
        if (topRight == bottomLeft) {
            return 1;
        }
        vector<int> middle = {
            topRight[0] == bottomLeft[0] ?
                bottomLeft[0] : bottomLeft[0] + (topRight[0] - bottomLeft[0] ) / 2 + 1,
            topRight[1] == bottomLeft[1] ?
                bottomLeft[1] : bottomLeft[1] + (topRight[1] - bottomLeft[1] ) / 2 + 1,
        };
        // These -1 may trigger illegal coords
        return countShips(sea, topRight, middle) +
            countShips(sea, {middle[0] - 1, topRight[1]}, {bottomLeft[0], middle[1]}) +
            countShips(sea, {middle[0] - 1, middle[1] - 1}, bottomLeft) +
            countShips(sea, {topRight[0], middle[1] - 1}, {middle[0], bottomLeft[1]});
    }
};
