// Remember the usage of std::pair/std::list/std::unordered_map
// std::list
//     with std::pair
//     empty: is empty
//     insert: move or copy a new element 
//     emplace: construct a new element in place 
//     splice: move elements between lists (insert + delete)
// std::unordered_map
//     find() (return iterator) and iter->second return the value (works like [], but could be utilized to check existence) (if you want to check existence and use the value at the same time, use iterator would save you an extra search)
// time O(1), space O(n)
//
// Q: Is replace values faster or delete then construct new one?
class LRUCache {
private:
    int _capacity;
    // double linked list, easily move itself to the front, all required manipulations are O(1)
    // use a pair to record key, in order to delete it in _map
    list<pair<int, int>> _list;
    // use a pair iterator to quickly designate the element that need to be moved 
    unordered_map<int, list<pair<int, int>>::iterator> _map;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto iter = _map.find(key);
        if (iter == _map.end()) {
            return -1;
        }
        _list.splice( _list.begin(), _list, iter->second);
        return iter->second->second;
    }
    
    void put(int key, int value) {
        auto iter = _map.find(key);
        if (iter != _map.end()) {
            iter->second->second = value;
            _list.splice( _list.begin(), _list, iter->second);
            return;
        }
        if (_map.size() < _capacity) {
            _list.emplace_front(key, value);
        } else {
            auto list_iter = _list.end();
            list_iter --;
            _map.erase(list_iter->first);
            //replace pair values with new ones
            list_iter->first = key;
            list_iter->second = value;
            _list.splice( _list.begin(), _list, list_iter);
        }
        _map[key] = _list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Wrong answer, get a node should move the node to the front
// Should use double linked list, which can easily move itself to the front
// also, did not check whether a key was already present when putting.
struct Node {
    int value;
    int key;
    Node* next;
    Node (int key, int value) : key(key), value(value), next(NULL) {} 
};

class LRUCache {
private:
    Node* _head = NULL;
    Node* _tail = NULL;
    unordered_map<int, Node*> _map;
    int _capacity;
    int _current_space = 0;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        //_map.reserve(_capacity);
    }
    
    int get(int key) {
        if (_map.find(key) == _map.end()) {
            return -1;
        } else {
            return (_map[key])->value;
        }
    }
    
    void put(int key, int value) {
        if (_head == NULL) {
            // empty
            // capacity is positive, at least 1
            _head = new Node(key, value); // need to deleted when deconstructed
            _tail = _head;
            _tail->next = _head; // always form a loop, point to iteself now
            _map[key] = _head;
            _current_space ++;
        } else if (_current_space == _capacity) {
            //move to the oldest node
            _tail = _tail->next;
            
            _map.erase(_tail->key);
            
            _tail->key = key;
            _tail->value = value;
            _map[key] = _tail;
            _tail = _tail->next;
        } else { // _current_space < _capacity
            _tail->next = new Node(key, value);
            _tail = _tail->next;
            _tail->next = _head; // always form a loop
            _map[key] = _tail;
            _current_space ++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
