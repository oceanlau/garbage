class Solution {
private:
    vector<int> _getline(vector<string>& words, int& maxWidth, int start) {
        int i = start;
        int words_count = 0;
        int total_words_len = 0;
        while (start + words_count + 1 <= words.size() && total_words_len + words[i].length() + words_count + 1 - 1 <= maxWidth) {
            total_words_len += words[i++].length();
            words_count ++;
        }
        return vector<int> {start, words_count, total_words_len};
    }
    string _justify(vector<string>& words, int& maxWidth, vector<int>& line_info) {
        int space_count = maxWidth - line_info[2];
        // edge case
        if (line_info[1] == 1) {
            return _justify_lastline(words, maxWidth, line_info);
        }
        int evened_space_count = space_count / (line_info[1] - 1);
        int remained_space_count = space_count % (line_info[1] - 1);
        string res;
        for (int i = 0; i < line_info[1]; i++) {
            if (i == line_info[1] - 1) {
                res += words[line_info[0] + i];
            } else {
                if (i < remained_space_count) {
                    res += words[line_info[0] + i] + string(evened_space_count + 1, ' ');
                } else {
                    res += words[line_info[0] + i] + string(evened_space_count, ' ');
                }
            }
        }
        return res;
    }
    string _justify_lastline(vector<string>& words, int& maxWidth, vector<int>& line_info) {
        int remained_space_count = maxWidth - line_info[2] - (line_info[1] - 1);
        string res;
        for (int i = 0; i < line_info[1]; i++) {
            if (i == line_info[1] - 1) {
                res += words[line_info[0] + i] + string(remained_space_count, ' ');
            } else {
                res += words[line_info[0] + i] + " ";
            }
        }
        return res;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // index of words, words count, total words len of one line
        vector<int> line_info(3, 0);
        vector<string> result;
        while (true) {
            // start idx in words
            line_info = _getline(words, maxWidth, line_info[0] + line_info[1]);
            // check new start idx
            if (line_info[0] + line_info[1] == words.size()) {
                // last idx
                break;
            }
            result.push_back(_justify(words, maxWidth, line_info));
        };
        result.push_back(_justify_lastline(words, maxWidth, line_info));
        return result;
    }
};
