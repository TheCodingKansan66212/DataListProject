#include "pythonList.h"

// Constructors
PythonList::PythonList(void)   // this method is correct
{
	itemCount = 0;            
}

PythonList::PythonList(const PythonList & listParm)    // copy constructor, this method is correct
{
    itemCount = listParm.itemCount;
	for ( int i = 0; i < itemCount; i++)
		data[i] = listParm.data[i];
}

PythonList::PythonList( const string info[], int num_cells)   // this method is correct
{
    itemCount = num_cells;
	for ( int i=  0; i < itemCount; i++)
		data[i] = info[i];
}




// Python Methods
void PythonList::append(string item)
{
	

}
void PythonList::extend(const PythonList & listToAdd)
{
   

}
void PythonList::insert(int index, string itemToInsert) // the if-loop increments through the data occupying the array, the for-loop decrements through the array cells. 
{
	if (index == itemCount) 
	{
		data[itemCount] = itemToInsert; //puts the new item at the end of the array, where the first empty slot is available. 
		itemCount++; //increment statement increases the #'s in itemCount by 1. 
		return; //use "return" statement @the end of every code to indicate that you're done with the method. 
				//step 1: data[4] = data[3]
				//step 2: data[3] = data[2]
				//step 3: data[2] = itemToInsert; --> this is how the "if" loop works. 
				// step 4: itemCount = 5; --> generally form is: data[index] = itemToInsert;

				// member function: each function has its own copy of the data. 
				//regular function: each function borrows the data from the original array.
	}
	for (int i = itemCount; i > index; i--)
	{
		data[i] = data[i - 1]; // data[1 - 1] looks at the neighbor to the left, moves the digits occupying each space and moves it to the right. In the loop, moves down the array until the cell index
								// has been moved over. 
	}
	data[index] = itemToInsert;
	itemCount++;

}
void PythonList::remove(string itemToRemove) //Remove the first item from the list whose value is itemToRemove. 
	       // It is an error if there is no such item.
{
	

}
string PythonList::pop(int positionToRemove) //pop vs. insert: pop == someone is removed from the group in order to insert the new data.
											// insert == all items are shifted over one cell in order to make room for the new number. 
{

	return ""; // Dummy Statement to get to compile

}

string PythonList::pop()                      // remove the last item in the list
{
	return ""; // Dummy Statement to get to compile
}

int  PythonList::index(string itemToFind) const // Return the index in the list of the first item whose value is xitemToFind. 
	    // It is an error if there is no such item.
{
	
	
	return -100;    // Dummy Statement to get to compile
}

int  PythonList::count(string itemToCount) const
{
        
	return -100;    // Dummy Statement to get to compile
}

void PythonList::sort()                     //   sort the list in place, will not implement a 
{
	


}

	                                         
void PythonList::reverse()                 //   reverse the elements in place
{


}

// functions with List arguments

int len(const PythonList & parm)      // Correct Code
{
	return parm.itemCount;
}

int    comp(const PythonList & left, const PythonList & right) // -1, 0, or 1
{
	return -100;    // Dummy Statement to get to compile

}

string max(const PythonList & aList)
{
	string large = "";
	for (int i = 0; i < aList.itemCount; i++)
	{
		if (aList.data[i]  > large) large = aList.data[i];
	}
	return large;    // Dummy Statement to get to compile

}

string min(const PythonList & aList)
{
	return " ";    // Dummy Statement to get to compile

}

// Python operators

bool PythonList::operator == ( const PythonList & right) const
{
   
	return true;      // Dummy Statement to get to compile
}

//  if a is["bill", "sue", "sam", "ann"]
//  a[-1] is "ann", a[-2] is "sam", a[-3] is "sue" and a[-4] is "bill"
string &   PythonList::operator [] (int index)                        //  index operator for l-value
{
    if ( index >= 0 ) return data[index];                         // CORRECT CODE
	return data[itemCount + index];                // for negative values of index
}

const string & PythonList::operator[](int index) const               //  index operator for r-value
{
	if ( index >= 0 ) return data[index];                        // CORRECT CODE
	return data[itemCount + index];                // for negative values of index
}

PythonList PythonList::operator+(const PythonList & right) const    //  will return by value a concateneated list
{
	PythonList ans;    // Dummy Code to get to compile


	return ans;
}

PythonList PythonList::operator*(int times) const                    //  see documentation for behavior of * operator
{
	PythonList ans;    // Dummy Code to get to compile
	

	return ans;
}


// operators that must be implemented as friends since the left operand is NOT a PythonList

bool inOperator(string lookFor, const PythonList & listToCheck)
	                     //  Python syntax 
	                     //   horsemen = ["war", "famine", "pestilence", "death"]
                         //  "pestilence" in horsemen
{

	return true;    // Dummy Statement to get to compile
}

bool notInOperator(string lookFor, const PythonList & listToCheck)   //  use the inOperator and negate the return value 
{

	return true;    // Dummy Statement to get to compile
}





//  useful operator for the C++ PythonList class, but not in Python

	            //   output in the form:   ["apple","pear","peach"]
ostream & operator << ( ostream & out, const PythonList & parm)                  // this operator is correct
{
	out << '[';
	for ( int i = 0; i < parm.itemCount; i++)
	{
		out << '"' << parm.data[i] << '"';
		if ( i != (parm.itemCount - 1) ) out << ',';
	}
	out << ']';
	return out;
}

// the = operator is correct
const PythonList & PythonList::operator=(const PythonList & right)  // this is NOT the python = operator, which creates an alias
{	                                                         //  rather, this operator changes the object on the left side of the = operator
    if ( this == & right ) return *this;
    itemCount = right.itemCount;
    for ( int i = 0; i < itemCount; i++)
	    data[i] = right.data[i];

    return *this;

}