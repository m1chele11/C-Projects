#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_CHUNK 40        // number of chars read from input each time
#define RESOURCE_ERROR 1
#define WORD_LIST_CHUNK 10

// Prototypes
void print_report(void);
void read_input(void);
void count_word(char * word);
void process_options(int argc, char * argv[]);
void display_help(void);
void log_msg(char * msg);
void add_word(char * new_word);



// Globals
char ** word_list;             // pointer to each word stored
unsigned int lst_wrd_indx = 0; // index of the last word in the list, i.e. how big is the list
unsigned int max_word_list = 0;

//counters
unsigned int in_tot_word_count = 0;
unsigned int in_tot_line_count = 0;
unsigned int in_tot_char_count = 0;

//flags
bool debug_flag = false;
bool verbose_flag = false;
bool wd_cnt_flag = false;
bool ln_cnt_flag = false;
bool freq_flag = false;
bool ch_cnt_flag = false;


int main(int argc, char * argv[]) {
    process_options(argc, argv);

    log_msg("main: initialize storage\n");
    // initialize my word store
    word_list = (char **)calloc(sizeof(char *), WORD_LIST_CHUNK);
    if (word_list == NULL) {
        perror("Unable to allocate storage for words.");
        exit(RESOURCE_ERROR);
    }
    max_word_list = WORD_LIST_CHUNK;
   
    read_input();
    print_report();
    if(!argv[1]){
     //printf("\n word_count : %d\n", in_tot_word_count);
    }
    if(wd_cnt_flag = true){
    	//printf("\n word_count: %d \n", in_tot_word_count);
    }

    free(word_list);
    word_list = NULL;

} // end main()

void log_msg(char * msg) {
    if (debug_flag)
        fprintf(stderr, "\t%s\n", msg);
}


void print_report(void) {
    if (wd_cnt_flag || verbose_flag) 
        printf("\nword_count : %d\n", in_tot_word_count);
    if (ln_cnt_flag || verbose_flag) 
        printf("line_count : %d\n", in_tot_line_count);
    if (ch_cnt_flag || verbose_flag)
        printf("char_count : %d\n", in_tot_char_count);
    if (freq_flag || verbose_flag) {
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

void read_input(void) {
    log_msg("process_input: begining processing input\n");
    size_t in_buf_size = INPUT_CHUNK;
    char * input = (char*)calloc(in_buf_size, sizeof(char));  // add an extra /0 strtok() usage
    if (input == NULL) {
        perror("Unable to allocate memory for input.");
        exit(RESOURCE_ERROR);
    }
    
    while(!feof(stdin) ) {
        in_tot_char_count += fread(input + in_tot_char_count, sizeof(char), INPUT_CHUNK, stdin);
        if (debug_flag) fprintf(stderr, "Input read so far: %d buffer: %ld\n", in_tot_char_count, in_buf_size);
        if (in_tot_char_count >= in_buf_size) {
            // need to resize the buffer
            char * tmp = realloc(input, in_buf_size + INPUT_CHUNK * sizeof(char));
            if (tmp == NULL) {
                perror("Unable to allocate additional storage for word storage.");
                exit(RESOURCE_ERROR);
            }
            input = tmp;
            memset(input + in_tot_char_count, '\0', INPUT_CHUNK);    
            in_buf_size += INPUT_CHUNK;        
        }
    } // end while !EOF
        
    input[in_buf_size] = '\0'; // null terminator at end of input for string
    if (debug_flag)
        fprintf(stderr, "\tprocess_input: read %d chars from input\n", in_tot_char_count);
    // find and count newlines
    for (char * i = input; i < input + in_buf_size; i++) {
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
} // read_input()


void count_word(char * word) {
    bool fnd_wrd = false;
    if (debug_flag)
        fprintf(stderr, "\tcount_word: counting word %s\n", word);
    for(int i = 0; i < lst_wrd_indx; i++) {
        if (debug_flag)
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



void process_options(int argc, char * argv[]) {
    if (argc < 2) {
        wd_cnt_flag = true;
        return;
    }
    
    for(int i = 1; i < argc; i++ ) {
        char * option = argv[i];
       if(!option[1]){
       wd_cnt_flag = true;
       }else{
       	switch (option[1]) {
            case 'v': 
		    verbose_flag = true; 
		    break;
            case 'd': 
                debug_flag = true; 
                log_msg("STDERR: Enabling debugging.\n");
                break;
            case 'h': 
		display_help();
		break;
            case 'w': 
		      wd_cnt_flag = true; 
		      break;
            case 'c': 
		      ch_cnt_flag = true; 
		      break;
            case 'f': 
		      freq_flag = true; 
		      break;
            case 'l': 
		      ln_cnt_flag = true; 
		      break;
        } // switch
    } // foreach argc
    }
    wd_cnt_flag = !(ch_cnt_flag && freq_flag && ln_cnt_flag);
} // process_options()


//    display_help() 
  //  Displays what each options does
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

} // end display_help()
