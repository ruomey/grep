#include <stdio.h>
#include <ctype.h>
int main()
{
    int i = 0;
    //ASCII value of all non-printable character
    int asciiValue[] =
    {
        0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
        17,18,19,20,21,22,23,24,25,26,27,28,29,30,31
    };
    //Get array size
    const int arraySize = sizeof(asciiValue)/sizeof(asciiValue[0]);
    // looping through all elements of array
    for (i = 0; i < arraySize; ++i)
    {
        if(isprint(asciiValue[i])!= 0)
        {
            //print
            printf("%c ", asciiValue[i]);
        }
    }
    return 0;
}