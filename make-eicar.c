#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main(void) {
  char file[] = "./eicar.txt";
  char part1[] = "X5O!P%@AP[4\\PZX54(P^)7CC)7}$";
  char part2[] = "EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*";

  int fh;

  /* write part 1 */
  if( (fh = open(file, O_CREAT|O_RDWR, 0666)) < 0 ) {
    perror(file);
    return 1;
  }
  if( write(fh, part1, sizeof(part1)-1) < 0 ) {
    perror(file);
    return 1;
  }
  if( close(fh) < 0) {
    perror(file);
    return 1;
  }

  /* append part 2 */
  if( (fh = open(file, O_APPEND|O_RDWR)) < 0 ) {
    perror(file);
    return 1;
  }
  if( write(fh, part2, sizeof(part2)-1) < 0 ) {
    perror(file);
    return 1;
  }
  if( close(fh) < 0) {
    perror(file);
    return 1;
  }

  /* over */
  return 0;
}
