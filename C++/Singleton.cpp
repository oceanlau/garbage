#include <iostream>

using namespace std;

class Singleton {
public:
    static Singleton& get_instance() {
        static Singleton instance;
        return instance;
    };
    Singleton(Singleton const&) = delete;
    // Why only delete non-copy-and-swap idiom
    Singleton& operator=(Singleton const&) = delete;
    void hi() {
        cout << "hi" << endl;
    };
private:
    Singleton() {};
};

int main() {
    Singleton& inst = Singleton::get_instance();
    inst.hi();
    return 0;
}
