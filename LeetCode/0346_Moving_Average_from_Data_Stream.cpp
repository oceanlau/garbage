class MovingAverage {
private:
    int overwrite_pos = 0;
    vector<int> container;
    int container_size = 0;
    double avg = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        container_size = size;
    }
    
    double next(int val) {
        if (container_size == 0) {
            return 0;
        }
        double sum = container.size() * avg;
        if (container.size() < container_size) {
            container.push_back(val);
            overwrite_pos = container.size() - 1;
            avg = (sum + val) / container.size();
            return avg;
        } else if (++ overwrite_pos == container_size){
            overwrite_pos = 0;
        }
        
        avg = (sum + val - container[overwrite_pos]) / container.size();;
        container[overwrite_pos] = val;
        return avg;
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
