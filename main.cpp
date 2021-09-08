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
    LinkedList(const LinkedList<T> &other);
    // Destructor
    ~LinkedList();

    // Operators

    // Copy assignment
    //LinkedList<T> & operator = (const LinkedList<T> &other);
    // Subscript operator
    //T operator [](int index);
    // ostream operator
    //friend ostream & operator <<(ostream &os, const LinkedList<T> &list);

    // Getters and setters
    T getHead(){
        return head_->getData();
    }

    T getTail(){
        return tail_->getData();
    }

    int getSize(){
        return size;
    }

    // Methods like push, pop, and clear
    // print, peekAt
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

    void peekAt(int index){
        int i = 0;
        if(index <= size-1) {
            auto current_ = new Node<T>();
            current_ = head_;
            while (index != i) {
                current_ = current_->getNext();
                i++;
            }
            cout << "Data at index " << index << " = " << current_->getData() << endl;
        }else{
            cout << "nothing to peek at index(" << index << ")" << endl;
        }
    }

    void pushAt(T data, int index){
        int i = 0;
        if(index==0){
            pushHead(data);
        }else {
            i++;
            if (index <= size - 1) {
                auto current_ = new Node<T>();
                current_ = head_;
                while (i < index) {
                    current_ = current_->getNext();
                    i++;
                }
                auto insert_ = new Node<T>();
                insert_->setNext(current_->getNext());
                insert_->setData(data);
                current_->setNext(insert_);
                size++;

            }else if(index == size){
                pushTail(data);
            }else{
                cout << ">>> Index-point does not exist. list is only " << size << endl;
            }
        }
    }

    T popAt(int index){
        T popData = T();

        int i = 0;
        if(index==0){
            popHead();
        }else {
            i++;
            if (index <= size - 1) {
                auto current_ = new Node<T>();
                current_ = head_;
                while (i < index) {
                    current_ = current_->getNext();
                    i++;
                }
                popData = current_->getNext()->getData();
                if(current_->getNext()->getNext() == nullptr){
                    popTail();
                }else{
                    auto temp_ = new Node<T>;
                    temp_->setNext(current_->getNext());
                    current_->setNext(current_->getNext()->getNext());
                    temp_->setNext(nullptr);
                }
                size--;
            }else if(index == size-1){
                popTail();
            }else{
                cout << ">>> Index-point does not exist. list is only " << size << endl;
            }
        }

        return popData;
    }

    void changeAt(T data, int index){
        head_->setData(data);
    }

    void clearList(){
        while(head_){
            popHead();
        }
        cout << "list cleared" << endl;
    }

    void setSize(int test){
        size = test;
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

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) : head_(nullptr), tail_(nullptr), size(0) {
    head_ = other.head_;
    size = other.size;



    if(head_){
        auto current1_ = head_;
        //auto current2_ = new Node<T>();
        while(current1_->getNext()){
            auto current2_ = current1_->getNext();
            if(head_==current1_){
                head_->setNext(current2_);
            }else{
                current1_->setNext(current2_);
            }
            current1_ = current1_->getNext();
        }
        tail_ = current1_;
    }
}

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

    LinkedList<int> linkedList1;

    //LinkedList<int>(linkedList1) linkedList2;



    //linkedList2 = linkedList1;

    cout << "# create list" << endl;
    linkedList1.pushTail(3);
    linkedList1.pushTail(4);
    linkedList1.pushTail(5);
    linkedList1.pushTail(6);
    linkedList1.pushTail(7);
    linkedList1.pushHead(2);
    linkedList1.pushHead(1);
    linkedList1.pushHead(0);
    cout << "listsize: " << linkedList1.getSize() << endl;
    linkedList1.printList();

// ----------------
    cout << "#######" << endl;
    auto linkedList2 =  new LinkedList<int>(linkedList1);
    linkedList1.printList();
    linkedList2->printList();
    cout << "#######" << endl;
    linkedList1.changeAt(69, 0);

    linkedList1.printList();
    linkedList2->printList();

    cout << "#######" << endl;







// ---------------
    cout << "# push at" << endl;
    linkedList1.pushAt(100, 3);
    cout << "listsize: " << linkedList1.getSize() << endl;
    linkedList1.printList();

    cout << "# pop at " << endl;
    linkedList1.popAt(5);
    cout << "listsize: " << linkedList1.getSize() << endl;
    linkedList1.printList();

    cout << "# pop head " << endl;
    linkedList1.popHead();
    cout << "listsize: " << linkedList1.getSize() << endl;
    linkedList1.printList();

    cout << "# pop tail " << endl;
    linkedList1.popTail();
    cout << "listsize: " << linkedList1.getSize() << endl;
    linkedList1.printList();

    cout << "# pop at (out of range) " << endl;
    linkedList1.popAt(20);
    cout << "listsize: " << linkedList1.getSize() << endl;
    linkedList1.printList();

    cout << "# peek at " << endl;
    linkedList1.peekAt(4);
    cout << "listsize: " << linkedList1.getSize() << endl;
    linkedList1.printList();

    cout << "# peek at (out of range)" << endl;
    linkedList1.peekAt(20);
    cout << "listsize: " << linkedList1.getSize() << endl;
    linkedList1.printList();

    cout << "# clear list" << endl;
    cout << "listsize: " << linkedList1.getSize() << endl;
    linkedList1.clearList();


    return 0;
}
