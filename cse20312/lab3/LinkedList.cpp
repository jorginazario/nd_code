/*LinkedList.cpp*/

#include<iostream>
#include<string>

using namespace std;

//Node struct
template<typename T>		//templating
struct Node{			//Node Struct
	T data;
	Node<T> *next;
	Node(const T &);
};

//List Struct
template<typename T>
struct List{
	List();		//Constructor
	~List();	//Deconstructor
	Node<T> *head=NULL;	//Node*(pointer) called head initialized to nullptr
	void pushFront(T &);	//pushFront()
	void print();	//prints content of list
};

//constructor for Node struct
template<typename T>
Node<T>::Node(const T &info) :data(info),next(NULL) {}

//constructor for list struct (empty body)
template<typename T>
List<T>::List() :head(NULL) {}

//destructor
template<typename T>
List<T>::~List() {

	Node<T> *temp=head;
	while (temp != NULL) {
		Node<T> *next = temp->next; // retrieve this node's "next" before we clobber it	
		delete temp;
		temp = next;	
	}
}

//pushfront function
template<typename T>
void List<T>::pushFront(T &data) {
	Node<T> *nn= new Node<T>(data);	//new Node
	nn->next=head;
	head=nn; 	
}

//print function
template<typename T>
void List<T>::print() {
	Node<T> *temp=head;
	while (temp != NULL) {
		cout << temp->data;
		temp=temp->next;
	}
	cout<<endl;
}

template<typename T>
List<T> addNumberLists(List<T> &, List<T> &);	//function implementation 

//main function

int main(){
	string numString1, numString2;
	int value;
	while (cin>>numString1>>numString2 && !cin.eof()){	
		List<int> myList1;      //initialize list object of strings
		List<int> myList2;      //initialize list object of strings
		for (int i=0; i<numString1.length(); i++){
			value=numString1[i]-48;
			myList1.pushFront(value);	//pushFront numStrings
		}
		for (int j=0; j<numString2.length();j++){
			value=numString2[j]-48;	
			myList2.pushFront(value);	
		}	
		addNumberLists(myList1, myList2).print();

                          
	}
}

template<typename T>
List<T> addNumberLists(List<T> &l1, List<T> &l2){
	List<int> myList3;
	int carry=0;
	int value;
	Node<T> *t1=l1.head;
	Node<T> *t2=l2.head;
	while (t1 != NULL || t2 != NULL || carry==1){
		if (t1 != NULL && t2 != NULL){
			value=t1->data + t2->data + carry;
			carry=0;
			t1=t1->next;
			t2=t2->next;
			if (value >=10){
				value=value%10;
				carry=1;
				myList3.pushFront(value);
			}
			else {
				myList3.pushFront(value);
			}				
		}
		else if (t1 == NULL && t2 != NULL){
			value=t2->data + carry;
			t2=t2->next;
			carry=0;
			if (value>=10){
				value=value%10;
				carry=1;
				myList3.pushFront(value);
			}
			else {
				myList3.pushFront(value);
			}
				
		}
		else if (t1 != NULL && t2 == NULL){
			value= t1->data + carry;
			t1=t1->next;
			carry=0;
			if (value>=10){
				value=value%10;
				carry=1;
				myList3.pushFront(value);
			}
			else {
				myList3.pushFront(value);
			}
		}
		else if (t1 == NULL && t2 == NULL && carry==1){
			myList3.pushFront(carry);
			carry=0;	
		}
	}
	return myList3;
	
}

                                                  
