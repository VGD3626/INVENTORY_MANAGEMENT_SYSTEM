#include <bits/stdc++.h>
#define MAX_ITEMS 100
using namespace std;

class Item {
    private:
        int Id;
        string name="";
        double cost_price;
        double sell_price;
        int quantity;
    public:
        Item() {

        }
        Item(int Id, string name, double cost_price, double sell_price, int  quantity) {
            this->Id= Id;
            this->name= name;
            this->cost_price= cost_price;
            this->sell_price= sell_price;
            this->quantity= quantity;
        }
        void DisplayItem() {
            cout << Id << endl;
            cout << name << endl;
            cout << cost_price << endl;
            cout << sell_price << endl;
            cout << quantity << endl;
            return;
        }
        int getId() {return Id;}
        void change(int uq) {
            this->quantity= uq;
        }
};

class Inventory: public Item {
    private:
    int Total_items=0;
    map<int,Item> Items;
    public:
    void Display() {
        for(auto x: Items) {
            x.second.DisplayItem();
        }
    }
    void AddItem(int Id, string name, double cost_price, double sell_price, int  quantity) {
        Item i(Id, name, cost_price, sell_price, quantity);
        Items.insert({Id,i});
        Total_items++;
    }
    void RemoveItem(int Id) {
        auto it= Items.find(Id);
        if(it != Items.end())
            Items.erase(it);
    }
    void ChangeQty(int Id, int uq) {
        auto it= Items.find(Id);
        if(it != Items.end())
            Items[Id].change(uq);
        else 
            cout << "Invalid Item-Id" << endl;
    }
    void Reset() {
        Items.clear();
    }
};

int main() {

    Inventory INV1;

    cout << "________________________________________________________________________\n" << endl;
    cout << "-------------------WELCOME TO INVENTORY MANAGEMENT SYSTEM---------------" << endl;
    cout << "________________________________________________________________________\n" << endl;
    int code;
    int Id, quantity;
    double sell_price;
    double cost_price;
    string name;
    cout << "*Enter the code corresponding to following details:\n" << endl;
    cout << "code 1: To Display current Items in the Inventory..." << endl;
    cout << "code 2: For adding new Item into the Inventory" << endl;
    cout << "code 3: To change the quantity of Items present in the Inventory..." << endl;
    cout << "code 4: To remove an item from inventory" << endl;
    cout << "code 5: To exit from console" << endl;
    while(1) {
    cout << "Enter the code or command:" << endl;
    cin >> code;
        if(code==1) {
            INV1.Display();
        }
        else if(code==2) {
            cout << "Let us give some details regarding to Item you want to add:\n";
            cout << "Enter the Item-Id:" << endl;
            cin >> Id;
            cout << "Enter the Item-name:" << endl;
            cin >> name;
            cout << "Enter the quantity of Item:" << endl;
            cin >> quantity;
            cout << "What is the sell_price of new Item:" << endl;
            cin >> sell_price;
            cout << "Enter the cost at which you purchase the Item:" << endl;
            cin >> cost_price;
            INV1.AddItem(Id, name, cost_price, sell_price, quantity);
        }
        else if(code==3) {
            int UpdatedQty;
            cout << "Enter the Id of the Item whose quantity you want to change..." << endl;
            cin >> Id;
            cout << "Enter the Item-Id and updated quantity of Item respectively:" << endl;
            cin >> UpdatedQty;
            INV1.ChangeQty(Id,UpdatedQty);
        }
        else if(code==4) {
            cout << "Enter the Id of the Item you want to remove from inventory" << endl;
            cin >> Id;
            INV1.RemoveItem(Id);
        }
        else if(code==6)
            INV1.Reset();
        else if(code==5) {
            cout << "------------------------Thanks for visiting-----------------------" << endl;
            break;
        }
    }
}