
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

// Menu Item Class
class MenuItem {
public:
    int id;
    string name;
    float price;
    string category;

    MenuItem(int i, string n, float p, string c) {
        id = i;
        name = n;
        price = p;
        category = c;
    }

    void display() {
        cout << left << setw(8) << id << setw(20) << name
             << setw(15) << category << "Rs. " << price << endl;
    }
};

// Order Structure
struct OrderItem {
    string name;
    float price;
    int quantity;

    float getAmount() {
        return price * quantity;
    }
};

// Canteen Management Class
class Canteen {
public:
    vector<MenuItem> menu;

    Canteen() {
        loadMenu();
    }

    // Load Menu From File
    void loadMenu() {
        ifstream file("menu.txt");
        string line;

        if (!file) {
            menu.push_back(MenuItem(1, "Sandwich", 50, "Food"));
            menu.push_back(MenuItem(2, "Burger", 80, "Food"));
            menu.push_back(MenuItem(3, "Pizza", 100, "Food"));
            menu.push_back(MenuItem(4, "Tea", 15, "Beverage"));
            menu.push_back(MenuItem(5, "Coffee", 25, "Beverage"));
            saveMenu();
            return;
        }

        while (getline(file, line)) {
            stringstream ss(line);
            int id;
            string name, category, temp;
            float price;

            getline(ss, temp, '|');
            id = stoi(temp);
            getline(ss, name, '|');
            getline(ss, temp, '|');
            price = stof(temp);
            getline(ss, category);

            menu.push_back(MenuItem(id, name, price, category));
        }
        file.close();
    }

    // Save Menu In File
    void saveMenu() {
        ofstream file("menu.txt");

        for (int i = 0; i < menu.size(); i++) {
            file << menu[i].id << "|" << menu[i].name << "|"
                 << menu[i].price << "|" << menu[i].category << endl;
        }
        file.close();
    }

    // Display Menu
    void displayMenu() {
        cout << "\n========== CANTEEN MENU ==========\n";
        cout << left << setw(8) << "ID" << setw(20) << "ITEM"
             << setw(15) << "CATEGORY" << "PRICE\n";

        for (int i = 0; i < menu.size(); i++)
            menu[i].display();
    }

    // Find Item
    int findItem(int id) {
        for (int i = 0; i < menu.size(); i++) {
            if (menu[i].id == id)
                return i;
        }
        return -1;
    }

    // Add New Item
    void addItem() {
        string name, category;
        float price;
        int id, choice;

        cout << "\nEnter Item Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Price: ";
        cin >> price;

        if (price <= 0 || name.empty()) {
            cout << "Invalid Details!\n";
            return;
        }

        cout << "\n1. Food\n2. Beverage\n";
        cout << "Enter Category: ";
        cin >> choice;

        if (choice == 1)
            category = "Food";
        else if (choice == 2)
            category = "Beverage";
        else {
            cout << "Invalid Category!\n";
            return;
        }

        id = 1;
        for (int i = 0; i < menu.size(); i++) {
            if (menu[i].id >= id)
                id = menu[i].id + 1;
        }

        menu.push_back(MenuItem(id, name, price, category));
        saveMenu();
        cout << "\nItem Added Successfully!\n";
    }

    // Update Item Price
    void updateItem() {
        int id;
        float price;

        displayMenu();
        cout << "\nEnter Item ID: ";
        cin >> id;

        int index = findItem(id);

        if (index == -1) {
            cout << "Item Not Found!\n";
            return;
        }

        cout << "Enter New Price: ";
        cin >> price;

        if (price <= 0) {
            cout << "Invalid Price!\n";
            return;
        }

        menu[index].price = price;
        saveMenu();
        cout << "\nPrice Updated Successfully!\n";
    }

    // Delete Item
    void deleteItem() {
        int id;
        displayMenu();

        cout << "\nEnter Item ID: ";
        cin >> id;

        int index = findItem(id);

        if (index == -1) {
            cout << "Item Not Found!\n";
            return;
        }

        menu.erase(menu.begin() + index);
        saveMenu();
        cout << "\nItem Deleted Successfully!\n";
    }

    // Place Order
    void placeOrder(vector<OrderItem>& cart) {
        int id, quantity;
        displayMenu();

        cout << "\nEnter Item ID: ";
        cin >> id;

        int index = findItem(id);

        if (index == -1) {
            cout << "Item Not Found!\n";
            return;
        }

        cout << "Enter Quantity: ";
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Invalid Quantity!\n";
            return;
        }

        OrderItem item;
        item.name = menu[index].name;
        item.price = menu[index].price;
        item.quantity = quantity;

        cart.push_back(item);
        cout << "\nItem Added To Cart!\n";
    }

    // Display Bill
    float displayBill(vector<OrderItem>& cart) {
        float total = 0;

        if (cart.empty()) {
            cout << "\nCart Is Empty!\n";
            return 0;
        }

        cout << "\n========== CUSTOMER BILL ==========\n";
        cout << "Item\t\tQuantity\tAmount\n";

        for (int i = 0; i < cart.size(); i++) {
            float amount = cart[i].getAmount();
            cout << cart[i].name << "\t\t" << cart[i].quantity
                 << "\t\t" << amount << endl;
            total += amount;
        }

        cout << "-----------------------------------\n";
        cout << "Total Amount: Rs. " << total << endl;
        return total;
    }

    // Save Bill
    void saveBill(vector<OrderItem>& cart) {
        if (cart.empty()) {
            cout << "\nCart Is Empty!\n";
            return;
        }

        float total = 0;
        ofstream file("bills.txt", ios::app);

        if (!file) {
            cout << "Cannot Save Bill!\n";
            return;
        }

        file << "\n========== CANTEEN BILL ==========\n";

        for (int i = 0; i < cart.size(); i++) {
            float amount = cart[i].getAmount();
            file << cart[i].name << " | Quantity: " << cart[i].quantity
                 << " | Amount: Rs. " << amount << endl;
            total += amount;
        }

        file << "Total Amount: Rs. " << total << endl;
        file << "==================================\n";
        file.close();

        cout << "\nBill Saved Successfully!\n";
        cart.clear();
    }
};

// Main Function
int main() {
    Canteen c;
    vector<OrderItem> cart;
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "    COLLEGE CANTEEN MANAGEMENT\n";
        cout << "====================================\n";
        cout << "1. Display Menu\n";
        cout << "2. Place Order\n";
        cout << "3. Display Bill\n";
        cout << "4. Save Bill\n";
        cout << "5. Add Menu Item\n";
        cout << "6. Update Item Price\n";
        cout << "7. Delete Menu Item\n";
        cout << "8. Exit\n";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                c.displayMenu();
                break;
            case 2:
                c.placeOrder(cart);
                break;
            case 3:
                c.displayBill(cart);
                break;
            case 4:
                c.saveBill(cart);
                break;
            case 5:
                c.addItem();
                break;
            case 6:
                c.updateItem();
                break;
            case 7:
                c.deleteItem();
                break;
            case 8:
                cout << "\nThank You For Using Our System!\n";
                break;
            default:
                cout << "\nInvalid Choice!\n";
        }
    } while (choice != 8);

    return 0;
}
