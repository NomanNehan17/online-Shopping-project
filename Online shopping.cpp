#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void login();
void registr();
void forgot();
int choose;
int price;
int quantity;
char buy;
int credit;
void electronics();
void general_Items();
void cloths();
void cosmatics();
void MainMenu();
loginpage()
{
    int choice;
    cout<<"*************************************************************************\n\n\n";
    cout<<"                        Welcome To Login Page                               \n\n";
    cout<<"*******************             MENU       *****************************\n\n";
    cout<<"1.LOGIN"<< endl;
    cout<<"2.CREAT A NEW ACCOUNT"<< endl;
    cout<<"3.FORGOT PASSWORD (or) USERNAME"<< endl;
    cout<<"4.If you are login successful press 4 going To Shopping Menu"<< endl;
    cout<<"\nEnter your Choice : ";
    cin>> choice;
    cout<<endl;
    switch(choice)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout<<"Going To Shopping Menu\n\n";
        break;
    case 5:
        cout<<"Thanks for using this program\nThis program is created by Dipa\n\n" ;
        break;
    default:
        system("cls");
        cout<< "You've made a mistake,give it a try again\n"<<endl;
        loginpage();

    }


}
void login()
{
    int count;
    string user,pass,u,p;
    system("cls");
    cout<< "please enter the following details"<< endl;
    cout<< "USERNAME : ";
    cin>>user;
    cout<< "PASSWORD : ";
    cin>>pass;

    ifstream input ( "database.txt");
    while(input>>u>>p)
    {
        if(u==user && p==pass)
        {
            count =1;
            system( "cls");
        }
    }
    input.close();
    if(count==1)
    {
        cout<< "\nHello"<<user<<"\nLOGIN SUCCESS\nWe're glad that you're here.\nThanks for logging in\n\n";
        cout<< "\nPress any key to go to the mainmenu. \n";
        cin.get();
        cin.get();
        loginpage();
    }
    else
    {
        cout<< "\nLOGIN ERROR\n\nPlease check your username and password\n\n\n";
        loginpage();
    }
}
void registr()
{
    string reguser,regpass,ru,rp;
    system( "cls");
    cout<< "Enter the username : ";
    cin>>reguser;
    cout<< "\nEnter the password :";
    cin>>regpass;

    ofstream reg ("database.txt",ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    system( "cls");
    cout<< "\nCreated Your Account Successfully\n";
    loginpage();

}
void forgot()
{
    int ch;
    system( "cls" );
    cout<< "Forgotten ? We're here for help\n";
    cout<< "1.Search your id by username"<<endl;
    cout<< "2.Search your id by password"<<endl;
    cout<< "3.Main menu"<<endl;
    cout<< "Enter your choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            int count=0;
            string searchuser,su,sp;
            cout<< "\nEnter your remembered username :";
            cin>>searchuser;

            ifstream searchu("database.txt");
            while(searchu>>su>>sp)
            {
                if(su==searchuser)
                {
                    count=1;
                }

            }
            searchu.close();
            if(count==1)
            {
                cout<< "\n\nYour,account found\n";
                cout<< "\nYour password is "<<sp;
                cin.get();
                cin.get();
                system( "cls");
                loginpage();

            }
            else
            {
                cout<< "\nSorry,Your userID is not found in our database\n";
                cout<< "\nPlease kindly contact your system administrator for more details \n";
                cin.get();
                cin.get();
                loginpage();

            }
            break;
        }
        case 2:
            {
                int count=0;
                string searchpass,su2,sp2;
                cout<< "\nEnter the remembered password :";
                cin>>searchpass;

                ifstream searchp("database.txt");
            while(searchp>>su2>>sp2)
            {
                if(sp2==searchpass)
                {
                    count=1;
                }

            }
            searchp.close();
            if(count==1)
            {
                 cout<< "\nYour password is found in the database \n";
                cout<< "\nYour id is : "<<su2;
                cin.get();
                cin.get();
                system( "cls");
                loginpage();

            }
            else
            {
                cout<< "Sorry,We cannot found your password in our database\n";
                cout<< "\nkindly contact your administrator for more information\n";
                cin.get();
                cin.get();
                loginpage();
            }
            break;


            }
        case 3 :
            {
              cin.get();
              loginpage();
            }
        default :
            cout<< "Sorry,You entered wrong choice. Kindly try again"<< endl;
            forgot();

    }


}
int main()
{
    loginpage();
    MainMenu();

    return 0;

}
void MainMenu()
{
    void electronics();
    void general_Items();
    void cloths();
    void cosmatics();
    lebel1:
    system( "cls");
    cout<<"**************************************************";
    cout<<"\n\n\n\t\t Welcome To Online Shopping System\n\n\n";
    cout<<"***********************************************";
    cout<<"\n\n\nChoose anyone from below :"<<endl<<endl<<
     "1. Electronics Gadegets : "<<endl<<
     "2. General Items :"<<endl<<
     "3. Cloths :"<<endl<<
     "4. Cosmatics:"<<endl<<endl<<"Your choice :";
    cin>>choose;
    switch(choose)
    {
    case 1:
        electronics();
        break;
    case 2:
        general_Items();
        break;
    case 3:
        cloths();
        break;
    case 4:
        cosmatics();
        break;
    default:
        cout<< "You have entered the wrong index"<<endl;
        goto lebel1;

    }


}
void electronics()
{
    system( "cls");
    cout<<"**************************************************";
    cout<<"\n\n\n\t\t Electronics Section\n\n\n";
    cout<<"***********************************************";
    cout<<"\n\n\nChoose anyone from below :"<<endl<<endl<<
     "1. Fridge : "<<endl<<
     "2. AC :"<<endl<<
     "3. Computer/Laptop :"<<endl<<
     "4. Smart Phone:"<<endl<<endl<<"Your choice :";
    cin>>choose;
    if (choose ==1)
    {
        system( "cls");
        price = 5000;
    cout<<"**************************************************";
     cout<<"\n\nFridge Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the Fridge .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy Fridge your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Y or N) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
         cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
               cout<< "You have successfully bought the fridge :";
               system ( "pause");
               MainMenu();

           }
           else
           {
               MainMenu();
           }

     }

    }
    else if(choose == 2)
    {
        price = 6000;
        system( "cls");
    cout<<"**************************************************";
     cout<<"\n\nAC Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the AC .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy AC your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
         cout<< "Enter your creditr card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
               cout<< "You have successfully bought the AC :";
               system ( "pause");
               MainMenu();
           }
           else
           {
             MainMenu();
           }
    }

}
else if(choose == 3)
{
      price = 7000;
        system( "cls");
    cout<<"**************************************************";
     cout<<"\n\nComputer Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the Computer .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy Computer your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
          cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
               cout<< "You have successfully bought the Computer :";
               system ( "pause");
               MainMenu();
           }
           else
           {
             MainMenu();
           }
     }

}
else if(choose == 4)
{
    price = 8000;
        system( "cls");
    cout<<"**************************************************";
     cout<<"\n\nSmart Phone Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the Smart Phone .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy Smart Phone your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
         cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
               cout<< "You have successfully bought the Smart Phone :";
               system ( "pause");
               MainMenu();

           }
           else
           {
               MainMenu();

           }

     }

}
}
void general_Items()
{
     system( "cls");
    cout<<"**************************************************";
    cout<<"\n\n\n\t\t GENERAL ITEMS\n\n\n";
    cout<<"***********************************************";
    cout<<"\n\n\nChoose anyone from below :"<<endl<<endl<<
     "1. RICE : "<<endl<<
     "2. PULSE :"<<endl<<
     "3. VEGETABLE :"<<endl<<
     "4. SPICE:"<<endl<<endl<<"Your choice :";
    cin>>choose;
    if (choose ==1)
    {

        system( "cls");
         price = 500;
    cout<<"**************************************************";
     cout<<"\n\n RICE Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the RICE  .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy  RICE your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
         cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
                cout<< "You have successfully bought the RICE :";
               system ( "pause");
               MainMenu();
           }
           else
           {
              MainMenu();
           }

     }

    }
    else if(choose == 2)
    {
          price = 600;
        system( "cls");
    cout<<"**************************************************";
     cout<<"\n\nPULSE Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the PULSE .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy PULSE your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
           cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
              cout<< "You have successfully bought the PULSE :";
               system ( "pause");
               MainMenu();
           }
           else
           {
               MainMenu();
           }

     }

    }
    else if(choose == 3)
    {
      price = 700;
        system( "cls");
    cout<<"**************************************************";
     cout<<"\n\nVEGETABLE Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the VEGETABLE .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy VEGETABLE your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
        cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
               cout<< "You have successfully bought the VEGETABLE :";
               system ( "pause");
               MainMenu();
           }
           else
           {
               MainMenu();
           }
     }
    }
    else if(choose == 4)
    {
        price = 800;
        system( "cls");
    cout<<"**************************************************";
     cout<<"\n\nSPICE Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the SPICE .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy SPICE your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
         cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
               cout<< "You have successfully bought the SPICE :";
               system ( "pause");
               MainMenu();
           }
           else
           {
               MainMenu();
           }
     }
    }
}
void cloths()
{
    system( "cls");
    cout<<"**************************************************";
    cout<<"\n\n\n\t\t CLOTHS SECTION\n\n\n";
    cout<<"***********************************************";
    cout<<"\n\n\nChoose anyone from below :"<<endl<<endl<<
     "1. SHIRT : "<<endl<<
     "2. T. SHIRT :"<<endl<<
     "3. JEANS :"<<endl<<
     "4. DRESS:"<<endl<<endl<<"Your choice :";
    cin>>choose;
    if (choose ==1)
    {
        system( "cls");
         price = 1000;
    cout<<"**************************************************";
     cout<<"\n\n SHIRT Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the SHIRT  .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy  SHIRT your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
         cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
               cout<< "You have successfully bought the SHIRT :";
               system ( "pause");
               MainMenu();
           }
           else
           {
                  MainMenu();
           }
     }
    }
     else if(choose == 2)
     {
           price = 2000;
        system( "cls");
    cout<<"**************************************************";
     cout<<"\n\nT. SHIRT Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the T. SHIRT .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy T. SHIRT  your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
          cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
               cout<< "You have successfully bought the T. SHIRT :";
               system ( "pause");
               MainMenu();
           }
           else
           {
               MainMenu();
           }
     }
     }
     else if(choose == 3)
     {
        price = 3000;
        system( "cls");
    cout<<"**************************************************";
     cout<<"\n\nJEANS Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the JEANS .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy JEANS  your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
         cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
               cout<< "You have successfully bought the JEANS :";
               system ( "pause");
               MainMenu();
           }
           else
           {
               MainMenu();
           }
     }
     }
     else if(choose == 4)
     {
          price = 4000;
        system( "cls");
    cout<<"**************************************************";
     cout<<"\n\nDRESS Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the DRESS .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy DRESS  your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
          cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
                cout<< "You have successfully bought the DRESS :";
               system ( "pause");
               MainMenu();
           }
           else
           {
                 MainMenu();
           }
     }
     }
}
void cosmatics()
{
   system( "cls");
    cout<<"**************************************************";
    cout<<"\n\n\n\t\tCOSMATIC SECTION\n\n\n";
    cout<<"***********************************************";
    cout<<"\n\n\nChoose anyone from below :"<<endl<<endl<<
     "1. NAILPAINT : "<<endl<<
     "2. MEHENDI :"<<endl<<
     "3. BINDI :"<<endl<<
     "4. PAYEL:"<<endl<<endl<<"Your choice :";
    cin>>choose;
    if (choose ==1)
    {
        system( "cls");
         price = 50;
    cout<<"**************************************************";
     cout<<"\n\nNAILPAINT  Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the NAILPAINT  .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy  NAILPAINT your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
          cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
                cout<< "You have successfully bought the NAILPAINT :";
               system ( "pause");
               MainMenu();
           }
           else
           {
                MainMenu();
           }
     }
    }
     else if(choose == 2)
     {
          price = 60;
        system( "cls");
    cout<<"**************************************************";
     cout<<"\n\nMEHENDI Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the MEHENDI .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy MEHENDI  your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
         cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
               cout<< "You have successfully bought the MEHENDI :";
               system ( "pause");
               MainMenu();
           }
           else
           {
               MainMenu();
           }
     }
     }
     else if(choose == 3)
     {
         price = 70;
        system( "cls");
    cout<<"**************************************************";
     cout<<"\n\nBINDI Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the BINDI .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy BINDI  your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {
         cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
               cout<< "You have successfully bought the BINDI :";
               system ( "pause");
               MainMenu();
           }
           else
           {
               MainMenu();
           }
     }
     }
     else if(choose == 4)
     {
         price = 80;
        system( "cls");
    cout<<"**************************************************";
     cout<<"\n\nPAYEL Area\n\n";
     cout<<"**************************************************";
     cout<<"\n\nYou are about to purchase the PAYEL .\n";
     cout<<"Price :"<<price<<endl;
     cout<<"How many items you want to purchase : ";
     cin>>quantity;
     cout<<"you want to buy PAYEL  your items are("<<quantity<<")"<<endl;
     cout<<"Your total price :"<<quantity*price<<endl;
     cout<< "Do you want to buy (Yes or No) :";
     cin>>buy;
     if(buy=='y'||buy=='Y')
     {

         cout<< "Enter your credit card number :";
         cin>>credit;
         cout<< "You have entered this credit card number :" <<credit<<endl;
           cout<<"Press 1 to buy\n Press any key to go to the Main Menu\n\n\nYour Choice :";
           cin>>choose;
           if(choose == 1)
           {
               cout<< "You have successfully bought the PAYEL :";
               system ( "pause");
               MainMenu();
           }
           else
           {
               MainMenu();
           }
           }
     }

}



