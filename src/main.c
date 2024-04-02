#include "main.h"
int main(int argc, char **argv) {
	/* Check if file paths are passed as inputs */
	assert("Missing file paths as input. Program requires files to operate" && argc > 1);
	/* Load hash-table for morse code */
	struct hsearch_data* hashtable = load_morse_code_into_hashtable();
	/* Loop that goes over all file paths that were passed as input */
	for(int i = 1; i < argc; i++) {
		/* Print the name of the file trying to open */
		printf("#FILE NAME: %s\n", argv[i]);
		/* Attempt to open the file */
		FILE *morse_file = fopen(argv[i], "r");
		/* Check if the file was successfully opened */
		assert("Failed to open the file. Check if it exists or if you are missing read permission" && \
				morse_file != NULL
		);
		/* Read morse code from the file and display decoded words */
		read_morse_display_word(morse_file, hashtable);
		/* Close the file */
		int fclose_res = fclose(morse_file);
		assert("Failed to close the file." && !fclose_res);
	}
	/* Clear the hash table */
	clear_hashtable(hashtable);
	return EXIT_SUCCESS;
}
