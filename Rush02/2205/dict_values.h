#ifndef __DICT_VALUES_H__
#define __DICT_VALUES_H__

const char *dict_get(unsigned int order, unsigned int idx);

void dict_values_init(void);

int dict_values_parse_line(char *line);

//const char* dict_values_get(unsigned int order, unsigned int idx);

void dict_values_destroy(void);

// REMOVE THIS
void dict_values_show(void);

#endif
