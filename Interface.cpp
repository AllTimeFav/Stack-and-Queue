#include <iostream>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int value) : data(value), next(NULL) {}
};

class stack{
    int *a ;
    int top;
    int capacity ;

    public :
    stack(int size){
        a = new int(size) ;
        top = -1;
        capacity = size ;
    }
    void push(int value){
        if(top==capacity-1){
            cout<<"stack is full";
        }
        top++;
        a[top] = value;
    }
    int pop(){
        if(top==-1){
            cout<<"stack is empty";
        }
        return a[top--];
    }
    int peek(){
        if (top == -1){
            cout<<"stack is empty";
            return -1 ;
        }
        return a[top];
    }
    bool isfull(){
       return (top == capacity-1) ? true : false ;
        // if(top == capacity-1){ return true; } else{ return false; }
    }
    bool isempty(){
        return (top == -1) ? true : false ;  
        // if(top == -1){ return true; } else{ return false; }
    }
};

// With linked list
//class node{
//    public:
//    int data ;
//    node *next ;
//    
//    node(int value){
//        data = value ;
//        next = nullptr;
//    }
//};

class stack_ll{
    node *top ;
    public :
    	stack_ll(){
    		top=NULL;
		}
    void push(int value){
        node *n = new node(value);
        n->next = top ;
        top = n ;
    }
    int pop(){
        if(top == NULL){ cout<<"stack is empty "; return -1; }
        node *temp = top;
        int data = temp->data;
        top = top->next;
        delete temp ;
        return data ;
    }
    int peek(){
        if(top == NULL){ cout<<"stack is empty "; return -1; }
        else{ return top->data ;}
    }
    int isempty(){
        return (top == NULL) ? true : false ;
    }
    int isfull(){ return false; }

};


class LinkedList_Queue {
    node* front;
    node* rear;
    int size;

public:
    LinkedList_Queue() : size(0), front(NULL), rear(NULL) {}

    void enqueue(int val) {
        node* new_node = new node(val);
        if (front == NULL || rear == NULL) {
            new_node->next = new_node;
            front = rear = new_node;

            size++;
            return;
        }
        rear->next = new_node;
        rear = new_node;
        rear->next = front;

        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow";
            return -1;
        }
        node* temp = front;
        int key = temp->data;

        if (front == rear) {
            delete temp;
            front = rear = NULL;
        } else {
            front = front->next;
            rear->next = front;
            delete temp;
        }

        size--;
        return key;
    }

    int getFront() {
        return front->data;
    }

    int getRear() {
        return rear->data;
    }

    bool isFull() {
        return false;
    }

    bool isEmpty() {
        return front == NULL;
    }

    int getSize() {
        return size;
    }

    void display() {
        node* curr = front;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != front);

        cout << endl;
        
    }

    void reverse() {
        stack s(size);

        while (!isEmpty()) {
            s.push(dequeue());
        }
        while (!s.isempty()) {
            enqueue(s.pop());
        }
    }
};

class Array_Queue {
    int front;
    int rear;
    int size;
    int* A;

public:
    Array_Queue(int n) : size(n), front(-1), rear(-1), A(new int[size]) {}

    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue overflow" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        A[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
            return 0;
        }
        int key = A[front];
        if (front >= rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        return key;
    }

    int getFront() {
        return A[front];
    }

    int getRear() {
        return A[rear];
    }

    int getsize() {
        return size;
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

       void reverse() {
        stack s(size);
        while (!isEmpty()) {
            s.push(dequeue());
        }

        while (!s.isempty()) {
            enqueue(s.pop());
        }
    }
};

int main() {
    int choice;
    
      stack s_arr(5);
      stack_ll s_ll;
//      Stack sll(10);
       
    LinkedList_Queue llq;
    Array_Queue aq(5);

    do {
        cout << "Choose an option:" << endl;
        cout << "1. Stack" << endl;
        cout << "2. Linked List Queue" << endl;
        cout << "3. Array Queue" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;

        switch (choice) {
        	
            case 1:
//            	system("cls");
//                  sll.push(7);
//                 cout << "Popped: " << sll.pop() << endl;
//                 cout << "Peek: " << sll.peek() << endl;
//                 break;
 

    do {
        cout << "Choose an option:" << endl;
        cout << "1. Push to stack with array" << endl;
        cout << "2. Pop from stack with array" << endl;
        cout << "3. Is stack with array full?" << endl;
        cout << "4. Is stack with array empty?" << endl;
        cout << "5. Push to stack with linked list" << endl;
        cout << "6. Pop from stack with linked list" << endl;
        cout << "7. Is stack with linked list empty?" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                int value_arr;
                cout << "Enter value to push to stack with array: ";
                cin >> value_arr;
                s_arr.push(value_arr);
                break;

            case 2:
                cout << "Popped from stack with array: " << s_arr.pop() << endl;
                break;

            case 3:
                cout << "Is stack with array full? " << (s_arr.isfull() ? "Yes" : "No") << endl;
                break;

            case 4:
                cout << "Is stack with array empty? " << (s_arr.isempty() ? "Yes" : "No") << endl;
                break;

            case 5:
                int value_ll;
                cout << "Enter value to push to stack with linked list: ";
                cin >> value_ll;
                s_ll.push(value_ll);
                break;

            case 6:
                cout << "Popped from stack with linked list: " << s_ll.pop() << endl;
                break;

            case 7:
                cout << "Is stack with linked list empty? " << (s_ll.isempty() ? "Yes" : "No") << endl;
                break;

            case 0:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);


            case 2:
                do {
                	
                    cout << "Choose an option:" << endl;
                    cout << "1. Enqueue" << endl;
                    cout << "2. Dequeue" << endl;
                    cout << "3. Display" << endl;
                    cout << "4. Reverse" << endl;
                    cout << "0. Exit" << endl;

                    cin >> choice;

                    switch (choice) {
                        case 1:
                            int val;
                            cout << "Enter value to enqueue: ";
                            cin >> val;
                            llq.enqueue(val);
                            break;

                        case 2:
                            cout << "Dequeued value: " << llq.dequeue() << endl;
                            break;

                        case 3:
                            cout << "Queue Contents: ";
                            llq.display();
                            break;

                        case 4:
                            llq.reverse();
                            cout << "Queue Reversed" << endl;
                            break;

                        case 0:
                            cout << "Exiting linked list queue menu." << endl;
                            break;

                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }

                } while (choice != 0);
                break;

            case 3:
                do {
                	system("cls");
                    cout << "Choose an option:" << endl;
                    cout << "1. Enqueue" << endl;
                    cout << "2. Dequeue" << endl;
                    cout << "3. Display" << endl;
                    cout << "4. Reverse" << endl;
                    cout << "0. Exit" << endl;

                    cin >> choice;

                    switch (choice) {
                    	system("cls");
                        case 1:
                            int val;
                            cout << "Enter value to enqueue: ";
                            cin >> val;
                            aq.enqueue(val);
                            break;

                        case 2:
                            cout << "Dequeued value: " << aq.dequeue() << endl;
                            break;

                        case 3:
                            cout << "Queue Contents: ";
                            aq.display();
                            break;

                        case 4:
                            aq.reverse();
                            cout << "Queue Reversed" << endl;
                            break;

                        case 0:
                            cout << "Exiting array queue menu." << endl;
                            break;

                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }

                } while (choice != 0);
                break;

            case 0:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
