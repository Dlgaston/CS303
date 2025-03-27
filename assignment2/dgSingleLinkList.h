

#ifndef DGSINGLELINKLIST_H
#define DGSINGLELINKLIST_H

#include  <iostream>

using namespace std;

template<typename T>
class dgSingleLinkList {
 private:
   struct Node {
     Node *next;
     T item;
     Node(const T& item, Node* next = nullptr):item(item), next(next) {}
     };
     Node *head;
     Node *tail;
     size_t num_items;
     public:
       dgSingleLinkList() : head(nullptr), tail(nullptr), num_items(0) {}
       ~dgSingleLinkList() {
         while (!isEmpty()) {
           pop_front();
         }
       }
       bool isEmpty() const {
         return num_items == 0;
       }
  // Empties the list.
  void empty() {
         while (!isEmpty()) {
           pop_front();
         }
       }
  // Removes head element and resets new head.
       void pop_front() {
         if(!head) return;
         Node *p = head;
         head = head->next;
         delete p;
         num_items--;
       }
  // Removes back element and resets tail.
       void pop_back() {
         if(!head) return;
         if(head==tail) {
           delete head;
           head = tail = nullptr;
           }
           else {
             Node *p = head;
             while(p->next != tail) {
               p = p->next;
             }
             delete tail;
             tail = p;
             tail->next = nullptr;
           }
           num_items--;
       }
  // Adds new element to front - assigns as head.
  void push_front(const T& item) {
         // If there is no head element, assigns tail to head
         if (!head) {
           head = new Node(item, nullptr);
           tail = head;
           return;
         }
         head = new Node(item, head);
         if (!tail) {
           tail = head;
         }
         num_items++;
       }
  // adds new element to back, assings as tail.
  void push_back(const T& item) {
         Node* new_tail = new Node(item, nullptr);
         // if there is no head element, assigns tail and head to new element
         if (!head) {

           head = new_tail;
           tail = new_tail;
         } else {
           tail->next = new_tail;
           tail = new_tail;
         }
         num_items++;
       }
  // Inserts element at back if index is out of bounds, inserts as head if indexs is 0, else loops through
  // and stops at element before index, inserting element after and reassigning pointers.
       void insert(size_t index, const T& item) {
         if(index == 0) {push_front(item); return;}
         if(index > num_items) {
           push_back(item);
           return;
         }
         Node *cur = head;
         for(int i = 1; i < index; i++) {
           cur = cur->next;
         }
         cur->next = new Node(item, cur->next);
         num_items++;
       }
// Removes element from index and returns true if 0 if fail or 1 if success.
  // Removes the element and reassigns the pointers.
       bool remove(size_t index) {
         if(index > num_items-1) {
           return 0;
         }
         if(index == num_items-1) {
           pop_back();
           return 1;
         }
         if(index == 0){
           pop_front();
           return 1;
           }
           Node *cur = head;
           for(int i = 1; i < index; i++) {
             cur = cur->next;
           }
           Node *temp = cur->next;
           cur->next = temp->next;
           if(!cur->next){
             tail = cur;
             }
           delete temp;
           num_items--;
           return 1;
       }
       T& front() const {
         if(!head){
          throw out_of_range("Empty list");
           }
           return head->item;
       }

       T& back() const {
         if(!head){
           throw out_of_range("Empty list");
           }
             return tail->item;
       }
       size_t find(const T& item) {

         if(!head){
           return -1;
         }
         Node *cur = head;
         size_t index = 0;
         while(cur){
           if(cur->item == item){
             return index;
             }
             cur = cur->next;
             index++;
             }
             return ++index;
           }
  size_t size() const{
         return num_items;
       }
  // Prints the list of elements.
  void print() {
         if(!head) {
           cout<<"Empty list"<<endl;
         }
         Node *cur = head;
         cout<<"[";
         while(cur) {
           cout<<cur->item<<",";
           cur = cur->next;
         }
         cout<<"]"<<endl;
       }
       };



#endif //DGSINGLELINKLIST_H
