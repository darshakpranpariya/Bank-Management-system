#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class BankManagment
{
private:
    int ac_no;
    char pn[20];
    char name[20];
    int balence;
    char ac_type[10];
    int password;
public:
    BankManagment()
    {
        ac_no=0;
        strcpy(name,"Enter a name");
        strcpy( ac_type,"s");
        balence=0;
        password=0;
    }
    void getdata()
    {
        string ch;
        cout<<"\nEnter a  New Account Number\n";
        cin>>ac_no;
        cout<<"\nEnter your New password\n";
        cin>>password;
        cin.ignore();
        cout<<"\nEnter your Name With Sirname\n";
        cin.getline(name,20);
        cout<<"\nEnter your Account Type\n";
        cout<<"s:saving  o:others\n";
        cin>>ch;
        if(ch=="s")
            strcpy(ac_type,"Saving");
        else
            strcpy(ac_type,"others");
        cin.ignore();
        cout<<"\nEnter your phone number\n";
        cin>>pn;
        cin.ignore();
        cout<<"\nEnter a balance in to your New Account\n";
        cin>>balence;
    }
    void showdata()
    {
        cout<<endl<<endl<<"     "<<ac_no<<"    "<<name<<"     "<<ac_type<<"       "<<pn<<"      "<<balence<<endl;
        cout<<" ----------------------------------------------------------------"<<endl;
    }
    int add_account()
    {
        ofstream fout;
        fout.open("file1.txt",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        return(1);
    }
    void view_all_account()
    {
        cout<<" ---*-----------*------------*-------------*------------*-------"<<endl;
        cout<<"     "<<"AC_NO"<<"       "<<"NAME"<<"       "<<"AC_TYPE"<<"       "<<"PHONE_NO"<<"       "<<"BALANCE"<<endl;
         cout<<" --*-----------*------------*-------------*------------*--------"<<endl;
        ifstream fin;
        fin.open("file1.txt",ios::binary);
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            showdata();
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }
    int add_amount(int ac)
    {
        if(balence==0&&password==0)
            cout<<"\nFirst made Account.............\n";
        else{
        fstream fout;
        int counter=0;
        fout.open("file1.txt",ios::in|ios::out|ios::binary|ios::ate);
        fout.seekg(0);
        fout.read((char*)this,sizeof(*this));
        while(!fout.eof())
        {
            if(ac_no==ac){
                int p;
                cout<<"\nEnter your Account password : ";
                cin>>p;
               if(password==p)
               {
                cout<<"\n Account Holder Name is : "<<name<<endl;
                int am;
                cout<<"\nEnter a Amount : ";
                cin>>am;
                balence=balence+am;
                cout<<"\nYour Total balance is :"<<balence;
                 cout<<"\n Amount Add successfully.............";
                fout.seekg(fout.tellp()-sizeof(*this));
                fout.write((char*)this,sizeof(*this));
                counter=0;
                break;}
                else
                    cout<<"\npassword is wrong Enter correct password......... ";
                         }
                         else
                            counter=1;
          fout.read((char*)this,sizeof(*this));
        }
        if(counter)
            cout<<"\n Account Number is Does not exits\n";
        fout.close();}

    }
     int withdraw_amount(int ac)
    {
        if(balence==0&&password==0)
            cout<<"\nFirst made Account.............\n";
        else{
        fstream fout;
        fout.open("file1.txt",ios::in|ios::out|ios::binary|ios::ate);
        fout.seekg(0);
        fout.read((char*)this,sizeof(*this));
        while(!fout.eof())
        {
            if(ac_no==ac){
                     int p;
                cout<<"\nEnter your Account password : ";
                cin>>p;
               if(password==p)
               {
                cout<<"\n Account Holder Name is : "<<name<<endl;
                int am;
                cout<<"\nEnter a Amount for withdraw : ";
                cin>>am;
                if(am<=balence){
                balence=balence-am;
                cout<<"\nYour Remaining balance is :"<<balence;
                fout.seekg(fout.tellp()-sizeof(*this));
                fout.write((char*)this,sizeof(*this));
                 cout<<"\n Amount withdraw successfully.............";}
                else
                    cout<<"\n Not Sufficient Balance In Account.............\n";
                }
             else
                    cout<<"\npassword is wrong Enter correct password......... ";

        }
          fout.read((char*)this,sizeof(*this));
        }
        fout.close();}
    }
    void search_account(int acc)
    {
        if(balence==0&&password==0)
            cout<<"\nFirst made Account.............\n";
        else{
        ifstream fout;
        int counter=0;
        fout.open("file1.txt",ios::in|ios::binary);
        fout.read((char*)this,sizeof(*this));
        while(!fout.eof())
        {
            if(ac_no==acc){

                     int p;
                cout<<"\nEnter your Account password : ";
                cin>>p;
               if(password==p)
               {
                showdata();
                counter=0;
                break;}
                else
                    cout<<"\npassword is wrong Enter correct password......... ";
            }
            else
                counter=1;

            fout.read((char*)this,sizeof(*this));
        }
        if(counter==1)
            cout<<"\nAccount Does not exists";
       fout.close();}
    }
     int update_account(int a1)
    {
        if(balence==0&&password==0)
            cout<<"\nFirst made Account.............\n";
        else{
        fstream fout;
        fout.open("file1.txt",ios::in|ios::out|ios::ate|ios::binary);
        fout.seekg(0);
        fout.read((char*)this,sizeof(*this));
        while(!fout.eof())
        {
            if(ac_no==a1){
                           int p;
                cout<<"\nEnter your Account password : ";
                cin>>p;
               if(password==p)
               {
                getdata();
                fout.seekg(fout.tellp()-sizeof(*this));
                fout.write((char*)this,sizeof(*this));
                cout<<"\nAccount Update Successfully.............\n";}
                 else
                    cout<<"\npassword is wrong Enter correct password......... ";
                        }

          fout.read((char*)this,sizeof(*this));
        }
        fout.close();}
    }
     void delete_account(int ac)
    {
        if(balence==0&&password==0)
            cout<<"\nFirst made Account.............\n";
        else{
        ifstream fin;
        ofstream fout;
        fin.open("file1.txt",ios::in|ios::binary);
        if(!fin)
        {
            cout<<"\nFile Doesn't exists";
        }
        else{
            fout.open("tempfile1.txt",ios::out|ios::binary);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
               if(ac_no!=ac)
                {
                    fout.write((char*)this,sizeof(*this));
                }
                else{
                int p;
                cout<<"\nEnter your Account password : ";
                cin>>p;
               if(password==p)
                    cout<<"\n Account delete successfully.............";
               else{
                   fout.write((char*)this,sizeof(*this));
                    cout<<"\npassword is wrong Enter correct password......... ";}
                }
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
            fout.close();
            remove("file1.txt");
            rename("tempfile1.txt","file1.txt");
            }}
    }
    void forgot_password()
    {
        char hint[30];
        cin.ignore();
        cout<<"\n Enter your Email-Id for getting the password........\n";
        cin.getline(hint,29);
        cout<<"\n You will get Your Pass-word Soon********\n";
    }
};
int main()
{
    BankManagment ob1;
    int ch;

    while(1)
    {
        system("cls");
        cout<<"\n\n";
         cout<<"    1.ADD Your New Account"<<endl;
         cout<<"    2.View All The Account"<<endl;
         cout<<"    3.ADD Amount in Your Account"<<endl;
         cout<<"    4.Withdraw Amount from your Account"<<endl;
         cout<<"    5.Search Account in Bank"<<endl;
         cout<<"    6.Modify your Account"<<endl;
         cout<<"    7.Delete your Account"<<endl;
         cout<<"    8.Forgot Password"<<endl;
         cout<<"    9.exit "<<endl;
         cout<<endl;
        cout<<"Enter Your Choice\n";
        cin>>ch;
         switch(ch)
         {
         case 1:
            ob1.getdata();
            ob1.showdata();
            ob1.add_account();
            cout<<"\n Account made successfully.............";
            break;
         case 2:
            ob1.view_all_account();
             break;
         case 3:
             int a1;
             cout<<"\nEnter your Account Number\n";
             cin>>a1;
             ob1.add_amount(a1);
              break;
         case 4:
             int a2;
             cout<<"\nEnter your Account Number\n";
             cin>>a2;
             ob1.withdraw_amount(a2);
              break;
         case 5:
            int a3;
             cout<<"\nEnter your Account Number\n";
             cin>>a3;
             ob1.search_account(a3);
              break;
         case 6:
              int a4;
             cout<<"\nEnter your Account Number\n";
             cin>>a4;
             ob1.update_account(a4);
              break;
         case 7:
             int a5;
             cout<<"\nEnter your Account Number\n";
             cin>>a5;
             ob1.delete_account(a5);
              break;
         case 8:
              ob1.forgot_password();
              break;
         case 9:
            exit(0);
             break;
         };
         getch();
     }
}
