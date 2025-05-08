#include <bits/stdc++.h>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx; 


//! HERE IN THIS EXAMPLE. SINCE I AM INTIALISING THE THREAD FROMT THE MAIN METHOD. I WANT TO INITALISE THE THREAD OF THE FUNCTION OF THE D1 AND D2 OBJECTS OF THE CLASS. SO I AM PASSING THE OBJECTS OF THE CLASS TO THE THREAD FUNCTION LIKE &D1 AND &D2. SO THAT THE THREAD CAN WORK ON THE OBJECTS OF THE CLASS.. THIS IS SAME AS THE "this pointer" inside the class.

class Demo {
    int x;
public:
    Demo(int val) : x(val) {}
    void print() { 
        lock_guard<mutex> lock(mtx);  // Lock the mutex for this thread. resource gets released when lock goes out of scope.
        cout << "Thread ID: " << this_thread::get_id() << endl;
        cout << "x = " << x << endl;
    }
};


int main(){
    Demo d1(5), d2(10);

    thread t1(&Demo::print, &d1);  // works on d1
    cout<<endl;
    thread t2(&Demo::print, &d2);  // works on d2

    t1.join();
    t2.join();
    return 0;

}