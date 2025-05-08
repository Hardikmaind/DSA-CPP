#include <iostream>
#include <thread>
using namespace std;



//! HERE IN THIS EXAPLE. THREAD IS BEING RUN FROM CLASS AND THREAD IS OF CLASS METHOD. SO 'this' IS USED TO REFER TO THE CURRENT OBJECT OF THE CLASS. IT MEANS I AM CALLING THE METHOD FROM THE PARTICULAR OBJECT OF THE CLASS.
class Demo {
public:
    void task() {
        cout << "Running task in thread" << endl;
    }

    void startThread() {
        thread t(&Demo::task, this);  // 'this' refers to the current object
        t.join();
    }
};

int main() {
    Demo d;
    d.startThread();  // Thread runs task() on the object 'd'

    return 0;
}
