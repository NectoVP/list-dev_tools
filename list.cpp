#include <iostream>

class list {
private:
    class node {
    public:
        node* next;
        node* prev;
        int data;

        node(int data = 0, node* next = nullptr, node* prev = nullptr) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };
    int msize;
    node* head;
    node* tail;

public:
    list();
    ~list() {};

    void push_back(int data);
    int pop_front();
    int pop_back();
    
    int size();
    int& operator [](int ind);
};

list::list() {
    msize = 0;
    this->head = new node(-1);
    this->tail = new node(-1);
}

void list::push_back(int data)
{
    if (head->next == nullptr) {
        node* temp = new node(data, this->tail, this->head);
        this->head->next = temp;
        this->tail->next = temp;
    }
    else {
        node* prev = this->tail->next;
        node* temp = new node(data, this->tail, prev);
        prev->next = temp;
        this->tail->next = temp;
        
    }
    ++msize;
}

int list::pop_front()
{
    node* fir = this->head->next;
    int first_elem = fir->data;
    if (msize == 1) {
        delete head;
        delete tail;
        this->head = new node(-1);
        this->tail = new node(-1);
    }
    else {
        this->head->next = fir->next;
        fir->next->prev = head;
    }
    delete fir;
    --msize;
    return first_elem;
}

int list::pop_back()
{
    node* last = this->tail->next;
    int last_elem = last->data;
    if (msize == 1) {
        delete head;
        delete tail;
        this->head = new node(-1);
        this->tail = new node(-1);
    }
    else {
        this->tail->next = last->prev;
        last->prev->next = tail;
    }
    delete last;
    --msize;
    return last_elem;
}

int& list::operator[](int ind)
{
    node* temp = this->head->next;
    
    int count = 0;
    while (temp != nullptr) {
        if (count == ind)
            return temp->data;
        temp = temp->next;
        ++count;
    }

}

int list::size() {
    return size;
}

int main() {
    list ls;
    ls.push_back(5);
    std::cout << ls.pop_back();
    return 0;
}
