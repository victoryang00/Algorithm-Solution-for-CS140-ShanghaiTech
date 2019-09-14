#include <iostream>
using namespace std;

class People {
private:
    int id;

    People *left;
    People *right;

public:
    People(int i) {
        this->id = i + 1;
    }

    virtual int getId() {
        return id;
    }

    virtual void setId(int id) {
        this->id = id;
    }

    virtual People *getLeft() {
        return left;
    }

    virtual void setLeft(People *left) {
        this->left = left;
    }

    virtual People *getRight() {
        return right;
    }

    virtual void setRight(People *right) {
        this->right = right;
    }
};
class Circle {
private:
    int     total;
    People *first;
    People *last;

public:
    virtual void addPeople(People *newPeople) {
        if (total <= 0) {

            first = newPeople;
            last  = newPeople;

            newPeople->setLeft(newPeople);
            newPeople->setRight(newPeople);
        } else {

            last->setRight(newPeople);
            newPeople->setLeft(last);
            newPeople->setRight(first);
            first->setLeft(newPeople);
            last = newPeople;
        }
        total++;
    }

    virtual void deletePeople(People *deletePeople) {
        if (total <= 0) {
            return;
        } else if (total == 1) {

            delete first;

            delete last;
        } else {

            if (deletePeople == first) {
                first = deletePeople->getRight();
            } else if (deletePeople == last) {
                last = deletePeople->getLeft();
            }

            deletePeople->getLeft()->setRight(deletePeople->getRight());

            deletePeople->getRight()->setLeft(deletePeople->getLeft());
        }
        total--;
    }

    virtual int getTotal() {
        return total;
    }

    virtual void setTotal(int total) {
        this->total = total;
    }

    virtual People *getFirst() {
        return first;
    }

    virtual void setFirst(People *first) {
        this->first = first;
    }

    virtual People *getLast() {
        return last;
    }

    virtual void setLast(People *last) {
        this->last = last;
    }
};

Circle *compute(int total, int keyNumber) {
    Circle *circle = new Circle();
    for (int i = 0; i < total; i++) {
        People *people = new People(i);
        (*circle).addPeople(people);
    }
    int     count  = 0;
    People *people = (*circle).getFirst();
    while ((*circle).getTotal() > 1) {
        count++;
        if (count == keyNumber) {
            count = 0;
            keyNumber--;
            (*circle).deletePeople(people);
        }
        people = (*people).getRight();
    }
    return circle;
}
int main() {
    int total, keyNumber;
    cin >> total >> keyNumber;
    Circle *circle = compute(total, keyNumber);
    cout << (*(*circle).getFirst()).getId() << "\n";
}