#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    // Default constructor
    Node();
    // Single argument constructor
    explicit Node(T data);
    // Two argument constructor
    Node(T data, Node<T> *next);
    // Destructor
    ~Node();

    // Getters and setters
    T getData();
    void setData(T data);

    Node<T> *getNext();
    void setNext(Node<T> *next);



private:
    T data_;
    Node<T> *next_;
};

template<typename T>
Node<T>::Node(): data_(T()), next_(nullptr) {
    cout << "Default Constructor. Data = " << data_ << endl;
}

template<typename T>
Node<T>::Node(T data) : data_(data), next_(nullptr){
    cout << "Single argument constructor. Data = " << data_ << endl;
}

template<typename T>
Node<T>::Node(T data, Node<T> *next) : data_(data), next_(next){
    cout << "Double argument constructor. Data = " << data_ << ", Next(address): " << next_ << endl;

}

template<typename T>
Node<T>::~Node() {
    cout << "Deconstructed" << endl;
}

template<typename T>
T Node<T>::getData() {
    return data_;
}

template<typename T>
void Node<T>::setData(T data) {
    data_ = data;
}

template<typename T>
Node<T> *Node<T>::getNext() {
    return next_;
}

template<typename T>
void Node<T>::setNext(Node<T> *next) {
    next_ = next;
}

template<typename T>
class LinkedList
{
public:
    // Default constructor
    LinkedList();
    // Copy constructor
    LinkedList(const LinkedList<T> &other);
    // Destructor
    ~LinkedList();

    // Operators

    // Copy assignment
    LinkedList<T> & operator = (const LinkedList<T> &other);
    // Subscript operator
    T operator [](int index);
    // ostream operator
    friend ostream & operator <<(ostream &os, const LinkedList<T> &list);

    // Methods like push, pop, and clear
    // **** ADD THEM! *****

    void pushHead(T data){
        //if(tail_ == NULL)
        setHead(data);
        cout << "Data set: " << getHead() << endl;
    }


    // Getters and setters
    // **** ADD THEM ****

    T getHead(){
        return head_->getData();
    }

    T getTail(){
        return tail_->getData();
    }

    void setHead(T data){
        head_->setData(data);
    }

    void setTail(T data){
        tail_->setData();
    }
private:
    Node<T> *head_;
    Node<T> *tail_;
    int size;
};

template<typename T>
LinkedList<T>::LinkedList() : head_(new Node<T>()), tail_(new Node<T>()), size(0) {
    cout <<"LinkedList created" << endl;
}

/*template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) {

}*/

template<typename T>
LinkedList<T>::~LinkedList() {
    cout << "LinkedList deconstructed :D" << endl;
}

/*template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other) {
    return <#initializer#>;
}

template<typename T>
T LinkedList<T>::operator[](int index) {
    return nullptr;
}

template<typename T>
ostream &operator<<(ostream &os, const LinkedList<T> &list) {
    return <#initializer#>;
}
*/

int main() {
    /*auto currentNode1 = new Node<int>(110);
    cout << currentNode1 << endl;
    auto currentNode2 = new Node<int>(111, currentNode1);
    delete currentNode1;
    delete currentNode2;*/

    auto linkedList1 = new LinkedList<int>();
    linkedList1->pushHead(10);

    delete linkedList1;
    //LinkedList<double> doubleList;
    return 0;
}
