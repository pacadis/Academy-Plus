#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define FLAGS O_WRONLY | O_CREAT | O_TRUNC

int main()
{
int i = 5;
if (i < 0) return (0);
char *filename;
asprintf(&filename, "Sully_%d.c", i);
int fd;
fd = open(filename, FLAGS, 0644);
char *executable;
asprintf(&executable, "./Sully_%d", i);
i--;
char *command;
asprintf(&command, "gcc -Wall -Wextra -Werror %s -o %s", filename, executable);
char *str = "#include <stdio.h>%c#include <fcntl.h>%c#include <unistd.h>%c#include <stdlib.h>%c#define FLAGS O_WRONLY | O_CREAT | O_TRUNC%c%cint main()%c{%cint i = %d;%cif (i < 0) return (0);%cchar *filename;%casprintf(&filename, %cSully_%cd.c%c, i);%cint fd;%cfd = open(filename, FLAGS, 0644);%cchar *executable;%casprintf(&executable, %c./Sully_%cd%c, i);%ci--;%cchar *command;%casprintf(&command, %cgcc -Wall -Wextra -Werror %cs -o %cs%c, filename, executable);%cchar *str = %c%s%c;%cdprintf(fd, str, 10, 10, 10, 10, 10, 10, 10, 10, i, 10, 10, 10, 34, 37, 34, 10, 10, 10, 10, 34, 37, 34, 10, 10, 10, 34, 37, 37, 34,10, 34, str, 34, 10, 10, 10, 10, 10, 10, 10);%cclose(fd);%csystem(command);%csystem(executable);%creturn (0);%c}%c";
dprintf(fd, str, 10, 10, 10, 10, 10, 10, 10, 10, i, 10, 10, 10, 34, 37, 34, 10, 10, 10, 10, 34, 37, 34, 10, 10, 10, 34, 37, 37, 34,10, 34, str, 34, 10, 10, 10, 10, 10, 10, 10);
close(fd);
system(command);
system(executable);
return (0);
}
