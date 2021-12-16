#include <iostream>
#include <string>

template<typename T>
struct Node {

public:
    T value;
    Node *next;

    T getValue(){
        return value;
    }

    Node * getNext(){
        return next;
    }

    void setValue(T value){
        this->value = value;
    }

    void setNext( Node *next){
        this->value = value;
    }
};

template<typename T>
class SortedList {

private:
    Node<T> *node;
    int size;

public:
    ~SortedList() {
        this->clear();
    }

    bool add(const T &value) {
        Node<T> *prev = node, *ptr = node;

        while (ptr != nullptr) {
            if (value < ptr->getValue())
                break;
            else {
                if (value == ptr->getValue())
                    break;
            }
            prev = ptr;
            ptr = ptr->getNext();
        }

        auto *p = new Node<T>();
        if (p) {
            p->value = value;

            if (ptr == node) {
                p->next = node;
                node = p;
            } else {
                p->next = ptr;
                prev->next = p;
            }
            ++size;
        }
        return (p != nullptr);
    }

    T *pop() {
        Node<T> *prev = node, *ptr = node->next;

        while (ptr->next) {
            prev->value = ptr->value;

            prev = prev->next;
            ptr = ptr->next;
        }
        prev->value = ptr->value;
        prev->next = nullptr;

        return &prev->value;
    }

    void clear() {
        Node<T> *ptr;
        while (node) {
            ptr = node;
            node = node->next;
            delete ptr;
        }
    }

    Node<T> *begin() { return node; }

    bool isEmpty() const { return (node == nullptr); }


    SortedList<T> filter(bool (*ptr)(T)) {
        SortedList newList = SortedList();
        Node<T> *tmp = node;
        while (tmp) {
            if (ptr(tmp->value)) {
                newList.add(tmp->value);
            }
            tmp = tmp->next;
        }
        return newList;
    }
};

bool checkDegreeThree(int value) {
    bool check = false;
    int num = 1;

    while (!check) {
        int total = num * num * num;
        if (total > value && total != value) break;
        if (total == value) check = true;
        num++;
    }

    return check;
}

int main() {
    SortedList<int> list{};
    list.add(225);
    list.add(64);
    list.add(8);
    list.add(81);
    list.add(1);

    int deleted = *list.pop();

    std::cout << "Deleted value " << deleted << std::endl;

    SortedList<int> newList = list.filter([](int j) { return checkDegreeThree(j); });

    for (Node<int> *val = newList.begin(); val != nullptr; val = val->next) {
        std::cout << val->value << " ";
    }
    list.clear();
    return 0;
}