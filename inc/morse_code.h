#ifndef MORSE_CODE_H
#define MORSE_CODE_H

/*Function Prototypes*/
extern struct hsearch_data *load_morse_code_into_hashtable(void);
extern void clear_hashtable(struct hsearch_data *);
extern char morse_char_to_roman_char(struct hsearch_data *, ENTRY);

#endif