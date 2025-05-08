#include <bits/stdc++.h>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

class Demo{
    
    public:
      int counter=0;
        Demo(){}
        void spawnThread(){
            thread t1(&Demo::Helloprint, this,ref(counter));
            thread t2(&Demo::Hiprint, this,ref(counter));
            t1.join();
            t2.join();
        }
        void Helloprint( int &counter){
            for(int i=0; i<10000; i++){
                lock_guard<mutex> lock(mtx); // Lock the mutex to protect the shared resource
                counter++;
            }
        }
        void Hiprint( int &counter){
            for(int i=0; i<10000; i++){
                lock_guard<mutex> lock(mtx); 
                counter++;
            }
        }


};
int main(){
    Demo* d=new Demo();
    d->spawnThread();
    cout<<d->counter<<endl;
    delete d;
    return 0;
}