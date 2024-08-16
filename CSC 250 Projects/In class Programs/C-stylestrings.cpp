// c-string porcessing functions

// c-string is a null terminated array of characters
// it is a char array, the chars in it belong together
//to some string or phrase
// there is a null character
// after the last valid char to the array and so the c-string
// is null-terminated

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int PHRASE_LENGTH = 51;

// function to determine the current length of a string.
int findStringlength(char str[]);

// function to convert the lower case characters to uppercase
void convertStringToUpper(char str[]);


int main()
{
    int str_length;
    char phrase[PHRASE_LENGTH] = {""};

    // read a phrase from the user
    cout << "Enter a phrase: ";
    cin.getline(phrase, PHRASE_LENGTH);

    str_length = findStringlength(phrase);

    cout << phrase << " contains " << str_length << " Characters.\n";

    cout << phrase << " contains " << strlen(phrase) << " Characters.\n";

    convertStringToUpper(phrase);

    cout << "Your phrase in upper case is " << phrase;

    return 0;
}

// function to determine the length of the string

int findStringlength(char str[])
{
    int count = 0;

    // c-string processing function
    // to process
    while(str[count] !='\0')
    {
        count++;
    }

    return count;
}

void convertStringToUpper(char str[])
{
    int count = 0;

    while(str[count] !='\0')
    {
        str[count] = toupper(str[count]);

        count++;
    }

    return;
}

