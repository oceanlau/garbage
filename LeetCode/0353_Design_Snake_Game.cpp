class SnakeGame {
private:
    deque<pair<int, int>> _body;
    unordered_set<string> _body_set;
    vector<vector<int>> _food;
    int _score = 0;
    int _food_i = 0;
    int _w;
    int _h;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        _w = width;
        _h = height;
        _food = food;
        _body.emplace_back(0, 0);
        _body_set.insert("0_0");
        if (_food_i < _food.size() && _food[_food_i][0] == 0 && _food[_food_i][1] == 0) {
            _score ++;
            _food_i ++;
        }
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int, int> head = _body.back();
        switch (direction[0]) {
            case 'U':
                head.first --;
                break;
            case 'L':
                head.second --;
                break;
            case 'R':
                head.second ++;
                break;
            case 'D':
                head.first ++;
                break;
            default:
                return -1;
        }
        string head_str = to_string(head.first) + "_" + to_string(head.second);
        if (_food_i < _food.size() && head.first == _food[_food_i][0] && head.second == _food[_food_i][1]) {
            _score ++;
            _food_i ++;
        } else {
            _body_set.erase(to_string(_body.front().first) + "_" + to_string(_body.front().second));
            _body.pop_front();
            if (head.first < 0 || head.first >= _h || head.second < 0 || head.second >= _w
                || _body_set.count(head_str)) {
                return -1;
            }
        }
        _body.emplace_back(head.first, head.second);
        _body_set.insert(head_str);
        return _score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
