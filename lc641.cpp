#include <stack>
#include <vector>
#include <deque>
using namespace std;

class MyCircularDeque {
public:
    int front = 0 , rear = 0 , capacity = 0;
    vector<int> q;
    MyCircularDeque(int k) {
        capacity = k + 1;
        q = vector<int>( k + 1 , 0 );
    }
    
    bool insertFront(int value) {
        if( isFull() )
            return false;
        front--;
        front += capacity;
        front %= capacity;
        q[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if( isFull() )
            return false;
        q[rear] = value;
        rear++;
        rear %= capacity;
        return true;
    }
    
    bool deleteFront() {
        if( isEmpty() )
            return false;
        front++;
        front %= capacity;
        return true;
    }
    
    bool deleteLast() {
        if( isEmpty() )
            return false;
        rear--;
        rear += capacity;
        rear %= capacity;
        return true;
    }
    
    int getFront() {
        if( isEmpty() )
            return -1;
        return q[front];
    }
    
    int getRear() {
        if( isEmpty() )
            return -1;
        return q[( rear - 1 + capacity ) % capacity];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return ( rear + 1 ) % capacity == front;
    }
};