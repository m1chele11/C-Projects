
// generate characters for a starship RPG
// Author: Kurt Seiffert

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REROLLS_ALLOWED 3
#define CREW_SIZE 5
#define CAP 0
#define COM 1
#define ENG 2
#define NAV 3
#define SEC 4

#define TERRAN 1
#define MARTIAN 2
#define VENUSIAN 3
#define SATURIAN 4

#define SIX_SIDED 6
#define TEN_SIDED 10

// Function Prototypes
void generate_crew(void);
void generate_crew_member(int crew_id);
void generate_race(int crew_id, int testing);
void generate_skills(int crew_id);
void print_crew_report(void);
void print_skill(int lvl);
int roll_dice(int rolls, int dice_sides);
int gen_enc_skill(int attr1, int attr2,int bonus_roll);
int decode_skill_value(int skill_cd);
int skill_bonus_lvl(int skill_cd);

/*
    List of character attributes:
        Charisma
        Intelligence
        Psionics
        Strength
        Agility
*/
int chCharisma[CREW_SIZE] = {0};
int chIntel[CREW_SIZE] = {0};
int chPsi[CREW_SIZE] = {0};
int chStr[CREW_SIZE] = {0};
int chAgi[CREW_SIZE] = {0};
// the rest of attributes represented in the same way

char chRace[CREW_SIZE] = {'Z','Z','Z','Z','Z'};

/*
    List of character skills
        SKILL       DEPENDS ON
        -----       ----------
        Nav         Inteligence, Psionics
        Eng         Intelligence, Agility
        Tac         Strength, Agility
        Lead        Charisma, Intelligence
        Dip         Charisma, Psionics

*/
int chNav[CREW_SIZE] = {0};
int chEng[CREW_SIZE] = {0};
int chTac[CREW_SIZE] = {0};
int chLead[CREW_SIZE] = {0};
int chDip[CREW_SIZE] = {0};
// the rest of the skills done in in similar arrays, but encode natural
// rolls into the skill value; decode when needing to display or use

/* 
Psuedocode for Character Gen program

prompt user for test run
if test_run == 0:
    generate_crew()
    for up to three times
        print_crew_report()
        prompt user - gen new crew, new char, or Quit
        if new_char_request:
            generate_char()
        else if generate_new_crew:
            generate_crew()
        else:
            Quit program
else:
    // test run conditions

func generate_crew()
    for each crew position
        generate_char()

func generate_char(crew_id)
    generate_char_attributes()
    generate_char_race()
    generate_char_skills()

func generate_random(max_value);

func roll_dice(number of dice, number of die sides)

func encode_char_skill()

int func decode_char_skill()

func print_crew_report()
    print report header
    for each crew member
        print crew abilities and skills and race
*/
int main(void) {
    // initialize services
    time_t t;
    srand(time(&t));

    // prompt user for test run [0 is no testing] T 1 indicates testcase 1
    puts("Enter test case number 0-9 (0 or newline means normal run):");
    char t_response;
    scanf(" %c", &t_response);
    switch (t_response) {
        case '\n':
        case '0':
            // normal run
            generate_crew();
            break;
        case '1': 
            // sets crew member attributes to ensure all skill values are tested. Includes
            // racial modifiers to abilities by testing all races as well.
            /* input:
                1
                Q
            
               output (no leading spaces in actual output):
                Enter test case number 0-9 (0 or newline means normal run):
                       Race   Attributes         Skills
                Crew          C  I  S  P  A      N    E    L    T    D
                Cap    T      3  3  3  3  3     -4+  -4+  -4+  -4+  -4+
                Com    M      6  6  4  8  6     -1*  -2*  -2*  -2*  -1*
                Eng    V     13 11 13 13 11      0    0    0    0    0
                Nav    S     15 18 15 17 16      2*   2*   2*   2*   2*
                Sec    T     18 18 18 18 18      4+   4+   4+   4+   4+
                Enter C to reroll the crew or a crew number [0-4] to reroll reroll a crew member. You have 3 of 3 rerolls left:
                Enjoy the game!
           */
            {
                int attr_val;
                int test_bonuses[CREW_SIZE] = {1, 2, 20, 80, 99};
                int test_attrs[CREW_SIZE] = {3, 6, 12, 16, 18};
                
                // generate test values for a crew 
                for (int i = 0; i < 5; ++i) {
                    chCharisma[i] = test_attrs[i];
                    chIntel[i] = test_attrs[i];
                    chPsi[i] = test_attrs[i];
                    generate_race(i, (i % 4) + 1);
                    chLead[i] = gen_enc_skill(chCharisma[i], chIntel[i], test_bonuses[i]);
                    chNav[i] = gen_enc_skill(chIntel[i], chPsi[i], test_bonuses[i]);
                }
            }
            break;
        case '2': ;
            // TODO: Implement your Test Case 2 here
            //
            // write test setup to test changing a single character consistently 
            // you can modify functions but minimize code only evaluated during a test.
            // provide the required input and expected output
	    // user must select between 0-4 what character to reroll, the attributes and everything will be random.
	    // this test will output the same results as test case 1, only difference will be the captains will be randomized. 
		/*
		  this test case will only be testing Captain and how it rerolls consitently the same random numbers using srand and r			and. It will only run once as per the hw description, this is the way I interpreted it. 
		  input:
		  2
		  0
		  output:
		  
		  you have re-rolled your Captain!
       		       Race   Attributes         Skills
		Crew          C  I  S  P  A      N    E    L    T    D
		Cap    T     18 18 18 18 18      4+   4+   4+   4+   4+
		Com    M      6  6  4  8  7     -1*  -2*  -2*  -2*  -1*
		Eng    V     13 11 13 13 11      0    0    0    0    0
		Nav    S     15 18 15 17 16      2*   2*   2*   2*   2*
		Sec    T     18 18 18 18 18      4+   4+   4+   4+   4+
		Enter C to reroll the crew or a crew number [0-4] to reroll reroll a crew member. You have 3 of 3 rerolls left:
		
		*/  
		{int attr_val;
                int test_bonuses[CREW_SIZE] = {1, 2, 20, 80, 99};
		//same as test case 1, for simplicity
                int test_attrs[CREW_SIZE] = {3, 6, 12, 16, 18};
		int selection;//will hold the user input for selecting the 0 index which is the captain 
                // generate test values for a crew 
		// this for loop displays the current crew with the captain not being rerolled yet
                for (int i = 0; i < 5; ++i) {
                    chCharisma[i] = test_attrs[i];
                    chIntel[i] = test_attrs[i];
                    chPsi[i] = test_attrs[i];
		    chStr[i] = test_attrs[i];
		    chAgi[i] = test_attrs[i];
                    generate_race(i, (i % 4) + 1);
                    chLead[i] = gen_enc_skill(chCharisma[i], chIntel[i], test_bonuses[i]);
                    chNav[i] = gen_enc_skill(chIntel[i], chPsi[i], test_bonuses[i]);
		    chTac[i] = gen_enc_skill(chStr[i], chAgi[i], test_bonuses[i]);
		    chEng[i] = gen_enc_skill(chIntel[i], chAgi[i], test_bonuses[i]);
		    chDip[i] = gen_enc_skill(chCharisma[i], chPsi[i], test_bonuses[i]);
		}
		print_crew_report();//print the crew report to user
		puts("Enter a number from 0-4 for which character you would like to re-roll\n0 - Cap\n1 - Com\n2 - Eng\n3 - Nav\n4 - Sec\n");
		int upper = 4; //upper bound
		int lower = 0; // lower bound
		srand(1000);//the seed number is 1000 to genrate a consistent random numbers
	        
		
		
		scanf("%d", &selection);//scans the user input which will be 0 to access the captain
		if(selection == 0){
			//for loop that only changes the zero index which is the captains with the random values, this could easily be implemented the same way if you wish to re-roll others, but the hw was just testing the captain. 
			for(int i = 0; i < 5; i++){
			int num = (rand() % (upper - lower + 1)) + lower;
			//printf("the num is: %2d\n", num);
			chCharisma[0] = test_attrs[num];
                    	chIntel[0] = test_attrs[num];
                    	chPsi[0] = test_attrs[num];
                    	chStr[0] = test_attrs[num];
                    	chAgi[0] = test_attrs[num];
                    	generate_race(0, (0 % 4) + 1);
                    	chLead[0] = gen_enc_skill(chCharisma[num], chIntel[num], test_bonuses[num]);
                    	chNav[0] = gen_enc_skill(chIntel[num], chPsi[num], test_bonuses[num]);
                    	chTac[0] = gen_enc_skill(chStr[num], chAgi[num], test_bonuses[num]);
                    	chEng[0] = gen_enc_skill(chIntel[num], chAgi[num], test_bonuses[num]);
                    	chDip[0] = gen_enc_skill(chCharisma[num], chPsi[num], test_bonuses[num]);
			}	
			puts("You have re-rolled your Captain!");//confirms that the action was finished and exits the case statment t				o a normal run but will output the print report with the captin re-rolled as print_crew_report() is the first action after the switch statements. 
	//		print_crew_report();
		}	
		  }
	      break; 
	case '3': ;
		  
            // TODO: Implement your Test Case 3 here
            //
            // write test setup to test changing entire crew consistently
            // you can modify functions but minimize code only evaluated during a test.
            // provide the required input and expected output
	    // input: 
	    /*
	     3
		output:
	     the crew was re-rolled!
       	  	      Race   Attributes         Skills
		Crew          C  I  S  P  A      N    E    L    T    D
		Cap    T      3  3  3  3  3     -4+  -4+  -4+  -4+  -4+
		Com    M     18 18 16 20 19      4+   4+   4+   4+   4+
		Eng    V     17 15 17 17 15      2*   2*   2*   2*   2*
		Nav    S     15 18 15 17 16      2*   2*   2*   2*   2*
		Sec    T     18 18 18 18 18      4+   4+   4+   4+   4+
	
	     */
		  {int attr_val;
                int test_bonuses[CREW_SIZE] = {1, 2, 20, 80, 99};//similar to test case 1 and 2
                int test_attrs[CREW_SIZE] = {3, 6, 12, 16, 18};

                //will display the crew_report before the entire crew is re-rolled		
		for (int i = 0; i < 5; ++i) {
		    chCharisma[i] = test_attrs[i];
                    chIntel[i] = test_attrs[i];
                    chPsi[i] = test_attrs[i];
                    chStr[i] = test_attrs[i];
                    chAgi[i] = test_attrs[i];
                    generate_race(i, (i % 4) + 1);
                    chLead[i] = gen_enc_skill(chCharisma[i], chIntel[i], test_bonuses[i]);
                    chNav[i] = gen_enc_skill(chIntel[i], chPsi[i], test_bonuses[i]);
                    chTac[i] = gen_enc_skill(chStr[i], chAgi[i], test_bonuses[i]);
                    chEng[i] = gen_enc_skill(chIntel[i], chAgi[i], test_bonuses[i]);
                    chDip[i] = gen_enc_skill(chCharisma[i], chPsi[i], test_bonuses[i]);
		}
		print_crew_report();

	      	puts("you will now re-roll the crew!: ");//confirms the action is about to be executed

		int upper = 4; //upper bound
                int lower = 0; // lower bound
                srand(1000);//same functionay and execution as test case 2 

		for(int i = 0; i < 5; i++){
			//similar loop to test case 2, except this time we are looping through each character in the group with the corresponding index, and not just index 0. 
			int num = (rand() % (upper - lower + 1)) + lower;
                        //printf("the num is: %2d\n", num);
                        chCharisma[i] = test_attrs[num];
                        chIntel[i] = test_attrs[num];
                        chPsi[i] = test_attrs[num];
                        chStr[i] = test_attrs[num];
                        chAgi[i] = test_attrs[num];
                        generate_race(i, (i % 4) + 1);
                        chLead[i] = gen_enc_skill(chCharisma[num], chIntel[num], test_bonuses[num]);
                        chNav[i] = gen_enc_skill(chIntel[num], chPsi[num], test_bonuses[num]);
                        chTac[i] = gen_enc_skill(chStr[num], chAgi[num], test_bonuses[num]);
                        chEng[i] = gen_enc_skill(chIntel[num], chAgi[num], test_bonuses[num]);
                        chDip[i] = gen_enc_skill(chCharisma[num], chPsi[num], test_bonuses[num]); 

		}
		puts("the crew was re-rolled!:"); //confirms that the code was exucuted before exiting the switch statement and printing the crew_report(); 
		
		  }
		break;
        default:
            break;
    }
    
    print_crew_report();

    // start prompting user for changes to rolled crew
    for (int i = REROLLS_ALLOWED; i > 0; i--) {
        char rr;
        int flag = 1;
        printf("Enter C to reroll the crew or a crew number [0-4] to reroll "
                   "reroll a crew member. You have %d of 3 rerolls left:\n", i);
        do {
            rr = getchar();
            if (rr == 'C' || rr == 'Q'|| (rr >= '0' && rr < '5'))
                flag = 0; // exit loop
            else if (rr == '\n' || rr == ' ')
                continue;
            else
                printf("Invalid option: %c", rr);

        } while (flag);

        if (rr == 'C')
            generate_crew();
        else if (rr == 'Q') {
            puts("Enjoy the game!");
            exit(1);
        } else 
            generate_crew_member(rr - '0');
        
        print_crew_report();
    }

    puts("You have exhaused your re-roll options. This is your crew. Enjoy the game!");


} // end main

/*
    print_crew_report:

    TODO: Implement displaying unimplmented attributes and skills.

    Prints table displaying crew position, race, attribute values, and skill values.
    Skill values denote if the crew member is a natural or extra-natural skill.
*/
void print_crew_report(void) {
    puts("       Race   Attributes         Skills");
    puts("Crew          C  I  S  P  A      N    E    L    T    D");
    for (int id = 0; id < CREW_SIZE; ++id) {
        switch (id) {
            case 0:
                printf("Cap    ");
                break;
            case 1:
                printf("Com    ");
                break;
            case 2: 
                printf("Eng    ");
                break;
            case 3:
                printf("Nav    ");
                break;
            case 4:
                printf("Sec    ");
                break;
        } // end switch

        printf("%c     ", chRace[id]);
        printf("%2d ", chCharisma[id]);
        printf("%2d ", chIntel[id]);
	printf("%2d ", chStr[id]);
	printf("%2d ", chPsi[id]);
	printf("%2d    ", chAgi[id]);
	print_skill(chNav[id]);
	printf(" "); 
	//printf("   0  ");
        print_skill(chEng[id]);
	printf(" ");
	//printf("   0  ");
	print_skill(chLead[id]);
	printf(" ");
	//printf("   0  ");
	print_skill(chTac[id]);
	printf(" ");
	//printf("   0  ");
	print_skill(chDip[id]);
	printf("\n");


	//added strength and agility
        /*	
        print_skill(chNav[id]);
        printf("   0  ");
	print_skill(chEng[id]);
	printf("   0  ");
        print_skill(chLead[id]);
	printf("   0  ");
	print_skill(chTac[id]);
	printf("   0  ");
	print_skill(chDip[id]);
        printf("   0    0\n");
	*/
	//added eng,dip,tac
    }

}

/*
    print_skill:

    Helper function that prints the skill value correctly by decoding the skill code
    and flaging the natural roll with a * or +. 
*/
void print_skill(int skill_cd) {
    int bonus = skill_bonus_lvl(skill_cd);
    int skill_val = decode_skill_value(skill_cd);

    printf(" ");  // print padding to the left
    if (bonus) {
        char bonus_char = bonus == 1 ? '*' : '+';
        if (skill_val > 0)
            printf(" ");
        printf("%d%c", skill_val, bonus_char);
    } else 
        printf(" %d ", skill_val );
}


void generate_crew(void) {
    for (int i = 0; i < CREW_SIZE; ++i) 
        generate_crew_member(i);
}

/*
   generate_crew_member: 

   TODO: Finish attribute generation
  
   Uses the crew_id to generate crew member stats. The stats
   are maintained in global arrays. 
*/
void generate_crew_member(int crew_id) {
    // generate basic attributes
    chCharisma[crew_id] = roll_dice(3, SIX_SIDED);
    chIntel[crew_id] = roll_dice(3, SIX_SIDED);
    chPsi[crew_id] = roll_dice(3, SIX_SIDED);
    chStr[crew_id] = roll_dice(3, SIX_SIDED);
    chAgi[crew_id] = roll_dice(3, SIX_SIDED);
    // need to finish basic attributes
    // finished

    
    generate_race(crew_id, 0);

    generate_skills(crew_id);
} 

/*
 * roll_dice:
    Takes the number of dice rolls and dice sides.
    
    Returns the sum of the all the dice rolls. 
*/
int roll_dice(int rolls, int dice_sides) {
    int sum = 0;
    for (int i = 0; i < rolls; ++i) {
        sum += (rand() % dice_sides) + 1;
    }
    
    return sum;
}

/*
    generate_race:

    TODO: Finish implementing racial attribute adjustment

    Generates a random race and then adjusts attributes accordingly. 
    Operates on global arrays.
*/
void generate_race(int crew_id, int testing) {
    int race;
    if (!testing)
        race = rand() % 4 + 1;
    else 
        race = testing;
    
    switch (race) {
        case TERRAN:
            chRace[crew_id] = 'T';

            break;
        case MARTIAN:
            chRace[crew_id] = 'M';
            chPsi[crew_id] += 2;
            // strength and agility adjustments not implemented
	    chStr[crew_id] -= 2;
	    chAgi[crew_id] += 1;
	    //added strength and agility
            break;
        case VENUSIAN:
            chRace[crew_id] = 'V';
	    chCharisma[crew_id] += 1;
	    chIntel[crew_id] -= 1;
	    chStr[crew_id] += 1;
	    chPsi[crew_id] += 1;
	    chAgi[crew_id] -= 1;
	    //done
            // implement racial bonues
            break;
        case SATURIAN:
            chRace[crew_id] = 'S';
	    chCharisma[crew_id] -= 1;
	    chIntel[crew_id] += 2;
	    chStr[crew_id] -= 1;
	    chPsi[crew_id] += 1;
	    //done
            // implement racial bonues
            break;
        default:
            puts("Something went terribly wrong to wind up here.");
            exit(1);
            break;

    }
} // end generate_race

/*
    generate_skills:

    TODO: Finish generating all skills

    Skills are based on critical attribute values and modified by
    natural bonus, we store the natural bonus in the skill array. 
    
*/
#define ROLL_NEW -1
void generate_skills(int crew_id) {
    chLead[crew_id] = gen_enc_skill(chCharisma[crew_id], chIntel[crew_id], ROLL_NEW);
    chNav[crew_id] = gen_enc_skill(chIntel[crew_id], chPsi[crew_id], ROLL_NEW);
    chEng[crew_id] = gen_enc_skill(chIntel[crew_id], chAgi[crew_id], ROLL_NEW);
    chTac[crew_id] = gen_enc_skill(chStr[crew_id], chAgi[crew_id],  ROLL_NEW);
    chDip[crew_id] = gen_enc_skill(chCharisma[crew_id], chPsi[crew_id], ROLL_NEW);
    // remaining skills needed
    // done wit this

}

/*
    encode_skill

    Codes the average critical skills according to the table:
    AVG_ATTR    Skill_cd
    --------    --------
      3           1
      4-6         2
      7-14        0
      15-17       3
      18          4

    Natural bonus is rolled and encoded as
    NAT_BONUS   Bonus_cd
    ---------   --------
      0-1         10
      2-19        20
      20-79       0
      80-97       30
      98-99       40

    Encoded skill is skill_cd + bonus_cd
*/
int gen_enc_skill(int attr1, int attr2, int bonus_roll) {
    int skill_cd;
    int avg_attr = (attr1 + attr2) / 2;
    if (avg_attr == 3) 
        skill_cd = 2;
    else if (avg_attr < 7)
        skill_cd = 1;
    else if (avg_attr < 15)
        skill_cd = 0;
    else if (avg_attr < 18)
        skill_cd = 3;
    else
        skill_cd = 4;
    
    
    if (bonus_roll < 0)
        bonus_roll = roll_dice(1, TEN_SIDED) * 10 + roll_dice(1, TEN_SIDED);
    int bonus_cd;
    if (bonus_roll < 2)
        bonus_cd = 20;
    else if (bonus_roll < 20)
        bonus_cd = 10;
    else if (bonus_roll < 80)
        bonus_cd = 0;
    else if (bonus_roll < 98)
        bonus_cd = 30;
    else
        bonus_cd = 40;
    
    return bonus_cd + skill_cd;

} // end gen_enc_skill

/*
    decode_skill_value:

    decodes the skill and returns the skill value.

    ability_based skill_cd = encoded_skill_cd % 10
    nat_roll_skill_cd = encoded_skill_cd / 10

    ability cd table (nat_roll_skill_cd's are the same except x10)
    ability_skill_cd    Value
    ----------------    -----
    0                   0
    1                   -2
    2                   -1
    3                   1
    4                   2
*/
int decode_skill_value(int encoded_skill) {
    int skill_value = 0;
    int skill_cd = encoded_skill % 10;
    int bonus_cd = encoded_skill / 10;

    // defensive coding
    if (skill_cd > 4 || bonus_cd > 4) {
        puts("Something is very wrong with an encoded skill value.");
        exit(1);
    }

    if (skill_cd > 0)
        if (skill_cd < 3)
            skill_value = skill_cd * -1;
        else 
            skill_value = skill_cd - 2;
     
    if (bonus_cd > 0)
        if (bonus_cd < 3)
            skill_value += (bonus_cd * -1);
        else
            skill_value += (bonus_cd - 2);
    
    return skill_value;
} // end decode_skill_value

/*
    skill_bonus_lvl:

    Returns 0, 1, or 2 for the bonus level of the skill.
*/
int skill_bonus_lvl(int skill_cd) {
    int decode_bonus = skill_cd / 10;

    if (decode_bonus > 2)
        return decode_bonus - 2;
    else
        return decode_bonus;
}
