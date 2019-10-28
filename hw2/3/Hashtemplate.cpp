#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define HASHSIZE 5

typedef struct Node {
    char *key;
    char *value;
    Node *next;
} Node;

class HashTable {
private:
    Node *node[ HASHSIZE ];

public:
    HashTable();
    ~HashTable();
    size_t      hash(const char *key);
    Node *      lookup(const char *key);
    bool        install(const char *key, const char *value);
    const char *get(const char *key);
    void        display();

private:
    char *strdup(const char *str);
};
HashTable::HashTable() {
    for (int i = 0; i < HASHSIZE; ++i) {
        node[ i ] = NULL;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < HASHSIZE; ++i) {
        Node *next = node[ i ];
        while (next) {
            Node *tmp = next->next;
            free(next->key);
            free(next->value);
            free(next);
            next = tmp;
        }
    }
}

char *HashTable::strdup(const char *str) {
    int   len = strlen(str) + 1;
    char *ns  = (char *)malloc(len * sizeof(char));
    strcpy(ns, str);
    if (ns == nullptr)
        return nullptr;
    else
        return ns;
}
size_t HashTable::hash(const char *key) {
    size_t hash = 0;
    while (*key) {
        hash += (hash << 5) + (*key++);
    }
    return hash % HASHSIZE;
}
Node *HashTable::lookup(const char *key) {
    Node * np;
    size_t index;
    index = hash(key);
    for (np = node[ index ]; np; np = np->next) {
        if (!strcmp(key, np->key))
            return np;
    }
    return NULL;
}
bool HashTable::install(const char *key, const char *value) {
    size_t index;
    Node * np;
    if (!(np = lookup(key))) {
        index = hash(key);
        np    = (Node *)malloc(sizeof(Node));
        if (!np)
            return false;
        np->key = strdup(key);
        if (np->key == nullptr)
            return false;
        np->next      = node[ index ];
        node[ index ] = np;
    } else {
        free(np->value);
    }
    np->value = strdup(value);
    if (np->key == nullptr)
        return false;
    return true;
}
void HashTable::display() {
    Node *temp;
    for (int i = 0; i < HASHSIZE; ++i) {
        if (!node[ i ]) {
            printf("[]\n");
        } else {
            printf("[");
            for (temp = node[ i ]; temp; temp = temp->next) {
                printf("[%s][%s] ", temp->key, temp->value);
            }
            printf("]\n");
        }
    }
}
void testHash(HashTable *ht) {
    const char *key[]   = {"a", "b", "c", "d", "e", "f"};
    const char *value[] = {"value1", "value2", "value3", "value4", "value5", "value6"};
    for (int i = 0; i < 6; ++i) {
        ht->install(key[ i ], value[ i ]);
    }
}
int main(int argc, char const *argv[]) {
    HashTable ht;
    testHash(&ht);
    ht.display();
    return 0;
}
