//
// Created by tomislav on 3/22/21.
//

#ifndef BOOK_MANAGEMENT_SYSTEM_BOOK_H
#define BOOK_MANAGEMENT_SYSTEM_BOOK_H


#include <cstring>
#include <iostream>

class Book {
private:
    int id;
    char title[20];
    float price;
    char genre[10];
    char author[30];
public:
    Book() {
        id = 0;
        strcpy(title, "no title");
        strcpy(genre, "no genre");
        strcpy(author, "no author");
        price = 0;
    }

    void getBookData();

    void showBookData();

    int storeBook();

    void viewAllBooks();

    void searchBook(char *);

    void deleteBook(char *);

    void updateBook(char *);
};
#endif //BOOK_MANAGEMENT_SYSTEM_BOOK_H
