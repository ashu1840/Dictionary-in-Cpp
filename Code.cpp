#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class dictionary
{
 private:
 char meaning[300];
 char pron[100];
 public:
 char word[100];
 void accept()
  {
   cout<<endl<<"enter word";
   cin>>word;
   cout<<endl<<"enter meaning";
   cin>>meaning;
   cout<<endl<<"pronounce";
   cin>>pron;
  }
 void display()
 {
  cout<<endl<<"********************************";
  cout<<endl<<"word is : "<<word;
  cout<<endl<<"meaning is : "<<meaning;
  cout<<endl<<"pronounced as : "<<pron;
 }
};
dictionary obj;
//class ends here
 void search()
  {
    fstream rd;
    rd.open("C:\\Users\\officeworks\\Desktop\\project\\ashutosh diction\\diction.txt",ios::in);
    char nm[50];
    cout<<endl<<"enter word to be searched";
    cin>>nm;
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof (obj);
    rd.seekg(0,ios::beg);
    int flag=0;
    for(int i=1;i<=size;i++)
     {
        rd.read((char*)&obj,sizeof (obj));
        if(strcmp(nm,obj.word)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<endl<<"word not found";
    }
    else
    {
        obj.display();
    }
 }
 void addrecord()
  {
  obj.accept();
  fstream wr;
  wr.open("C:\\Users\\officeworks\\Desktop\\project\\ashutosh diction\\diction.txt",ios::app);
  wr.write((char*)&obj,sizeof(obj));
  cout<<endl<<"object written successfully";
  }
  void viewrecord()
  {
    fstream rd("C:\\Users\\officeworks\\Desktop\\project\\ashutosh diction\\diction.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof (obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size;i++)
    {
      rd.read((char*)&obj,sizeof(obj));
      obj.display();
    }
  }
 void removerecord()
 {
    fstream rd;
    rd.open("C:\\Users\\officeworks\\Desktop\\project\\ashutosh diction\\diction.txt",ios::in);
    fstream wr("C:\\Users\\officeworks\\Desktop\\project\\ashutosh diction\\temp.txt",ios::out);
    char nm[50];
    cout<<endl<<"enter word to be removed";
    cin>>nm;
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof (obj);
    rd.seekg(0,ios::beg);
    int flag=0;
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof (obj));
        if(strcmp(nm,obj.word)==0)
        {
            cout<<endl<<"word removed";
        }
        else
        {
            wr.write((char*)&obj,sizeof (obj));
        }
    }
        rd.close();
        wr.close();
        remove("C:\\Users\\officeworks\\Desktop\\project\\ashutosh diction\\diction.txt");
        rename("C:\\Users\\officeworks\\Desktop\\project\\ashutosh diction\\temp.txt","C:\\Users\\officeworks\\Desktop\\project\\ashutosh diction\\diction.txt");
  }
    void updaterecord()
    {
        fstream rd;
        rd.open("C:\\Users\\officeworks\\Desktop\\project\\ashutosh diction\\diction.txt",ios::in);
        fstream wr("C:\\Users\\officeworks\\Desktop\\project\\ashutosh diction\\temp.txt",ios::app);
        char nm[50];
        cout<<endl<<"enter word to be updated";
        cin>>nm;
        rd.seekg(0,ios::end);
        int size=rd.tellg()/sizeof (obj);
        rd.seekg(0,ios::beg);
        int flag=0;
        for(int i=1;i<=size;i++)
        {
            rd.read((char*)&obj,sizeof (obj));
            if(strcmp(nm,obj.word)==0)
            {
             obj.accept();
             wr.write((char*)&obj,sizeof(obj));
            }
            else
            {
                wr.write((char*)&obj,sizeof(obj));
            }
        }
            rd.close();
            wr.close();
            remove("C:\\Users\\officeworks\\Desktop\\project\\ashutosh diction\\diction.txt");
            rename("C:\\Users\\officeworks\\Desktop\\project\\ashutosh diction\\temp.txt","C:\\Users\\officeworks\\Desktop\\project\\ashutosh diction\\diction.txt");
   }
void main()
{
    int a;
    cout<<endl<<"enter 1 to add words";
    cout<<endl<<"enter 2 to view all words";
    cout<<endl<<"enter 3 to search words";
    cout<<endl<<"enter 4 to remove words";
    cout<<endl<<"enter 5 to edit words";
    cout<<endl<<"enter 6 to exit";
    cin>>(a);
    switch(a)
    {
    case 1:
        {
        addrecord();
        break;
        }
    case 2:
        {
        viewrecord();
        break;
        }
    case 3:
        {
        search();
        break;
        }
    case 4:
        {
        removerecord();
        break;
        }
    case 5:
        {
        updaterecord();
        break;
        }
    case 6:
        {
        cout<<"exit";
        break;
        }
     default:
        {
            cout<<"invalid";
        }
   }
}

