#ifndef LINKEDLISTEXCEPTIONS_H
#define LINKEDLISTEXCEPTIONS_H

#include <iostream>


class MemoryAllocationException {
public:
    const char* what() const noexcept {
        return "Memory allocation failed!";
    }
};


class EmptyListException {
public:
    const char* what() const noexcept {
        return "List is empty!";
    }
};

#endif
