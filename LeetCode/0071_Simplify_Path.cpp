class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dirs;
        stringstream ss(path);
        string dir;
        while(getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") {
                continue;
            }
            if (dir == "..") {
                //careful here
                if (dirs.size() > 0) {
                    dirs.pop();
                }
            } else {
                dirs.push('/' + dir);
            }            
        }
        string res = "";
        while (dirs.size() > 0) {
            res = dirs.top() + res;
            dirs.pop();
        }
        if (res == "") {
            return "/";
        } else {
            return res;
        }
    }
};
