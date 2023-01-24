#include<stdio.h>

main()
{
    char data = 100;
    printf("%llu\n", &data);
    char* addr_data = &data;
    printf("%llu\n", addr_data);
    printf("%c\n", *addr_data);
    char value = *addr_data;
    printf("%c\n", value);

    *addr_data = 85;
    printf("%c\n", *addr_data);

}