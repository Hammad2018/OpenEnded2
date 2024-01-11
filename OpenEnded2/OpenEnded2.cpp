#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int publicationYear;
    string genre;
};

void inputDetails(Book books[6]) {
    for (int i = 0; i < 6; ++i) {
        cout << "Enter details for Book " << i + 1 << ":\n";
        cout << "Title: ";
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "Publication Year: ";
        cin >> books[i].publicationYear;
        cout << "Genre: ";
        cin >> books[i].genre;
        cin.ignore();
        cout << "\n";
    }
}

void categorizeBooks(const Book books[6], Book fiction[6], Book nonFiction[6], int& fictionCount, int& nonFictionCount) {
    fictionCount = 0;
    nonFictionCount = 0;

    for (int i = 0; i < 4; ++i) {
        if (books[i].genre == "Fiction") {
            fiction[fictionCount++] = books[i];
        }
        else if (books[i].genre == "Non-Fiction") {
            nonFiction[nonFictionCount++] = books[i];
        }
    }
}

Book findEarliestBook(const Book category[], int count) {
    Book earliestBook = category[0];

    for (int i = 1; i < count; ++i) {
        if (category[i].publicationYear < earliestBook.publicationYear) {
            earliestBook = category[i];
        }
    }

    return earliestBook;
}

void displayDetails(const Book fiction[4], int fictionCount, const Book nonFiction[4], int nonFictionCount) {
    cout << "\nFiction Books:\n";
    for (int i = 0; i < fictionCount; ++i) {
        cout << "Title: " << fiction[i].title << "\tAuthor: " << fiction[i].author
            << "\tPublication Year: " << fiction[i].publicationYear << "\tGenre: " << fiction[i].genre << "\n";
    }

    Book earliestFiction = findEarliestBook(fiction, fictionCount);

    cout << "\nEarliest Published Fiction Book:\n";
    cout << "Title: " << earliestFiction.title << "\tAuthor: " << earliestFiction.author
        << "\tPublication Year: " << earliestFiction.publicationYear << "\tGenre: " << earliestFiction.genre << "\n";

    cout << "\nNon-Fiction Books:\n";
    for (int i = 0; i < nonFictionCount; ++i) {
        cout << "Title: " << nonFiction[i].title << "\tAuthor: " << nonFiction[i].author
            << "\tPublication Year: " << nonFiction[i].publicationYear << "\tGenre: " << nonFiction[i].genre << "\n";
    }

    Book earliestNonFiction = findEarliestBook(nonFiction, nonFictionCount);

    cout << "\nEarliest Published Non-Fiction Book:\n";
    cout << "Title: " << earliestNonFiction.title << "\tAuthor: " << earliestNonFiction.author
        << "\tPublication Year: " << earliestNonFiction.publicationYear << "\tGenre: " << earliestNonFiction.genre << "\n";
}

int main() {
    Book books[4];
    Book fiction[4];
    Book nonFiction[4];
    int fictionCount, nonFictionCount;

    inputDetails(books);
    categorizeBooks(books, fiction, nonFiction, fictionCount, nonFictionCount);
    displayDetails(fiction, fictionCount, nonFiction, nonFictionCount);

    return 0;
}