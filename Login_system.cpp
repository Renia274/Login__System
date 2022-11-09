#include <iostream>
#include <fstream>
#include <string>
#include<iostream>
#include<fstream>
using namespace std;

bool Logged()

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
        usercommand, //to choose what user wants to do each time
        new_username, new_password, quesb, quesa, quesc,//the ones that will be found in the file(used a file named' registration.txt')
        inName, inPassword, inquesa, inquesb, inquesc, //the ones  user is giving in input from keyboard while verifications
        regquesb, regquesa, regquesc, userCommand;
   
    ; //add also what user is  giving in input while registering

    while (1) {
        cout << "  *******************************************************************************************************************\n\n";
        cout << "                              Welcome to lmy page                             \n\n\n";
        cout << "                                               Login Securely !!                                \n\n\n";
        cout << "  **************************************        OPTIONS:       *********************************************************\n\n";

        cout << "1.REGISTER" << endl;
        cout << "2.LOGIN" << endl;
        cout << "3.FORGOT PASSWORD (or) USERNAME" << endl;
        cout << "4.Exit" << endl;
        cout << "\nEnter your choice :";
        string choice;
        getline(cin, choice);

        if (choice == "1")
        {
            //open a file for registration
            ofstream g("file.txt"); //ofstream is  for getting the stored data from the file,
            //and the file does not need have to exist or made beforehand. It is 'ofstream', so , it'll take care of it for you..
            //but please be sure that if there is a file called "registration.txt" in the same folder as the
            //.exe file, the contents will be deleted/ overwritten

            if (!g.is_open()) //if it's not open, then there is no such file with the given name inside this folder (means, in the folder where the .exe file is going to be made )
            {
                cout << "could not open file registration.txt\n"; //just sowe can know why it ain't ;  workin , if it doesn't
                return 0;
            }
            cout << "\n\n\n" // newlines
                << "New Username: ";
            getline(cin, new_username); //user input from keyboard will go into registerName variable for registration
            cout << "New Password: ";
            getline(cin, new_password); //user input from keyboard will go into registerPassword variable fors registration
            cout << "\nFor Your security we ask you a question ,and for helping you if you ever forget your password   : ";
            cout << "\n Security Q1: What is Your favorite color? Please enter everything in  lowercase :";
            cout << "\nEnter the security question's answer:";
            getline(cin, regquesa);
            cout << "\n Security Q2: What is your contact no: ?:";
            cout << "\nEnter the security question's answer:";
            getline(cin, regquesb);
            cout << "\n Security Q3: Where have you completed your high school ,(also city  and state)Please enter everything in  lowercase :";
            cout << "\nEnter the security question's answer:";
            getline(cin, regquesc);

            g << new_username; //this put whatever's to the right (registerName) into , g (("registration.txt"))

            g << '\n'; //and change to anew line in file
            g << new_password; //and now write/store,the password
            //all data placed  safely insidea the file that g opened
            g << '\n';
            g << regquesa;
            g << '\n';
            g << regquesb;
            g << '\n';
            g << regquesc;
            g << '\n';
            

            

        }
        else if (choice == "2")
        {
            
            for (int j = 0; j < 2;j++) {
               
                    bool a = Logged();
                    if (!a)
                    {
                        cout << "incorrect username or password , please check again ." << endl;
                        break;
                    }
                    else if (a)
                    {
                        cout << "Succesfully logged in ." << endl << endl;
                        break;

                    }
                    else {
                        cout << "Your account is locked,please contact with the adminstrator";
                    }
                    break;
                }

            
            

        }
        else if (choice == "3") {

            string ch;
           
            //open file, and then put the name and password into the strings
            ifstream file("file.txt"); //ifstream is the one for getting data from the file, and
            //let us assume you've already created a file called "registration.txt"
            if (!file.is_open()) //if it's not open, then there is no such file with the given name inside
                //the folder (that is, in the folder where the .exe file is going to be)
            {
                cout << "could not open file\n"; //just so that you know why it won't work if it doesn't
                return 0;
            }
            getline(file, new_username, '\n'); //reads the user name from file f (which is using "registration.txt")
            getline(file, new_password, '\n'); //reads the password from file f (which is using "registration.txt")
            getline(file, quesa, '\n');
            getline(file, quesb, '\n');
            getline(file, quesc, '\n');
            //also, if you tell the file to get you that text up until '\n', that's when you know it reads
            //the whole line at most, and won't go any further
            //and that is done by the 3rd parameter
            file.close(); //you don't need it open now, since we now have the name and password from the file
            cout << "Forgotten ? We're here for help for retrieving\n";
            cout << "1.Search your id by username you remember" << endl;
            cout << "2.Search your id by password you remember" << endl;
            cout << "3.Come to Main menu" << endl;
            cout << "Enter your choice :";
            getline(cin, ch);
            if (ch == "1") {

                //forgot
                while (1)
                {
                    //user has to input the name and  question's answers here

                    cout << "\n\n\n"
                        << "Enter Username: ";
                    getline(cin, inName);


                    cout << "\n Security Q1: What is Your favorite color? Please enter everything in  lowercase";
                    cout << "\nPlease Enter the security question's answer:";
                    getline(cin, inquesa);

                    cout << "\n Security Q2: What is your contact no: ?:";
                    cout << "\nEnter the security question's answer:";
                    getline(cin, inquesb);

                    cout << "\n Security Q3: Where have you completed your high school ,(also specify city  and state)Please enter everything in  lowercase :";
                    cout << "\nEnter the security question's answer:";
                    getline(cin, inquesc);

                    if (inName == new_username && inquesb == quesb && inquesc == quesc && inquesa == quesa)
                    {
                        cout << "\nFinding and Searching  Successful\n" //the '\n' is a character, so we can add it and it will then automatically output a newline in the console, alongside the string
                            << "Welcome, "
                            << inName;
                        cout << "\nYour retrieved password is:" <<new_password;
                        break; //this will  exit the while loop if user  entered a valid / correct account credentials
                    }
                    cout << "incorrect username or security answers\n"; //if user entered wrong  account details then the while loop is not done yet and should be iterated again till
                    //the correct details are folled. So this cout is outside  without any if condition
                }
                //now process the account

            }
            if (ch == "2")
            {

                //forgot
                while (1)
                {
                    //user will input the name and password here
                    cout << "\n\n\nEnter Password: ";
                    getline(cin, inPassword);

                    cout << "\n Security Q1: What is Your favorite color? Please enter everything in  lowercase :";
                    cout << "\nPlease Enter the security question's answer:";
                    getline(cin, inquesa);

                    cout << "\n Security Q2: What is your contact no: ?:";
                    cout << "\nEnter the security question's answer:";
                    getline(cin, inquesb);

                    cout << "\n Security Q3: Where have you completed your high school ,(also specify city  and state)Please enter everything in  lowercase :";
                    cout << "\nEnter the security question's answer:";
                    getline(cin, inquesc);

                    if (inPassword == new_password && inquesb == quesb && inquesc == quesc && inquesa == quesa)
                    {
                        cout << "\nFinding and Searching  Successful\n" //the '\n' is a character, so we can  add it and it will then automatically output a newline in the console, alongside the string
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
    return 1;
}

 

    
    
