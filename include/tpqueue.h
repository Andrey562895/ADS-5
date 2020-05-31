#include <cassert>
#include <list>
using namespace std;
template<typename T>

class TPQueue : private list<T>
{
  // Сюда помещается описание структуры "Очередь с приоритетами"
  TPQueue() {};         
    ~TPQueue() {};         
    void push(const T &); 
    T pop();              
    T get() const;        
    bool isEmpty() const; 
};

template<typename T>
void TPQueue<T>::push(const T & item) {
       if (this->empty()) {
        this->push_back(item);
        return;
    }
       for (auto iter = this->begin(); iter != this->end(); iter++) {
        if (iter->prior < item.prior) {
            this->insert(iter, item);
            return;
        }
    }
    this->push_back(item);
}

template<typename T>
T TPQueue<T>::pop() {
    T elem = this->front();
    this->pop_front();
    return elem;
}

template<typename T>
T TPQueue<T>::get() const {
    return this->front();
}

template<typename T>
bool TPQueue<T>::isEmpty() const {
    return this->empty();
}

struct SYM
{
	char ch;
	int  prior;
};
