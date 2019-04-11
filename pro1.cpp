#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <utility>

using namespace std;


template<class T>
class dynamicQueue{
  public:
    dynamicQueue<T>();
    bool empty();
    size_t size();
    T front();
    void pop();
    void push(T param);
    void printQueue();


  private:
    vector<T> _v;
    std::size_t _size;
    std::size_t _front;



};

//Constructor
  template<class T>
  dynamicQueue<T>::dynamicQueue(){
    _v.resize(8);
    _size = 0;
    _front = 0;
  }

//EMPTY
  template<class T>
  bool dynamicQueue<T>::empty(){
    if(_size == 0){
      return true;
    }
      return false;
  }

//SIZE
  template<class T>
  std::size_t dynamicQueue<T>::size(){
    return(_size);
  }

//FRONT
  template<class T>
  T dynamicQueue<T>::front(){
    if(_size == 0){
      cout << "Empty Queue" << endl;
      return T();
    }
    else{
      return _v.at(_front);
    }
  }

//POP
  template<class T>
  void dynamicQueue<T>::pop(){
    _front++;
    _size--;
  }

//PUSH
  template<class T>
  void dynamicQueue<T>::push(T param){
    if(_size == 0){
      _v.at(0) = param;
      _size++;
      _front = 0;
    }

    //front = 0; and vector isn't full
    else if(_size < _v.size()){
      _v.at((_front+_size)%_v.size()) = param;
      _size++;
    }

    //front = 0; and vector is full
    else if(_front == 0 && _size >= _v.size()){
      _v.resize(_size*2);
      _v.at((_front+_size)%_v.size()) = param;
      _size++;
    }

    else if(_front != 0){
      cout<<"hit. Placing at: " << _size%_v.size()<<endl;
      _v.at(_size%_v.size()) = param;
      _size++;
    }
    /*    else if(_front != 0 && _size >= _v.size()){
          cout<<"hit. Placing at: " << _size%_v.size()<<endl;
          _v.at(_size%_v.size()) = param;
          _size++;
        }
        */

  }
template<class T>
  void dynamicQueue<T>::printQueue(){
    cout<< "size: " << _size << endl;
    for(size_t i = 0; i < _size; ++i){
      cout << i%_v.size() << ":" << _v.at((_front+i)%_v.size()) << endl;
    }
  }




//Main
int main() {
  dynamicQueue<int> myQueue;
  myQueue.push(1);
  myQueue.push(2);
  myQueue.push(3);
  myQueue.push(4);
  myQueue.push(5);
  myQueue.push(6);
  myQueue.push(7);

  //myQueue.printQueue();
  cout<<""<<endl;

  myQueue.pop();
  myQueue.pop();
  //  myQueue.printQueue();

      cout<<""<<endl;
      cout<<"Pushing"<<endl;

    myQueue.push(100);
    myQueue.push(999);
    //myQueue.push(999);

    myQueue.printQueue();
/*
  cout<< myQueue.front() << endl;
  myQueue.pop();
  cout<< myQueue.front() << endl;
  myQueue.pop();
  cout<< myQueue.front() << endl;
  myQueue.pop();
  cout<< myQueue.front() << endl;
  myQueue.pop();
  cout<< myQueue.front() << endl;
  myQueue.pop();
  cout<< myQueue.front() << endl;
  myQueue.pop();
  cout<< myQueue.front() << endl;
  myQueue.pop();
  cout<< myQueue.front() << endl;
  myQueue.pop();
  cout<< myQueue.front() << endl;
  myQueue.pop();
  */


  return 0;
}
