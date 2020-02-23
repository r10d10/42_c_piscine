#ifndef __PARSE_H__
#define __PARSE_H__

unsigned int get_number_length(const char *string);

unsigned int get_spaces(const char *string);

unsigned int get_words(char *string);

int parse_dict_number(const char *line, unsigned int length,
		      unsigned int *order, unsigned int *idx);

char *dupstr(const char *str);

#endif
