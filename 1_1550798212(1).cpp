#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef long long x;
string name = "A71,Iphonex,Nokia";
string company = "Samsung,Apple,Microsoft";
///////////////////////////////////////////
enum Ram
{
    R_2GB,
    R_4GB,
    R_6GB,
    R_8GB,

    R_12GB,
    R_16GB,
    R_32GB,
    R_64GB
};
enum OS
{
    iOS,
    Android,
    Windowsphone
};
enum Storage
{
    S_16GB,
    S_32GB,
    S_64GB,
    S_128GB,
    S_256GB,
    S_512GB,
    S_1TB,
    S_2TB
};
enum Color
{
    black,
    white,
    rosgold,
    silver
};
struct mobile
{
    string name;
    string company;
    x price;
    Ram mobileRam;
    OS mobileOs;
    Storage mobileStorage;
    Color mobileColor;
    int NumberOfAvailable = 0;
    int NumberOfSold = 0;
};
struct mobileShop
{
    int capacity = 0;
    mobile *mobileArray = new mobile[capacity];
} shop;
///////////////////////////////////////////////
void print_rams()
{
    cout << "The list of Rams:\n";
    cout << "1- 2GB\n2- 4GB\n3- 6GB\n4- 8GB\n5- 12GB\n6- 16GB\n7- 32GB\n8- 64GB\n";
    cout << "Choose the Ram: ";
}
////////////////////////////////////////////////////
void print_storage()
{
    cout << "The list of Rams:\n";
    cout << "1- 16GB\n2- 32GB\n3- 64GB\n4- 128GB\n5- 256GB\n6- 512GB\n7- 1TB\n8- 2TB\n";
    cout << "Choose the Ram: ";
}
////////////////////////////////////////////////////
void print_color()
{
    cout << "The list of OS:\n";
    cout << "1- white\n2- black\n3- resgold\n4-silver\n";
    cout << "Choose the OS: ";
}
////////////////////////////////////////////////////
void print_OS()
{
    cout << "The list of OS:\n";
    cout << "1- iOS\n2- Android\n3- WindowsPhone\n";
    cout << "Choose the OS: ";
}
////////////////////////////////////////////////////
void add_phone()
{
    mobile newMobile;
    cout << "Enter mobile name: ";
    cin >> newMobile.name;
    cout << "Enter mobile company: ";
    cin >> newMobile.company;
    cout << "Enter the mobile price: ";
    cin >> newMobile.price;
    int input;
    bool flag = true;
    while (flag)
    {
        flag = false;
        print_rams();
        cin >> input;
        switch (input)
        {
        case 1:
            newMobile.mobileRam = R_2GB;
            break;
        case 2:
            newMobile.mobileRam = R_4GB;
            break;
        case 3:
            newMobile.mobileRam = R_6GB;
            break;
        case 4:
            newMobile.mobileRam = R_8GB;
            break;
        case 5:
            newMobile.mobileRam = R_12GB;
            break;
        case 6:
            newMobile.mobileRam = R_16GB;
            break;
        case 7:
            newMobile.mobileRam = R_32GB;
            break;
        case 8:
            newMobile.mobileRam = R_64GB;
            break;
        default:
            flag = true;
            cout << "wrong number!\n";
            break;
        }
    }
    ////////////////////////////////////////////////////
    // OS
    flag = true;
    while (flag)
    {
        print_OS();
        flag = false;
        cin >> input;
        switch (input)
        {
        case 1:
            newMobile.mobileOs = iOS;
            break;
        case 2:
            newMobile.mobileOs = Android;
            break;
        case 3:
            newMobile.mobileOs = Windowsphone;
            break;
        default:
            flag = true;
            cout << "wrong number!\n";
            break;
        }
    }
    ////////////////////////////////////////////////////
    // storage
    flag = true;
    while (flag)
    {
        print_storage();
        flag = false;
        cin >> input;
        switch (input)
        {
        case 1:
            newMobile.mobileStorage = S_16GB;
            break;
        case 2:
            newMobile.mobileStorage = S_32GB;
            break;
        case 3:
            newMobile.mobileStorage = S_64GB;
            break;
        case 4:
            newMobile.mobileStorage = S_128GB;
            break;
        case 5:
            newMobile.mobileStorage = S_256GB;
            break;
        case 6:
            newMobile.mobileStorage = S_512GB;
            break;
        case 7:
            newMobile.mobileStorage = S_1TB;
            break;
        case 8:
            newMobile.mobileStorage = S_2TB;
            break;
        default:
            flag = true;
            cout << "wrong number!\n";
            break;
        }
    }
    ////////////////////////////////////////////////////
    // color
    flag = true;
    while (flag)
    {
        print_color();
        flag = false;
        cin >> input;
        switch (input)
        {
        case 1:
            newMobile.mobileColor = white;
            break;
        case 2:
            newMobile.mobileColor = black;
            break;
        case 3:
            newMobile.mobileColor = rosgold;
            break;
        case 4:
            newMobile.mobileColor = silver;
            break;
        default:
            flag = true;
            cout << "wrong number!\n";
            break;
        }
    }
    ////////////////////////////////////////////////////
    // numberOFAvailable
    cout << "Enter the number of available phones: ";
    cin >> newMobile.NumberOfAvailable;
    // extend the mobileArray
    shop.capacity++;
    mobile *newMobileArray = new mobile[shop.capacity];
    mobile *temp = shop.mobileArray;
    for (int i = 0; i < shop.capacity - 1; i++)
        newMobileArray[i] = shop.mobileArray[i];
    newMobileArray[shop.capacity - 1] = newMobile;
    shop.mobileArray = newMobileArray;
    delete[] temp;
}
///////////////////////////////////////////////////////
void print_array()
{
    for (int i = 0; i < shop.capacity; i++)
    {
        cout << i + 1 << shop.mobileArray[i].name << " " << shop.mobileArray[i].company << " " << shop.mobileArray[i].price << " "
             << shop.mobileArray[i].mobileColor << " " << shop.mobileArray[i].mobileOs << " " << shop.mobileArray[i].mobileRam << " "
             << shop.mobileArray[i].mobileStorage << " " << shop.mobileArray[i].NumberOfAvailable << " " << shop.mobileArray[i].NumberOfSold;
        cout << endl;
        print_rams();
        cout << endl;
        print_OS();
        cout << endl;
        print_storage();
        cout << endl;
        print_color();
        cout << endl;
    }
}
///////////////////////////////////////////////////////
void print_index()
{
    for (int i = 0; i < shop.capacity; i++)
    {
        cout << i + 1 << ". " << shop.mobileArray[i].name << " " << shop.mobileArray[i].company << endl;
    }
}
///////////////////////////////////////////////////////
void remove_phone()
{
    bool flag = true;
    while (flag)
    {
        print_index();
        int index;
        cout << "Enter the index to remove: \n";
        cin >> index;
        int i;
        for (i = 0; i < shop.capacity; i++)
        {

            if (i == index)
            {
                flag = false;
            }
        }
        if (index != -1)
        {
            for (i = index; i < shop.capacity - 1; i++)
            {
                shop.mobileArray[i] = shop.mobileArray[i + 1];
            }
            (shop.capacity)--;
        }
    }
}
//////////////////////////////////////////////////////////////
void sort_by_price()
{
    mobile temp;
    for (int i = 0; i < shop.capacity; i++)
    {
        for (int j = 0; j < shop.mobileArray[i].price; j++)
        {
            if (shop.mobileArray[i].price > shop.mobileArray[i + 1].price)
            {
                temp = shop.mobileArray[i];
                shop.mobileArray[i] = shop.mobileArray[i + 1];
                shop.mobileArray[i + 1] = temp;
            }
        }
    }
}
/////////////////////////////////////////////////////////////
void search()
{
    string namemob, nameofcompany;
    cout << "Enter name of the mobile: \n";
    cin >> namemob;
    cout << "Enter name of the coompany: \n";
    cin >> nameofcompany;
    for (int i = 0; i < shop.capacity; i++)
    {
        if (namemob == shop.mobileArray[i].name && nameofcompany == shop.mobileArray[i].company)
        {
            cout << i + 1 << shop.mobileArray[i].name << " " << shop.mobileArray[i].company << " " << shop.mobileArray[i].price << " "
                 << shop.mobileArray[i].mobileColor << " " << shop.mobileArray[i].mobileOs << " " << shop.mobileArray[i].mobileRam << " "
                 << shop.mobileArray[i].mobileStorage << " " << shop.mobileArray[i].NumberOfAvailable << " " << shop.mobileArray[i].NumberOfSold;
            cout << endl;
            print_rams();
            cout << endl;
            print_OS();
            cout << endl;
            print_storage();
            cout << endl;
            print_color();
            cout << endl;
        }
    }
}
/////////////////////////////////////////////////////////////
void sell_a_phone()
{
    bool flag = true;
    while (flag)
    {
        print_index();
        int index;
        cout << "Enter the index to search for sell: \n";
        cin >> index;
        int i;
        for (i = 0; i < shop.capacity; i++)
        {

            if (i == index)
            {
                flag = false;
            }
        }
        if (index != -1)
        {
            for (i = index; i < shop.capacity - 1; i++)
            {
                shop.mobileArray[i] = shop.mobileArray[i + 1];
            }
            shop.mobileArray[i].NumberOfAvailable--;
            shop.mobileArray[i].NumberOfSold++;
        }
    }
}
////////////////////////////////////////////////////////////////////
void most_sold_item()
{
    for (int i = 0; i < shop.capacity; i++)
    {
        for (int j = 0; j < shop.capacity - i - 1; j++)
        {
            if (shop.mobileArray[j].NumberOfSold > shop.mobileArray[j + 1].NumberOfSold)
            {
                swap(shop.mobileArray[j].NumberOfSold, shop.mobileArray[j + 1].NumberOfSold);
            }
        }
    }
}
////////////////////////////////////////////////////////////////////
void menu2()
{
    cout << "1.Change OS\n"
         << "2.Change Ram\n"
         << "3.Change Storage\n"
         << "4.Change Price\n"
         << "5.Change Color\n"
         << "6.Change NumberOfAvailable\n"
         << "7.Change NumberOfSold \n";
}
////////////////////////////////////////////////////////////////////
void change_mobile_info()
{
    menu2();
    fstream phone("mobile.txt", ios::ate);
    if (phone)
    {
        print_index();
        int index;
        cout << "Enter the index to search: \n";
        cin >> index;
        int i;
        for (i = 0; i < shop.capacity; i++)
        {
            int c;
            cout << "your choice:";
            cin >> c;
            switch (c)
            {
            case 1:
                print_OS();
                break;
            case 2:
                print_rams();
                break;
            case 3:
                print_storage();
                break;
            case 4:
                cout << shop.mobileArray[i].price << endl;
                break;
            case 5:
                print_color();
                break;
            case 6:
                cout << shop.mobileArray[i].NumberOfAvailable << endl;
                break;
            case 7:
                cout << shop.mobileArray[i].NumberOfSold << endl;
                break;
            }
        }
    }
    else
    {
        cout << "error!" << '\n';
    }
}
////////////////////////////////////////////////////////////////////
void writeinfo()
{
    ifstream phone("mobile.txt", ios::out);
    if (phone)
    {
        for (int i = 0; i < shop.capacity; i++)
        {
            cout << i << ")" << endl;
            cout << shop.mobileArray[i].name << endl;
            cout << shop.mobileArray[i].company << endl;
            cout << shop.mobileArray[i].NumberOfAvailable << endl;
            cout << shop.mobileArray[i].NumberOfSold << endl;
            cout << shop.mobileArray[i].price << endl;
            print_rams();
            cout << endl;
            print_OS();
            cout << endl;
            print_storage();
            cout << endl;
            print_color();
            cout << endl;
        }
    }
    else
    {
        cout << "error!" << '\n';
    }
}
////////////////////////////////////////////////////////////////////
void menu()
{
    cout << "1.Add a phone\n";
    cout << "2.Remove a phone\n";
    cout << "3.Sort phones by price\n";
    cout << "4.Search a phone\n";
    cout << "5.Change mobile info\n";
    cout << "6.Sell a phone\n";
    cout << "7.Print phones\n";
    cout << "8.Print phones sorted by the most sold to the least\n";
    cout << "9.Quit\n";
}
////////////////////////////////////////////////////////////////////
int main()
{
    while (true)
    {
        menu();
        int c;
        cout << "Your choice: \n";
        cin >> c;
        switch (c)
        {
        case 1:
            add_phone();
            system("pause");
            break;
        case 2:
            remove_phone();
            system("pause");
            break;
        case 3:
            sort_by_price();
            system("pause");
            break;
        case 4:
            search();
            system("pause");
            break;
        case 5:
            change_mobile_info();
            system("pause");
            break;
        case 6:
            sell_a_phone();
            system("pause");
            break;
        case 7:
            print_array();
            break;
        case 8:

            break;
        default:
            writeinfo();
            // cout << "worng choice! try again";
            break;
        }
    }
    return 0;
}