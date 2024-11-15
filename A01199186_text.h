#include <iostream>
#include <vector>
#include <string>

int initialInstructions(){
    std::cout << "Welcome to our library system, here you will be able to do different things" << std::endl;
    std::cout << "Press 1 in order to create a new user, you must log in to access different features" << std::endl;
    return 0;
}

int secondInstructions(){
    std::cout << " =============== " << std::endl;
    std::cout << "Press 2 in order to see how many items we have" << std::endl;
    std::cout << "Press 3 in order to borrow an item" << std::endl;
    std::cout << "Press 4 in order to check borrow history" << std::endl;
    std::cout << "Press 5 in order to return an item" << std::endl;
    std::cout << "Press 6 in order to see acc information" << std::endl;
    std::cout << "Press 7 in order to add a new book" << std::endl;
    return 0;
}