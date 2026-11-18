# 🍽️ College Canteen Management System

## 1. Project Overview

The **College Canteen Management System** is a menu-driven C++ application designed to manage daily canteen operations.

It allows users to display food items, place orders, generate customer bills, and manage menu items. The system also uses file handling to store menu details and customer bills permanently.

The main objective of this project is to simplify canteen operations using basic C++ programming concepts, Object-Oriented Programming (OOP), vectors, structures, and file handling.

---

## 2. Features

- **Display Menu:** View all available food items and beverages with their prices.
- **Place Order:** Select items using their ID and specify the quantity.
- **Shopping Cart:** Store selected items temporarily before generating a bill.
- **Generate Bill:** Calculate the total amount based on item prices and quantities.
- **Save Bill:** Store customer bills permanently in a text file.
- **Add Menu Item:** Add new food items or beverages.
- **Update Price:** Modify the price of existing menu items.
- **Delete Item:** Remove unwanted items from the menu.
- **File Handling:** Automatically save and load menu information.

---

## 3. Technologies Used

| Technology | Purpose |
|---|---|
| C++ | Core programming language |
| OOP | Class and object implementation |
| STL Vector | Dynamic storage of menu and cart items |
| File Handling | Permanent data storage |
| Structures | Managing order information |
| iostream | Input and output operations |

---

## 4. Project Structure

```text
College-Canteen-Management/
│
├── main.cpp
│
├── menu.txt
│
├── bills.txt
│
└── README.md
```

**File Description:**

- `main.cpp` – Contains the complete source code.
- `menu.txt` – Stores menu items, IDs, prices, and categories.
- `bills.txt` – Stores generated customer bills.
- `README.md` – Contains project documentation.

*Note: The text files are automatically created when required by the program.*

---

## 5. Program Flow

```text
             START
               |
               v
       Create Canteen Object
               |
               v
        Load Menu From File
               |
       +-------+-------+
       |               |
   File Exists     File Missing
       |               |
   Read Menu       Create Default
       |             Menu
       +-------+-------+
               |
               v
          Main Menu
               |
               v
        Select Operation
               |
     +---------+----------+
     |         |          |
     v         v          v
 Display    Place      Manage
  Menu      Order       Menu
     |         |          |
     |         v          |
     |      Add Item      |
     |      To Cart       |
     |         |          |
     |         v          |
     |    Generate Bill   |
     |         |          |
     |         v          |
     |      Save Bill     |
     |         |          |
     +---------+----------+
               |
               v
       Update Menu File
       When Menu Changes
               |
               v
        Return To Main Menu
               |
               v
          Exit Selected?
           /       \
         No         Yes
         |           |
         v           v
      Main Menu     END
```

---

## 6. Working of the Project

### A. Menu Management

The `MenuItem` class stores the following information:

- Item ID
- Item Name
- Item Price
- Item Category

The system provides functions to add, display, update, and delete menu items.

### B. Order Management

The `OrderItem` structure stores:

- Item Name
- Item Price
- Quantity

The user selects an item using its ID and enters the required quantity.

The selected item is added to the cart using a vector.

### C. Bill Generation

The system calculates the amount of each item using:

**Amount = Price × Quantity**

The total bill is calculated by adding the amounts of all selected items.

**Total Bill = Sum of All Item Amounts**

### D. File Handling

The project uses two text files:

**1. menu.txt**

Stores menu information permanently.

Example:

```text
1|Sandwich|50|Food
2|Burger|80|Food
3|Pizza|100|Food
4|Tea|15|Beverage
```

**2. bills.txt**

Stores customer bill information.

The program uses:
- `ifstream` to read menu information.
- `ofstream` to write menu information.
- `ios::app` to append new bills without deleting previous bills.

---

## 7. OOP Concepts Used

### 1. Class and Object
The `MenuItem` and `Canteen` classes define the properties and functions of the system. Objects are created to access their functionality.

### 2. Constructor
Constructors initialize menu item details and automatically load menu data when the Canteen object is created.

### 3. Encapsulation
Data and related member functions are grouped inside classes. In this implementation, the menu data members are public.

### 4. Data Structures
Structures and vectors are used to organize and dynamically store menu and order information.

---

## 8. How to Run the Project

**Step 1:** Clone the repository.

```bash
git clone YOUR_GITHUB_REPOSITORY_LINK
```

**Step 2:** Open the project folder.

```bash
cd College-Canteen-Management
```

**Step 3:** Compile the program using a C++ compiler.

```bash
g++ main.cpp -o canteen
```

**Step 4:** Run the program.

Windows:

```bash
canteen.exe
```

Linux:

```bash
./canteen
```

---

## 9. Sample Menu

```text
====================================
    COLLEGE CANTEEN MANAGEMENT
====================================
1. Display Menu
2. Place Order
3. Display Bill
4. Save Bill
5. Add Menu Item
6. Update Item Price
7. Delete Menu Item
8. Exit

Enter Your Choice: 1

========== CANTEEN MENU ==========
ID      ITEM                CATEGORY       PRICE
1       Sandwich            Food           Rs. 50
2       Burger              Food           Rs. 80
3       Pizza               Food           Rs. 100
4       Tea                 Beverage       Rs. 15
5       Coffee              Beverage       Rs. 25
```

---

## 10. Advantages

- Simple and user-friendly interface.
- Reduces manual calculations.
- Supports dynamic menu management.
- Maintains permanent menu records.
- Saves previous customer bills.
- Demonstrates practical applications of C++ concepts.

---

## 11. Future Improvements

- Add customer login and authentication.
- Add different user roles for admin and customers.
- Implement payment management.
- Add inventory and stock management.
- Generate detailed sales reports.
- Develop a graphical user interface (GUI).
- Integrate a database for better data management.

---

## 12. Conclusion

The College Canteen Management System demonstrates how C++ programming concepts can be used to develop a simple real-world management application.

It combines Object-Oriented Programming, vectors, structures, and file handling to manage menu items, customer orders, and billing operations efficiently.

The project provides a foundation for developing more advanced canteen management applications.

---

## 👨‍💻 Project Information

**Project Name:** College Canteen Management System  
**Language:** C++  
**Project Type:** Console-Based Application  
**Domain:** Management System  
**Storage:** Text File Handling

**Developed as an academic C++ project.**