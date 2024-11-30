#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// Declaring Global Variables & Arrays
int index = 0;
long double totalTax = 0, tax1 = 0, tax2 = 0, tax3 = 0, tTax1 = 0, tTax2 = 0, tTax3 = 0, c = -1;
string taxStatus;
bool validation;
const int usize = 5;  // Maximum Number of Users
const int psize = 10; // Maximum Number of Properties
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

// Functions Declaration
void headerFBR();
void headerTax();
void adminHeader();
void userHeader();
bool validName(string str);
bool validPasscode(string password);
bool validCellNo(string &cellNo);
bool validCNIC(string cnic);
bool validEmail(string email);
bool isUnique(string cnic, int limit);
bool isUniqueNo(string cellNo, int limit);
bool isUniqueMail(string mail, int limit);
bool validCreditCardNo(string creditNo);
bool checkUser(string person);
bool UserSign(string nicard, string nic);
long double salaryTax(double salary);
long double cashTax(double cash);
long double calculateTax(long double tax1, long double tax2, long double tax3, string name, int c, bool valid);

// Main Function
int main()
{
    system("cls");
    system("Color 0F");
    // Declaring Variables
    int login, input1, input2, n1 = 0;
    int ID = 1;
    string name, email;
    string user, code, cnic, cellNo, nic;
    bool check, Flag = false, valid = false, flag1 = false;
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    do
    {
        // Calling Function
        headerFBR();
        if (n1 == 0)
        {
            headerTax();
        }
        cout << "** 1.Administrator" << endl;
        cout << "** 2.User" << endl;
        cout << "** 3.Exit" << endl;
        cout << "** Enter a choice for login (Enter only 1 character digit):";
        //  cin >> login;
        if (!(cin >> login))
        {
            cout << "** Invalid input. Please enter a valid choice (1, 2, or 3)." << endl;
            break;
        }

        cout << "**" << endl;
        cout << "**" << endl;

        if (login == 1 || login == 2)
        {
            cout << "** Please enter your username and password." << endl;
        }
        else if (login == 3)
        {
            cout << "** Your request for logout is being processed." << endl;
        }
        else
        {
            cout << "** You entered invalid choice for login. Enter your choice again." << endl;
        }
        // Switch statement for Login Functionality
        switch (login)
        {
        case 1:
        {
            cout << "** Enter the Username: ";
            cin >> user;
            cout << "** Enter Password: ";
            cin >> code;
            if (user == "Admin" || user == "ADMIN" && code == "FBR2024")
            {
                check = true;
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
            cout << "** Enter the Username: ";
            cin >> user;
            if (validName(user))
            {
                cout << "** Enter Password: ";
                cin >> code;
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
                cout << "** Name must consist of three letters." << endl;
            }
        }
        break;
        case 3:
        {
            system("cls");
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
            cout << "** Invalid Input." << endl;
        }
        }

        // For Administrator
        if (login == 1 && check == true)
        {
            // system("cls");
            adminHeader();
            do
            {

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
                if (!(cin >> input1))
                {
                    cout << "** Invalid input. Please enter valid choice (1,2,3,4 or 0)." << endl;
                    break;
                }
                // Implementation of input choices
                switch (input1)
                {
                // Case 1 to register user in the system
                case 1:
                {
                    string names;
                    cout << "** The ID of user : ";
                    cout << ID << endl;
                    cout << "** Enter username: ";
                    index = ID - 1;
                    getline(cin, names);
                    username[index] = names;
                    if (validName(names))
                    {
                        cout << "** Enter Password: ";
                        getline(cin, code);
                        if (validPasscode(code))
                        {
                            passwords[index] = code;
                            cout << "** Enter CNIC (Don't enter hyphen): ";
                            cin >> cnic;
                            if (validCNIC(cnic))
                            {
                                if (isUnique(cnic, index))
                                {
                                    NIC[index] = cnic;
                                    cout << "** Enter Cell Number (03001247897): ";
                                    cin >> cellNo;
                                    if (validCellNo(cellNo))
                                    {
                                        if (isUniqueNo(cellNo, index))
                                        {
                                            cellNum[index] = cellNo;
                                            cout << "** Enter e-mail: ";
                                            cin >> mails[index];
                                            email = mails[index];
                                            if (validEmail(email))
                                            {
                                                if (isUniqueMail(email, index))
                                                {
                                                    cout << "** User Registered Successfully! " << endl;
                                                    validation = false;
                                                }
                                                else
                                                    ID--;
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
                                                ID--;
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
                                        ID--;
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
                                ID--;
                            }
                        }
                        else
                        {
                            cout << "** ! You entered invalid credentials for PASSWORD. !" << endl;
                            cout << "** Password must consist of eight letters." << endl;
                            username[index] = "0";
                            passwords[index] = "0";
                            cout << "** The user you entered will not be registered." << endl;
                            ID--;
                        }
                    }
                    else
                    {
                        cout << "** ! You entered invalid credentials for Name. !" << endl;
                        cout << "** Username must consist of three letters." << endl;
                        username[index] = "0";
                        cout << "** The user you entered will not be registered." << endl;
                        ID--;
                    }
                    ID++;
                }
                break;
                // Case 2 to calculate user taxes in the system
                case 2:
                {
                    cout << "** Calculate Taxes: " << endl;
                    cout << "** Enter user for which you want to calculate taxes:";
                    cin >> name;
                    bool checked;
                    Flag = checkUser(name);
                    if (c < 6)
                    {
                        if (Flag == true)
                        {

                            cout << "** Enter Salary:";
                            cin >> salary;
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

                            cout << "** Enter Bank Balance & cash in hand:";
                            cin >> cash;
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
                            calculateTax(tTax1, tTax2, tTax3, name, c, validation);
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
                    cout << "** For Deletion of user account : " << endl;
                    int ID;
                    cout << "** Enter ID of user (1 digit number only): ";
                    cin >> ID;
                    if (ID > 0 && ID <= usize)
                    {
                        index = ID - 1;
                        cout << "** Enter the username to delete: ";
                        cin >> name;
                        if (checkUser(name))
                        {
                            username[index] = "0";
                            passwords[index] = "0";
                            NIC[index] = "0";
                            cellNum[index] = "0";
                            mails[index] = "0";
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
                    cout << "** For Updation of user account : " << endl;
                    int ID;
                    cout << "** Enter ID of user (1 digit number only): ";
                    cin >> ID;
                    if (ID > 0 && ID <= usize)
                    {
                        index = ID - 1;
                        cout << "** Enter the username to edit/update: ";
                        cin >> name;
                        if (checkUser(name))
                        {
                            cout << "** Enter the updted username : ";
                            cin >> userName;
                            if (validName(userName))
                            {
                                username[index] = userName;
                                cout << "** Enter the updted password: ";
                                cin >> userPassword;
                                if (validPasscode(userPassword))
                                {
                                    passwords[index] = userPassword;
                                    cout << "** Enter user's CNIC: ";
                                    cin >> userCNIC;
                                    if (validCNIC(userCNIC))
                                    {
                                        if (isUnique(userCNIC, index))
                                        {
                                            NIC[index] = userCNIC;
                                            cout << "** Enter Cell Number (03001247897): ";
                                            cin >> cellNo;
                                            if (validCellNo(cellNo))
                                            {
                                                if (isUniqueNo(cellNo, index))
                                                {
                                                    cellNum[index] = cellNo;
                                                    cout << "** Enter user's E-mail: ";
                                                    cin >> mails[index];
                                                    email = mails[index];
                                                    if (validEmail(email))
                                                    {
                                                        if (isUniqueMail(email, index))
                                                        {
                                                            cout << "** User updated Successfully!" << endl;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        cout << "** ! You entered invalid mail credentials. ! " << endl;
                                                        mails[index] = "0";
                                                        cout << "** ! User email will have a null value. " << endl;
                                                        cout << "** Choose update option again to resolve this issue. ! " << endl;
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                cout << "** ! You entered invalid Cell Number credentials. ! " << endl;
                                                cellNum[index] = "0";
                                                cout << "** ! User CNIC will have a null value. " << endl;
                                                cout << "** Choose update option again to resolve this issue. ! " << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "** ! You entered invalid CNIC credentials. ! " << endl;
                                        NIC[index] = "0";
                                        cout << "** ! User CNIC will have a null value. " << endl;
                                        cout << "** Choose update option again to resolve this issue. ! " << endl;
                                    }
                                }
                                else
                                {
                                    cout << "** ! Password must consists of 8 characters !" << endl;
                                    passwords[index] = "0";
                                    cout << "** ! User password will have a null value. " << endl;
                                    cout << "** Choose update option again to resolve this issue. ! " << endl;
                                }
                            }
                            else
                            {
                                cout << "** ! Username must consists of 8 characters !" << endl;
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
                        cout << "** " << i + 1 << "  ";
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
                    cout << "** !! Invalid choice !!";
                    break;
                }
                }
                validation = false;
            } while (input1 != 0);
        }
        // For User
        if (login == 2 && Flag == true)

        {
            // system("cls");
            userHeader();
            do
            {
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
                if (!(cin >> input2))
                {
                    cout << "** Invalid input. Please enter valid choice (1,2,3,4 or 0)." << endl;
                    break;
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
                    long double comp = calculateTax(tTax1, tTax2, tTax3, name, c, validation);
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
                    cout << "** !! Invalid choice !!";
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
// Function for Password Validation
bool validPasscode(string password)
{
    if (password.length() >= 8)
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
bool isUnique(string cnic, int limit)
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
bool isUniqueNo(string cellNo, int limit)
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
bool isUniqueMail(string mail, int limit)
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
bool checkUser(string person)
{
    for (int i = 0; i < usize; i++)
    {
        if (person == username[i])
        {
            return true;
        }
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
long double calculateTax(long double tax1, long double tax2, long double tax3, string name, int c, bool valid)
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
