//Michele Barrantes



/*****************************************************************************
PseudoCode: 
  function initialize_buffer(buffer)
    count = 0
    ch = get_character()
    while ch is not end-of-file and count < BUFFER_SIZE
        buffer[count] = ch
        count = count + 1
        ch = get_character()
    if count == 0
        return -1
    return count

 function index_buffer_by_array(buffer, index, w_counts)
    word_cnt = 0
    buf_size = length(buffer)
    w_len = 0
    for i = 0 to WORD_LIMIT-1
        index[i][WD_BGN] = NOT_FOUND
        index[i][WD_END] = NOT_FOUND
        w_counts[i] = 0
    i = 0
    while i < buf_size and word_cnt < WORD_LIMIT
        while i < buf_size and buffer[i] is whitespace
            i = i + 1
        if i >= buf_size
            break
        index[word_cnt][WD_BGN] = i
        while i < buf_size and buffer[i] is not whitespace
            w_len = w_len + 1
            i = i + 1
        index[word_cnt][WD_END] = i - 1
        w_counts[word_cnt] = w_counts[word_cnt] + 1
        word_cnt = word_cnt + 1
        j = word_cnt - 2
        while j >= 0
            if substr(buffer, index[word_cnt-1][WD_BGN], w_len) equals substr(buffer, index[j][WD_BGN], w_len)
                w_counts[j] = w_counts[j] + 1
                word_cnt = word_cnt - 1
                exit while
            j = j - 1
        w_len = 0
    return word_cnt
    function find_word_by_array(word_beg, buffer, index)
    i = 0
    j = 0
    while buffer[word_beg] is not end-of-string and buffer[word_beg] is whitespace
        word_beg = word_beg + 1
    while i < WORD_LIMIT and index[i][WD_BGN] is not NOT_FOUND
        j = index[i][WD_BGN]
        while buffer[j] is not end-of-string and buffer[j] equals buffer[word_beg]
            j = j + 1
            word_beg = word_beg + 1
        if buffer[j] is end-of-string and buffer[word_beg] is whitespace
            return i
        i = i + 1
    return NOT_FOUND

function find_word_by_ptr(word, index):
    for each entry in index:
        if entry[WD_BGN] points to word:
            return the index of the entry
    return NOT_FOUND

function print_report_by_ptr(buf, index, counts):
    for each entry in index:
        calculate the offset of the word in buf
        print the index, offset, count, and word for the entry

function index_buffer_by_ptr(buf, index, word_counts):
    initialize variables
    loop through the buffer:
        if character is not whitespace:
            if a word has not started:
                set word_start to current index
            increment word_len
        else:
            if a word has started:
                if the word is not already in the index:
                    add the word to the index and set the word count to 1
                    increment the index count
                else:
                    increment the word count for the word in the index
                reset word_start and word_len for next word
    if a word is still in progress:
        if the word is not already in the index:
            add the word to the index and set the word count to 1
            increment the index count
        else:
            increment the word count for the word in the index
    return the index count
 * 
*****************************************************************************/
/***************
 test case explenation: 
 input: all the dogs and all the cats in all the planet.
output:  
0( 0):  3 all 
1( 4):  3 the 
2( 8):  1 dogs 
3(13):  1 and 
4(25):  3 cats 
5(30):  1 in 
6(41):  3 planet.
as we can see my output is incorrect as cats and planet is displayed to be appearing 3 times. I was unable to fix this bug along with the print_report by array function. 

 ************/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "string_index.h"



int main(void) {
    // variable declartaions 
	int words_found;
        const char *word_index[WORD_LIMIT][2];
        int word_index_array[BUFFER_SIZE][2];//index of the word the start n end it
        int word_counts[WORD_LIMIT];


    // initialize storage
    char buffer[BUFFER_SIZE] = "";



    /* ***** DO NOT CHANGE ANY CODE BEYOND THIS POINT IN main() ****** */
    initialize_buffer(buffer);

    words_found = index_buffer_by_ptr(buffer, word_index, word_counts);

    print_report_by_ptr(buffer, word_index, word_counts, words_found);

    words_found = index_buffer_by_array(buffer, word_index_array, word_counts);

    print_report_by_array(buffer, word_index_array, word_counts, words_found);
    
} // end main


int initialize_buffer(char buffer[]) {
    int count = 0;
    int ch;
	//loop runs for chars in input
    while ((ch = getchar()) != EOF && count < BUFFER_SIZE) {
        buffer[count] = ch;
        count++;//incremnts the count
    }
    if (count == 0) {
        return -1;
    } 
    return count;//returns number of chars including spaces
}

int index_buffer_by_array(const char buffer[], int index[][2], int w_counts[]) {
	int i = 0;//initializng variables
    	int j = 0;
    	int word_cnt = 0;//will keep track of the word
    	int buf_size = strlen(buffer);//makes the size the len of the buffer
    	int w_len = 0;
//for loop runs while less than word limit
    for (i = 0; i < WORD_LIMIT; i++) {
        index[i][WD_BGN] = NOT_FOUND;
        index[i][WD_END] = NOT_FOUND;
        w_counts[i] = 0;
    }
    i = 0;
    while (i < buf_size && word_cnt < WORD_LIMIT) {
        while (i < buf_size && isspace(buffer[i])) {
            i++;
        }
	//we break out if i is at the max size
        if (i >= buf_size) {
            break;
        }
        index[word_cnt][WD_BGN] = i;
        while (i < buf_size && !isspace(buffer[i])) {
            w_len++;
            i++;
        }
        index[word_cnt][WD_END] = i;
        w_counts[word_cnt]++;
        word_cnt++;
	//copying the word
        for (j = word_cnt-2; j >= 0; j--) {
            if (strncmp(buffer + index[word_cnt-1][WD_BGN], buffer + index[j][WD_BGN], w_len) == 0) {
                w_counts[j]++;
                word_cnt--;
                break;
            }
        }
        w_len = 0;
    }
    return word_cnt;
}

int find_word_by_array(int word_beg, const char buf[], int index[][2]) {
	int i = 0;//variables initialized
    	int j = 0;
	
    	while (buf[word_beg] != '\0' && isspace(buf[word_beg])) {
        	word_beg++;
	}
	//comparing the indexes to see if the word has been found or not
    	while (i < WORD_LIMIT && index[i][WD_BGN] != NOT_FOUND) {
        	j = index[i][WD_BGN];
        	while (buf[j] != '\0' && buf[j] == buf[word_beg]) {
            		j++;//our index is incremendted
            		word_beg++;//the beging of the word is incremented 
	}
		//checking if terminator and begining of the word is space
        if (buf[j] == '\0' && isspace(buf[word_beg])) {
            return i;
        }
        i++;
    }

    return NOT_FOUND;
    }

void print_report_by_array(const char buf[], int index[][2], int counts[], int word_cnt) {
    puts("\n");
	for (int i = 0; i < word_cnt; i++) {//for loop to print the display
        int word_len = index[i][WD_END] - index[i][WD_BGN] + 1;
	//prints the chars and the number that corresponds to them
        printf("%d(%2d): %2d ", i, index[i][WD_BGN], counts[i]);

        for (int j = index[i][WD_BGN]; j <= index[i][WD_END]; j++) {
            putchar(buf[j]);
        }

        putchar('\n');
    }
}
/*
    find_word_by_ptr:
    Determines if the word in  beginning at the char * beg  is already indexed.
    A word terminates with the first whitespace character.
    Returns the index number for the word if found, otherwise returns NOT_FOUND.
*/
int find_word_by_ptr(const char * beg, const char * index[][2]){
	//loop to go through the buffer and get the beg and end of the words
	for (int i = 0; i < BUFFER_SIZE; i++) {
        const char *word_beg = index[i][0];
        const char *word_end = index[i][1];
        
        if (beg >= word_beg && beg <= word_end) {
            return i;
        }
    }
    
    return NOT_FOUND;
}

int index_buffer_by_ptr(const char * buf, const char * index[][2], int word_counts[]) {
	// initialize variables
    int index_count = 0;
    int buf_index = 0;
    int word_start = NOT_FOUND;
    int word_len = 0;

    // loop through the buffer
    while (buf[buf_index] != '\0'){
        // if character is not whitespace, start a new word or add to existing word
        if (!isspace(buf[buf_index])) {
            if (word_start == NOT_FOUND) {
                word_start = buf_index;
            }
            word_len++;
        }
        // if character is whitespace, end the current word
        else {
            if (word_start != NOT_FOUND) {
                // check if word is already in index
                int word_index = find_word_by_ptr(&buf[word_start], index);
                if (word_index == NOT_FOUND) {
                    // add word to index
                    index[index_count][WD_BGN] = &buf[word_start];
                    index[index_count][WD_END] = &buf[buf_index];
                    word_counts[index_count] = 1;
                    index_count++;
                }
                else {
                    // update word count
                    word_counts[word_index]++;
                }
                // reset word_start and word_len for next word
                word_start = NOT_FOUND;
                word_len = 0;
            }
        }
        buf_index++;
    }

    // if last character is part of a word, add it to the index
    if (word_start != NOT_FOUND) {
        // check if word is already in index
        int word_index = find_word_by_ptr(&buf[word_start], index);
        if (word_index == NOT_FOUND) {
            // add word to index
            index[index_count][WD_BGN] = &buf[word_start];
            index[index_count][WD_END] = &buf[buf_index];
            word_counts[index_count] = 1;
            index_count++;
        }
        else {
            // update word count
            word_counts[word_index]++;
        }
    }

    return index_count;	
    }

void print_report_by_ptr(const char * buf, const char * index[][2], int counts[], int word_cnt) {

	 int i;
    	const char * word_beg;
    	const char * word_end;
    	int word_count;
	for (i = 0; i < word_cnt; i++) {
		//similar to the array print report except with pointers
		//however I could not figure out my bug on why this wasn't printing it runs through the loop but does not print 
        	word_beg = index[i][WD_BGN];
        	word_end = index[i][WD_END];
        	word_count = counts[i];
        	printf("%d(%ld): %d ", i, word_beg - buf, word_count);
        while (word_beg != word_end) {
        	putchar(*word_beg);
            	word_beg++;
        }
        	putchar('\n');
    }



}
