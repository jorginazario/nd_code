#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void disp(vector<string>);
void nsaying(vector<string>&);
void search(vector<string>);
void newfile(vector<string>);

int main(){
  
  //Initialize variables
  string filename;
  vector<string> sayings;
  string newsaying;
  string currenttext;
  string word=" ";
  string outputfile;
  string holder;
  ifstream ifs;
  ofstream ofs;
  int choice;
  
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
  
  //Turn text from startup file into a vector that can be edited  
  while (getline(ifs,currenttext)){
    sayings.push_back(currenttext);
  }

  ifs>>filename;
  while (choice !=5){
    cout<<"Tasks you can perform:"<<endl;
    cout<<"1: show all sayings."<<endl;
    cout<<"2: enter a new saying."<<endl;
    cout<<"3: list sayings that contain a given word."<<endl;
    cout<<"4: save all sayings in a new text file."<<endl;
    cout<<"5: quit."<<endl;
    cout<<"Your choice? "; 
    cin>>choice;
    
    //Show all sayings
    if (choice==1){
      disp(sayings);                    
    }
    //Enter a new saying
    else if (choice==2){
      nsaying(sayings);
    }
    //list sayings that contain a given word
    else if (choice==3){
      search(sayings);
    }
    //save all sayings in a new text file
    else if (choice==4){
      newfile(sayings);  
    }  
  }  
}

//show all sayings
void disp(vector<string> sayings){  
  for (auto it=0; it<sayings.size();it++){
   cout<<sayings[it]<<endl;     
  }
}

//enter a new saying
void nsaying(vector<string>& sayings){
  string newsaying;
  cout<<"Write your next saying: ";
  cin.ignore();
  getline(cin,newsaying);
  sayings.push_back(newsaying);
}

//list sayings that contain a given word
void search(vector<string> sayings){
  string holder, word;
  cout<<"What word?"<<endl;
  cin>>word;
  for (auto it=sayings.begin();it<sayings.end();it++){
    holder=*it;
    if (holder.find(word) != string::npos){
      cout<<*it<<endl;
    }          
  }
}

//save all sayings in a new text file
void newfile(vector<string> sayings){
  string outputfile;
  ofstream ofs;
  cout<<"What would you like to save the new file as?"<<endl;
  cin>>outputfile;

  ofs.open(outputfile);
  for (auto it=sayings.begin(); it!=sayings.end(); it++){
    ofs<<*it<<endl;
  }
  ofs.close();
}
