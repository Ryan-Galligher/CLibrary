#ifndef controlLinkedLists
#define controlLinkedLists

void push_int(int val);
void push_float(float val);
void push_char(char * val);
void push(linkList ** head, int type, char * val);

int pop_int();
float pop_float();
char * pop_char();
returns pop(linkList ** head, int type);

int remove_last_int();
float remove_last_float();
char * remove_last_char();
returns remove_last(linkList * head, int type);

int remove_int_by_index(int index);
float remove_float_by_index(int index);
char * remove_string_by_index(int index);
returns remove_by_index(int type, int index);

int find_index(int type, char * info);

#endif
