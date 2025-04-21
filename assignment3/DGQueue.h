

#ifndef DGQUEUE_H
#define DGQUEUE_H

#include <iostream>

using namespace std;

template<class T>
class DGQueue {
    struct Node {
        Node *next;
        Node *prev;
        T item;
        Node(const T& item, Node* next = nullptr,Node* prev =nullptr):item(item), next(next), prev(prev) {}
    };
    size_t num_items;
    Node *front;
    Node *rear;
    public:
    ~DGQueue() {
        empty();
    };
    DGQueue() : front(nullptr), rear(nullptr), num_items(0) {}
    T peekFront() const {
        return front->item;
    }
    T peekRear() const {
        return rear->item;
    }
    // Pushes to end of queue/
    void push(const T& item) {
        if (!front) {
            front = new Node(item, nullptr,nullptr);
            rear = front;
        }
        else {
            rear->next = new Node(item, nullptr, rear);
            rear = rear->next;
        }
        num_items++;
    }
    // Removes first element
    T pop() {
        if (!front) {
            throw runtime_error("Queue is empty");
        }

        Node* temp = front;
        T item = temp->item;
        front = front->next;

        if (front) {
            front->prev = nullptr;
        } else {
            rear = nullptr;
        }

        delete temp;
        num_items--;
        return item;
    }
    // Removes all elements from queue.
    void empty() {
        while (!isEmpty()) {
            pop();
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty";
        } else {
            while (!isEmpty()) {
                cout<<to_string(peekFront())<<" ";
                pop();
            }
        }
        cout << endl;
    }
    // Displays the relationship between nodes to help keep track of order.
    void displayRelations() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            while (temp) {
                cout << "Item: " << temp->item
                     << " Prev: " << (temp->prev ? to_string(temp->prev->item) : "null")
                     << " Next: " << (temp->next ? to_string(temp->next->item) : "null")
                     << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    bool isEmpty() const {
        return num_items == 0;
    }
    // Moves front item to end of queue.
    void moveFrontToRear() {
        T item = pop();
        push(item);
    }

    // This insertion sort starts at the 2nd item in the queue.
    //  It will check the previous elements, if it sees that an prior element is greater than the current one
    // It will swap the data inside that node.
    // Continues until it reaches a null prior element or the curr is greater than prev.
    void insertionSort() {
        if (!front || !front->next) return;

        Node* curr = front->next;

        while (curr) {
            T key = curr->item;
            Node* scan = curr->prev;
            while (scan && key < scan->item) {
                scan->next->item = scan->item;
                scan = scan->prev;
            }
            if (scan)
                scan->next->item = key;
            else
                front->item = key;

            curr = curr->next;
        }
    }
};



#endif //DGQUEUE_H
