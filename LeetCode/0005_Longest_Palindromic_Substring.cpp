// Solution 1: intuitive
class Solution {
public:
    string longestPalindrome(string s) {
        _target_str = s;
        _target_length = s.length();
        int pos = 0;
        while (pos < _target_length) {
            _find_longest_palindrome(pos - 1, pos);
            _find_longest_palindrome(pos, pos);
            pos++;
        }
        return _target_str.substr(_current_max_left, _current_max_len);
    }

private:
    string _target_str;
    int _target_length;
    int _current_max_len = 0;
    int _current_max_left = 0;

    void _find_longest_palindrome (int left, int right) {
        if (left < 0 || right >= _target_length) {
            return;
        }
        if (_target_str[left] == _target_str[right]) {
            if (_current_max_len < right - left + 1) {
                _current_max_len = right - left + 1;
                _current_max_left = left;
            }
            _find_longest_palindrome(left - 1, right + 1);
        }
    }
};

//Solution 2: Skip Redundant Job
class Solution {
public:
    string longestPalindrome(string s) {
        _target_str = s;
        _target_length = s.length();
        int pos = 0;
        while (pos < _target_length
               //Skip unneccesary jobs. (Except when _current_max_len was never set)
               && (_current_max_len == 0 
                   || _target_length - (pos + 1) > _current_max_len / 2
                  )
              ) {
            //Skip duplicated characters.
            //Also avoid special treatment to odd- and even-length palindrome cases.
            int left = pos;
            int right = pos;
            while (_target_str[right] == _target_str[right + 1]) {
                right = right + 1;
            }
            pos = right + 1;

            _find_longest_palindrome(left, right);
        }
        return _target_str.substr(_current_max_left, _current_max_len);
    }

private:
    string _target_str;
    int _target_length;
    int _current_max_len = 0;
    int _current_max_left = 0;

    void _find_longest_palindrome (int left, int right) {
        if (left < 0 || right >= _target_length) {
            return;
        }
        if (_target_str[left] == _target_str[right]) {
            if (_current_max_len < right - left + 1) {
                _current_max_len = right - left + 1;
                _current_max_left = left;
            }
            _find_longest_palindrome(left - 1, right + 1);
        }
    }
};

