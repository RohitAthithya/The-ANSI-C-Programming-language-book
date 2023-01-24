#include<stdio.h>

main()
{
    int c;
    //type any char
     _flushall();
    int a = (getchar() != EOF);
    printf("%d\n", a);;

    _flushall();
    //don't type -1
    //type ctrl+z => as in windows prompt the end of file is denoted by ^Z
    a = getchar() != EOF ;
    printf("%d\n", a);

}