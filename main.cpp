#include <iostream>
#include <string>
#include "Programmer.h"

/*
 * @author y. glad
 * Задание 1.1-1.2 Связный список с сохранением упорядоченности при добавлении
 */
template<typename T>
struct Node { // Узел

public:
    T value; // Значение
    Node *next; // Указатель на следующий

    T getValue() {
        return value;
    }

    Node *getNext() {
        return next;
    }

    void setValue(T value) {
        this->value = value;
    }

    void setNext(Node *next) {
        this->value = value;
    }
};

// Cписок
template<typename T>
class SortedList {

private:
    Node<T> *node; // Указатель на первый узел
    int size; // размер списка

public:
    ~SortedList() { //  деструктор
        this->clear();
    }

    bool push_back(const T &value) { // добавить элемент с сохранением упорядоченности
        Node<T> *prev = node, *ptr = node;

        while (ptr) {
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
            size++;
        }
        return (p != nullptr);
    }

    // Удалить последний элемент из списка
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

    // очистить список
    void clear() {
        Node<T> *ptr;
        while (node) {
            ptr = node;
            node = node->next;
            delete ptr;
        }
    }

    Node<T> *begin() { return node; }

    // Функция фильтрации. Принимает функцию, которая задает принцип сортирвки
    SortedList<T> filter(bool (*ptr)(T)) {
        SortedList newList = SortedList();
        Node<T> *tmp = node;
        while (tmp) {
            if (ptr(tmp->value)) {
                newList.push_back(tmp->value);
            }
            tmp = tmp->next;
        }
        return newList;
    }
};

// проверить, что число является кубом
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

bool operator==(const Programmer &p1, const Programmer &p2) {
    return p1.name == p2.name && p1.surname == p2.surname && p1.mainDevLang == p2.mainDevLang &&
           p1.telegram == p2.telegram;
}

bool operator!=(const Programmer &p1, const Programmer &p2) {
    return p1.name != p2.name || p1.surname != p2.surname || p1.mainDevLang != p2.mainDevLang ||
           p1.telegram != p2.telegram;
}

bool operator>(const Programmer &p1, const Programmer &p2) {
    if (p1.level > p2.level) return true;
    else if (p1.level == p2.level) {
        if (p1.mainDevLang > p2.mainDevLang)
            return true;
        else if (p1.mainDevLang == p2.mainDevLang) {
            if (p1.name > p2.name)
                return true;
            else return false;
        } else return false;
    } else return false;
}

bool operator<(const Programmer &p1, const Programmer &p2) {
    if (p1.level < p2.level) return true;
    else if (p1.level == p2.level) {
        if (p1.mainDevLang < p2.mainDevLang)
            return true;
        else if (p1.mainDevLang == p2.mainDevLang) {
            if (p1.name < p2.name)
                return true;
            else return false;
        } else return false;
    } else return false;
}

int main() { // пример рабаоты
    SortedList<int> list{};
    list.push_back(225);
    list.push_back(64);
    list.push_back(8);
    list.push_back(81);
    list.push_back(1);

    int deleted = *list.pop();

    std::cout << "Deleted value " << deleted << std::endl;

    SortedList<int> newList = list.filter([](int j) { return checkDegreeThree(j); }); // Задание 1.1 25 вариант

    for (Node<int> *val = newList.begin(); val != nullptr; val = val->next) {
        std::cout << val->value << " ";
    }
    list.clear();

    std::cout << std::endl;
    SortedList<Programmer> list2{};
    list2.push_back(Programmer("Yana", "Glad", "Koltin", 10)); // Задание 1.2
    list2.push_back(Programmer("Andrey", "Andrey", "C++", 5));
    list2.push_back(Programmer("Egor", "Egor", "Kotlin", 1));
    list2.push_back(Programmer("Ivan", "Ivanov", "Java", 7));
    list2.push_back(Programmer("Igor", "Igor", "Swift", 8));

    for (Node<Programmer> *val = list2.begin(); val != nullptr; val = val->next) {
        std::cout << val->value.name << " ";
    }
    return 0;
}