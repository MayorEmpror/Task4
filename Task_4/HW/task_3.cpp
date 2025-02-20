#include <iostream>
#include <string>
using namespace std;

class Invoice {
    private:
        string partNumber;
        string partDescription;
        int quantity;
        double pricePerItem;

    public:
       
        Invoice(string partNum, string partDesc, int qty, double price) {
            partNumber = partNum;
            partDescription = partDesc;
            quantity = (qty > 0) ? qty : 0;  
            pricePerItem = (price > 0) ? price : 0.0;  
        }

       
        double getInvoiceAmount() const {
            return quantity * pricePerItem;
        }

       
        void printInvoiceDetails() const {
            cout << "Part Number: " << partNumber << endl;
            cout << "Part Description: " << partDescription << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "Price per Item: $" << pricePerItem << endl;
            cout << "Total Invoice Amount: $" << getInvoiceAmount() << endl;
        }
};

int main() {
   
    Invoice invoice("A123", "Hammer", 5, 12.50);

   
    invoice.printInvoiceDetails();

    return 0;
}
