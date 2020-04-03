const int STATE_READ_INTO_NEW_LINE = 0;
const int STATE_MATCH_BLOCK_END = 1;
const int STATE_READ_INTO_LAST_LINE = 2;
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        int state = STATE_READ_INTO_NEW_LINE;
        vector<string> cleaned;
        for (int i = 0; i < source.size(); i++) {
            int start = 0;
            for (int j = 0; j < source[i].length(); j++) {
                if (state == STATE_MATCH_BLOCK_END) {
                    if (source[i][j] == '*' && j < source[i].length() - 1 && source[i][j+1] == '/') {
                        j++;
                        if (j < source[i].length() - 1) {
                            state = STATE_READ_INTO_LAST_LINE;
                            start = j + 1;
                        } else {
                            state = STATE_READ_INTO_NEW_LINE;
                            break;
                        }
                    }
                } else { // STATE_READ_INTO_NEW_LINE  STATE_READ_INTO_LAST_LINE
                    if (source[i][j] == '/' && j < source[i].length() - 1) {
                        if (source[i][j+1] == '/') {
                            string line = source[i].substr(start, j - start);
                            if (line.length() > 0) {
                                if (state == STATE_READ_INTO_NEW_LINE || cleaned.size() == 0) {
                                    if (cleaned.size() > 0 && cleaned[cleaned.size() - 1].length() == 0) {
                                        cleaned.pop_back();
                                    }
                                    cleaned.push_back(line);
                                } else {
                                    cleaned[cleaned.size() - 1] += line;
                                }
                            }
                            state = STATE_READ_INTO_NEW_LINE;
                            break;
                        } else if (source[i][j+1] == '*') {
                            string line = source[i].substr(start, j - start);
                            
                            //if (line.length() > 0) {
                                if (state == STATE_READ_INTO_NEW_LINE || cleaned.size() == 0) {
                                    if (cleaned.size() > 0 && cleaned[cleaned.size() - 1].length() == 0) {
                                        cleaned.pop_back();
                                    }
                                    cleaned.push_back(line);
                                } else {
                                    cleaned[cleaned.size() - 1] += line;
                                }
                            //}
                            state = STATE_MATCH_BLOCK_END;
                            j++;
                            continue;
                        }
                    }
                    string line = source[i].substr(start);
                    if (j == source[i].length()-1) {
                        if (line.length() > 0) {
                            if (state == STATE_READ_INTO_NEW_LINE || cleaned.size() == 0) {
                                if (cleaned.size() > 0 && cleaned[cleaned.size() - 1].length() == 0) {
                                    cleaned.pop_back();
                                }
                                cleaned.push_back(line);
                            } else {
                                cleaned[cleaned.size() - 1] += line;
                            }
                        }
                        state = STATE_READ_INTO_NEW_LINE;
                    }
                }
            }
        }
        return cleaned;
    }
};
