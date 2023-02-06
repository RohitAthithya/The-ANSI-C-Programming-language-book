/*
            Exercise 1-19. Write a function reverse(s) that reverses the character string s. 
            Use it to write a program that reverses its input a line at a time.
*/

#include<stdio.h>
#include<stdint.h>

#define CTRL(x) x & 0x1F 
#define MAXLINE 1000

void reverse(char[], int );
int getLine(char[]);
main()
{
    int c;
    int string[MAXLINE];
    int length = getline(string);
    printf("the reverse of the input is : %s", );
}

int getLine(char string[])
{
    int chr = 0, i;
    for(i = 0; (i < MAXLINE) && ( chr = getchar() )!='\n' && chr != CTRL('d') ; ++i)
    {
        string[i] = chr;
    }
    if(chr == '\n')
    {
        string[i] = '\n';
        ++i;
    }
    string[i] = '\0'; //makes sure that the end contains '\0'

    return i;// the length of the input!
}

void reverse(char str[], int length)
{
    char temp[length];
    int i = 0;
    while(str[i]!='\0')
    {
        temp[i] = str[length - i];
        ++i;
    }
    temp[i+1] = '\0';
    //end the program
}