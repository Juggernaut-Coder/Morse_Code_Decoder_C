#include "main.h"

/* PRINTF_MAX_CHAR_LIMIT is defined in read.h and is commented. If you want a fixed line-width please uncomment it */

/* Global variables */
char morse_buff[MORSE_BUFFER_SIZE];
int morse_buff_idx = 0;

/* local functions */
static char read_morse_return_char(FILE *morse_file, struct hsearch_data *hashtable) {
    int read_char;

    while( ( read_char = fgetc( morse_file ) ) != ' ' && read_char != '\n' )
        morse_buff[morse_buff_idx++] = read_char;
    
    morse_buff[morse_buff_idx] = '\0';
    morse_buff_idx = 0;

    ENTRY item = {.key = morse_buff};

    return morse_char_to_roman_char(hashtable,item);
}

void read_morse_display_word(FILE *morse_file, struct hsearch_data *hashtable) {
    #ifdef PRINTF_MAX_CHAR_LIMIT
    int current_char_count = 0;
    #endif
    int read_char;

    do {
        while( ( read_char = fgetc( morse_file ) ) != ' ' && read_char != EOF && read_char != '\n' ) {
            morse_buff[morse_buff_idx++] = read_char; /* append char in morse_buff */
            putchar(read_morse_return_char(morse_file,hashtable));
            #ifdef PRINTF_MAX_CHAR_LIMIT
            current_char_count++;
            #endif
        }
        putchar(' ');
        #ifdef PRINTF_MAX_CHAR_LIMIT
        current_char_count++;
        if(current_char_count > PRINTF_MAX_CHAR_LIMIT) {
            putchar('\n');
            current_char_count = 0;
        }
        #endif
    } while( read_char != EOF && fgetc(morse_file) != EOF );
    putchar('\n');
}

