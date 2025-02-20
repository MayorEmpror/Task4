#include <iostream>
#include <string>
#include <limits>

using namespace std;


class MenuItem {
public:
    string name;
    string type;  
    double price;


    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};


class CoffeeShop {
private:
    string name;                         
    MenuItem** menu;                    
    string* orders;                      
    int menuSize;                       
    int orderCount;                       

public:

    CoffeeShop(string shopName, int menuSize) : name(shopName), menuSize(menuSize), orderCount(0) {
        menu = new MenuItem*[menuSize];  
        orders = new string[menuSize];   
    }


    ~CoffeeShop() {
        delete[] orders;
        for (int i = 0; i < menuSize; ++i) {
            delete menu[i]; 
        }
        delete[] menu;
    }

  
    void addMenuItem(int index, MenuItem* item) {
        if (index >= 0 && index < menuSize) {
            menu[index] = item;
        }
    }

   
    string addOrder(string itemName) {
        for (int i = 0; i < menuSize; ++i) {
            if (menu[i] != nullptr && menu[i]->name == itemName) {
                if (orderCount < menuSize) {
                    orders[orderCount++] = itemName;
                    return "Order for " + itemName + " has been added.";
                }
                return "Order array is full.";
            }
        }
        return "This item is currently unavailable.";
    }


    string fulfillOrder() {
        if (orderCount > 0) {
            string fulfilledOrder = orders[0];
            for (int i = 1; i < orderCount; ++i) {
                orders[i - 1] = orders[i];
            }
            orderCount--;
            return "The " + fulfilledOrder + " is ready.";
        }
        return "All orders have been fulfilled.";
    }

   
    void listOrders() {
        if (orderCount == 0) {
            cout << "No orders yet." << endl;
            return;
        }
        cout << "Orders: ";
        for (int i = 0; i < orderCount; ++i) {
            cout << orders[i] << " ";
        }
        cout << endl;
    }

   
    double dueAmount() {
        double total = 0;
        for (int i = 0; i < orderCount; ++i) {
            for (int j = 0; j < menuSize; ++j) {
                if (menu[j] != nullptr && menu[j]->name == orders[i]) {
                    total += menu[j]->price;
                    break;
                }
            }
        }
        return total;
    }

   
    string cheapestItem() {
        if (menuSize == 0) return "";
        double minPrice = numeric_limits<double>::infinity();
        string cheapest;
        for (int i = 0; i < menuSize; ++i) {
            if (menu[i] != nullptr && menu[i]->price < minPrice) {
                minPrice = menu[i]->price;
                cheapest = menu[i]->name;
            }
        }
        return cheapest;
    }

   
    void drinksOnly() {
        cout << "Drinks: ";
        for (int i = 0; i < menuSize; ++i) {
            if (menu[i] != nullptr && menu[i]->type == "drink") {
                cout << menu[i]->name << " ";
            }
        }
        cout << endl;
    }

  
    void foodOnly() {
        cout << "Foods: ";
        for (int i = 0; i < menuSize; ++i) {
            if (menu[i] != nullptr && menu[i]->type == "food") {
                cout << menu[i]->name << " ";
            }
        }
        cout << endl;
    }

  
    string getName() {
        return name;
    }
};


int main() {
   
    CoffeeShop shop("The Cozy Cafe", 4);

    
    shop.addMenuItem(0, new MenuItem("Espresso", "drink", 3.50));
    shop.addMenuItem(1, new MenuItem("Latte", "drink", 4.50));
    shop.addMenuItem(2, new MenuItem("Croissant", "food", 2.00));
    shop.addMenuItem(3, new MenuItem("Sandwich", "food", 5.00));

  
    cout << "Welcome to " << shop.getName() << "!" << endl;

    
    cout << shop.addOrder("Espresso") << endl;
    cout << shop.addOrder("Croissant") << endl;
    cout << shop.addOrder("Pancakes") << endl;  

    
    cout << shop.fulfillOrder() << endl;  

  
    shop.listOrders();

   
    cout << "Total Amount Due: $" << shop.dueAmount() << endl;

   
    cout << "The cheapest item is: " << shop.cheapestItem() << endl;

   
    shop.drinksOnly();
    shop.foodOnly();

    return 0;
}
