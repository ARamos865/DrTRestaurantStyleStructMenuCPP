#include <ios> // Provides ios_base::failure
#include <iostream> // Provides cin
#include<string> //for string manipulation
#include<sstream> //for string manipulation and comparison
using namespace std;

//Function Prototypes
int getValidInt(string);
short getValidShort(string);
double getValidDouble(string);
char getValidChar(string);
bool getValidBool(string);
string getValidString(string);

template <typename T>
T getValidatedInput()
{
T result;
cin >> result;

// Check if the failbit has been set, meaning the beginning of the input
// was not type T. Also make sure the result is the only thing in the input
// stream, otherwise things like 2b would be a valid int.
if (cin.fail() || cin.get() != '\n')
{
// Set the error state flag back to goodbit. If you need to get the input
// again (e.g. this is in a while loop), this is essential. Otherwise, the
// failbit will stay set.
cin.clear();

// Clear the input stream using and empty while loop.
while (cin.get() != '\n')
;

// Throw an exception. Allows the caller to handle it any way you see fit
// (exit, ask for input again, etc.)
throw ios_base::failure("Invalid input.");
}

return result;
}

template <typename T>
T tryGetValidInput(string message)
{
T input;
while (true)
{
cout << message;

try
{
input = getValidatedInput<T>();
}
catch (exception e)
{
cerr << e.what() << ": Invalid input." << endl;
continue;
}

break;
}
  
return input;
}

//Function Definitions
int getValidInt(string message = "")
{
return tryGetValidInput<int>(message + "Enter an integer: ");
}
short getValidShort(string message = "")
{
return tryGetValidInput<short>(message + "Enter an integer: ");
}
double getValidDouble(string message = "")
{
return tryGetValidInput<double>(message + "Enter a number with or without decimals (double): ");
}
char getValidChar(string message = "")
{
return tryGetValidInput<char>(message + "Enter a single letter or number (1 digit): ");
}
bool getValidBool(string message = "")
{
int value = -1;
while (value != 0 && value != 1)
{
value = tryGetValidInput<int>(message + "Enter 1 (true) or 0 (false): ");
if (value != 0 && value != 1)
cout << "Invalid input." << endl;
}
return value;
}
string getValidString(string message = "")
{
return tryGetValidInput<string>(message + "Enter a word (no spaces): ");
}