#include <fstream>
#include "book/book.h"
#include "menu/menu.h"


int main()
{

    Book b1;
    char title[20];

    while (1) {
        switch (menu()) {
        case 1:
            b1.getBookData();
            b1.storeBook();
            std::cout << "\nRecord inserted";
            break;

        case 2:
            b1.viewAllBooks();
            break;

        case 3:
            std::cout << "\nEnter title of "
                 << "book to search : ";
            std::cin.ignore();
            std::cin.getline(title, 19);
            b1.searchBook(title);
            break;

        case 4:
            std::cout << "\nEnter book title "
                 << "for delete record : ";
            std::cin.ignore();
            std::cin.getline(title, 19);
            b1.deleteBook(title);
            break;

        case 5:
            std::cout << "\nEnter book title "
                 << "to update record : ";
            std::cin.ignore();
            std::cin.getline(title, 19);
            b1.updateBook(title);
            break;

        case 6:
            std::cout << "\n Thanks for using";
            std::cout << "\n Press any key to exit";
            exit(0);

        default:
            std::cout << "Invalid input";
        }
    }
}