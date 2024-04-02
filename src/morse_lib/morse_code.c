#include "main.h"

/* Define morse symbols string array */
static char * morse_symbol_str[] = {
	".-"/*A*/, 	"-..."/*B*/, "-.-."/*C*/,  "-.."/*D*/, "."/*E*/, "..-."/*F*/, "--."/*G*/, 
	"...."/*H*/, ".."/*I*/, ".---"/*J*/, "-.-"/*K*/, ".-.."/*L*/, "--"/*M*/, "-."/*N*/, 
	"---"/*O*/, ".--."/*P*/, "--.-"/*Q*/, ".-."/*R*/, "..."/*S*/, "-"/*T*/, "..-"/*U*/,
	"...-"/*V*/, ".--"/*W*/, "-..-"/*X*/, "-.--"/*Y*/, "--.."/*Z*/,
	"-----"/*0*/, ".----"/*1*/, "..---"/*2*/, "...--"/*3*/, "....-"/*4*/, "....." /*5*/,
	"-...."/*6*/, "--..."/*7*/, "---.."/*8*/, "----."/*9*/,
	".-..."/*&*/, "-.--."/*(*/, "-.--.-"/*)*/, ".-.-."/*+*/, "-...-"/*=*/, "-.-.--"/*!*/,
	"..--.."/*?*/, "-....-"/*-*/, ".----."/*'*/, ".-..-."/*"*/, "-..-."/*/*/, "--..--"/*,*/,
	".--.-."/*@*/, "---..."/*:*/, ".-.-.-"/*.*/,
    "........"/*ERROR*/
};

/* Define corresponding characters 
 * 39 is the ascii character number for the character '
 * The NUL character is assigned to error morse symbol
 */
static char morse_char_arr[] = {
	'A','B','C','D','E','F','G','H','I','J','K','L','M',
	'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'0','1','2','3','4','5','6','7','8','9','&','(',')',
	'+','=','!','?','-',39,'"','/',',','@',':','.',
    216
};

struct hsearch_data *load_morse_code_into_hashtable(void) {
	ENTRY item;
	ENTRY *item_ptr;
	const size_t capacity = sizeof(morse_symbol_str) / sizeof(morse_symbol_str[0]);
	/* Allocate memory for the hash table pointer */
	struct hsearch_data* hashtable = malloc(sizeof(struct hsearch_data*)); 
    assert("Failed to allocate memory" && hashtable != NULL);
	/* Create the hash table */
	hcreate_r(capacity, hashtable);
	/* Create hast table item and item pointer */
	/* Assign Values to the hash table */
	for (size_t i = 0; i < capacity; i++) {
		item.key = morse_symbol_str[i];
		item.data = (void*) &morse_char_arr[i];
		int hsrc_res = hsearch_r(item, ENTER, &item_ptr, hashtable);
		/* Ensure that there is no failure */
		assert("FAILED TO LOAD HASHTABLE" && hsrc_res);
	}
	return hashtable;
}

void clear_hashtable(struct hsearch_data *hashtable) {
	hdestroy_r(hashtable);
	free(hashtable);
}

char morse_char_to_roman_char(struct hsearch_data *hashtable, ENTRY item) {
	ENTRY *item_ptr;
	int hsrc_res = hsearch_r(item, FIND, &item_ptr, hashtable);
	assert("FAILED TO FIND CHARACTER FROM MORSE SYMBOL" && hsrc_res);
	return *(char *)item_ptr->data;
}
