#include"list.h"
#include<string>
#include<vector>
#include<algorithm>
int main(){
  ArrayList arr=ArrayList(4);
  List& list1=arr ;
  list1.add(100);
  list1.add(200);
  list1.print();
  list1.add(50);
  list1.add(70);
  list1.add(234);
  list1.print();
  LinkedList lnk=LinkedList();
  List& list2=lnk;
  list2.add(100);
  list2.add(200);
  list2.print();
  list2.add(50);
  list2.add(70);
  list2.add(234);
  list2.print();
  return 0;
}

/*

*/