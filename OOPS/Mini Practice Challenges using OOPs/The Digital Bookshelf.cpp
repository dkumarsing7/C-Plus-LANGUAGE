#include<iostream>
using namespace std;

// Create a class named Book.
class Book{
// The class should have the following private member variables:
// title (string)
// author (string)
// pages (int)
    string title, author;
    int pages;

// Implement a public parameterized constructor that takes the title, author, and number of pages as arguments and initializes the member variables.
public : 
    Book(string title, string author, int pages){
        this->title = title;
        this->author = author;
        this->pages = pages;
    }

// Implement a public method called displayDetails() that prints the book's information to the console in a readable format.
    void displayDetails(){
        cout<< endl<< "Title: " << title<< "\nAuthor: " << author<< "\nPages: "<< pages;
    }

};

// In the main() function, create an instance (object) of the Book class and call the displayDetails() method to show its information.
int main(){
    Book b1("The Lord of the Rings", "J.R.R. Tolkien", 1178);
    b1.displayDetails();
}

// Example Output:
// Generated code
// Title: The Lord of the Rings
// Author: J.R.R. Tolkien
// Pages: 1178