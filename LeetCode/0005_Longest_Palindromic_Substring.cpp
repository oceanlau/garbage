class Solution {
private:
    // starting index, len
    pair<int, int> expand(string& s, int i, int j, int len) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            len += 2;
            i --;
            j ++;
        }
        return make_pair(i + 1, len);
    }
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        int longest = 1;
        string longest_str (1, s[0]);
        for (int i = 0; i < s.length(); i ++) {
            pair<int, int> result = expand(s, i - 1, i + 1, 1);
            pair<int, int> result2 = expand(s, i, i + 1, 0);
            if (result2.second > result.second) {
                result = result2;
            }
            if (result.second > longest) {
                longest = result.second;
                longest_str = s.substr(result.first, result.second);
            }
        }
        return longest_str;
    }
};

class Solution {
private:
    int expand(string& s, int i, int j, string& longests) {
        int len = 0;
        if (i == j) {
            len = 1;
            i --;
            j ++;
        }
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            i --;
            j ++;
            len += 2;
        }
        if (i + 1 < s.length()) {
            longests = s.substr(i + 1, len);
        } else {
            longests = "";
        }
        return len;
    }
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        int longest = 0;
        string longests = "";
        for (int i = 0; i < s.length() - longest / 2; i++) {
            string tmp_longest_str = "";
            int tmp_len = 0;
            tmp_len = expand(s, i, i, tmp_longest_str);
            if (tmp_len > longest) {
                longest = tmp_len;
                longests = tmp_longest_str;
            }
            tmp_len = expand(s, i, i + 1, tmp_longest_str);
            if (tmp_len > longest) {
                longest = tmp_len;
                longests = tmp_longest_str;
            }
        }
        return longests;
    }
};

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

