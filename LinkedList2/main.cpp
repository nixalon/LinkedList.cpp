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
    cout << "Node deconstructed" << endl;
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
    //LinkedList(const LinkedList<T> &other);
    // Destructor
    ~LinkedList();

    // Operators

    // Copy assignment
    //LinkedList<T> & operator = (const LinkedList<T> &other);
    // Subscript operator
    //T operator [](int index);
    // ostream operator
    //friend ostream & operator <<(ostream &os, const LinkedList<T> &list);

    // Methods like push, pop, and clear
    // **** ADD THEM! *****

    void pushHead(T data){
        if(!head_){
            head_ = new Node<T>(data);
            tail_ = head_;
        }else{
            auto current_ = new Node<T>(data);
            current_->setNext(head_);
            head_ = current_;
        }
        size++;
        cout << "Data set: " << getHead() << ". Size: " << size << endl;
    }

    T popHead(){
        if(!head_){
            return T();
        }
        T headData = head_->getData();

        if(head_==tail_){
            tail_ = nullptr;
        }
        auto current_ = head_->getNext();
        delete head_;
        head_ = current_;
        size--;
        return headData;
    }

    void pushTail(T data){
        if(!tail_){
            tail_ = new Node<T>(data);
            head_ = tail_;
        }else{
            auto current_ = new Node<T>(data);
            tail_->setNext(current_);
            tail_ = current_;
        }
        size++;
        cout << "Tail set: " << getTail() << ". Size: " << size << endl;
    }

    T popTail(){
        if(!tail_){
            return T();
        }
        T tailData = tail_->getData();

        if(head_) {
            if(head_==tail_){
                return popHead();
            }
            auto current_ = head_;
            while(current_->getNext()->getNext()) {
                current_ = current_->getNext();
            }
            delete tail_;
            current_->setNext(nullptr);
            tail_ = current_;
            size--;
        }

        return tailData;
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
        size++;
    }

    void setTail(T data){
        tail_->setData();
    }

    int getSize(){
        return size;
    }

    void printList(){
        auto current_ = new Node<T>();
        cout << ": ";
        if(head_) {
            current_ = head_;
            cout << current_->getData() << " : ";
        }

        while (tail_) {
            current_ = current_->getNext();
            if(current_){
                cout << current_->getData() << " : ";
            }
            else{
                break;
            }
        }
        cout << endl;
    }

private:
    Node<T> *head_;
    Node<T> *tail_;
    int size;
};

template<typename T>
LinkedList<T>::LinkedList() : head_(nullptr), tail_(nullptr), size(0) {
    cout <<"LinkedList created" << endl;
}

/*template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) {
}*/

template<typename T>
LinkedList<T>::~LinkedList() {
    while(head_){
        cout << "node deleted with data: " << head_->getData() << endl;
        auto current_ = head_->getNext();
        delete head_;
        head_ = current_;
        size--;
    }
    tail_ = nullptr;
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

    //auto linkedList1 = new LinkedList<int>();
    LinkedList<int> linkedList1;

    linkedList1.pushHead(10);
    linkedList1.pushHead(12);
    cout << "listsize: " << linkedList1.getSize() << endl;


    cout << linkedList1.popHead() << endl;
    cout << "listsize: " << linkedList1.getSize() << endl;
    cout << linkedList1.popHead() << endl;
    cout << "listsize: " << linkedList1.getSize() << endl;


    linkedList1.pushTail(32);
    linkedList1.pushTail(64);

    cout << "Tail deleted with data : " << linkedList1.popTail() << endl;
    cout << "listsize: " << linkedList1.getSize() << endl;
    linkedList1.printList();

    return 0;
}