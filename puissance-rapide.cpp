#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
  int data;
  struct element *next;
} Element;

Element *getLast(Element *L)
{
  Element *current = L;
  while (current->next != NULL)
  {
    current = current->next;
  }
  return current;
}

Element *createElement(int data)
{
  Element *e = (Element *)malloc(sizeof(Element));
  e->data = data;
  e->next = NULL;
  return e;
}

void insertData(int data, Element *L)
{
  Element *e = createElement(data);
  if (L == NULL)
  {
    L = e;
    return;
  }
  getLast(L)->next = e;
}

void displayList(Element *L)
{
  Element *current = L;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main()
{
  Element *L;
  L = NULL;
  L = createElement(0);
  insertData(1, L);
  insertData(2, L);
  insertData(3, L);
  insertData(4, L);
  displayList(L);
  return 0;
}
