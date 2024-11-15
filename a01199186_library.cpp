// FRANCO VARELA VILLEGAS
// A01199186
// HOMEWORK 3, LIBRARY SYSTEM.
#include <iostream>
#include <vector>
#include <string>
#include "A01199186_text.h"
#include <random>
#include <ctime>
#include <cstdlib>
// MAIN CLASS OF ITEMS (ABSTRACT)
class Item{
    protected:
        std::string itemTitle;
        std::string itemAuthor;
        int itemID;
        bool itemStatus; // TRUE IF ITEM IS AVAILABLE, FALSE IF IT IS NOT
        std::string itemDate;
        int itemPrice;
    public:
    //CONSTRUCTOR
        Item(std::string title, std::string author, int id, bool status, std::string date, int price)
         : itemTitle(title), itemAuthor(author), itemID(id), itemStatus(status), itemDate(date), itemPrice(price) {}
    
        virtual ~Item() = default;
        // DISPLAY ITEM
        virtual void display() const{
            std::cout << "Title: " << itemTitle << " Author: " << itemAuthor << " ID: " << itemID
            << " Status: " << (itemStatus ? " Available " : " Not Available ") << " Date: " << itemDate
            << " Price: " << itemPrice << std::endl;
        }

        void borrow() {
            if (itemStatus) {
                itemStatus = false;
            }
        }

        void returnCheck() {
            if (itemStatus == false) {
                itemStatus = true;
            }
        }


        bool checkStatus() const{
            if (itemStatus) {
                return true;
            }
            return false;
        }

        std::string displayName(){
            return itemTitle;
        }
};
// CLASS OF BOOKS (INHERITANCE)
class Book : public Item{
    private:
        int bookIsbn;
        int bookPages;
    public:
    //CONSTRUCTOR
        Book(std::string title, std::string author, int id, bool status, std::string date, int price, int ISBN, int pages)
         : Item(title, author, id, status, date, price), bookIsbn(ISBN), bookPages(pages){}
        
        void display(){
            Item::display();
            std::cout << " ISBN: " << bookIsbn << "Pages: " << bookPages << std::endl;
        }
};
// CREATE LIBRARY OF ITEMS
// CLASS OF JOURNALS (INHERITANCE)
class Journal : public Item{
    private:
        int journalVolume;
        int journalIssue;
    public:
    //CONSTRUCTOR
        Journal(std::string title, std::string author, int id, bool status, std::string date, int price, int vol, int issue)
         : Item(title, author, id, status, date, price), journalVolume(vol), journalIssue(issue){}
        
        void display(){
            Item::display();
            std::cout << " Volume: " << journalVolume << "Issue: " << journalIssue << std::endl;
        }
};
// CLASS OF DVDS (INHERITANCE)
class Dvd : public Item{
    private:
        int durationMins;
        std::string dvdGender;
    public:
    //CONSTRUCTOR
        Dvd(std::string title, std::string author, int id, bool status, std::string date, int price, int duration, std::string gender)
         : Item(title, author, id, status, date, price), durationMins(duration), dvdGender(gender){}
                        
        void display() const override{
            Item::display();
            std::cout << " Duration: " << durationMins << "Gender: " << dvdGender << std::endl;
        }
};

class Library {
    public:
    // vector for array
        std::vector<Item*> itemsArray;
        Library() {
            // Agregar manualmente algunos elementos al inventario de la biblioteca
            // 5 BOOKS
            itemsArray.push_back(new Book("Book1", "Author1", 101, true, "2020-01-01", 499, 123456, 100));
            itemsArray.push_back(new Book("Book2", "Author2", 102, true, "2021-02-01", 399, 654321, 150));
            itemsArray.push_back(new Book("Book3", "Author3", 103, true, "2022-03-01", 599, 112233, 200));
            itemsArray.push_back(new Book("Book4", "Author4", 104, true, "2023-04-01", 349, 445566, 120));
            itemsArray.push_back(new Book("Book5", "Author5", 105, true, "2024-05-01", 699, 789012, 250));
            // 5 JPURNALS
            itemsArray.push_back(new Journal("Journal1", "Author1", 106, true, "2020-01-01", 299, 1, 1));
            itemsArray.push_back(new Journal("Journal2", "Author2", 107, true, "2021-02-01", 349, 2, 3));
            itemsArray.push_back(new Journal("Journal3", "Author3", 108, true, "2022-03-01", 249, 3, 2));
            itemsArray.push_back(new Journal("Journal4", "Author4", 109, true, "2023-04-01", 299, 4, 4));
            itemsArray.push_back(new Journal("Journal5", "Author5", 110, true, "2024-05-01", 199, 5, 5));
            // 5 DVDS
            itemsArray.push_back(new Dvd("DVD1", "Author1", 111, true, "2020-01-01", 199, 120, "Action"));
            itemsArray.push_back(new Dvd("DVD2", "Author2", 112, true, "2021-02-01", 149, 90, "Drama"));
            itemsArray.push_back(new Dvd("DVD3", "Author3", 113, true, "2022-03-01", 249, 140, "Thriller"));
            itemsArray.push_back(new Dvd("DVD4", "Author4", 114, true, "2023-04-01", 179, 110, "Comedy"));
            itemsArray.push_back(new Dvd("DVD5", "Author5", 115, true, "2024-05-01", 199, 120, "Horror"));

        }
        // DISPLAY ENTIRE LIBRARY
        void displayAllitemsArray() const {
            for (const Item* item : itemsArray) {
                item->display();
                std::cout << "---------------------" << std::endl;
            }
        }
        void addItem() {
            int numberOfItems;
            std::cout << "How many items would you like to add? ";
            std::cin >> numberOfItems;

            for (int i = 0; i < numberOfItems; ++i) {
                std::cout << "Adding item " << (i + 1) << " of " << numberOfItems << std::endl;

                int itemType;
                std::cout << "Select the type of item to add:\n";
                std::cout << "1. Book\n";
                std::cout << "2. Journal\n";
                std::cout << "3. DVD\n";
                std::cout << "Enter choice: ";
                std::cin >> itemType;

                std::string title, author, date;
                int id, price;

                // Solicita la información común
                std::cout << "Enter Title: ";
                std::cin >> std::ws; // Limpia el buffer de entrada
                std::getline(std::cin, title);

                std::cout << "Enter Author: ";
                std::getline(std::cin, author);

                std::cout << "Enter ID: ";
                std::cin >> id;

                std::cout << "Enter Date (YYYY-MM-DD): ";
                std::cin >> date;

                std::cout << "Enter Price: ";
                std::cin >> price;

                // Condicionales para tipos específicos de ítems
                if (itemType == 1) {
                    int ISBN, pages;
                    std::cout << "Enter ISBN: ";
                    std::cin >> ISBN;

                    std::cout << "Enter number of Pages: ";
                    std::cin >> pages;

                    itemsArray.push_back(new Book(title, author, id, true, date, price, ISBN, pages));
                    std::cout << "Book added successfully!\n";
                } else if (itemType == 2) {
                    int volume, issue;
                    std::cout << "Enter Volume: ";
                    std::cin >> volume;

                    std::cout << "Enter Issue: ";
                    std::cin >> issue;

                    itemsArray.push_back(new Journal(title, author, id, true, date, price, volume, issue));
                    std::cout << "Journal added successfully!\n";
                } else if (itemType == 3) {
                    int duration;
                    std::string genre;
                    std::cout << "Enter Duration (in minutes): ";
                    std::cin >> duration;

                    std::cout << "Enter Genre: ";
                    std::cin >> genre;

                    itemsArray.push_back(new Dvd(title, author, id, true, date, price, duration, genre));
                    std::cout << "DVD added successfully!\n";
                } else {
                    std::cout << "Invalid item type selected. Skipping...\n";
                }
            }

            std::cout << "All items have been added successfully!" << std::endl;
        }

};

// =====================================================================================================================================

// CLASS OF MEMBER (ABSTRACT)
class Member{
    private:
        int memberID;
        std::string memberName;
        int memberAge;
        long long int memberPhone;
        std::string memberEmail;
        std::vector<std::string> memberHistory;

        int generateRandomID() {
            return 1000 + rand() % 9000; // RANDOM ID GENERATOR
        } 
    public:
    // Members should be able to borrow an item
    // Members should be able to return an item
    // Members should be able to view their borrowing history
    // Members should be able to view their account information
    // Members should be able to see the library
        Member() : memberID(generateRandomID()) {}
        void createMember(){
            std::cout << "Enter your name: ";
            std::getline(std::cin >> std::ws, memberName);

            std::cout << "Enter your Age: ";
            std::cin >> memberAge;

            std::cout << "Enter your Phone: ";
            std::cin >> memberPhone;

            std::cout << "Enter your Email: ";
            std::getline(std::cin >> std::ws, memberEmail);
        };

        void displayMemberInformation(){
            std::cout << "Member ID: " << memberID << std::endl;
            std::cout << "Member Name: " << memberName << std::endl;
            std::cout << "Member Age: " << memberAge << std::endl;
            std::cout << "Member Phone: " << memberPhone << std::endl;
            std::cout << "Member Email: " << memberEmail << std::endl;
        }

        std::string getMemberName() const{
            return memberName;
        }

        void borrowItem(Library& library){
             std::cout << "These are all the available items" << std::endl;
                library.displayAllitemsArray();
                // Ask how many items they want
                int userBorrowSelection;
                std::cout << "How many items would you like to borrow? " << std::endl;
                std::cin >> userBorrowSelection;

                // FOR LOOP FOR HOW MANY ITEMS THEY WANT TO BORROW
                for (int i = 0; i < userBorrowSelection; i++) {
                    int borrowedItem;
                    std::cout << "Insert the number of the item you want to borrow: (e.g., book1 = 0, dvd5 = 15) ";
                    std::cin >> borrowedItem;
                    // check if that number is in the array
                    if (borrowedItem >= 0 && borrowedItem < library.itemsArray.size()){
                        Item* itemToBorrow = library.itemsArray[borrowedItem]; 
                        // check the status
                        if (itemToBorrow->checkStatus()){
                            itemToBorrow->borrow();
                            std::cout << "You have successfully borrowed: " << itemToBorrow->displayName() << std::endl;
                            memberHistory.push_back(itemToBorrow->displayName());   
                        }
                        else{
                            std::cout << "Sorry, that item is not available" << std::endl;
                            i--;
                        }
                    }
                    else{
                        std::cout << "Item not found, try something between 0 and " << library.itemsArray.size() - 1 << std::endl;
                        i--;
                    }
                    std::cout << "You have borrowed a total of: " << memberHistory.size() << " items" << std::endl;
                }
        }
        // end of borrow
        // display member history
        void displayMemberHistory() {
            std::cout << "Borrowing History of: " << getMemberName() << std::endl;
            if (memberHistory.empty()) {
                std::cout << "No items borrowed yet." << std::endl;
            } else {
                for (const auto& item : memberHistory) {
                    std::cout << "- " << item << std::endl;
                }
            }
        }
        // end of history
        // start of borrow
        void returnItem(Library& library, Member& member) {
            std::cout << "These are all the items you have borrowed" << std::endl;
            member.displayMemberHistory();
            // Ask how many items they want to return
            int userReturnSelection;
            std::cout << "How many items would you like to return? " << std::endl;
            std::cin >> userReturnSelection;
            // FOR LOOP FOR HOW MANY ITEMS THEY WANT TO RETURN
            for (int i = 0; i < userReturnSelection; i++) {
                int returnedItem;
                std::cout << "Insert the number of the item you want to return from your borrowed list (0 - " << memberHistory.size() << std::endl;
                std::cin >> returnedItem;
                // check if that number is in the array
                if (returnedItem >= 0 && returnedItem < memberHistory.size()) {
                    std::string itemName = memberHistory[returnedItem];

                    bool itemFound = false;
                    for(auto& item: library.itemsArray){
                        if(item->displayName() == itemName && !item->checkStatus()){
                            item->returnCheck();
                            memberHistory.erase(memberHistory.begin() + returnedItem);
                            std::cout << "Item: " << itemName << " returned successfully" << std::endl;
                            itemFound = true;
                            break;
                        }
                    }

                    if(!itemFound){
                        std::cout << "Item not found or already returned " << std::endl;
                        i--;
                        continue;
                    }
                }
            }
            std::cout << "You have returned a total of " << userReturnSelection << " items." << std::endl;
        }

};

int main() {
    Library newLibrary;
    initialInstructions();
    int initialPress;
    std::cout << "Input your option: ";
    std::cin >> initialPress;
    std::cout << "You selected: " << initialPress << std::endl;

    // WHILE THERE IS NO USER CREATED, THE PROGRAM WILL KEEP ASKING FOR THE USER'S INFORMATION
    while (initialPress != 1) {
        std::cout << "You must become a member, press 1" << std::endl;
        std::cout << "Input your option: ";
        std::cin >> initialPress;
    }

    // IF USER SELECTED 1, THE PROGRAM WILL ASK THEM TO CREATE A NEW MEMBER
    if (initialPress == 1) {
        // member scenario
        Member newMember;
        newMember.createMember();
        std::cout << "Member created successfully!" << std::endl;
        std::cout << "=====================" << std::endl;
        std::cout << "Member information:" << std::endl;
        std::cout << "=====================" << std::endl;
        newMember.displayMemberInformation();

        // ALL THE FOLLOWING WILL HAPPEN RIGHT HERE
        std::cout << "Hello " << newMember.getMemberName() << ", Insert a new option from this menu. " << std::endl;
        secondInstructions();

        bool continueOperations = true;  // Flag to control the loop
        while (continueOperations) {
            int secondPress;
            std::cout << "Input your new option: (2 to check, 3 to borrow, 4 to check borrowed items, 5 to return, 6 to see acc info, 7 to add items) ";
            std::cin >> secondPress;
            std::cout << "==============" << std::endl;

            // NEW FUNCTIONS
            // ============= CHECK LIBRARY
            if (secondPress == 2) {
                newLibrary.displayAllitemsArray();
            }
            // ============= BORROW AN ITEM
            else if (secondPress == 3) {
                newMember.borrowItem(newLibrary);
            }
            // CHECK HISTORY
            else if (secondPress == 4) {
                newMember.displayMemberHistory();
            }
            // RETURN AN ITEM
            else if (secondPress == 5) {
                newMember.returnItem(newLibrary, newMember);
            }
            
            else if(secondPress == 6){
                newMember.displayMemberInformation();
            }

            else if(secondPress == 7){
                newLibrary.addItem();
            }

            else{
                std::cout << "Invalid option. Please try again with a value between 2 and 5." << std::endl;
            }
            // Ask if the user wants to do another operation
            int continueChoice;
            std::cout << "Do you want to perform another action? (1 if yes, 0 if no): ";
            std::cin >> continueChoice;

            if (continueChoice == 0) {
                continueOperations = false;
                std::cout << "Thank you for using our service!" << std::endl;
            }
        }
    }

    return 0;
}