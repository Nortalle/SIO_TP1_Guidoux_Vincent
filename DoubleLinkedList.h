/*
 ------------------------------------------------------------------------------
 Labo        : TP1
 File        : DoubleLinkedList.h
 Author(s)   : Vincent Guidoux
 Date        : 18.04.2018

 Goal        : List doublement chainées

 Commentaire : Labo POO2
 ------------------------------------------------------------------------------
*/

#ifndef TP1_DOUBLELINKEDLIST_H
#define TP1_DOUBLELINKEDLIST_H

#include <cstdlib>
#include <stdexcept>
#include <iostream>

class DoubleLinkedList;

class DoubleLinkedList {
private:

    typedef struct Node {

        Node *previous = nullptr;
        size_t element;
        Node *next = nullptr;
    } Node;

    Node *head = nullptr;

    size_t length = 0;

public:

    DoubleLinkedList() : head(nullptr), length(0) {}

    size_t size() const {

        return length;
    }

    ~DoubleLinkedList() {

        Node *tmp = head;

        while (tmp != nullptr) {

            Node *temp = tmp;
            tmp = tmp->next;

            delete temp;
        }
    }

    Node *front() const {

        return head;
    }

    size_t pop() {

        if (head != nullptr)
            return remove(head);

        throw std::runtime_error("The list is empty");
    }

    Node* push(size_t element) {

        Node *to_append = new Node();
        to_append->next = head;
        to_append->element = element;

        if (head != nullptr)
            head->previous = to_append;

        head = to_append;

        length++;

        return head;
    }

    size_t remove(Node *o)  {

        size_t element = o->element;

        if (o == head)
            head = o->next;
        else {
            if (o->next != nullptr)
                o->next->previous = o->previous;

            if (o->previous != nullptr)
                o->previous->next = o->next;

        }
        delete o;

        length--;
        return element;
    }
};


#endif //TP1_DOUBLELINKEDLIST_H
