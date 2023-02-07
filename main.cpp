#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isLoggedIn(string un, string pw) {
            //Comparison strings for checking against user login
            string comp_line;
            string buffer;
            string my_creds = "username:" + un + " " + "password:" + pw;

            //Read file of existing accounts
            ifstream myFile ("credentials.txt"); 
        
            //Verify whether inputted username & password exist
            if (myFile.is_open()) {
                while (getline(myFile, comp_line)) {
                    buffer += comp_line;
                }
            }

            if (buffer.find(my_creds) != -1) {
                cout << "Succesfully Logged in!\n";
                return true;
            } else {
                cout << "Error with credentials!\n";
                return false;
            }
        }

class Account {
    private:
        string username, password;

    public:
        bool isDuplicate() {
            //Comparison strings for checking against user login
            string comp_line;
            string buffer;
            string my_creds = "username:" + Account::username + " " + "password:" + Account::password;

            //Read file of existing accounts
            ifstream myFile ("credentials.txt"); 
        
            //Verify whether inputted username & password exist
            if (myFile.is_open()) {
                while (getline(myFile, comp_line)) {
                    buffer += comp_line;
                }
            }

            if (buffer.find(my_creds) != -1) {
                cout << "Sorry, this account already exists - please log in or try a different username\n";
                return true;
            } else {
                cout << "You have been succesfully registered!\n";
                return false;
            }
        }

        void registration() {
            cout << "Please select a username: ";
            cin >> Account::username;
            cout << "Please select a password: ";
            cin >> Account::password;

            if (isDuplicate() == false) {
                ofstream file;
                file.open("credentials.txt", std::ios_base::app);

                file << "username:" << Account::username << " " << "password:" << Account::password << endl;
                file.close();

                exit;
            }
            else {
                exit;
            }
        }

        void login(){
            cout << "Please enter your username: ";
            cin >> Account::username;
            cout << "Please enter your password: ";
            cin >> Account::password;
            isLoggedIn(Account::username, Account::password);
        }
};

int main() {
    int choice;

    Account myAccount;

    //Ask user to either register or log in to existing account
    cout << "Please choose one of the following: \n1) Register \n2) Log In\n3) Exit\n";
    cin >> choice;

    //If user 
    if (choice==1) {
        myAccount.registration();
        main();
    }
    else if (choice==2) {
        myAccount.login();
        main();
    }
    else if (choice==3){
        return 0;
    }

}