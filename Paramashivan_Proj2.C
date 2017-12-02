/*
Name: Ashwin Paramashivan
Date: 12/4/17
ProjName: Balanced Parenthesis
Class: CS 421 MW 2:30 - 3:45 pm
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector <char> v; //Creates a vector with a type

//Purpose: To push an element into a stack
//Parameter: Take a element character as a datatype
void push(char elem)
{
  v.push_back(elem);
}

//Purpose: To pop an element from a stack
//Parameter: Pass by reference character as a datatype
void pop(char& elem)
{
  elem = v[v.size()-1];
  v.pop_back();
}

//Purpose: To find the top element of the stack
//Parameter: Pass by reference char as a datatype
int topElem(char& elem)
{
  elem = v[v.size() - 1];
  return elem;
}

//Purpose: To display the entire stack vertically
void displayAll()
{

  if (v.empty())
    cout << " | Z | " << endl << " ----- " << endl;
  else
    {
      for(int i = v.size()-1; i >= 0; i--)
	{
	  cout << " | " << v[i] << " | " << endl;
	}
      cout << " | Z | " << endl << " ----- " << endl;
    }
}

//Purpose: The main purpose of this program is to check to see if the paranthesis are balanced or not. 
int main()
{
  char elem; //Element as char
  ifstream inFile; //Creates a file datatype of inFile
  string str; //String to read a set of parenthesis
  int Line = 0; //Initializes the Line counter to 0. Counts every line

  //If the file has a wrong name then it is unable to open the file.
  if(!inFile)
    cout << "Error: Unable to open the file. \n Must use the filename 'input.txt'. \n";

  inFile.open("input.txt"); //Opens the file 'input.txt'.	
	
  while(inFile >> str) //Reads the string in the line
	  {
	    cout << "Reading line " << ++Line << endl; //Uses a prefix to set the line counter to one.
	    for (int j = 0; j < str.length(); j++) //Counts every character in the string.
	      {
		elem = str[j];
		
		//If the first character in the string reads ')' or ']' and if the stack is empty then the parser moves to the trap state and displays that the parenthesis is not balanced.
		if((elem == ')' || elem == ']') && v.empty()) 
		  {
		    cout << "Reading " << elem << endl;
		    cout << "Moving to trap state. " << endl;
		    push(elem);
		    displayAll();
		    break;
		  }

	  switch(elem)
	    {
	    case '(': //Reads '(', pushes '(' on to the stack and displays the stack.
	      push(elem);
	      cout << "Reading " << elem << endl;
	      cout << "Pushing " << elem << endl;
	      displayAll();
	      break;
	    case '[': //Reads '[', pushes '[' on to the stack and displays the stack.
	      push(elem);
	      cout << "Reading " << elem << endl;
	      cout << "Pushing " << elem << endl;
	      displayAll();
	      break;
	    case ')':{ //Reads ')', pops '(' out of the stack and displays the stack.
	      cout << "Reading " << elem << endl;
	      if(topElem(elem) == '(')
		{
		  pop(elem);
		  cout << "Popping " << elem << endl;
		}
	      displayAll();
	      break;
	    }
	    case ']':{ //Reads ']', pops '[' out of the stack and displays the stack.
	      cout << "Reading " << elem << endl;
	      if(topElem(elem) == '[')
		{
		  pop(elem);
		  cout << "Popping " << elem << endl;
		}
	      displayAll();
	      break;
	    }

	    default: //If it reads anything besides a parenthesis then we leave the stack as it is. 
	      cout << "Reading " << elem << endl;
	      displayAll();
	      break;
	
	    }
	  }
	  cout << "----------------" << endl;
	  cout << "Finished reading. " << endl;
	  cout << "----------------" << endl;

	  if(v.empty()) //If the stack is empty then we move to a final state and show that the parenthesis are balanced.
	    {
	      cout << "Moving to final state. " << endl;
	      displayAll();
	      cout << "The parenthesis are balanced. " << endl;
	    }
	  else //If not then the parenthesis are not balanced and we must empty the stack by poping the remaining elements in the stack so we can start with an empty stack when reading a string from a new line.
	    {
	      displayAll();
	      cout << "The parenthesis are not balanced. " << endl;
	      while(!v.empty())
		pop(elem);
	    }

	  }
  inFile.close();
    
  return 0;
}
