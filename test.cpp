#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>

using namespace std;
class Book
{
public:
    Book(std::string t, std::string a) : title(t), author(a), isBorrowed(false) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    bool getIsBorrowed() const { return isBorrowed; }

    void borrowBook() { isBorrowed = true; }
    void returnBook() { isBorrowed = false; }

private:
    std::string title;
    std::string author;
    bool isBorrowed;
};

class Library
{
public: 
    map<string,int>title;
    map<string,string>author;
    // TODO: Implement addBook method to add a book to the library
    void addBook(string title_name, string author_name){

        Book newbook = Book(title_name, author_name); 

        title[title_name]++;
        author[title_name] = author_name;
        books.push_back(newbook);
        cout<<"Book Added"<<endl;
    }
    // TODO: Implement borrowBook method to borrow a book from the library
    void borrrowBook(string title_name){
        string author_name = author[title_name];
        Book *current_book = new Book(title_name, author_name);
        if(title.find(title_name)==title.end()){
            cout<<"Book Not Available"<<endl;
            return;
        }
        title.erase(title_name);
        current_book->borrowBook();
        cout<<"Book Borrowed"<<endl;
    }
    // TODO: Implement returnBook method to return a borrowed book to the library
    void returnBook(string title_name, string author_name){
        Book *current_book = new Book(title_name, author_name);
        title[title_name]++;
        current_book->returnBook();
        cout<<"Book Returned"<<endl;
    }
    // TODO: Implement listBooks method to list all the books in the library
    void listBooks(){
        for(int i=0;i<books.size();i++){
            cout<<books[i].getTitle()<<" "<<books[i].getAuthor()<<endl;
        }
        cout<<endl;
    }
private:
    std::vector<Book> books;
};

int main()
{
    Library myLibrary;
    int choice;

    do
    {
        std::cout << "1. Add Book\n";
        std::cout << "2. Borrow Book\n";
        std::cout << "3. Return Book\n";
        std::cout << "4. List Books\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        string title_name, author_name;
        switch (choice)
        {
        case 1:
            cin.ignore();
            cout<<"Enter the Book Title:";
            getline(cin,title_name);
            cout << "Enter the Author:";
            getline(cin,author_name);
            myLibrary.addBook(title_name,author_name);
            break;
        case 2:
            cin.ignore();
            cout << "Enter the Book Title:";
            getline(cin,title_name);
            myLibrary.borrrowBook(title_name);
            // TODO: Implement borrowing a book from the library
            break;
        case 3:
            cin.ignore();
            cout << "Enter the Book Title:";
            getline(cin, title_name);
            cout << "Enter the Author:";
            getline(cin, author_name);
            myLibrary.returnBook(title_name,author_name);
            // TODO: Implement returning a book to the library
            break;
        case 4:
            // TODO: Implement listing all books in the library
            myLibrary.listBooks();
            break;
        }
    } while (choice != 5);

    return 0;
}
