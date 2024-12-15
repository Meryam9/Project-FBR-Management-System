#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

// Declaring Global Variables
int index = 0, var = 0;
long double totalTax = 0, tax3 = 0, tTax1 = 0, tTax2 = 0, tTax3 = 0, c = -1;
string taxStatus;
bool validation;
const int usize = 50; // Maximum Number of Users
const int psize = 10; // Maximum Number of Properties

// Functions Declaration
void headerFBR();
void headerTax();
void adminHeader();
void userHeader();
bool validName(string str);
bool checkName(string str);
bool validPasscode(string password);
bool validCellNo(string &cellNo);
bool validCNIC(string cnic);
bool validEmail(string email);
bool isUnique(string cnic, int limit, string NIC[]);
bool isUniqueNo(string cellNo, int limit, string cellNum[]);
bool isUniqueMail(string mail, int limit, string mails[]);
bool validCreditCardNo(string creditNo);
bool checkUser(string person, int num, int ID[], string username[]);
bool UserSign(string nicard, string nic);
bool inputValidation(int inputs);
long double salaryTax(double salary);
long double cashTax(double cash);
long double calculateTax(long double tax1, long double tax2, long double tax3, string name, int c, bool valid, string users[], long double taxCalculation[]);

// Main Function
int main()
{
    system("cls");
    system("Color 0F");
    // Declaring Variables
    int login, input1, input2, n1 = 0;
    // int ID = 1;
    string name, email;
    string user, code, cnic, cellNo, nic;
    bool check, Flag = false, valid = false, flag1 = false;
    int ID[usize];
    string username[usize];
    string passwords[usize];
    string NIC[usize];
    string mails[usize];
    string cellNum[usize];
    string users[usize];
    long double taxCalculation[usize];
    string unit[psize];
    int area[psize];
    int price[psize];
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    do
    {
        // Calling Function
        Sleep(1000);
        system("cls");
        headerFBR();
        if (n1 == 0)
        {
            headerTax();
        }
        cout << "** 1.Administrator" << endl;
        cout << "** 2.User" << endl;
        cout << "** 3.Exit" << endl;
        cout << "** Enter a choice for login (Enter only 1 character digit):";
        cin >> login;
        cout << "**" << endl;
        cout << "**" << endl;
        while (inputValidation(login))
        {
            cout << "** 1.Administrator" << endl;
            cout << "** 2.User" << endl;
            cout << "** 3.Exit" << endl;
            cout << "** Enter a choice for login (Enter only 1 character digit):";
            cin >> login;
            cout << "**" << endl;
            cout << "**" << endl;
        }
        // Switch statement for Login Functionality
        switch (login)
        {
        case 1:
        {
            cout << "** Please enter your username and password." << endl;
            cout << "** Enter the Username: ";
            cin >> user;
            cout << "** Enter Password: ";
            cin >> code;
            if (user == "Admin" || user == "ADMIN" && code == "FBR2024")
            {
                check = true;
                cout << "** LOGIN SUCCESSFUL!." << endl;
            }
            else
            {
                check = false;
                cout << "** You entered invalid Credentials!." << endl;
            }
        }
        break;
        case 2:
        {
            string nicard;
            cout << "** Please enter your username and password." << endl;
            cout << "** Enter the Username: ";
            cin.ignore();
            getline(cin, user);
            if (validName(user) && checkName(user))
            {
                cout << "** Enter Password: ";
                // cin.ignore();
                getline(cin, code);
                if (validPasscode(code))
                {
                    cout << "** Enter CNIC(don't enter hypen): ";
                    cin >> nic;
                    if (validCNIC(nic))
                    {
                        // write code to search user from user list
                        for (int i = 0; i < usize; i++)
                        {
                            if ((user == username[i]) && (code == passwords[i]) && (nic == NIC[i]))
                            {
                                nicard = NIC[i];
                                if (UserSign(nicard, nic))
                                {
                                    Flag = true;
                                    break;
                                }
                            }
                        }
                        if (Flag == true)
                        {
                            cout << "** Login Successful!" << endl;
                        }
                        if (Flag == false)
                        {
                            cout << "** You entered invalid credentials." << endl;
                        }
                    }
                    else
                    {
                        cout << "** CNIC must consist of 13 digits without hipen & alphabets or special characters!" << endl;
                    }
                }
                else
                {
                    cout << "** ! You entered invalid credentials for PASSWORD. !" << endl;
                    cout << "** Password must consist of eight letters." << endl;
                }
            }
            else
            {
                cout << "** ! You entered invalid credentials for Username. !" << endl;
                cout << "** Name must consist of three letters and have no digits." << endl;
            }
        }
        break;
        case 3:
        {
            system("cls");
            cout << "**                          Your request for logout is being processed." << endl;
            cout << "** " << endl;
            cout << "** " << endl;
            cout << "** " << endl;
            cout << "**                             Thank You for using the system! " << endl;
            cout << "**                                        Logging Out!! " << endl;
            cout << "** " << endl;
            cout << "** " << endl;
            cout << "** " << endl;
            break;
        }
        default:
        {
            cout << "**" << endl;
            cout << "** !! Invalid choice !!" << endl;
            cout << "** Enter your choice again." << endl;
            cout << "**" << endl;
        }
        }

        // For Administrator
        if (login == 1 && check == true)
        {           
            do
            {
                Sleep(2000);
                system("cls");
                adminHeader();
                int num;
                double salary, cash;
                cout << "** " << endl;
                cout << "** Choose the desired option" << endl;
                cout << left << setw(20) << "\tOptions" << endl
                     << setw(15) << "** 1. Register new user" << endl
                     << setw(15) << "** 2. Calculate taxes" << endl
                     << setw(15) << "** 3. Delete user account" << endl
                     << setw(15) << "** 4. Update user account" << endl
                     << setw(15) << "** 5. List of users" << endl
                     << setw(15) << "** 0. Logout " << endl;
                cout << "** " << endl;
                cout << "** Choose an option: ";
                cin >> input1;
                while (inputValidation(input1))
                {
                    cout << "** " << endl;
                    cout << "** Choose the desired option" << endl;
                    cout << left << setw(20) << "\tOptions" << endl
                         << setw(15) << "** 1. Register new user" << endl
                         << setw(15) << "** 2. Calculate taxes" << endl
                         << setw(15) << "** 3. Delete user account" << endl
                         << setw(15) << "** 4. Update user account" << endl
                         << setw(15) << "** 5. List of users" << endl
                         << setw(15) << "** 0. Logout " << endl;
                    cout << "** " << endl;
                    cout << "** Choose an option: ";
                    cin >> input1;
                }
                // Implementation of input choices
                switch (input1)
                {
                // Case 1 to register user in the system
                case 1:
                {
                    string names;
                    ID[index] = index + 1;
                    cout << "** The ID of user : ";
                    cout << ID[index] << endl;
                    cout << "** Enter username: ";
                    cin.ignore();
                    getline(cin, names);
                    username[index] = names;
                    if (validName(names) && checkName(names))
                    {
                        cout << "** Enter Password: ";
                        // cin.ignore();
                        getline(cin, code);
                        if (validPasscode(code))
                        {
                            passwords[index] = code;
                            cout << "** Enter CNIC (Don't enter hyphen): ";
                            cin >> cnic;
                            if (validCNIC(cnic))
                            {
                                if (isUnique(cnic, index, NIC))
                                {
                                    NIC[index] = cnic;
                                    cout << "** Enter Cell Number (03001247897): ";
                                    cin >> cellNo;
                                    if (validCellNo(cellNo))
                                    {
                                        if (isUniqueNo(cellNo, index, cellNum))
                                        {
                                            cellNum[index] = cellNo;
                                            cout << "** Enter e-mail: ";
                                            cin >> mails[index];
                                            email = mails[index];
                                            if (validEmail(email))
                                            {
                                                if (isUniqueMail(email, index, mails))
                                                {
                                                    cout << "** User Registered Successfully! " << endl;
                                                    validation = false;
                                                }
                                                else
                                                {
                                                    ID[index] = 0;
                                                    index--;
                                                }
                                            }
                                            else
                                            {
                                                cout << "** !! User Email Credentials are wrong !!" << endl;
                                                username[index] = "0";
                                                passwords[index] = "0";
                                                NIC[index] = "0";
                                                cellNum[index] = "0";
                                                mails[index] = "0";
                                                cout << "** The user you entered will not be registered." << endl;
                                                ID[index] = 0;
                                                index--;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "** !! User Cell Number Credentials are wrong !!" << endl;
                                        username[index] = "0";
                                        passwords[index] = "0";
                                        NIC[index] = "0";
                                        cellNum[index] = "0";
                                        cout << "** The user you entered will not be registered." << endl;
                                        ID[index] = 0;
                                        index--;
                                    }
                                }
                            }
                            else
                            {
                                cout << "** !! User CNIC Credentials are wrong !! " << endl;
                                username[index] = "0";
                                passwords[index] = "0";
                                NIC[index] = "0";
                                cout << "** The user you entered will not be registered." << endl;
                                ID[index] = 0;
                                index--;
                            }
                        }
                        else
                        {
                            cout << "** ! You entered invalid credentials for PASSWORD. !" << endl;
                            cout << "** Password must consist of eight letters." << endl;
                            username[index] = "0";
                            passwords[index] = "0";
                            cout << "** The user you entered will not be registered." << endl;
                            ID[index] = 0;
                            index--;
                        }
                    }
                    else
                    {
                        cout << "** ! You entered invalid credentials for Name. !" << endl;
                        cout << "** Username must consist of three letters and no digits." << endl;
                        username[index] = "0";
                        cout << "** The user you entered will not be registered." << endl;
                        ID[index] = 0;
                        index--;
                    }
                    index++;
                }
                break;
                // Case 2 to calculate user taxes in the system
                case 2:
                {
                    int identity;
                    cout << "** Calculate Taxes: " << endl;
                    cout << "** Enter user for which you want to calculate taxes:";
                    cin.ignore();
                    getline(cin, name);
                    cout << "** Enter user ID:";
                    cin >> identity;
                    bool checked;
                    Flag = checkUser(name, identity, ID, username);
                    if (c < 6)
                    {
                        if (Flag == true)
                        {

                            cout << "** Enter Salary:";
                            cin >> salary;
                            if (salary > 1000)
                            {
                                cout << "** The tax alloted to the user on salary is :";
                                cout << fixed << setprecision(2);
                                cout << salaryTax(salary) << endl;
                                tTax1 = salaryTax(salary);
                                fout << "** Enter Salary:";
                                fin >> salary;
                                fout << "** The tax alloted to the user on salary is :";
                                fout << fixed << setprecision(2);
                                fout << salaryTax(salary) << endl;
                                tTax1 = salaryTax(salary);
                            }
                            else
                                cout << "** Salary should be greater than 1000." << endl;
                            cout << "** Enter Bank Balance & cash in hand:";
                            cin >> cash;
                            if (cash > 1000)
                            {
                                cout << "** The tax alloted to the user on bank balance and cash is :";
                                cout << fixed << setprecision(2);
                                cout << cashTax(cash) << endl;
                                tTax2 = cashTax(cash);
                                fout << "** Enter Bank Balance & cash in hand:";
                                fin >> cash;
                                fout << "** The tax alloted to the user on bank balance and cash is :";
                                fout << fixed << setprecision(2);
                                fout << cashTax(cash) << endl;
                                tTax2 = cashTax(cash);
                            }
                            else
                                cout << "** Bank balance should be greater than 1000." << endl;
                            cout << "** Enter number of properties owned (up to 10):";
                            cin >> num;
                            fout << "** Enter number of properties owned (up to 10):";
                            fin >> num;
                            if (num > psize)
                            {
                                cout << "** Number of properties cannot exceed 10. Your tax on propety will not be calculated." << endl;
                                cout << "** For valid Tax calculation, enter valid credentials." << endl;
                                fout << "** Number of properties cannot exceed 10. Your tax on propety will not be calculated." << endl;
                                fout << "** For valid Tax calculation, enter valid credentials." << endl;
                                break;
                            }
                            if (num == 0)
                            {
                                cout << "** The total tax on land is:" << tTax3 << endl;
                                fout << "** The total tax on land is:" << tTax3 << endl;
                            }
                            for (int i = 1; i <= num; i++)
                            {
                                cout << "** Enter property " << i << endl;
                                cout << "** Enter measurement unit (i.e: marla, kanal, acre):  ";
                                cin >> unit[i];
                                fout << "** Enter property " << i << endl;
                                fout << "** Enter measurement unit (i.e: marla, kanal, acre):  ";
                                fin >> unit[i];
                                if (unit[i] == "marla" || unit[i] == "kanal" || unit[i] == "acre")
                                {
                                    checked = true;
                                    cout << "** Enter total area (i.e: 5):  ";
                                    cin >> area[i];
                                    cout << "** Enter price of land:  ";
                                    cin >> price[i];

                                    fout << "** Enter total area (i.e: 5):  ";
                                    fin >> area[i];
                                    fout << "** Enter price of land:  ";
                                    fin >> price[i];
                                }
                                else
                                {
                                    checked = false;
                                    cout << "**!!! You entered invalid measurement unit !!!" << endl;
                                    fout << "**!!! You entered invalid measurement unit !!!" << endl;
                                }

                                if (checked)
                                {
                                    // Calculate tax based on measurement type and area
                                    if (unit[i] == "acre")
                                    {
                                        tax3 = price[i] * 10.0;
                                    }
                                    else if (unit[i] == "kanal")
                                    {
                                        tax3 = price[i] * 5.0;
                                    }
                                    else if (unit[i] == "marla")
                                    {
                                        tax3 = price[i] * 2.0;
                                    }
                                    tTax3 = tTax3 + tax3;
                                    cout << fixed << setprecision(2);
                                    cout << "** The total tax on land is:" << tTax3 << endl;
                                    fout << fixed << setprecision(2);
                                    fout << "** The total tax on land is:" << tTax3 << endl;
                                }
                                else
                                {
                                    cout << "**!! As you entered invalid measurement unit your tax for that land will not be calculated!! " << endl;
                                    fout << "**!! As you entered invalid measurement unit your tax for that land will not be calculated!! " << endl;
                                }
                            }
                            c++;
                            // cout << "** " <<c<<endl;
                            cout << "** The total tax alloted to user is : ";
                            fout << "** The total tax alloted to user is : ";
                            validation = true;
                            calculateTax(tTax1, tTax2, tTax3, name, c, validation, users, taxCalculation);
                        }
                        if (Flag == false)
                        {
                            cout << "** The User you entered is not registered!" << endl;
                            fout << "** The User you entered is not registered!" << endl;
                        }
                    }
                }
                break;
                // Case 3 to delete user account in the system
                case 3:
                {
                    int no;
                    cout << "** For Deletion of user account : " << endl;
                    cout << "** Enter ID of user (1 digit number only): ";
                    cin >> no;
                    if (no > 0 && no <= usize)
                    {
                        // index = ID - 1;
                        cout << "** Enter the username to delete: ";
                        cin.ignore();
                        getline(cin, name);
                        if (checkUser(name, no, ID, username))
                        {
                            ID[var] = 0;
                            username[var] = "0";
                            passwords[var] = "0";
                            NIC[var] = "0";
                            cellNum[var] = "0";
                            mails[var] = "0";
                            cout << "** User deleted Successfully!";
                        }
                        else
                        {
                            cout << "** The User you entered is not registered!" << endl;
                        }
                    }
                    else
                    {
                        cout << "** ! You entered invalid ID !" << endl;
                    }
                }
                break;
                // Case 3 to update user account in the system
                case 4:
                {
                    string userName, userPassword, userCNIC, userMail;
                    int num;
                    cout << "** For Updation of user account : " << endl;
                    // int ID;
                    cout << "** Enter ID of user (1 digit number only): ";
                    cin >> num;
                    if (num > 0 && num <= usize)
                    {
                        // index = ID - 1;
                        cout << "** Enter the username to edit/update: ";
                        cin.ignore();
                        getline(cin, name);
                        if (checkUser(name, num, ID, username))
                        {
                            cout << "** Enter the updted username : ";
                            // cin.ignore();
                            getline(cin, userName);
                            if (validName(userName) && checkName(userName))
                            {
                                username[var] = userName;
                                cout << "** Enter the updted password: ";
                                // cin.ignore();
                                getline(cin, userPassword);
                                if (validPasscode(userPassword))
                                {
                                    passwords[var] = userPassword;
                                    cout << "** Enter user's CNIC: ";
                                    cin >> userCNIC;
                                    if (validCNIC(userCNIC))
                                    {
                                        if (isUnique(userCNIC, var, NIC))
                                        {
                                            NIC[var] = userCNIC;
                                            cout << "** Enter Cell Number (03001247897): ";
                                            cin >> cellNo;
                                            if (validCellNo(cellNo))
                                            {
                                                if (isUniqueNo(cellNo, var, cellNum))
                                                {
                                                    cellNum[var] = cellNo;
                                                    cout << "** Enter user's E-mail: ";
                                                    cin >> mails[var];
                                                    email = mails[var];
                                                    if (validEmail(email))
                                                    {
                                                        if (isUniqueMail(email, var, mails))
                                                        {
                                                            cout << "** User updated Successfully!" << endl;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        cout << "** ! You entered invalid mail credentials. ! " << endl;
                                                        mails[var] = "0";
                                                        cout << "** ! User email will have a null value. " << endl;
                                                        cout << "** Choose update option again to resolve this issue. ! " << endl;
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                cout << "** ! You entered invalid Cell Number credentials. ! " << endl;
                                                cellNum[var] = "0";
                                                cout << "** ! User CNIC will have a null value. " << endl;
                                                cout << "** Choose update option again to resolve this issue. ! " << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "** ! You entered invalid CNIC credentials. ! " << endl;
                                        NIC[var] = "0";
                                        cout << "** ! User CNIC will have a null value. " << endl;
                                        cout << "** Choose update option again to resolve this issue. ! " << endl;
                                    }
                                }
                                else
                                {
                                    cout << "** ! Password must consists of 8 characters !" << endl;
                                    passwords[var] = "0";
                                    cout << "** ! User password will have a null value. " << endl;
                                    cout << "** Choose update option again to resolve this issue. ! " << endl;
                                }
                            }
                            else
                            {
                                cout << "** ! Username must consists of 3 letters and no digits!" << endl;
                                cout << "** !! The User you entered is not registered !" << endl;
                            }
                        }
                        else
                        {
                            cout << "** !! The User you entered is not registered !" << endl;
                            cout << "** So contents can't be updated!" << endl;
                        }
                    }
                    else
                    {
                        cout << "** ! You entered invalid ID !" << endl;
                    }
                }
                break;
                case 5:
                {
                    cout << "** U.I  USERNAME       PASSWORD       CNIC       CELL-NUMBER       MAILS: " << endl;
                    cout << "****************************************************************************************" << endl;
                    for (int i = 0; i <= index; i++)
                    {
                        cout << "** " << ID[i] << "  ";
                        cout << username[i] << "       ";
                        cout << passwords[i] << "       ";
                        cout << NIC[i] << "       ";
                        cout << cellNum[i] << "       ";
                        cout << mails[i] << "       " << endl;
                    }
                }
                break;
                // Case 0 to log out as admin
                case 0:
                {
                    cout << "**" << endl;
                    cout << "**" << endl;
                    cout << "**                          !!! Administrator is logged out !!!" << endl;
                    cout << "**" << endl;
                    cout << "**" << endl;
                    break;
                }
                default:
                {
                    cout << "**" << endl;
                    cout << "** !! Invalid choice !!" << endl;
                    cout << "** Enter your choice again" << endl;
                    cout << "**" << endl;
                    break;
                }
                }
                validation = false;
            } while (input1 != 0);
        }
        // For User
        if (login == 2 && Flag == true)

        {
            do
            {
                Sleep(2000);
                system("cls");
                userHeader();               
                int income;
                string creditNo;
                cout << "** " << endl;
                cout << "** Choose the desired option\n";
                cout << left << setw(10)
                     << setw(25) << "** 1. View Tax Status" << endl
                     << setw(25) << "** 2. e-Payment" << endl
                     << setw(25) << "** 0. Logout" << endl;
                cout << "** " << endl;
                cout << "** Choose an option: ";
                cin >> input2;

                while (inputValidation(input2))
                {
                    cout << "** " << endl;
                    cout << "** Choose the desired option\n";
                    cout << left << setw(10)
                         << setw(25) << "** 1. View Tax Status" << endl
                         << setw(25) << "** 2. e-Payment" << endl
                         << setw(25) << "** 0. Logout" << endl;
                    cout << "** " << endl;
                    cout << "** Choose an option: ";
                    (cin >> input2);
                }
                // Implementation of input choices
                switch (input2)
                {
                // Case 1 to display tax status of user
                case 1:
                {
                    cout << "** For Tax Status : " << endl;
                    cout << "** Name of User: ";
                    cout << user << endl;
                    cout << "** CNIC of User: ";
                    cout << nic << endl;
                    fout << "** For Tax Status : " << endl;
                    fout << "** Name of User: ";
                    fout << user << endl;
                    fout << "** CNIC of User: ";
                    fout << nic << endl;
                    if (taxStatus == "paid")
                    {
                        cout << "** Tax status is : paid" << endl;
                        fout << "** Tax status is : paid" << endl;
                    }
                    else
                    {
                        cout << "** Tax status is : unpaid" << endl;
                        fout << "** Tax status is : unpaid" << endl;
                    }
                }
                break;
                // Case 1 to display tax assigned to user
                case 2:
                {
                    long double comp = calculateTax(tTax1, tTax2, tTax3, name, c, validation, users, taxCalculation);
                    cout << "** For e-Payment : " << endl;
                    cout << "** Name of User: ";
                    cout << user << endl;
                    cout << "** CNIC of User: ";
                    cout << nic << endl;
                    fout << "** For e-Payment : " << endl;
                    fout << "** Name of User: ";
                    fout << user << endl;
                    fout << "** CNIC of User: ";
                    fout << nic << endl;
                    for (int i = 0; i < 5; i++)
                    {
                        if (user == users[i])
                        {
                            if (taxCalculation[i] != 0.0)
                            {
                                comp = taxCalculation[i];
                                break;
                            }
                        }
                    }
                    if (comp != 0)
                    {
                        if (taxStatus != "paid")
                        {
                            cout << "** Your tax is :";
                            cout << fixed << setprecision(2);
                            cout << comp << endl;
                            cout << "** Enter your credit card number(16 dig without alphabets, space & hiphen):";
                            cin >> creditNo;
                            fout << "** Your tax is :";
                            fout << fixed << setprecision(2);
                            fout << comp << endl;
                            fout << "** Enter your credit card number(16 dig without alphabets, space & hiphen):";
                            fin >> creditNo;

                            if (validCreditCardNo(creditNo))
                            {
                                cout << "** " << comp << " Rs will be transacted. You have paid your tax successfully!" << endl;
                                fout << "** " << comp << " Rs will be transacted. You have paid your tax successfully!" << endl;
                                taxStatus = "paid";
                            }
                            else
                            {
                                cout << "** Invalid Credentials!" << endl;
                                fout << "** Invalid Credentials!" << endl;
                                taxStatus = "unpaid";
                            }
                        }
                        else
                            cout << "** You have already paid your tax." << endl;
                        fout << "** You have already paid your tax." << endl;
                    }
                    else
                    {
                        cout << "** Your tax is not yet calculated. " << endl;
                        fout << "** Your tax is not yet calculated. " << endl;
                    }

                    break;
                }
                    // Case 0 to log out as user
                case 0:
                {
                    cout << "**" << endl;
                    cout << "**" << endl;
                    cout << "**                           !!! User is logged out !!!" << endl;
                    cout << "**" << endl;
                    cout << "**" << endl;
                    break;
                }
                default:
                {
                    cout << "**" << endl;
                    cout << "** !! Invalid choice !!" << endl;
                    cout << "** Enter your choice again" << endl;
                    cout << "**" << endl;
                    break;
                }
                }
            } while (input2 != 0);
        }
        n1++;
    } while (login != 3);
    fout.close();
    fin.close();
    cout << "**" << endl;
    return 0;
}

// Funtion to print FBR Header
void headerFBR()
{
    cout << "*****************************************************************************************"
         << "*************************************************************************************" << endl;
    cout << "*****************************************************************************************"
         << "*************************************************************************************" << endl;
    cout << "**" << endl;
    cout << "**" << endl;
    cout << "**                                                    ______ ____  _____     " << endl;
    cout << "**                                                   |  ____|  _ \\|  __ \\   " << endl;
    cout << "**                                                   | |__  | |_) | |__) |   " << endl;
    cout << "**                                                   |  __| |  _ <|  _  /   " << endl;
    cout << "**                                                   | |    | |_) | | \\ \\  " << endl;
    cout << "**                                                   |_|    |____/|_|  \\_\\  " << endl;
    cout << "**" << endl;
    cout << "**                                                          PAKISTAN" << endl;
    cout << "**" << endl;
    cout << "**" << endl;
    cout << "**" << endl;
}
void headerTax()
{
    cout << "**                                                     .-------------------. " << endl;
    cout << "**                                                     | .---------------. | " << endl;
    cout << "**                                                     | |               | | " << endl;
    cout << "**                                                     | |      |T|      | | " << endl;
    cout << "**                                                     | |      |A|      | | " << endl;
    cout << "**                                                     | |      |X|      | | " << endl;
    cout << "**                                                     | |      |E|      | | " << endl;
    cout << "**                                                     | |      |S|      | | " << endl;
    cout << "**                                                     | |               | | " << endl;
    cout << "**                                                     | '---------------' | " << endl;
    cout << "**                                                     '-------------------' " << endl;
    cout << "**" << endl;
}
// Funtion to print Admin Header
void adminHeader()
{
    cout << "** " << endl;
    cout << "** " << endl;
    cout << "** " << endl;
    cout << "**                              _           _                              _ " << endl;
    cout << "**                     /\\      | |         (_)          | |               (_)      " << endl;
    cout << "**                    /  \\   __| |_ __ ___  _ _ __      | |      ___   __ _ _ _ __  " << endl;
    cout << "**                   / /\\ \\ / _` | '_ ` _ \\| | '_  |    | |     / _ \\ / _` | | '_ \\ " << endl;
    cout << "**                  / ____ \\ (_| | | | | | | | | | |    | |___ | (_) | (_| | | | | |" << endl;
    cout << "**                 /_/    \\_\\__,_|_| |_| |_|_|_| |_|    |______ \\___/ \\__, |_|_| |_|" << endl;
    cout << "**                                                                     __/ |        " << endl;
    cout << "**                                                                    |___/         " << endl;
    cout << "** " << endl;
    cout << "**                                      Welcome to FBR Management System!." << endl;
    cout << "** " << endl;
}
// Funtion to print User Header
void userHeader()
{
    cout << "** " << endl;
    cout << "** " << endl;
    cout << "** " << endl;
    cout << "**                           _    _                 _                 _  " << endl;
    cout << "**                          | |  | |               | |               (_)   " << endl;
    cout << "**                          | |  | |___  ___ _ __  | |     ___   __ _ _ _ __ " << endl;
    cout << "**                          | |  | / __|/ _ \\ '__| | |    / _ \\ / _` | | '_ \\ " << endl;
    cout << "**                          | |__| \\__ \\  __/ |    | |___| (_) | (_| | | | | |" << endl;
    cout << "**                           \\____/|___/\\___|_|    |______\\___/ \\__, |_|_| |_|" << endl;
    cout << "**                                                               __/ |        " << endl;
    cout << "**                                                              |___/         " << endl;
    cout << "** " << endl;
    cout << "**                                      Welcome to FBR Management System!." << endl;
    cout << "** " << endl;
}
// Function for Name Validation
bool validName(string str)
{
    if (str.length() >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Function for Name Validation
bool checkName(string str)
{
    // bool check=false;
    for (int i = 0; i < str.length(); i++)
    {
        if (!(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z'))
            return false;
    }
    return true;
}
// Function for Password Validation
bool validPasscode(string password)
{
    if (password.length() >= 7)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Function for CellNo Validation
bool validCellNo(string &cellNo)
{
    bool accurate = false;
    if (cellNo.length() == 11)
    {
        for (int i = 0; i < 11; i++)
        {
            if (cellNo[i] < '0' || cellNo[i] > '9')
            {
                return false;
            }
            else
            {
                accurate = true;
            }
        }
    }
    else
    {
        accurate = false;
    }
    return accurate;
}
// Function for CNIC Validation
bool validCNIC(string cnic)
{
    bool accurate = false;
    if (cnic.length() == 13)
    {
        for (int i = 0; i < 13; i++)
        {
            if (cnic[i] < '0' || cnic[i] > '9')
            {
                return false;
            }
            else
            {
                accurate = true;
            }
        }
    }
    else
    {
        accurate = false;
    }
    return accurate;
}
// Functon for Email Validation
bool validEmail(string email)
{
    int atRateOfPos = email.find('@');
    int dotPos = email.find('.', atRateOfPos);
    if ((atRateOfPos == string::npos) || (dotPos == string::npos))
    {
        return false;
    }
    else
        return true;
}
// Function to check if the user cinc is unique
bool isUnique(string cnic, int limit, string NIC[])
{
    bool identical = true;
    for (int i = 0; i <= usize; i++)
    {
        if (NIC[i] == cnic)
        {
            if (i != limit)
            {
                // Duplicate exists
                identical = false;
                cout << "** !! The CNIC you entered is already registered for another user." << endl;
                cout << "** This could result in serious issues." << endl;
                cout << "** Go to update account & enter valid CNIC." << endl;
                break;
            }
        }
    }
    return identical;
}
// Function to check if the user cell number is unique
bool isUniqueNo(string cellNo, int limit, string cellNum[])
{
    bool identical = true;
    for (int i = 0; i <= usize; i++)
    {
        if (cellNum[i] == cellNo)
        {
            if (i != limit)
            {
                // Duplicate exists
                identical = false;
                cout << "** !! The Cell Number you entered is already registered for another user." << endl;
                cout << "** This could result in serious issues." << endl;
                cout << "** Go to update account & enter valid Cell number." << endl;
                break;
            }
        }
    }
    return identical;
}
// Function to check if the user mail is unique
bool isUniqueMail(string mail, int limit, string mails[])
{
    bool identical = true;
    for (int i = 0; i <= usize; i++)
    {
        if (mails[i] == mail)
        {
            if (i != limit)
            {
                // Duplicate exists
                identical = false;
                cout << "** !! The Mail you entered is already registered for another user." << endl;
                cout << "** This could result in serious issues." << endl;
                cout << "** Go to update account & enter valid mail." << endl;
                break;
            }
        }
    }
    return identical;
}
// Functon for Credit Card Number Validation
bool validCreditCardNo(string creditNo)
{
    bool accurate = false;
    if (creditNo.length() == 16)
    {
        for (int i = 0; i < 16; i++)
        {
            if (creditNo[i] < '0' || creditNo[i] > '9')
            {
                return false;
            }
            else
            {
                accurate = true;
            }
        }
    }
    else
    {
        return false;
    }
    return accurate;
}
// Function to check user sign in
bool UserSign(string nicard, string nic)
{
    bool accurate = false;
    for (int i = 0; i < 13; i++)
    {
        if (nic[i] == nicard[i])
        {
            accurate = true;
        }
        else
            return false;
    }
    return accurate;
}
// Function to check user
bool checkUser(string person, int num, int ID[], string username[])
{
    for (int i = 0; i < usize; i++)
    {
        if (person == username[i] && ID[i] == num)
        {
            var = i;
            return true;
        }
    }
    return false;
}
// Function to check validation
bool inputValidation(int inputs)
{
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "**" << endl;
        cout << "** !! Invalid choice !!";
        cout << "** Enter your choice again";
        cout << "**" << endl;
        return true;
    }
    return false;
}
// Function to calculate Salary Tax
long double salaryTax(double salary)
{
    long double tax1;
    if (salary < 20, 000)
    {
        tax1 = 0;
    }
    else if (salary <= 50, 000)
    {
        tax1 = 0.01 * salary;
    }

    else if (salary <= 100, 000)
    {
        tax1 = 0.02 * salary;
    }
    else if (salary <= 150, 000)
    {
        tax1 = 0.03 * salary;
    }
    else if (salary <= 200, 000)
    {
        tax1 = 0.04 * salary;
    }
    else if (salary <= 300, 000)
    {
        tax1 = 0.05 * salary;
    }
    else
    {
        tax1 = 0.09 * salary;
    }
    return tax1;
}
// Function to calculate cashTax
long double cashTax(double cash)
{
    long double tax2;
    if (cash < 30, 000)
    {
        tax2 = 0;
    }
    else if (cash <= 50, 000)
    {
        tax2 = 0.01 * cash;
    }
    else if (cash <= 100, 000)
    {
        tax2 = 0.02 * cash;
    }
    else if (cash <= 150, 000)
    {
        tax2 = 0.03 * cash;
    }
    else if (cash <= 200, 000)
    {
        tax2 = 0.04 * cash;
    }
    else if (cash <= 300, 000)
    {
        tax2 = 0.05 * cash;
    }
    else
    {
        tax2 = 0.08 * cash;
    }
    return tax2;
}
// Functon to calculate total tax
long double calculateTax(long double tax1, long double tax2, long double tax3, string name, int c, bool valid, string users[], long double taxCalculation[])
{
    totalTax = tax1 + tax2 + tax3;
    if (valid)
    {
        for (int i = 0; i < usize; i++)
        {
            if (i == c)
            {
                taxCalculation[i] = totalTax;
                users[i] = name;
                cout << users[i];
                cout << fixed << setprecision(2);
                cout << "  tax is " << taxCalculation[i] << endl;
                break;
            }
        }
        return totalTax;
    }
    else
    {
        totalTax = 0;
    }
    return totalTax;
}
