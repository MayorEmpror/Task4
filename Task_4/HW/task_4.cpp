#include <iostream>
#include <string>
using namespace std;


class Book {
    public:
        string title;
        string author;
        string stockPosition;
        string publisher;
        int stock;
        double price;

       
        Book() {
            title = "";
            author = "";
            stockPosition = "";
            publisher = "";
            stock = 0;
            price = 0.0;
        }

        // Constructor with parameters
        Book(string t, string a, string sp, string p, int s, double pr)
            : title(t), author(a), stockPosition(sp), publisher(p), stock(s), price(pr) {}

        // Function to display book details
        void displayBookDetails() const {
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Stock Position: " << stockPosition << endl;
            cout << "Price: $" << price << endl;
            cout << "Available Stock: " << stock << endl;
        }
};



class Inventory {
    private:
        Book* books;      
        int numBooks;     

    public:
        
        Inventory(Book books[], int numBooks) {
            this->books = new Book[numBooks];
            this->numBooks = numBooks;
            for (int i = 0; i < numBooks; ++i) {
                this->books[i] = books[i];  
            }
        }

       
        ~Inventory() {
            delete[] books;
        }

       
        Book* searchBook(string title, string author) {
            for (int i = 0; i < numBooks; ++i) {
                if (books[i].title == title && books[i].author == author) {
                    return &books[i]; 
                }
            }
            return nullptr; 
        }

        
        void processSale(string title, string author, int requestedCopies) {
            Book* foundBook = searchBook(title, author);
            if (foundBook) {
                foundBook->displayBookDetails();
                if (foundBook->stock >= requestedCopies) {
                    double totalCost = requestedCopies * foundBook->price;
                    cout << "Total cost for " << requestedCopies << " copies: $" << totalCost << endl;
                    foundBook->stock -= requestedCopies; 
                } else {
                    cout << "Required copies not in stock. Only " << foundBook->stock << " copies are available." << endl;
                }
            } else {
                cout << "Book not available in the inventory." << endl;
            }
        }
};

int main() {
    
    Book books[] = {
        Book("C++ Programming", "Bjarne Stroustrup", "Shelf A1", "Pearson", 10, 49.99),
        Book("Data Structures", "Mark Allen Weiss", "Shelf B3", "Addison-Wesley", 5, 39.99),
        Book("Algorithms", "Robert Sedgewick", "Shelf C2", "Prentice Hall", 3, 59.99)
    };

   
    Inventory inventory(books, 3);

  
    string title, author;
    int requestedCopies;

    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);

    cout << "Enter number of copies required: ";
    cin >> requestedCopies;

   
    inventory.processSale(title, author, requestedCopies);

    return 0;
}
