//45% 13%
class Solution {
private:
    vector<int> _expand(string s, int i, int l, int r) {
        vector<int> longest{i, l};//l is init len by coincidence
        for (int d = 0; d < s.length(); d++) {
            if (i - (l + d) < 0) {
                break;
            }
            if (i + (r + d) >= s.length()) {
                break;
            }
            if (s[i - (l + d)] != s[i + (r + d)]) {
                break;
            }
            longest[0] = i - (l + d);
            longest[1] = l + r + 2*d + 1;
        }
        return longest;
    }
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        vector<int> longest(2, 0);
        for (int i = 0; i < s.length(); i++) {
            vector<int> longest_odd = _expand(s, i, 1, 1);
            vector<int> longest_even = _expand(s, i, 0, 1);
            if (longest_odd[1] > longest_even[1]) {
                if (longest_odd[1] > longest[1]) {
                    longest = longest_odd;
                }
            } else if (longest_even[1] > longest[1]){
                longest = longest_even;
            }
        }
        return s.substr(longest[0], longest[1]);
    }
};

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

