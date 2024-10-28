#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}

    bool is_empty() {
        return head == nullptr;
    }

    void Insert_Begin(int Value) {
        Node* temp = new Node(Value);
        if (is_empty()) {
            head = temp;
        }
        else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void Insert_End(int Value) {
        Node* temp = new Node(Value);
        if (is_empty()) {
            head = temp;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = temp;
            temp->prev = current;
        }
    }

    void Insert_After(int OldV, int NewV) {
        Node* temp = new Node(NewV);
        Node* p = head;
        while (p != nullptr && p->data != OldV) {
            p = p->next;
        }
        if (p == nullptr) {
            cout << "Node not found!" << endl;
            delete temp;
            return;
        }
        temp->next = p->next;
        temp->prev = p;
        p->next = temp;
        if (temp->next != nullptr) {
            temp->next->prev = temp;
        }
    }

    void Delete_Begin() {
        if (is_empty()) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void Delete_End() {
        if (is_empty()) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        if (current->prev != nullptr) {
            current->prev->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete current;
    }

    void Delete_Node(int Value) {
        if (is_empty()) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        if (head->data == Value) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        Node* p = head->next;
        Node* q = head;
        while (p != nullptr && p->data != Value) {
            q = p;
            p = p->next;
        }
        if (p == nullptr) {
            cout << "Node not found!" << endl;
            return;
        }
        q->next = p->next;
        if (p->next != nullptr) {
            p->next->prev = q;
        }
        delete p;
    }

    void Display() {
        if (is_empty()) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* current = head;
        cout << "List is: " << endl;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void Alternate_Nodes() {
        if (is_empty()) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        int count = 0;
        cout << "Alternate nodes are: " << endl;
        while (temp != nullptr) {
            if (count % 2 == 0) {
                cout << temp->data << " ";
            }
            count++;
            temp = temp->next;
        }
        cout << endl;
    }

    void Display_Reverse() {
        if (is_empty()) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        cout << "List in reverse: " << endl;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    List li;
    li.Insert_Begin(10);
    li.Insert_Begin(20);
    li.Insert_Begin(30);
    li.Insert_End(40);
    li.Insert_End(50);
    li.Insert_After(30, 60);
    li.Display();
    li.Delete_Begin();
    li.Display();
    li.Delete_End();
    li.Display();
    li.Delete_Node(20);
    li.Display();
    li.Insert_Begin(70);
    li.Insert_Begin(80);
    li.Insert_Begin(90);
    li.Display();
    li.Alternate_Nodes();
    li.Display_Reverse();

    return 0;
}
