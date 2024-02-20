#ifndef STRING_INDEX_HEADER
#define STRING_INDEX_HEADER

#define BUFFER_SIZE 2048
#define WORD_LIMIT 100
#define NOT_FOUND -1
#define WD_BGN  0
#define WD_END  1

// Prototypes

/*
    initialize_buffer:
    Fills the given array with characters from stdin until either EOF or 
    2048 characters have been loaded.
    Returns the total number of characters loaded and -1 if no characters loaded.
*/
int initialize_buffer(char buffer[]);

/********************************************************
  Functions that work with arrays
********************************************************/

/*
    index_buffer_by_array:
    Indexes the beginning and end of each unique word (string of non-whitespace characters). 
    The index is a list of beginning and ending array indexes for each unique word found.
    Duplicate words are counted in w_counts array. 
    Returns the total number of unique words found in the character buffer.
*/
int index_buffer_by_array(const char buffer[], int index[][2], int w_counts[] );

/*
    find_word_by_array:
    Determines if the word in buf[] beginning at index word_beg is already indexed. 
    A word terminates with the first whitespace character.
    Returns the index number for the word if found, otherwise returns NOT_FOUND.
*/
int find_word_by_array(int word_beg, const char buf[], int index[][2]);

/*
    print_report_by_array:
    Prints to stdout a report giving the word index number, offset of first letter from
    beginning of the buffer, the word count, and the word itself. This function expects index
    to be an array of array indexes for the beginning and end of each word.
    Example output for buffer containing the characters in quotes "all the all"
    0( 0): 2 all
    1( 4): 1 the
*/
void print_report_by_array(const char buf[], int index[][2], int counts[], int word_cnt);

/*******************************************************
  Functions that work with pointers
********************************************************/

/*
    index_buffer_by_ptr:
    Indexes the beginning and end of each unique word (string of non-whitespace characters). 
    The index is a list of beginning and ending char pointers for each unique word found.
    Duplicate words are counted in w_counts array. 
    Returns the total number of unique words found in the character buffer.
*/
int index_buffer_by_ptr(const char * buf, const char * index[][2], int word_counts[] );

/*
    find_word_by_ptr:
    Determines if the word in  beginning at the char * beg  is already indexed. 
    A word terminates with the first whitespace character.
    Returns the index number for the word if found, otherwise returns NOT_FOUND.
*/
int find_word_by_ptr(const char * beg, const char * index[][2]);

/*
    print_report_by_ptr:
    Prints to stdout a report giving the word index number, offset of first letter from
    beginning of the buffer, the word count, and the word itself. This function expects index
    to be an array of char pointers for the beginning and end of each word.
    Example output for buffer containing the characters in quotes "all the all"
    0( 0): 2 all
    1( 4): 1 the
*/
void print_report_by_ptr(const char * buf, const char * index[][2], int counts[], int word_cnt);


#endif
