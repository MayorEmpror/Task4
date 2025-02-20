#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    private:
        string accountHolderName;
        int accountID;
        float balance;

    public:
       
        BankAccount(int id, float initialBalance, string name) {
            accountID = id;
            accountHolderName = name;
            balance = initialBalance;
        }

        
        void credit(float amount) {
            if (amount > 0) {
                balance += amount;
                cout << "Successfully credited " << amount << " to the account." << endl;
            } else {
                cout << "Invalid deposit amount." << endl;
            }
        }

       
        void debit(float amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Successfully debited " << amount << " from the account." << endl;
            } else if (amount > balance) {
                cout << "Insufficient balance for withdrawal." << endl;
            } else {
                cout << "Invalid withdrawal amount." << endl;
            }
        }

       
        float getBalance() const {
            return balance;
        }

     
        void printAccountDetails() const {
            cout << "Account ID: " << accountID << endl;
            cout << "Account Holder: " << accountHolderName << endl;
            cout << "Current Balance: $" << balance << endl;
        }
};

int main() {
   
    BankAccount account(1, 500.0, "John Doe");

   
    account.printAccountDetails();

  
    account.credit(100.0);
    cout << "Updated Balance: $" << account.getBalance() << endl;

   
    account.debit(50.0);
    cout << "Updated Balance: $" << account.getBalance() << endl;

   
    account.debit(600.0);

    return 0;
}
