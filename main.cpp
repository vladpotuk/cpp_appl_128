#include "LinkedList.h"
#include "LinkedListExceptions.h" 

int main() {
    try {
        LinkedList<int> intList;

        intList.AddToHead(1);
        intList.AddToTail(2);
        intList.AddToTail(3);

        std::cout << "Original List: ";
        intList.Show();

        intList.DeleteFromHead();
        intList.DeleteFromTail();

        std::cout << "List after deletions: ";
        intList.Show();
    }
    catch (const MemoryAllocationException& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }
    catch (const EmptyListException& e) {
        std::cerr << "List is empty: " << e.what() << std::endl;
    }

    return 0;
}
