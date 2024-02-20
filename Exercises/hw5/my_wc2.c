//Michele Barrantes
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/***********
Psuedocode:
define a function initialize_buffer that takes a character array as input
    initialize count to zero
    initialize ch to zero
    while ch is not equal to end of file and count is less than the buffer size
        read a character from input and store it in ch
        store the character in the buffer at the current count index
        increment count by 1
    if count is equal to zero
        return -1
    otherwise
        return the count of characters stored in the buffer

define a function report_word_count that takes a character array as input
    initialize a delimiter string
    initialize a portion variable to null
    split the input string into words using the delimiter
    initialize a word count variable to zero
    while there are still portions left in the split string
        increment the word count by 1
        get the next portion of the split string
    return the word count

define a function print_options that takes no input
    print out the available command options

define the main function
    initialize the input buffer to a size of 10 characters
    initialize the length of the input string to zero
    allocate memory for the input buffer dynamically
    initialize a flag for counting to zero
    initialize the last command entered to a space character
    print out a prompt for the user to enter commands
    while the end of standard input has not been reached
        read a line of input from standard input into a separate input buffer
        split the input buffer by spaces
        for each token in the split string
            if the token is "-c"
                set the counting flag to 1
            if the token is "-h"
                call the print_options function
            if the token starts with "-"
                set the last command entered to the second character in the token
            otherwise, use a switch statement to handle the last command entered
                if the command is "l"
                    print out the line count
                if the command is "c"
                    call the initialize_buffer function and print out the character count
                if the command is "w"
                    call the report_word_count function and print out the word count
                if the command is "f"
                    print out each word in the input and its frequency
                if the command is "v"
                    print out all information (equivalent to "-l -c -w -f")
                if the command is "h"
                    call the print_options function
                if the command is "d"
                    print out debugging information to stderr
    free the dynamically allocated input buffer memory
    return 0
************/

#define STRING_INDEX_HEADER
#define BUFFER_SIZE 80
#define WORD_LIMIT 100
#define NOT_FOUND -1
#define WD_BGN  0
#define WD_END  1
#define MAX_INPUT 100
#define MAX_WORD_LENGTH 50 

//this function returns total chars
int count_chars(char *input_string) {
    int count = 0;//counter
    int len = strlen(input_string); //len of string
//for loop to count chars in index [i] until len has been reached. 
    for (int i = 0; i < len; i++) {
        if (input_string[i] != '\0' && input_string[i] != '\n') {
            count++;
	    printf("%c", input_string[i]);
        }
    }

    return count;
}
//this function returns the line count
int count_lines(char *input[]) {
    int line_count = 0; //counter
    const char delimiters = "\n";
    char *token = strtok(input, delimiters); // tokenize input using newline as delimiter
    while (token != NULL) {
        line_count++;
        token = strtok(NULL, "\n"); // move to the next token
    }
    return line_count;
}

//this function returns the word count
/*
int report_word_count(char buffer[]){
        char d [] = " ,."; //delimeter
        char *portion = strtok(buffer,d);
//      printf("%s\n", portion);
        int word_count = 0;
        while(portion != NULL){
                word_count++;
                portion = strtok(NULL, d);
        }
        return word_count;
}
*/
int count_words(char *input_string) {
    int count = 0;
    int len = strlen(input_string);

    // Check if the first character is not a space
    if (input_string[0] != ' ') {
        count++;
    }

    // Iterate over the string and count spaces
    for (int i = 1; i < len; i++) {
        //comparing if position [i] is a space
	    if (input_string[i] == ' ' && input_string[i - 1] != ' ') {
            count++;
        }
    }

    return count;
}

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} word_freq_pair;

//this function counts the word frequency 
void count_word_frequency(char *input) {
    const char *delimiters = " .,!?\n\t";
    word_freq_pair *word_freq_list = NULL;
    int list_size = 0;
    int num_words = 0;

    char *token = strtok(input, delimiters);
    while (token != NULL) {
        // Check if the word is already in the list
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word_freq_list[i].word, token) == 0) {
                word_freq_list[i].frequency++;
                break;
            }
        }

        // If the word is not in the list, add it
        if (i == num_words) {
            // Resize the list if necessary
            if (num_words == list_size) {
                list_size += 10;
                word_freq_list = realloc(word_freq_list, list_size * sizeof(word_freq_pair));//reallocating
            }

            // Add the new word to the list
            strncpy(word_freq_list[num_words].word, token, MAX_WORD_LENGTH);//string copy
            word_freq_list[num_words].frequency = 1;
            num_words++;
        }

        token = strtok(NULL, delimiters);
    }

    // Print the results
    //printf("Word frequency:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%6s: %d\n", word_freq_list[i].word, word_freq_list[i].frequency);
    }

    // Free the memory
    free(word_freq_list);
}

//function with prints statements of all the command options available.
void print_options() {
    printf("Usage: ./program [OPTIONS]\n");
    printf("-l : report the line count\n");
    printf("-c : report the character count\n");
    printf("-w : report the word count\n");
    printf("-f : report each word and its frequency\n");
    printf("-v : reports all information (equivalent to all options -l -c -w -f)\n");
    printf("-h : prints a brief synopsis on how to use your program\n");
    printf("-d : print to stderr debugging information as your program progresses\n");
}
//extra credit to support char count but exclude punctiations. 
void report_extra_char(char *input_string){
    int char_count = 0;
    int line_count = 0;
    int word_count = 0;
    int len = strlen(input_string); 
    // Iterate over the string and count words, characters, and lines
    for (int i = 0; i < len; i++) {
        // If the current character is a whitespace or a newline
        if (isspace(input_string[i]) || input_string[i] == '\n') {
            // Check if the previous character was not a whitespace or a newline
            if (i > 0 && !isspace(input_string[i - 1]) && input_string[i - 1] != '\n') {
                word_count++;
            }
            if (input_string[i] == '\n') {
                line_count++;
            }
        } else {
            char_count++;
        }
    }
    printf("total chars: %d", char_count++); 
}

//extra credit to report avg word len and avg line len
void report_extras(char *input_string) {
    int word_count = 0;
    int char_count = 0;
    int line_count = 0;
    int len = strlen(input_string);

    // Iterate over the string and count words, characters, and lines
    for (int i = 0; i < len; i++) {
        // If the current character is a whitespace or a newline
        if (isspace(input_string[i]) || input_string[i] == '\n') {
            // Check if the previous character was not a whitespace or a newline
            if (i > 0 && !isspace(input_string[i - 1]) && input_string[i - 1] != '\n') {
                word_count++;
            }
            if (input_string[i] == '\n') {
                line_count++;
            }
        } else {
		fprintf(stderr, "char increasing: %d",char_count);
            char_count++;
        }
    }

    // Check if the last character is not a whitespace or a newline
    if (!isspace(input_string[len - 1]) && input_string[len - 1] != '\n') {
        word_count++;
    }
    // Count the last line if it's not already counted
    if (input_string[len - 1] != '\n') {
        line_count++;
    }

    // Compute average word length and line length
    float avg_word_len = (float) char_count / word_count;
    float avg_line_len = (float) len / line_count;

    // Print the results
    printf("Average word length: %.2f\n", avg_word_len);
    printf("Average line length: %.2f\n", avg_line_len);
}
int main(int argc, char * argv[]){
	//argc is the size of argv
	//argv contains the commands (options to execute) 
	//proccess commands first before doing anythin
	//1) what are we doing
	//2) read inpit from stdin
	//3) analyze info
	//4) print it out
	//realloc memmory after the commands
	
	//fprintf(); for stderr 
	//takes 4 paramets stderr, %s etc, what i want to print, where 
	
	//do reallocation here
	int size = 40;
    	int index = 0;
    	char *input_string = malloc(size * sizeof(char));
    	char c;

    	while ((c = getchar()) != '\n' && c != EOF) {
        	if (index >= size) {
            		size += 10;
            		input_string = realloc(input_string, size * sizeof(char));//reallocating memory
            	if (input_string == NULL) {
                	printf("Memory allocation failed\n");//checking reallocation of memory
                	fprintf(stderr, "Memroy Allocation failed with size %ld\n", input_string + size); 
			return 1;
            }
        }
        	input_string[index] = c;
        	index++;
    }
    input_string[index] = '\0';	
	for(int i = 1; i < argc; i++){//stacking options supported
		//a bunch of string compares to see what option the user has chosen if 0, then we call corresponding function. 
			if(strcmp(argv[i], "-l") == 0){
				fprintf(stderr, "In the if for -l: %s",argv[i]); 
				printf("line_count : %d\n",count_lines(argv));
				fprintf(stderr, "In the if for -f: %s",argv[i]);
			}
			if(strcmp(argv[i], "-c") == 0){
				fprintf(stderr, "In the if for -c: %s",argv[i]);
				int count = count_chars(argv);
				printf("char_count : %d\n", count);	
				fprintf(stderr, "In the if for -c: %s",argv[i]);
			}
			if(strcmp(argv[i], "-w") == 0){
				fprintf(stderr, "In the if for -w: %s",argv[i]);
                                printf("word_count : %d",count_words(argv)); 
				fprintf(stderr, "In the if for -w: %s",argv[i]);	
			}
			if(strcmp(argv[i], "-f") == 0){
                                printf("word frequency: \n");
                		for(int j = i; j < argc; j++){
				count_word_frequency(argv[j]);
				fprintf(stderr, "In the if for -f: %s",argv[i]);
				}
			}
			if(strcmp(argv[i], "-v") == 0){
                                printf("\nin the v\n");
				fprintf(stderr, "In the if for -v: %s",argv[i]);
				/*
				printf("word_count : %d\n",count_words(argv));
				printf("line_count : %d\n",count_lines(argv));
				int count_v = count_chars(argv);
                                printf("char_count : %d\n", count_v);
				printf("word frequency: \n");
                                for(int j = i; j < argc; j++){
                                count_word_frequency(argv[j]);
                                }*/
                	}
			if(strcmp(argv[i], "-h") == 0){
                                print_options();
				fprintf(stderr, "In the if for -h: %s",argv[i]);
                	}
			if(strcmp(argv[i], "-d") == 0){
                                printf("\nin the d\n");
				fprintf(stderr, "In the if for -l: %s",argv[i]);
			}
			//extra credit option for avg word length and line length
			 if(strcmp(argv[i], "-x") == 0){
                                report_extras(argv);
                        } 
			 //extra credit option for total chars excluding punction. 
			 if(strcmp(argv[i], "-p") == 0){
                        	report_extra_char(argv);
			 }
		free(input_string);  // free dynamically allocated memory
		
	}
}
