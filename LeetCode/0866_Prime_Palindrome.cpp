class Solution {
public:
    int primePalindrome(int N) {
        int cur = 1;
        
        int even = 1;
        int odd = 1;
        while (cur < N || !is_prime(cur)) {
            int even_palindrome = build_even(even);
            int odd_palindrome = build_odd(odd);
            cur = min(even_palindrome, odd_palindrome);
            if (cur == even_palindrome) {
                even ++;
            } else {
                odd ++;
            }
        }
        return cur;
    }
    
    int is_prime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    int build_even(int n) {
        string l = to_string(n);
        string r = l;
        reverse(r.begin(), r.end());
        return stoi(l + r);
    }
    
    int build_odd(int n) {
        string l = to_string(n);
        string r = l.substr(0, l.length() - 1);
        reverse(r.begin(), r.end());
        return stoi(l + r);
    }
};
