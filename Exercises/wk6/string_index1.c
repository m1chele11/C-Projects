// Program description
// Author: Michele Barrantes

/*****************************************************************************
 * 
 * Psuedocode here:
 * 
*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "string_index.h"
#include <string.h>
#define INDEX_SIZE BUFFER_SIZE / 2 + 1 // max number of words that fit 
int main(void) {
    // variable declartaions 

	int words_found; 
	int word_index;
	int word_index_array[BUFFER_SIZE][2];//index of the word the start n end it
	int word_counts;

        	
    // initialize storage
    char buffer[BUFFER_SIZE] = "";

    /* ***** DO NOT CHANGE ANY CODE BEYOND THIS POINT IN main() ****** */
    initialize_buffer(buffer);

    //words_found = index_buffer_by_ptr(buffer, word_index, word_counts);

    //print_report_by_ptr(buffer, word_index, word_counts, words_found);

    words_found = index_buffer_by_array(buffer, word_index_array, word_counts);

//    print_report_by_array(buffer, word_index_array, word_counts, words_found);
    
} // end main

/* ***** YOUR FUNNCTION DEFINTIONS BELOW ***** */

int initialize_buffer(char buffer[]){
        char c;
        int cur_pos = 0;


        puts("test from other file. \n");
        while(( c = getchar()) != EOF && cur_pos < BUFFER_SIZE){
                buffer[cur_pos++] = c;
        }
        printf("\ntotal chars: %d \n", cur_pos);

}
        /*
        for (i = 0; i < BUFFER_SIZE; i++) {
                c = buffer[i];
                if (c == EOF) {
                        if (i == 0) {
                                return -1;
                        } else {
                                break;
                        }
                }
                //c = buffer[i];
        } 
        return i;
	}*/
/*
    index_buffer_by_array:
    Indexes the beginning and end of each unique word (string of non-whitespace characters).
    The index is a list of beginning and ending array indexes for each unique word found.
    Duplicate words are counted in w_counts array.
    Returns the total number of unique words found in the character buffer.
*/
int index_buffer_by_array(const char buffer[], int index[][2], int w_counts[] ){
	//will call find word by array inside the if when we get a char not encountered if in word
	//index [][2] is word_index_array 
	//handle words in if 
	//new words handled in else 
	//w_counts 
	//find word by array will return the index if found or not 
	//whatever index find word by array returns use that index for w_counts to increase it's count
	int start = 0;
	int end = 0;
	bool in_word = false; //if in word true, false if not in word
	while(int i = 0; i < BUFFER_SIZE){
		if(buffer[i] != ' '){
			if(in_word){
			i++;//in the word so we just want to increase i 
			}else{
			//means we are not in a word so it is the start of one
			start = buffer[i];
		        	
			}	
		}else{
			if(!in_word){
			end = i;	
			}
		}
				
		
	} 
}
	/*
	printf("%s",buffer);
	puts("\n");
	int cur_char = 0;
	int word_number = 0; 
	bool in_word = false; //flag to indicate if in a word or not
	while(cur_char < BUFFER_SIZE){
		if(buffer[cur_char] != ' '){
			if(in_word){
				cur_char++;
			}else{
				//found a new word
				index[word_number++] == cur_char++;
				in_word = true;	
				//index[		
		}
	}else{
		//cur_char is not part of a word
		in_word = false;
		cur_char++; 
		}
	}
	return word_number; 
*/
//}
/*
    find_word_by_array:
    Determines if the word in buf[] beginning at index word_beg is already indexed.
    A word terminates with the first whitespace character.
    Returns the index number for the word if found, otherwise returns NOT_FOUND.
*/
int find_word_by_array(int word_beg, const char buf[], int index[][2]){

	for (int i = 0; i < INDEX_SIZE; i++) {
        	if (index[i][0] == -1) {
            		// End of list, word not found
            		return NOT_FOUND;
        	}
        	if (word_beg == index[i][0] && buf[word_beg] == buf[index[i][1]]) {
            		// Word found
            		return i;
		
        	}
    }
    	// Index full, word not found
    	return NOT_FOUND;
}
/*
    print_report_by_array:
    Prints to stdout a report giving the word index number, offset of first letter from
    beginning of the buffer, the word count, and the word itself. This function expects index
    to be an array of array indexes for the beginning and end of each word.
    Example output for buffer containing the characters in quotes "all the all"
    0( 0): 2 all
    1( 4): 1 the
*/
void print_report_by_array(const char buf[], int index[][2], int counts[], int word_cnt){
 	printf("Word index (offset): count word\n");
	for (int i = 0; i < word_cnt; i++) {
        	printf("%10d (%2d): %5d ", buf[i], index[i][0], counts[i]);
        for (int j = index[i][0]; j <= index[i][1]; j++) {
		printf("%c", buf[i]);
        }
        puts("\n");
    }
}
