#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListExceptions.h"

template <typename T>
class Node {
public:
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList() {
        DeleteAll();
    }

    void AddToHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!newNode) {
            throw MemoryAllocationException();
        }
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void AddToTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!newNode) {
            throw MemoryAllocationException();
        }
        if (!tail) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteFromHead() {
        if (!head) {
            throw EmptyListException();
        }
        Node<T>* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void DeleteFromTail() {
        if (!tail) {
            throw EmptyListException();
        }
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        delete temp;
    }

    void DeleteAll() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void Show() {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif
