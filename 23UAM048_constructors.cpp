#include <iostream>
#include <cstring>  // For strcpy and strlen

class Book {
private:
    char* title;		//title of the book
    char* author;		//author name of the book
    int pageCount;		//page count
    bool formatType;  // true = hardcover, false = paperback
    float* chapterPages;		//array of pages of chapter
    int numChapters;

public:
    // Default Constructor
    Book() {
        title = new char[1];
        title[0] = '\0';

        author = new char[1];
        author[0] = '\0';

        pageCount = 0;
        formatType = false;
        numChapters = 0;
        chapterPages = NULL;
    }

    // Parameterized Constructor
    Book(const char* t, const char* a, int pCount, bool format, int chapters)
        : pageCount(pCount), formatType(format), numChapters(chapters) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);

        author = new char[strlen(a) + 1];
        strcpy(author, a);

        if (numChapters > 0) {
            chapterPages = new float[numChapters];

            // Distribute pages uniformly
            float avgPages = (numChapters > 0) ? static_cast<float>(pageCount) / numChapters : 0;
            for (int i = 0; i < numChapters; i++) {
                chapterPages[i] = avgPages;
            }
        } else {
            chapterPages = NULL;
        }
    }

    // Copy Constructor (Deep Copy)
    Book(const Book& other)
        : pageCount(other.pageCount), formatType(other.formatType), numChapters(other.numChapters) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);

        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);

        if (numChapters > 0) {
            chapterPages = new float[numChapters];
            for (int i = 0; i < numChapters; i++) {
                chapterPages[i] = other.chapterPages[i];
            }
        } else {
            chapterPages = NULL;
        }
    }

    // Destructor
    ~Book() {
        delete[] title;
        delete[] author;
        delete[] chapterPages;
    }

    // Display Book Information
    void display() const {
        std::cout << "Title: " << title << "\n";
        std::cout << "Author: " << author << "\n";
        std::cout << "Page Count: " << pageCount << "\n";
        std::cout << "Format: " << (formatType ? "Hardcover" : "Paperback") << "\n";
        std::cout << "Number of Chapters: " << numChapters << "\n";
        if (numChapters > 0) {
            std::cout << "Chapter Pages: ";
            for (int i = 0; i < numChapters; i++) {
                std::cout << chapterPages[i] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    // Using Default Constructor
    Book book1;
    book1.display();
    
    std::cout << "\n";

    // Using Parameterized Constructor
    Book book2("C++ Programming", "Bjarne Stroustrup", 500, true, 10);
    book2.display();
    
    std::cout << "\n";

    // Using Copy Constructor
    Book book3(book2);
    book3.display();

    return 0;
}
