
/** Linked list VI - Using an object and operators to do the dirty work 
    Add an iterator class */

   // ~cps330/Examples/list_VI.C 

#include <stream.h>
#include <String.h>

class Data_line {
  public:
    String contents;
    Data_line *next;
  }; // End of Data_list class

class Data_list {
  private:
    Data_line *top;            // Will point to the top element

  public:
    Data_list() { top = NULL; cout << "List constructed\n"; }
    ~Data_list() { cout << "List destructing\n" ; }
  
    void operator += (String str);  
    friend ostream & operator << ( ostream & os, const Data_list & listval);
    friend istream & operator >> ( istream & is, const Data_list & listval);
    friend class Data_iter;
} ;

class Data_iter {
  private:
    Data_line * current;
    Data_list & List;
  public:
    Data_iter(const Data_list & Parm_list ) : List(Parm_list) { init(); }
    init() { current = List.top; } 
    String & operator () () { return(current->contents); }
    int operator ! () { return( current != NULL ) ; }
    void operator ++ () { current = current->next; } 
} ;

void Data_list::operator += (const String str) 

{

  Data_line *ptr;            // Will point to the new element
  Data_line *prev;           // Previous element (during search)
  Data_line *curr;           // Current element (during search)

  ptr = new Data_line;  // Allocate an object

  ptr->contents = str;    // Copy string into new space

  // Find the position in the list
    
  curr = top;
  prev = NULL;
  while(curr != NULL ) {
    if ( curr->contents > str ) break;
    prev = curr;
    curr = curr->next;
  }

  if ( prev == NULL ) {
     ptr->next = top;
     top = ptr;
  } else {
     ptr->next = curr;
     prev->next = ptr;
  }
} // End of Data_list::operator += 

ostream & operator << ( ostream & os, const Data_list & listval) {
  Data_line *ptr;
  ptr = listval.top; 
  while ( ptr != NULL ) {
    os << ptr->contents << "\n";
    ptr = ptr->next;
  }
  return os;
}

istream & operator >> ( istream & is, Data_list & listval) {
  String input_string;
  cout << "Enter a list element\n";
  readline(is,input_string);
  if ( is.eof() ) return is;
  listval += input_string;
  return is;
}

main() {

  Data_list stuff;          // Our ADT
  Data_iter i(stuff);       // Our Iterator

  cout << "Welcome to the beginning of the program\n";

  while(1) { 
    cout << "Enter a string \n";
    cin >> stuff;
    if ( cin.eof() ) break;
  }

  cout << "Here is your list using an iterator...\n";
  for(i.init(); !i ; i++ ) {
    cout << i() << "\n";
  }

  cout << "Another style of iterator usage...\n";

  for(Data_iter itvar(stuff); !itvar ; itvar++ ) {
    cout << itvar() << "\n";
  }

  cout << "End of the program\n";


}
