#ifndef READ_H
#define READ_H

/* Comment by adding the // before #define PRINTF_MAX_CHAR_LIMIT
 * remove to the line feed when the last word printed exceeds the maximum line capacity.
 * Therefore, if there is a URL or a very long word it will exceed the limit quite a lot.
 */
#define PRINTF_MAX_CHAR_LIMIT 102

extern void read_morse_display_word(FILE *morse_file, struct hsearch_data *);

#endif
