#include "Square.h"

Square::Square() {
    try {
        value = new char('O');
        isEmpty = true;
        isVisited = false;
    } catch (const std::exception& e) {
        std::cerr << "Error initializing square: " << e.what() << std::endl;
        throw;
    }
}

Square::~Square() {
    try {
        delete value;
    } catch (const std::exception& e) {
        std::cerr << "Error during square destruction: " << e.what() << std::endl;
    }
}

bool Square::isSquareEmpty() const {
    return isEmpty;
}

void Square::setValue(const char* val) {
    try {
        *value = *val;
        isEmpty = false;
    } catch (const std::exception& e) {
        std::cerr << "Error setting square value: " << e.what() << std::endl;
        throw;
    }
}

char Square::getValue() const {
    return *value;
}

void Square::setIsVisited() {
    isVisited = true;
}

void Square::resetVisited() {
    isVisited = false;
}

bool Square::getIsVisited() const {
    return isVisited;
}

std::ostream& operator<<(std::ostream& out, const Square& sq) {
    out << *sq.value;
    return out;
}