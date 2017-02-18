#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <list>

using namespace std;

void disp(list<string>);
void search(list<string>);
void newfile(list<string>);
void deletesay(list<string>&, int);
void alphabet(list<string> &mylist, string);

int main(){
  //Initialize variables
  string filename;
  list<string> mylist;
  string newsaying;
  string currenttext;
  string word=" ";
  string outputfile;
  string holder,str1;
  ifstream ifs;
  ofstream ofs;
  int num;
  int choice,numsay;
  double n;
  
  //Choose file to open
  cout<<"Welcome to the sayings manager!:"<<endl;
  cout<<"Enter name of startup file: ";
  cin>>filename;

  ifs.open(filename);
  if(!ifs){
    cout<<"Error opening file"<<endl;
    return 1;
  }
  cin.ignore();
  
  //Turn text from startup file into a list that can be edited
  //give my list the first element of the file to have something with which to compare the second element of the file stream
  mylist.push_back(currenttext);
  getline(ifs,currenttext);
  mylist.push_back(currenttext); 
  while (!ifs.eof()){
    alphabet(mylist, currenttext);
    getline(ifs, currenttext);
  }



  ifs>>filename;
  while (choice !=6){
    cout<<"Tasks you can perform:"<<endl;
    cout<<"1: show all sayings."<<endl;
    cout<<"2: enter a new saying."<<endl;
    cout<<"3: list sayings that contain a given word."<<endl;
    cout<<"4: save all sayings in a new text file."<<endl;
    cout<<"5: delete a saying."<<endl; 
    cout<<"6: quit."<<endl;
    cout<<"Your choice? ";
    cin>>choice;
    
    //Show all sayings
    if (choice==1){
    disp(mylist);
    }
    //Enter a new saying
    else if (choice==2){
      int q=0;
      do{
          cout<<"Enter the new saying: ";
          cin.ignore();
          getline(cin,currenttext);
          if (currenttext!=""){
            alphabet(mylist,currenttext);
            cout<<"New saying has been entered."<<endl;
          }
          else {
            cout<<"Invalid input."<<endl;
          }
          cout<<"Do you want to enter a new saying? Yes=0, No=Any other number: "<<endl;
          cin>>q;
        }while (q==0);        
    }
    //list sayings that contain a given word
    else if (choice==3){
      search(mylist);
    }
    //save all sayings in a new text file
    else if (choice==4){
      newfile(mylist);
    }
    //Delete a saying
    else if (choice==5){
      cout<<"The sayings are: "<<endl;
      disp(mylist);
      cout<<"What number of saying would you like to delete?"<<endl;
      cin>>numsay;
      deletesay(mylist,numsay);
      cout<<"The new list sayings is: "<<endl;
      disp(mylist);  
    }
  }
}
//show all sayings
void disp(list<string> mylist){
  int i=1;
  for (auto it=mylist.begin(); it!=mylist.end();it++){
    cout<<i<<". "<<*it<<endl;
    i++;
  }
}
//list sayings that contain a given word
void search(list<string> mylist){
  string holder, word;
  cout<<"What word?"<<endl;
  cin>>word;
  for (auto it=mylist.begin();it!=mylist.end();it++){
    holder=*it;
    if (holder.find(word) != string::npos){
      cout<<*it<<endl;
    }
  }
}
//save all sayings in a new text file
void newfile(list<string> mylist){
  string outputfile;
  ofstream ofs;
  cout<<"What would you like to save the new file as?"<<endl;
  cin>>outputfile;

  ofs.open(outputfile);
  for (auto it=mylist.begin(); it!=mylist.end(); it++){
    ofs<<*it<<endl;
  }
  ofs.close();
}
//compare the sayings being added to those that are already sorted, and places it in alphabetical order.
void alphabet(list<string> &mylist, string currenttext){
   string str1;
   double n;

   for (auto it=mylist.begin();it!=mylist.end(); ++it){
     str1=*it;
     n=currenttext.compare(str1);
       if (n<0){
         mylist.insert(it,currenttext);
       }
    }
}
//delete a saying from the list
void deletesay(list<string> &mylist, int numsay){
  auto it=mylist.begin();
  advance(it,numsay-1);
  mylist.erase(it);
}
