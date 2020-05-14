#include <stdio.h>
#include <fcntl.h>
#define FILENAME "Grace_kid.c"
#define FLAGS O_WRONLY | O_CREAT | O_TRUNC
#define FT(x) int    main(void) {int fd = open(x, FLAGS, 0644); char *str = "#include <stdio.h>%c#include <fcntl.h>%c#define FILENAME %cGrace_kid.c%c%c#define FLAGS O_WRONLY | O_CREAT | O_TRUNC%c#define FT(x) int    main(void) {int fd = open(x, FLAGS, 0644); char *str = %c%s%c; dprintf(fd, str, 10, 10, 34, 34, 10, 10, 34, str, 34, 10, 10, 10, 10, 10, 10, 10); return (0);}%c%c/*%c  this is a comment%c*/%c%cFT(FILENAME)%c"; dprintf(fd, str, 10, 10, 34, 34, 10, 10, 34, str, 34, 10, 10, 10, 10, 10, 10, 10); return (0);}

/*
  this is a comment
*/

FT(FILENAME)
