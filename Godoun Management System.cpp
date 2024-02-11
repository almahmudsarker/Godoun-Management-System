#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

// Define the structure for an inventory item
struct InventoryItem {
    string itemName;
    int quantity;
    double price;
};

// Function to display the main menu
void displayMenu() {
    cout << "\n===== Godoun Management System =====\n";
    cout << "1. Add Item\n";
    cout << "2. Update Item\n";
    cout << "3. View Inventory\n";
    cout << "4. Exit\n";
}

// Function to add an item to the inventory
void addItem(vector<InventoryItem>& inventory) {
    InventoryItem newItem;
    cout << "\nEnter Item Name: ";
    cin.ignore();
    getline(cin, newItem.itemName);
    cout << "Enter Quantity: ";
    cin >> newItem.quantity;
    cout << "Enter Price: $";
    cin >> newItem.price;

    // Add the new item to the inventory
    inventory.push_back(newItem);

    cout << "Item added successfully!\n";
}

// Function to update an item in the inventory
void updateItem(vector<InventoryItem>& inventory) {
    cout << "\nEnter the index of the item to update (starting from 0): ";
    int index;
    cin >> index;

    if (index >= 0 && index < inventory.size()) {
        InventoryItem& itemToUpdate = inventory[index];
        cout << "Enter new quantity: ";
        cin >> itemToUpdate.quantity;
        cout << "Enter new price: $";
        cin >> itemToUpdate.price;

        cout << "Item updated successfully!\n";
    } else {
        cout << "Invalid index. No item updated.\n";
    }
}

// Function to view the inventory
void viewInventory(const vector<InventoryItem>& inventory) {
    cout << "\n===== Inventory List =====\n";
    cout << setw(20) << "Item Name" << setw(15) << "Quantity" << setw(15) << "Price\n";

    for (const auto& item : inventory) {
        cout << setw(20) << item.itemName << setw(15) << item.quantity << setw(15) << fixed << setprecision(2) << item.price << endl;
    }
}

// Function to save the inventory to a file
void saveInventory(const vector<InventoryItem>& inventory) {
    ofstream outputFile("inventory.txt");

    for (const auto& item : inventory) {
        outputFile << item.itemName << " " << item.quantity << " " << item.price << endl;
    }

    outputFile.close();
}

// Function to load the inventory from a file
void loadInventory(vector<InventoryItem>& inventory) {
    ifstream inputFile("inventory.txt");

    if (inputFile.is_open()) {
        InventoryItem newItem;
        while (inputFile >> newItem.itemName >> newItem.quantity >> newItem.price) {
            inventory.push_back(newItem);
        }

        inputFile.close();
    }
}

int main() {
    vector<InventoryItem> inventory;

    // Load inventory from file at the beginning
    loadInventory(inventory);

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(inventory);
                break;
            case 2:
                updateItem(inventory);
                break;
            case 3:
                viewInventory(inventory);
                break;
            case 4:
                // Save inventory to file before exiting
                saveInventory(inventory);
                cout << "Exiting the program. Inventory saved.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}


// cd "E:\Projects\Godoun Management System\" ; if ($?) { g++ "Godoun Management System.cpp" -o "Godoun Management System" } ; if ($?) { .\"Godoun Management System" }
