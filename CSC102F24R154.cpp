#include <iostream>
#include <iomanip>
#include <string>
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
bool validPasscode(string password);
bool validCellNo(string &cellNo);
bool validCNIC(string cnic);
bool validEmail(string email);
bool validCreditCardNo(string creditNo);
bool checkUser(string person);
bool UserSign(string nicard, string nic);
long double salaryTax(double salary, long double tax1);
long double cashTax(double cash, long double tax2);
long double calculateTax(long double tax1, long double tax2, long double tTax3, string name, int c, bool valid);

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
                case 1:
                {
                    cout << "** The ID of user : ";
                    cout << ID << endl;
                    cout << "** Enter username: ";
                    index = ID - 1;
                    cin >> username[index];
                    cout << "** Enter Password: ";
                    cin >> passwords[index];
                    code=passwords[index];
                    if (validPasscode(code))
                    {
                        cout << "** Enter CNIC (Don't enter hyphen): ";
                        cin >> cnic;
                        if (validCNIC(cnic))
                        {
                            NIC[index] = cnic;
                            cout << "** Enter Cell Number (03001247897): ";
                            cin >> cellNo;
                            if (validCellNo(cellNo))
                            {
                                cout << "** Enter e-mail: ";
                                cin >> email;
                                if (validEmail(email))
                                {
                                    cout << "** User Registered Successfully!" << endl;
                                    validation = false;
                                }
                                else
                                {
                                    cout << "** !! User Email Credentials are wrong !!" << endl;
                                    cout << "** User will be registered witouht Email. " << endl;
                                }
                            }
                            else
                            {
                                cout << "** !! User Cell Number Credentials are wrong !!" << endl;
                                cout << "** User will be registered witouht Cell Number. " << endl;
                            }
                        }
                        else
                        {
                            cout << "** !! User CNIC Credentials are wrong !! " << endl;
                            cout << "** This could result in serious issues. " << endl;
                            username[index] = "0";
                            passwords[index] = "0";
                            NIC[index] = "0";
                            cout << "** The user you entered will not be registered." << endl;
                        }
                    }
                    else
                    {
                        cout << "** ! You entered invalid credentials for PASSWORD. !" << endl;
                        cout << "** Password must consist of eight letters." << endl;
                        username[index] = "0";
                        passwords[index] = "0";
                        cout << "** The user you entered will not be registered." << endl;
                    }
                    ID++;
                }
                break;
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
                            cout << "** The tax alloted to the user on salary is :" << salaryTax(salary, tax1) << endl;
                            tTax1 = salaryTax(salary, tax1);

                            cout << "** Enter Bank Balance & cash in hand:";
                            cin >> cash;
                            cout << "** The tax alloted to the user on bank balance and cash is :" << cashTax(cash, tax2) << endl;
                            tTax2 = cashTax(cash, tax2);

                            cout << "** Enter number of properties owned (up to 10):";
                            cin >> num;
                            if (num > psize)
                            {
                                cout << "** Number of properties cannot exceed 10. Your tax on propety will not be calculated." << endl;
                                cout << "** For valid Tax calculation, enter valid credentials." << endl;
                                break;
                            }
                            if (num == 0)
                            {
                                cout << "** The total tax on land is:" << tTax3 << endl;
                            }
                            for (int i = 1; i <= num; i++)
                            {
                                cout << "** Enter property " << i << endl;
                                cout << "** Enter measurement unit (i.e: marla, kanal, acre):  ";
                                cin >> unit[i];
                                if (unit[i] == "marla" || unit[i] == "kanal" || unit[i] == "acre")
                                {
                                    checked = true;
                                    cout << "** Enter total area (i.e: 5):  ";
                                    cin >> area[i];
                                    cout << "** Enter price of land:  ";
                                    cin >> price[i];
                                }
                                else
                                {
                                    checked = false;
                                    cout << "**!!! You entered invalid measurement unit !!!" << endl;
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
                                    cout << "** The total tax on land is:" << tTax3 << endl;
                                }
                                else
                                {
                                    cout << "**!! As you entered invalid measurement unit your tax for that land will not be calculated!! " << endl;
                                }
                            }
                            c++;
                            // cout << "** " <<c<<endl;
                            cout << "** The total tax alloted to user is : ";
                            validation = true;
                            calculateTax(tTax1, tTax2, tTax3, name, c, validation);
                        }
                        if (Flag == false)
                        {
                            cout << "** The User you entered is not registered!" << endl;
                        }
                    }
                }

                break;
                case 3:
                {
                    cout << "** For Deletion of user account : " << endl;
                    int ID;
                    cout << "** Enter ID of user (1 digit number only): ";
                    cin >> ID;
                    index = ID - 1;
                    cout << "** Enter the username to delete: ";
                    cin >> name;
                    if (checkUser(name))
                    {
                        username[index] = "0";
                        passwords[index] = "0";
                        cout << "** User deleted Successfully!";
                    }
                    else
                    {
                        cout << "** The User you entered is not registered!" << endl;
                    }
                    //
                    // index = index + 1;
                }
                break;
                case 4:
                {
                    cout << "** For Updation of user account : " << endl;
                    int ID;
                    cout << "** Enter ID of user (1 digit number only): ";
                    cin >> ID;
                    index = ID - 1;
                    cout << "** Enter the username to edit/update: ";
                    cin >> name;
                    if (checkUser(name))
                    {
                        cout << "** Enter the updted username : ";
                        cin >> username[index];
                        cout << "** Enter the updted password: ";
                        cin >> passwords[index];
                        cout << "** Enter user's CNIC: ";
                        cin >> NIC[index];
                        cout << "** User updated Successfully!";
                    }
                    else
                    {
                        cout << "** The User you entered is not registered!" << endl;
                    }
                    //
                    // index = index + 1;
                }
                break;
                case 0:
                {
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
                case 1:
                {
                    cout << "** For Tax Status : " << endl;
                    cout << "** Name of User: ";
                    cout << user << endl;
                    cout << "** CNIC of User: ";
                    cout << nic << endl;
                    if (taxStatus == "paid")
                    {
                        cout << "** Tax status is : paid" << endl;
                    }
                    else
                    {
                        cout << "** Tax status is : unpaid" << endl;
                    }
                }
                break;
                case 2:
                {
                    long double comp = calculateTax(tTax1, tTax2, tTax3, name, c, validation);
                    cout << "** For e-Payment : " << endl;
                    cout << "** Name of User: ";
                    cout << user << endl;
                    cout << "** CNIC of User: ";
                    cout << nic << endl;
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
                            cout << "** Your tax is :" << comp << endl;
                            cout << "** Enter your credit card number(16 dig without alphabets, space & hiphen):";
                            cin >> creditNo;

                            if (validCreditCardNo(creditNo))
                            {
                                cout << "** " << comp << " Rs will be transacted. You have paid your tax successfully!" << endl;
                                taxStatus = "paid";
                            }
                            else
                            {
                                cout << "** Invalid Credentials!" << endl;
                                taxStatus = "unpaid";
                            }
                        }
                        else
                            cout << "** You have already paid your tax." << endl;
                    }
                    else
                    {
                        cout << "** Your tax is not yet calculated. " << endl;
                    }

                    break;
                }

                case 0:
                {
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
// Function for Password Validation
bool validPasscode(string password)
{
    if (password.length()>=8)
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
long double salaryTax(double salary, long double tax1)
{
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
long double cashTax(double cash, long double tax2)
{
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
long double calculateTax(long double tax1, long double tax2, long double tTax3, string name, int c, bool valid)
{
    totalTax = tax1 + tax2 + tTax3;
    if (valid)
    {
        for (int i = 0; i < usize; i++)
        {
            if (i == c)
            {
                taxCalculation[i] = totalTax;
                users[i] = name;
                cout << users[i] << "  tax is " << taxCalculation[i] << endl;
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
