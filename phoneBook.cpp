#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class PhoneBook
{
private:
    string name;
    string number;
    string email;

public:
    // declare a static variable

    void getDetails()
    {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter number: ";
        getline(cin, number);
        cout << "Enter email: ";
        getline(cin, email);
    }

    void saveDetails()
    {

        // open file in append mode
        ofstream out;

        out.open("phoneBook.csv", ios::app);

        // out<<"Name"<<","<<"Number"<<","<<"Email"<<endl;
        out << name << "," << email << "," << number << endl;
        out.close();
        cout << "Contact saved successfully !!! " << endl;
    }

    void showDetails()
    {
        ifstream in;
        in.open("phoneBook.csv");
        char ch;
        while (!in.eof())
        {
            in.get(ch);
            cout << ch;
        }
        in.close();
    }

    void searchDetails()
    {
        ifstream in;
        in.open("phoneBook.csv");
        string word;
        cout << "Enter name to search: ";
        getline(cin, word);
        string line;
        while (getline(in, line))
        {
            if (line.find(word) != string::npos)
            {
                cout << line << endl;
            }
        }
        in.close();
    }

    void deleteContactDetails()
    {
        ifstream in;
        ofstream out;
        in.open("phoneBook.csv");
        out.open("temp.csv");
        string word;
        cout << "Enter name to delete: ";
        getline(cin, word);
        string line;
        while (getline(in, line))
        {
            if (line.find(word) == string::npos)
            {
                out << line << endl;
            }
        }
        in.close();
        out.close();
        remove("phoneBook.csv");
        rename("temp.csv", "phoneBook.csv");
    }

    void updateContactDetails()
    {
        ifstream in;
        ofstream out;
        in.open("phoneBook.csv");
        out.open("temp.csv");
        string word;
        cout << "Enter name to update: ";
        getline(cin, word);
        string line;
        while (getline(in, line))
        {
            if (line.find(word) != string::npos)
            {
                cout << "Enter new name: ";
                getline(cin, name);
                cout << "Enter new number: ";
                getline(cin, number);
                cout << "Enter new email: ";
                getline(cin, email);
                out << name << "," << number << "," << email << endl;
            }
            else
            {
                out << line << endl;
            }
        }
        in.close();
        out.close();
        remove("phoneBook.csv");
        rename("temp.csv", "phoneBook.csv");
    }

    // delete all contacts  header
    void deleteAll()
    {
        ofstream out;
        out.open("phoneBook.csv");
        out.close();
    }
};

int main()
{
    PhoneBook p;
    // p.getDetails();
    // p.saveDetails();
    // p.showDetails();
    // p.searchDetails();
    // p.deleteContact();
    // p.updateContact();
    // p.deleteAll();

    int choice;

    cout << "\n\n\n";
    cout << "======Phone Book===========" << endl;
    cout << "===========================" << endl;
    cout << "1. Add contact" << endl;
    cout << "2. Show contacts" << endl;
    cout << "3. Search contact" << endl;
    cout << "4. Delete contact" << endl;
    cout << "5. Update contact" << endl;
    cout << "6. Delete all contacts" << endl;
    cout << "7. Exit" << endl;
    cout << "===========================" << endl;
    do
    {
        cout << "===========================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            p.getDetails();
            p.saveDetails();
            break;
        case 2:
            p.showDetails();
            break;
        case 3:
            p.searchDetails();
            break;
        case 4:
            p.deleteContactDetails();
            break;
        case 5:
            p.updateContactDetails();
            break;
        case 6:
            p.deleteAll();
            break;
        case 7:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 7);

    return 0;
}