#include <stdio.h>

struct People {
    int id;

    People *left;
    People *right;

    People(int i) {
        this->id = i + 1;
    }

    int getId() {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    People *getLeft() {
        return left;
    }

    void setLeft(People *left) {
        this->left = left;
    }

    People *getRight() {
        return right;
    }

    void setRight(People *right) {
        this->right = right;
    }
};
struct Circle {

    int     total;
    People *first;
    People *last;

    void addPeople(People *newPeople) {
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

    void deletePeople(People *deletePeople) {
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

    int getTotal() {
        return total;
    }

    void setTotal(int total) {
        this->total = total;
    }

    People *getFirst() {
        return first;
    }

    void setFirst(People *first) {
        this->first = first;
    }

    People *getLast() {
        return last;
    }

    void setLast(People *last) {
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
    scanf("%d %d", &total, &keyNumber);
    Circle *circle = compute(total, keyNumber);
    printf("%d\n", (*(*circle).getFirst()).getId());
}