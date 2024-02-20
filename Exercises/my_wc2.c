/*
    my_wc is an implementation of wc that outputs in yaml format.

    Reads arbitrary input from stdin. It notes counts each
    character, word, and line from the input. It also counts the
    frequency of each word.

    All normal goes to stdout. 
    All errors or debugging output is sent to stderr.

    It supports the following options:
        - h -- displays a short synopsis of the program usages and exits with 0
        - w -- displays the word count
        - l -- displays the line count
        - c -- displays the character count
        - f -- displays each word and its frequency in the input
        - d -- enables debugging print statements. 
        - v -- reports all information; equivalent to -wlcf

    If no options specified, default to -w. 
    
    Output uses a YAML format with the following keys 
    word_count : <int>
    line_count : <int>
    char_count : <int> 
    word_frequency : 
        word1 : <int>
        word2 : <int>

    Returns 0 for normal operations.
    Returns 1 if resource constrained during processsing.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_CHUNK 40        // number of chars read from input each time
#define RESOURCE_ERROR 1
#define WORD_LIST_CHUNK 10
#define MAX_WORD_LENGTH 100

// Prototypes
void print_report(void);
void process_input(char* file_path);
void count_word(char * word);
void process_args(int argc, char * argv[]);
void display_help(void);
void log_msg(char * msg);
void add_word(char * new_word);
void output_file(int argc, char* argv[]); 


// Globals
char *file_path_in; 
char ** word_list;             // pointer to each word stored
unsigned int lst_wrd_indx = 0; // index of the last word in the list, i.e. how big is the list
unsigned int max_word_list = 0;

unsigned int in_tot_word_count = 0;
unsigned int in_tot_line_count = 0;
unsigned int in_tot_char_count = 0;

bool debug_f = false;
bool verbose_f = false;
bool wd_cnt_f = false;
bool ln_cnt_f = false;
bool freq_f = false;
bool ch_cnt_f = false;
bool output_f = false; 


/*
    main() 

    Driver for the workflow.

    Process the arguements to determine output and run options.
    Allocate a word_list array to point to word structures.
    Process the stdin 
    Print the results of the processing
    Release allocated storage.
*/
typedef struct Node {//struct storing word content and word freq
    char word[MAX_WORD_LENGTH];
    int count;//the count
    struct Node *next;
} Node;

//following are the lists comparing the current position in the list to the previous, using strncpy to copy into the list and strcompare to compare the words. 
Node *createNode(char *word) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Error: Memory allocation failed.\n");//checking if allocation failed
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->word, word, MAX_WORD_LENGTH);
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

Node *addNode(Node *head, char *word) {
    if (!head) {
        head = createNode(word);
    } else {
        Node *curr = head;
        while (curr) {
            if (strncmp(curr->word, word, MAX_WORD_LENGTH) == 0) {
                curr->count++;
                return head;
            }
            curr = curr->next;
        }
        Node *newNode = createNode(word);
        newNode->next = head;
        head = newNode;
    }
    return head;
}
//function to print our lists
void printList(Node *head) {
    Node *curr = head;
    while (curr) {
        printf("%s: %d\n", curr->word, curr->count);
        curr = curr->next;
    }
}

void writeFile(Node *head, char *filename) {
    FILE *fp;
    fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: Unable to open file for writing.\n");//checking if file can be opnend
        exit(EXIT_FAILURE);
    }
    Node *curr = head;
    while (curr) {//printing out the words to the file
        fprintf(fp, "%s: %d\n", curr->word, curr->count);
        curr = curr->next;
    
    fclose(fp);//closing
	}
}

int main(int argc, char * argv[]) {
    process_args(argc, argv);

    log_msg("main: initialize storage\n");
    // initialize my word store
    word_list = (char **)calloc(sizeof(char *), WORD_LIST_CHUNK);
    if (word_list == NULL) {
        perror("Unable to allocate storage for words.");
        exit(RESOURCE_ERROR);
    }
    max_word_list = WORD_LIST_CHUNK;
   
    process_input(file_path_in);//calling the process input taking in the file path found in process args
    print_report();
    if(output_f || verbose_f){//calling the -o option function 
    output_file(argc, argv); 
    }

    free(word_list);
    word_list = NULL;

} // end main()

/*
    log_msg

    Sends a message to stderr if debug flag is set.
*/
void log_msg(char * msg) {
    if (debug_f)
        fprintf(stderr, "\t%s\n", msg);
}


/*
    print_report

    prints the requested reports
    For each output flag emit tot stdout the requested information.
    Iterate over the word frequencies if requested.
*/
void print_report(void) {
    if (wd_cnt_f || verbose_f) 
        printf("word_count : %d\n", in_tot_word_count);
    if (ln_cnt_f || verbose_f) 
        printf("line_count : %d\n", in_tot_line_count);
    if (ch_cnt_f || verbose_f)
        printf("char_count : %d\n", in_tot_char_count);
    if (freq_f || verbose_f) {
        printf("word_frequency :\n");
        for(int i = 0; i < lst_wrd_indx; i++) {
            printf("\t%s : %hhd\n", word_list[i], *(word_list[i] + strlen(word_list[i]) + 1));
        }
    }
    for (int i = 0; i < lst_wrd_indx; i++) {
        free(word_list[i]);
        word_list[i] = NULL;
    }
}
//function to write to an output file if option is -o then we call this in  the main
void output_file(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input file> -o <output file>\n", argv[0]);
    }

    char *inputFilename = argv[1];
    char *outputFilename = argv[3];

    FILE *fp;
    fp = fopen(inputFilename, "r");
    if (!fp) {
        printf("Error: Unable to open file for reading.\n");
    }

    Node *head = NULL;
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) == 1) {
        head = addNode(head, word);
    }
    fclose(fp);

    writeFile(head, outputFilename);

    printf("Output written to %s.\n", outputFilename);
}
/*
    process_input

    Reads data from stdin, counts newlines, and discovers words in the input
    buffer.

    PC:
    Allocate an input buffer
    while not the EOF of stdin
        read up to to the buffer size
        increase buffer size if insufficient
    Walk the buffer counting and replacing \n with \0
    For each word in buffer using strtok()
        count the word
    release the input buffer allocation

*/

void process_input(char* file_path) {
    log_msg("process_input: begining processing input\n");
    size_t in_buf_sz = INPUT_CHUNK;
    char * input = (char*)calloc(in_buf_sz, sizeof(char));  // add an extra /0 strtok() usage
    if (input == NULL) {
        perror("Unable to allocate memory for input.");
        exit(RESOURCE_ERROR);
    }

    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Unable to open input file");
    }

    size_t in_tot_char_count = fread(input, sizeof(char), INPUT_CHUNK, file);
    while(in_tot_char_count > 0 ) {
        if (debug_f) fprintf(stderr, "Input read so far: %ld buffer: %ld\n", in_tot_char_count, in_buf_sz);
        if (in_tot_char_count >= in_buf_sz) {
            // need to resize the buffer
            char * tmp = realloc(input, in_buf_sz + INPUT_CHUNK * sizeof(char));
            if (tmp == NULL) {
                perror("Unable to allocate additional storage for word storage.");
                exit(RESOURCE_ERROR);
            }
            input = tmp;
            memset(input + in_tot_char_count, '\0', INPUT_CHUNK);
            in_buf_sz += INPUT_CHUNK;
        }
        in_tot_char_count += fread(input + in_tot_char_count, sizeof(char), INPUT_CHUNK, file);
    } //end while fread()

    fclose(file);

    input[in_tot_char_count] = '\0'; // null terminator at end of input for string
    if (debug_f)
        fprintf(stderr, "\tprocess_input: read %ld chars from input\n", in_tot_char_count);
    // find and count newlines
    for (char * i = input; i < input + in_tot_char_count; i++) {
        if (*i == '\n') {
            in_tot_line_count++;
            *i = ' ';
        }
        if (*i == '\0')
            *i = ' ';
    }
    // find words in updated buffer
    char * delims = " \t";
    char * nxt_wrd = strtok(input, delims);
    while (nxt_wrd != NULL) {
        in_tot_word_count++;
        count_word(nxt_wrd);
        nxt_wrd = strtok(NULL, delims);
    }
    free(input);
    input = NULL;
} // end process_input()
/*
    count_word

    Increments the count of any word already discovered or adds the word 
    as a new word to the list and starts the count.

    PC:
    if the the word is in the word_list
        increment the count for the word
    else
        add the word
    
*/
void count_word(char * word) {
    bool fnd_wrd = false;
    if (debug_f)
        fprintf(stderr, "\tcount_word: counting word %s\n", word);
    for(int i = 0; i < lst_wrd_indx; i++) {
        if (debug_f)
            fprintf(stderr, "\tcount_word: comparing to %s\n", word_list[i]);
        if (strcmp(word, word_list[i]) == 0) {
            log_msg("count_word: matched word list");
            char * wrd_cnt_ptr = word_list[i] + strlen(word_list[i]) + 1; // length of word + \0 + byte for count
            if (*(wrd_cnt_ptr) < 0xFF) {
                (*(wrd_cnt_ptr))++;
                fnd_wrd = true;
                break;
            } else {
                fprintf(stderr, "Exceeded our capacity to count words %s : %d\n", word_list[i], *(wrd_cnt_ptr));
            }
        }
    } // end for each word in word_list
    
    if (!fnd_wrd) {
        add_word(word);
    }
} // end count_word


/*
    add_word

    Adds a new word to the list.

    PC:
    allocate new word structure
        copy the word to the new structure
        initialize the word count to 0
*/
void add_word(char * new_word) {
    log_msg("add_word: found a new word.");
    unsigned int wrd_len = strlen(new_word);

    if (lst_wrd_indx >= max_word_list ) {
        log_msg("word_count: resizing word_list storage");
        char ** tmp = realloc(word_list, (max_word_list + WORD_LIST_CHUNK) * sizeof(char*));
        if (tmp == NULL) {
            perror("Unable to allocate additional storage for word storage.");
            exit(RESOURCE_ERROR);
        }
        word_list = tmp;
        // initialize additional storage
        for (int i = max_word_list; i < max_word_list + WORD_LIST_CHUNK; i++) {
            word_list[i] = NULL;
        }
        // resize_storage((void**) &word_list, max_word_list, WORD_LIST_CHUNK * sizeof(char *));
        max_word_list += WORD_LIST_CHUNK;
    }
    char * new_word_store = malloc(wrd_len + 2); // add byte for \0 and another for word count
    strcpy(new_word_store, new_word);
    new_word_store[wrd_len] = '\0';
    new_word_store[wrd_len + 1] = 0x01; // initial count of 1
    word_list[lst_wrd_indx] = new_word_store;
    lst_wrd_indx++;
}



/*
    process_args

    Process any args and set the appropriate flags. This implementation 
    does not support stacking. 

    PC:
    if no options to process return
    For each argument
        set the corresponding flag
*/
void process_args(int argc, char * argv[]) {
	//flag to check if we have a file path
	bool file_path_found = false;
	if (argc < 2) {
        	wd_cnt_f = true;
        return;
    }
    
    for(int i = 1; i < argc; i++ ) {
        char * option = argv[i];
      //   char option = (*(argv[i]))[1]; // the second letter of the argument
        switch (option[1]) {
            case 'v': verbose_f = true; break;
            case 'd': 
                debug_f = true; 
                log_msg("STDERR: Enabling debugging.\n");
                break;
            case 'h': display_help();
		      break; 
            case 'w': wd_cnt_f = true; break;
            case 'c': ch_cnt_f = true; break;
            case 'f': freq_f = true; break;
            case 'l': ln_cnt_f = true; break;
	    case 'o': output_f = true; break;
      	    default:
                if (!file_path_found) {
                    file_path_found = true;
                    // execute action for file path
                    file_path_in = option;//seeting our global variable for the file path equal to this so it can be used in the main function 
                } else {
                    printf("Error: too many file paths provided\n");
                    return;
                }
	} // switch

	if (!file_path_found) {
        	printf("Error: no file path provided\n");
        	return;
    	}
    } // foreach argc
    wd_cnt_f = !(ch_cnt_f && freq_f && ln_cnt_f);
} // process_args()

/*
    display_help() 

    Displays a synopsis to use the program.
*/
void display_help(void) {
    puts("Prints the worc count from stdin.");
    puts("Usage: wc [-h] [-l] [-c] [-w] [-f] [-d] [-v]");
    puts("\n\t-h -- display this help message");
    puts("\t-d -- debugging output to stderr");
    puts("\t-w -- word count (default with no options)");
    puts("\t-c -- character count");
    puts("\t-l -- line count");
    puts("\t-f -- word frequency");
    puts("\t-v -- output all word, line, character. and frequency");
    exit(0);

} // end display_help(



