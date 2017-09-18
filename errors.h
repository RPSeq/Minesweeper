#include <exception>
#include <iostream>

class bad_index : public std::exception
{
public:
    const char* what() { return "Error: Index out of range!";}
    
}