#include <stdio.h>

void    print(void)
{
char *str = "#include <stdio.h>%c%cvoid    print(void)%c{%cchar *str = %c%s%c;%cprintf(str, 10, 10, 10, 10, 34, str, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);%c/*%c  this is first comment%c*/%c}%c%c/*%c  this is second comment%c*/%c%cint    main(void)%c{%cprint();%creturn (0);%c}%c";
printf(str, 10, 10, 10, 10, 34, str, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);
/*
  this is first comment
*/
}

/*
  this is second comment
*/

int    main(void)
{
print();
return (0);
}
