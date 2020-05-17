class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n, 1);
        list<int> numbers {1};
        for (int i = 1; i < n; i++) {
            factorial[i] = i * factorial[i-1];
            numbers.push_back(i + 1);
        }
        string res = "";
        //careful!
        k --;
        while (n > 0) {
            auto it = numbers.begin();
            advance(it, k / (factorial[n - 1]));
            res += to_string(*it);
            numbers.erase(it);
            if (k >= factorial[n - 1]) {
                k %= factorial[n - 1];
            }
            n --;
        }
        return res;
    }
};

// 0ms, poor mem though
class Solution {
private:
    vector<int> _possibilities {0, 1};
    int _getPossibilities(int n){
        if (_possibilities.size() < n + 1) {
            _possibilities.push_back(n * _getPossibilities(n - 1));
        }
        return _possibilities[n];
    }
    string _getStr(int k, vector<int>& n_vector) {
        
        //cout << "vec size: " << n_vector.size() << endl;
        if (n_vector.size() == 1) {
            return to_string(n_vector[0]);
        }
        int n = n_vector.size();
        //cout << "_getPossibilities n-1: " << _getPossibilities(n-1) << endl;
        int nth_pos;
        int next_k;
        int rest = k % _getPossibilities(n-1);
        if (rest == 0) {
            next_k = _getPossibilities(n-1);
            nth_pos = k / _getPossibilities(n-1) - 1;
            //cout << "nth_pos1: " << nth_pos << endl;
            //cout << "next_k1: " << next_k << endl;
        } else {
            next_k = rest;
            nth_pos = k / _getPossibilities(n-1);
            //cout << "nth_pos2: " << nth_pos << endl;
            //cout << "next_k2: " << next_k << endl;
        }
        string nth_digit = to_string(n_vector[nth_pos]);
        //cout << nth_pos << endl;
        n_vector.erase(n_vector.begin() + nth_pos);
        return nth_digit + _getStr(next_k, n_vector);
    }
public:
    string getPermutation(int n, int k) {
        vector<int> n_vector(n);
        iota(n_vector.begin(), n_vector.end(), 1);
        return _getStr(k, n_vector);
    }
};
