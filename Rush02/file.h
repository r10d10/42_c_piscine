#ifndef __FILE_H__
#define __FILE_H__

int open_file(const char *path);

int read_file_line(char **ptr);

void close_file(void);

#endif
