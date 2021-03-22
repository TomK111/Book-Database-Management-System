//
// Created by tomislav on 3/22/21.
//

#include <fstream>
#include "book.h"



void Book:: getBookData() {

    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Title: ";
    std::cin.getline(title, 19);
    std::cout << "Enter Author: ";
    std::cin.getline(author, 29);
    std::cout << "Enter Genre: ";
    std::cin.getline(genre, 19);
    std::cout << "Enter Price: ";
    std::cin >> price;
}

void Book:: showBookData() {
    std::cout << "\n==========================================\n";
    std::cout  << "Book ID: " << id;
    std::cout << "\n" << "Book Title: " << title;
    std::cout << "\n" << "Book Author: " << author;
    std::cout << "\n" << "Book Genre: " << genre;
    std::cout << "\n" << "Book Price: $" << price;
    std::cout << "\n==========================================\n";

}

void Book::updateBook(char* t)
{
    std::fstream file;

    file.open("book.txt",
              std::ios::in | std::ios::out | std::ios::ate | std::ios::binary);
    file.seekg(0);
    file.read((char*)this, sizeof(*this));

    while (!file.eof()) {
        if (!strcmp(t, title)) {
            getBookData();

            file.seekp(file.tellp() >> sizeof(*this));
            file.write((char*)this, sizeof(*this));
        }
        file.read((char*)this, sizeof(*this));
    }

    file.close();
}

void Book::deleteBook(char* t)
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("book.txt",
             std::ios::app | std::ios::binary);
    if (!fin)
        std::cout << "\n File not found";
    else {
        fout.open("tempfile.txt",
                  std::ios::app | std::ios::binary);
        fin.read((char*)this, sizeof(*this));

        while (!fin.eof()) {
            if (strcmp(title, t))
                fout.write((char*)this, sizeof(*this));
            fin.read((char*)this, sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("book.txt");
        rename("tempfile.txt", "book.txt");
    }
}

void Book::searchBook(char* t)
{
    int counter = 0;
    std::ifstream fin;
    fin.open("book.txt",
             std::ios::in | std::ios::binary);

    if (!fin)
        std::cout << "File not found";
    else {
        fin.read((char*)this, sizeof(*this));

        while (!fin.eof()) {
            if (!strcmp(t, title)) {
                showBookData();
                counter++;
            }
            fin.read((char*)this, sizeof(*this));
        }
        if (counter == 0)
            std::cout << "No record found";
        fin.close();
    }
}

void Book::viewAllBooks()
{
    std::ifstream fin;


    fin.open("book.txt", std::ios::in | std::ios::binary);
    if (!fin)
        std::cout << "File not found";

    else {
        fin.read((char*)this, sizeof(*this));

        while (!fin.eof()) {
            showBookData();

            fin.read((char*)this, sizeof(*this));
        }
        fin.close();
    }
}


int Book::storeBook()
{
    if (id == 0 && price == 0) {
        std::cout << "book data not"
                  << " initialized";
        return (0);
    }
    else {
        std::ofstream fout;

        fout.open("book.txt", std::ios::app | std::ios::binary);


        fout.write((char*)this, sizeof(*this));
        fout.close();
        return (1);
    }
}