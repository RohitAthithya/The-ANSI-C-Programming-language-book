/*note that the book was written for UNIX terminals:
so we wont kinda get the Backspace characters and all 
for the modren terminals as they are OS controlled
kindly skip this , just remember the exercise's solution is that simple code given below.
*/
/*Write a program to copy its input to its output, replacing each tab by \t, each

backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an

unambiguous way.*/
/*expl.:
    copy i/p to o/p - replace the following as:
    tab space : '\t'
    backspace : '\b'
    backslash : '\\'

    //this makes the tabs and the backspaces visible in an unambiguous way
*/
/*Soln.:
    again use the finite state machine model of programming
    - getchar
    - check if i/p if other than \t \b or \ 
        -if yes, then putchar as such 
        -if no, then go to the next level of checking stuff
    - check if the i/p is \t
        -if yes, then printf("\\t");
        -if no, then go to the next level of checking stuff
    - do the same for the backspaces and backslash
*/
/*problem faced 1:
    the compiler could not read the backslash that was used:
*/
/*Soln. to prob 1: read: https://stackoverflow.com/questions/14206753/kr-1-10-the-terminal-eats-the-backspace
    We are not able to read the backslash because the OS is 
    handling the IO of the terminal we are working

    if on linux: typ
    e the next line after compiling/linking/loading and before opening the executable file
    "$ stty -icanon -echo; ./a.out; stty icanon echo"
    what happens:
        disables the 



*/


#include<stdio.h>
#include<stdlib.h>
//this is for method 1 where backspace did not work on the terminal and stuff
//#define CTRL(x)  (x & 0x1f)
//d = 100 or 0x64 and 0x1f

/*method 3:*/
main()
{
    int c;
    while((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            c = 't';
        }
        if (c == '\b')
        {
            putchar('\\');
            c = 'b';
        }
        if (c == '\\')
        {
            putchar('\\');
            c = '\\';
        }
        putchar(c);
    }
    
}
/*method 2:
        if(c != '\t')
            if(c != '\b')
                if(c != '\\')
                    putchar(c);
        */
/*method 1: the one that i did 
    int c = 0;// of course char works but it is better this way!
    //previously i put the others 's initialisation here!!!
    while(((c = getchar()) != EOF) && CTRL('d'))// i suppose we must enter -1 to get out of the loop otherwise
    {
        int others = 0;//part of method 1: //it is kind of a flag variable

        if(c == '\t')
        {
            printf("\\t");//putchar("\\"); putchar("t");
            others = 1;
        }
        if(c == '\b')
        {
            printf("\\b");//putchar("\\"); putchar("b");
            others = 1;
        }
        if(c == '\\') // it is not a single slash within the quotes
        {
            printf("\\\\");//putchar("\\"); putchar("\\");
            others = 1;
        }

        if( others == 0) //i had previously put: if(others == )...
            putchar(c);
    }
    //why is the code not simple => constraint to use only these above mentioned keywords!
}
*/

//command to execute on linux : 
// cd "terminals-eats-the-backspace" ; stty -icanon -echo; gcc -save-temps backspace-nope.c -o backspace-nope; ./backspace-nope; stty icanon echo