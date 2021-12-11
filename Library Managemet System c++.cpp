#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<ctype.h>
using namespace std;
void capital(char s[])
{
for(int i=0;i<=strlen(s);i++)
{
if(s[i]>=97 && s[i]<=122)
{

s[i]=s[i]-32;

}}
}

class books
{


public:
    int id;
    char name[30];
    void getdata();
    void showdata();


    int retid()
    {
        return id;
    }


}obj;

     void books :: getdata()
    {
        cout<<" Enter Book id :";
        cin>>id;
        cout<<"Enter Book Name :";
           cin.ignore();

       cin.getline(name,30);
       capital(name);






    }
       void books ::showdata()
    {
        cout<<"Book id :"<<id<<endl;

        cout<<"Book Name :"<<name<<endl;

        cout<<"------------------------------------------------------------------------";
        cout<<"\n";




    }
    void write()
{

    ofstream fp2;
    fp2.open("books.dat",ios::binary|ios::out|ios::app);
    obj.getdata();
    fp2.write((char*)&obj,sizeof(obj));
    fp2.close();
     cout<<"\n\nData Successfully Saved to File....\n\n";
    system("pause");
}
void read()
{

    ifstream fp1;
    fp1.open("books.dat",ios::in|ios::binary);
    while(fp1.read((char*)&obj,sizeof(obj)))
    {
        obj.showdata();
    }
fp1.close();
 cout<<"\n\nData Reading from file completed Successfully ....\n";

system("pause");
}

void searchdata(int n)
{
  int  check=0;;

    ifstream fp1;
     fp1.open("books.dat",ios::binary);
     while(fp1.read((char*)&obj,sizeof(obj)))
     {
       if(obj.retid()==n){
        obj.showdata();
        check++;
       }

     }
     fp1.close();
     if(check==0)

     {
         cout<<"The book  id . "<<n<<" not found....\n\n";
     }
cout<<"\n\nData Searching Successfully From  File....\n";
}

void searchdata(char s1[])
{

  int  check=0;



    ifstream fp1;
     fp1.open("books.dat",ios::binary);
     while(fp1.read((char*)&obj,sizeof(obj)))
     {
       if(strcmp(s1,obj.name)==0){
        obj.showdata();
        check++;
       }

     }
     fp1.close();
     if(check==0)

     {
          cout<<"The book  name . "<<s1<<" not found....\n\n";
     }
     cout<<"\n\nData Searching Successfully From  File....\n";
}

void modify(int n)

{
    int chk=0,currpos;
    fstream f;
    f.open("books.dat",ios::out|ios::binary|ios::in);
    while(f.read((char*)&obj,sizeof(obj)))
    {
        currpos=f.tellg();
        if(obj.retid()==n)
        {
             cout<<"The Following Book id. "<<n<<" will be modified with new data:\n\n";
                 obj.showdata();
                 cout<<"\n\nNow Enter the New Details of book....\n";
                 obj.getdata();
                 f.seekg(currpos-sizeof(obj));
                 f.write((char*)&obj,sizeof(obj));
                 chk++;

        }

    }
        f.close();
        if(chk==0)
        {
             cout<<"The book  id . "<<n<<" not found....\n\n";
             return ;
             }
             cout<<"\n\nData Modification Successfully Done in File....\n";
}

void modify(char s2[])

{

    int chk=0,currpos;
    fstream f;
    f.open("books.dat",ios::out|ios::binary|ios::in);
    while(f.read((char*)&obj,sizeof(obj)))
    {
         currpos=f.tellg();
        if(strcmp(s2,obj.name)==0)
        {
             cout<<"The Following Book name. "<<s2<<" will be modified with new data:\n\n";
                 obj.showdata();
                 cout<<"\n\nNow Enter the New Details of book....\n";
                 obj.getdata();
                 f.seekg(currpos-sizeof(obj));
                 f.write((char*)&obj,sizeof(obj));
                 chk++;}

    }
        f.close();
        if(chk==0)
        {
           cout<<"The book  name . "<<s2<<" not found....\n\n";
        }
         cout<<"\n\nData Updated Successfully Done in File....\n";
}
void deletes(int n)
{
 int  flag=0;
 ifstream fin;
 ofstream fout;

 fin.open("books.dat",ios::in|ios::binary);
 fout.open("Temp.dat",ios::out|ios::app|ios::binary);
while(fin.read((char*)&obj,sizeof(obj)))
 {
  if(n!=obj.retid())
  {
fout.write((char*)&obj,sizeof(obj));
  }
  else{
        cout<<"The Following book id. "<<n<<" has been deleted:\n";
    obj.showdata();
  flag++;
  }
}
 fout.close();
fin.close();
 if(flag==0)
  cout<<"The book id. "<<n<<" not found....\n\n";
 remove("books.dat");
 rename("temp.dat","books.dat");

}

void deletes(char s3[])
{
 int  flag=0;
 ifstream fin;
 ofstream fout;

 fin.open("books.dat",ios::in|ios::binary);
 fout.open("Temp.dat",ios::out|ios::app|ios::binary);

while(fin.read((char*)&obj,sizeof(obj)))
 {
 if(strcmp(s3,obj.name)!=0)
  {
fout.write((char*)&obj,sizeof(obj));
  }
  else{
        cout<<"The Following book name. "<<s3<<" has been deleted:\n";
    obj.showdata();
  flag++;
  }
}
 fout.close();

 fin.close();
 if(flag==0)
  cout<<"The book id. "<<s3<<" not found....\n\n";
 remove("books.dat");
 rename("temp.dat","books.dat");

}

void booksmanage()
{

    int num;
    do{
            system("cls");
            cout<< "0 for exit "<<endl;
            cout<< "1 for Add new record of books "<<endl;
            cout<< "2 for Show record of books "<<endl;
            cout<< "3 for Search record of books "<<endl;
            cout<< "4 for Modify record of books "<<endl;
            cout<< "5 for Delete record of books "<<endl;
            cout<< "Enter Your Choice : ";
            cin>>num;
            system("cls");
    switch(num)
    {
          case 1:write();break;
          case 2:read();break;
          case 3:

              { int n,num2;
                    char s1[30];
                    do{
                            system("cls");
                          cout<< "0 for go back "<<endl;
                          cout<<"1 For search records by book id "<<endl;
                          cout<<"2 For search records by book name "<<endl;
                          cout<< "Enter Your Choice : ";
                          cin>>num2;
                         system("cls");
                       switch(num2)
                      {
                          case 1: {
                           cout<<"Enter Book id to search : ";
                           cin>>n;
                           searchdata(n);
                           break;
                          }

                          case 2: {
                          cout<<"Enter Book name to search : ";
                          cin.ignore();
                          cin.getline(s1,30);
                          capital(s1);
                          searchdata(s1);
                          break;
                          }
                          break;
                      }

                   system("pause");
                    }while(num2);
              }


        case 4:

              {
                  int n1,num3;
                    char s2[30];
                    do{
                            system("cls");
                         cout<< "0 for go back "<<endl;
                         cout<<"1 For modify records by book id "<<endl;
                         cout<<"2 For modify records by book name "<<endl;
                          cout<< "Enter Your Choice : ";
                         cin>>num3;
                         system("cls");
                      switch(num3)
                      {
                          case 1: {
                           cout<<"Enter Book id to modify : ";
                           cin>>n1;
                           modify(n1);
                           break;
                          }

                          case 2: {
                          cout<<"Enter Book name to modify : ";
                          cin.ignore();cin.getline(s2,30);
                           capital(s2);
                           modify(s2);
                          break;
                          }

                      }
                      system("pause");


                    }while(num3);

              }

            case 5:
                    {
                          int n2,num4;
                          char s3[30];
                    do{
                            system("cls");
                         cout<< "0 for go back "<<endl;
                         cout<<"1 For delete records by book id "<<endl;
                         cout<<"2 For delete records by book name "<<endl;
                          cout<< "Enter Your Choice : ";
                         cin>>num4;
                         system("cls");
                      switch(num4)
                      {
                          case 1: {
                           cout<<"Enter Book id to delete : ";
                           cin>>n2;
                           deletes(n2);
                           break;
                          }

                          case 2: {
                          cout<<"Enter Book name to delete : ";
                          cin.ignore();cin.getline(s3,30);
                        capital(s3);
                           deletes(s3);
                          break;


                          }
                          break;
                      }
                      system("pause");


                    }while(num4);
         }
     system("pause");
        }
    }while(num);
}

int main()
{
booksmanage();
return 0;
}
