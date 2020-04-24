class ProductOfNumbers {
private:
    vector<int> prefixprods;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            prefixprods.clear();
        } else if (prefixprods.size() == 0){
            prefixprods = {num};
        } else {
            prefixprods.push_back(num * prefixprods.back());
        }
    }
    
    int getProduct(int k) {
        if (k > prefixprods.size()) {
            return 0;
        } else {
            int prod = prefixprods.back();
            if (prefixprods.size() - k  > 0) {
                prod /= prefixprods[prefixprods.size() - k - 1];
            }
            return prod;
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
