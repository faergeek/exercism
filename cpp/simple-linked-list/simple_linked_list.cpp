#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    return current_size;
}

void List::push(int entry) {
    auto old_head = head;
    head = new Element(entry);
    head->next = old_head;
    current_size++;
}

int List::pop() {
    if (current_size == 0) {
        throw std::length_error("Can't pop from an empty list");
    }

    current_size--;
    auto el = head;
    head = el->next;
    auto data = el->data;
    delete el;

    return data;
}

void List::reverse() {
    Element *newHead = nullptr;
    auto el = head;
    while (el) {
        auto next = el->next;
        el->next = newHead;
        newHead = el;
        el = next;
    }

    head = newHead;
}

List::~List() {
    auto el = head;
    while (el) {
        auto next = el->next;
        delete el;
        el = next;
    }
}

}  // namespace simple_linked_list
