class MyCircularQueue {
private:
    vector<int> storage;
    int capacity = 0;
    int head = 0;
    int tail = 0;
    bool is_empty = true;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        storage.resize(k, -1);
        capacity = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        storage[tail++] = value;
        is_empty = false;
        if (tail == capacity) {
            tail = 0;
        }
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        int value = storage[head++];
        if (head == capacity) {
            head = 0;
        }
        if (head == tail) {
            is_empty = true;
        }
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return storage[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        if (tail - 1 == -1) {
            return storage[capacity - 1];
        }
        return storage[tail - 1];
        
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return is_empty;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return head == tail && !is_empty;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
