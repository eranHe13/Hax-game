#ifndef HEX_SQUARE_H
#define HEX_SQUARE_H

#include <iostream>

class Square {
public:
    Square(); // Default constructor
    ~Square(); // Destructor

    bool isSquareEmpty() const; // Check if square is empty
    void setValue(const char* value); // Set the value of the square
    char getValue() const; // Get the value of the square

    void setIsVisited(); // Mark square as visited
    void resetVisited(); // Reset visited flag
    bool getIsVisited() const; // Check if square was visited

    friend std::ostream& operator<<(std::ostream& out, const Square& sq); // Overload << operator for board printing

private:
    char* value; // Value stored in square
    bool isEmpty; // Whether the square is empty
    bool isVisited; // Whether the square has been visited
};

#endif // HEX_SQUARE_H