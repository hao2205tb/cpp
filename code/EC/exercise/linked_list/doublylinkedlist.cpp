#include <iostream>
using namespace std;

template <typename T>
class LinkedList{
private:
    struct Node{
        T data;
        Node* prev;
        Node* next;
        Node(T data, Node* prev, Node* next): data(data), prev(prev), next(next){}
    };
    Node* head;
    Node* tail;
    size_t size;

public:
    // Constructors
    LinkedList(): head(nullptr), tail(nullptr), size(0){}

    // add a new element at the beginning of the list.
    void push_front(T value){
        Node* ptr = new Node(value, nullptr, head);
        if (head == nullptr) {
            head = tail = ptr;
        }
        else{
            head->prev = ptr;
            head = ptr;
        }
        size++;
        
    }

    // add a new element at the end of the list.
    void push_back(T value){
        Node* ptr = new Node(value, tail, nullptr);
        if (head == nullptr) {
            head = tail = ptr;
        }
        else{
            tail->next = ptr;
            tail = ptr;
        }
        size++; 
        
    }

    // Insertion in between two nodes in Doubly Linked List
    void insert(size_t pos, T value){
        if (pos>size-1) throw std::out_of_range("Index out of bounds");
        else if (pos==0) push_front(value);
        else if (pos==size) push_back(value);
        else{
            Node* nextptr = find(pos);
            Node* prevptr = nextptr->prev;
            Node* newptr = new Node(value, prevptr, nextptr);
            prevptr->next = newptr;
            nextptr->prev = newptr;
            size++;
        }
    }

    Node* find(size_t pos){
        Node* ptr = head;
        for (size_t i=0; i<pos; i++){
            ptr = ptr->next;
        }
        return ptr;
    }

    void show(){
        Node* ptr = head;
        while (ptr!=nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }

    T pop_front(){
        Node* ptr = head;
        head = head->next;
        T value = ptr->data;
        delete(ptr);
        return value;
    }

    ~LinkedList(){
        Node* ptr = head;
        while (ptr!=nullptr)
        {
            delete(ptr);
            ptr = ptr->next;
        }
        cout << "call destructor\n";
    }
};

int main(){
    LinkedList<int> ls;
    ls.push_front(2);
    ls.push_front(3);
    ls.push_back(1);
    ls.insert(1, 5);
    ls.show(); 
    cout << endl << ls.pop_front() << endl;
    ls.show();

}