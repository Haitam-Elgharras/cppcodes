#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;
class List{
  protected :
    int size;
  public:
    virtual void moveFirst()=0;
    virtual void moveNext()=0;
    virtual void movePrevious()=0;
    virtual int getValue()const =0;
    virtual bool hasNext()const=0;
    virtual bool isEmpty()const =0;
    virtual void add(int )=0;
    virtual void print()const=0;
};

class Node{
  private :
    int value;
    Node *next;
  public :
  Node(int value,Node* next=nullptr){
    this->value=value;
    this->next=next;
  }
  void print()const{
    cout<<value<<" ->";
  }
  friend class LinkedList;
};
class LinkedList:public List{
  private :
    Node *head,*tail,*cursor;
  public :
    LinkedList(){
      head=tail=cursor=nullptr;
      size=0;
    }
    void moveFirst(){
      if(isEmpty())throw "moveFirst Exception: The list is empty!!!";
      cursor=head;
    }
    void moveNext(){
      if(isEmpty())throw "moveNext Exception: The list is empty!!!";
      cursor=cursor->next;
    }
    void movePrevious(){
      if(isEmpty())throw "movePrevious Exception: The list is empty!!!";
      if(cursor==tail)return;
      Node *temp=head;
      while(temp->next!=cursor)temp=temp->next;
      cursor=temp;
    }
    int getValue()const{
      if(isEmpty())throw "getValue Exception : The list is empty!!!";
      return cursor->value;
    }
    bool hasNext()const{
      return cursor->next!=nullptr;
    }
    bool isEmpty()const{
      return head==nullptr;
    }
    void add(int x){
      if(isEmpty())head=tail=cursor=new Node(x);
      else{
        cursor->next=new Node(x,cursor->next);
        cursor=cursor->next;
      }
      size++;
    }
    void print()const{
      if(isEmpty())
        cout<<"The list is empty!!!"<<endl;
      else{
        cout<<"size: "<<size<<endl;
        cout<<"Values: ";
        Node *temp=head;
        while(temp!=nullptr){
          temp->print();
          temp=temp->next;
        }
        cout<<endl;
      }
    }    
};

class ArrayList:public List{
  private :
    int *values;
    int cursor;
    int maxSize;
  public :
    ArrayList(int maxSize){
      this->maxSize=maxSize;
      values=new int[maxSize];
      size=0;
      cursor=-1; //synonym of empty list
    }
    void moveFirst(){
      if(isEmpty())throw "moveFirst Exception: The list is empty!!!";
      cursor=0;
    }
    void moveNext(){
      if(isEmpty())throw "moveNext Exception: The list is empty!!!";
      if(cursor==size-1)return;
      cursor++;
    }
    void movePrevious(){
      if(isEmpty())throw "movePrevious Exception: The list is empty!!!";
      if(cursor==0)return;
      cursor--;
    }
    int getValue()const{
      if(isEmpty())throw "getValue Exception : The list is empty!!!";
      return values[cursor];
    }
    bool hasNext()const{
      return cursor<size-1;
    }
    bool isEmpty()const{
      return size==0;
    }
    void add(int x){
      if(isEmpty())
        values[++cursor]=x;
      else{
        if(size==maxSize){
          maxSize*=2;
          int *temp=new int[maxSize];
          copy(values,values+cursor+1,temp);
          temp[++cursor]=x;
          copy(values+cursor,values+size,temp+cursor+1);
          delete[] values;
          values=temp;
        }
        else{
          for(int i=size-1;i>cursor;i--)values[i+1]=values[i];
          values[++cursor]=x;
        }
      }
      size++;  
      //print();
    }
    void print()const{
      if(isEmpty())
        cout<<"The list is empty!!!"<<endl;
      else{
        cout<<"size: "<<size<<endl;
        cout<<"cursor: "<<cursor<<endl;
        cout<<"Values: ";
        for(int i=0;i<size;i++)
          cout<<values[i]<<",";        
        cout<<endl;
      }
    }
};