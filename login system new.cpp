#include <iostream>
#include <fstream>
#include <string>
#include<iostream>
#include<fstream>
using namespace std;
//This functions checks if the credentials is the same with the registered ones
bool IsLogged()

{
    string username, password, user, pass;
    bool status = false;
    cout << "enter username :";
    cin >> username;
    cout << "Enter password :";
    cin >> password;

    ifstream read("file.txt");

    getline(read, user);
    getline(read, pass);


    if (username == user && password == pass)
    {
        return true;
        status = true;
    }
    else
    {

        return false;
    }
}



int main()
{
    string
        usercommand, 
        new_username, new_password, ques2, ques1, ques3,
        inName, inPassword, inques1, inques2, inques3, regques1, regques2, regques3; 


    while (1) {
        cout << "  *******************************************************************************************************************\n\n";
        cout << "                                                Welcome!!!                         \n\n\n";
        cout << "                                                                          \n\n\n";
        cout << "  **************************************        OPTIONS:       *********************************************************\n\n";

        cout << "1.REGISTER" << endl;
        cout << "2.LOGIN" << endl;
        cout << "3.FORGOT PASSWORD (or) USERNAME" << endl;
        cout << "4. EXIT" << endl;

        cout << "\nEnter your choice :";
        string usercommand;
        getline(cin, usercommand);

        if (usercommand == "1")
        {
            //open the file for registration
            ofstream f("file.txt"); //gets the stored data from the file


            if (!f.is_open()) //if it's not open, then there is not a file with this name inside this folder 
            {
                cout << "could not open this file\n";
                return 0;
            }
            cout << "\n\n\n" // newlines
                << "New Username: ";
            getline(cin, new_username); //registered username
            cout << "New Password: ";
            getline(cin, new_password); //registered password
            cout << "\nFor security reasons we ask you a question ,and for helping you if you ever forget your password   : ";
            cout << "\n Security Q1: What is Your favorite color? Please enter everything in  lowercase :";
            cout << "\nEnter the security question's answer:";
            getline(cin, regques1);
            cout << "\n Security Q2: What is your favorite pet ?:";
            cout << "\nEnter the security question's answer:";
            getline(cin, regques2);
            cout << "\n Security Q3: Where have you completed your high school ,(also city  and state)Please enter everything in  lowercase :";
            cout << "\nEnter the security question's answer:";
            getline(cin, regques3);

            f << new_username; //this put whatever's to the right neregistered name into

            f << '\n'; //adds new line to the file
            f << new_password; //store password to the file 
            //store the security questions to the file
            f << '\n';
            f << regques1;
            f << '\n';
            f << regques2;
            f << '\n';
            f << regques3;
            f << '\n';




        }
        else if (usercommand == "2")
        {

            for (int j = 0; j < 2; j++) {

                bool a = IsLogged();
                if (!a)
                {
                    cout << "incorrect username or password , please check again ." << endl;
                    
                }
                else if (a)
                {
                    cout << "Succesfully logged in ." << endl << endl;
                   

                }
                else {
                    cout << "Your account is locked,please contact with the adminstrator";
                }
              
            }
        }






        else if (usercommand == "3") {

            string ch;

            //open file, and then put the name and password into the strings
            ifstream file("file.txt");
            if (!file.is_open())
            {
                cout << "could not open file\n"; //just so that you know why it won't work if it doesn't
                return 0;
            }
            getline(file, new_username, '\n'); //reads the user name from file.txt
            getline(file, new_password, '\n'); //reads the password from file.txt
            getline(file, ques1, '\n');
            getline(file, ques2, '\n');
            getline(file, ques3, '\n');

            file.close();
            cout << "Forgotten ? We're here for help for retrieving\n";
            cout << "1.Search your id by username you remember" << endl;
            cout << "2.Search your id by password you remember" << endl;
            cout << "3.Come to Main menu" << endl;
            cout << "Enter your choice :";
            getline(cin, ch);
            if (ch == "1") {

                //forgotten username
                while (1)
                {
                    //user has to input the name and  question's answers here

                    cout << "\n\n\n"
                        << "Enter Username: ";
                    getline(cin, inName);


                    cout << "\n Security Q1: What is Your favorite color? Please enter everything in  lowercase";
                    cout << "\nPlease Enter the security question's answer:";
                    getline(cin, inques1);

                    cout << "\n Security Q2: What is your contact no: ?:";
                    cout << "\nEnter the security question's answer:";
                    getline(cin, inques2);

                    cout << "\n Security Q3: Where have you completed your high school ,(also specify city  and state)Please enter everything in  lowercase :";
                    cout << "\nEnter the security question's answer:";
                    getline(cin, inques3);

                    if (inName == new_username && inques2 == ques2 && inques3 == ques3 && inques1 == ques1)
                    {
                        cout << "\nFinding and Searching  Successful\n" 
                            << "Welcome, "
                            << inName;
                        cout << "\nYour retrieved password is:" << new_password;
                        break; //this will  exit the while loop if user  entered a valid / correct account credentials
                    }
                    cout << "incorrect username or security answers\n"; /
                }
                //now process the account

            }
            //forgotten password
            if (ch == "2")
            {


                while (1)
                {

                    cout << "\n\n\nEnter Password: ";
                    getline(cin, inPassword);

                    cout << "\n Security Q1: What is Your favorite color? Please enter everything in  lowercase :";
                    cout << "\nPlease Enter the security question's answer:";
                    getline(cin, inques1);

                    cout << "\n Security Q2: What is your contact no: ?:";
                    cout << "\nEnter the security question's answer:";
                    getline(cin, inques2);

                    cout << "\n Security Q3: Where have you completed your high school ,(also specify city  and state)Please enter everything in  lowercase :";
                    cout << "\nEnter the security question's answer:";
                    getline(cin, inques3);

                    if (inPassword == new_password && inques2 == ques2 && inques3 == ques3 && inques1 == ques1)
                    {
                        cout << "\nFinding and Searching  Successful\n"
                            << "Welcome, "
                            << new_username;
                        cout << "\nYour Username is:" << new_username;
                        break; //we have to exit the whole while loop if user has entered the valid account
                    }
                    cout << "incorrect password or security answers\n"; //if user entered the wrong account detals, then then the while loop is not done yet. So here we have this output "cout .."  without any if condition
                }
            }


        }

        //now process about the account

        cout << "\n\n\n\n\n"; //give it 5 newlines
       
    }
    }
   





