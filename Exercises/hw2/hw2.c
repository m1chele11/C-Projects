// homework two
// Author Michele Barrantes
//C291 
#include <stdio.h> 

	int main(void){
		printf("Welcome to salary calcs:\n");
		
		//initial directions
		printf("Directions:\n for each employee type their will be a paycode that shall correspond to them. when wanting to input information please enter the correct paycode followed by their corresponding Overtime, credit hours, or courses taught.\nthe paycodes are:\nA = Administator Staff, no OT\nS = Staff, has OT\nR = Regular Faculty, has credit hours\nJ = Adjunct Faculty, has credit hours \nT = Teaching Assistant, has amount of courses, and OT\nH = Hourly staff");
		//initializing variables to hold input values
		char input;
	       	//salary holders	
		int a;int s; int r; int j; int t; int h;
	       	//OT rates if applicable	
		int s_ot; float r_credits; float j_credits;float t_ot;float h_ot;
	   	//week and month averages	
		float month_Avg_A=0;float month_Avg_S=0;float month_Avg_R=0;float month_Avg_J=0;float month_Avg_H=0;float month_Avg_T=0;
	        float week_Avg_A=0; float week_Avg_S=0;float week_Avg_R=0; float week_Avg_J=0;float week_Avg_H=0;float week_Avg_T=0; 
		float ot_pay_S;	float r_credits_pay;int t_courses;int t_hours;   
		//these variables are counter for each employee type
		int count_A = 0; int count_S = 0; int count_R = 0; int count_J = 0; int count_T = 0; int count_H = 0; 
		//these hold the avereges
		float Avg_pay_A;float Avg_pay_S; float Avg_pay_R; float Avg_pay_J; float Avg_pay_T; float Avg_pay_H;  
		//do while loop with loop statements that runs unluss user enters Q
		do{
			//reads paycode
			//for loop is extra credit +10 points for validating that the code is correct
			for(;;){
			puts("Enter the paycode you wish:\n"); 
			scanf("%c", &input);
			if(input == 'A' || 'S' || 'R' || 'J' || 'H' || 'T'||'?'){
			break;
				}
			}
			//switch cases to determine what math to apply
			switch(input){
				case 'A': ;
						  
				       	count_A ++; 
					puts("Please enter salary for administrator\n");
						scanf("%d", &a); 		
				       Avg_pay_A += a; 
				       month_Avg_A += a / 12;
				       week_Avg_A += month_Avg_A / 4; 
					 
					break;
				case 'S': ;
					count_S ++; 
					puts("Please enter salary for staff followed by OT hours worked with a space in between: \n"); 
						scanf("%d %d", &s, &s_ot);
						//checking amount of hours and if OT is applicable
						if(s_ot == 0){
							month_Avg_S = s /12;
							week_Avg_S = month_Avg_S / 4;
							ot_pay_S = 0; 
						}else{
							month_Avg_S = s / 12; 
							ot_pay_S = 1.5 * month_Avg_S * s_ot/160;
							week_Avg_S = month_Avg_S / 4; 
						}
						Avg_pay_S = s + ot_pay_S; 	
					break;
				case 'R': ;
					 count_R ++;  
					 puts("Please enter salary for Regular falculty followed by credits of overload with speace in between:\n");
					  scanf("%d %f", &r, &r_credits);
					  //checking amount of credits 
					  if(r_credits == 0){
					  	month_Avg_R = r / 10; 
						week_Avg_R = month_Avg_R / 4;
					       	r_credits_pay = 0; 	
					  }else{
					  	month_Avg_R = r / 10; 
						r_credits_pay = (r_credits / 3) * 8500; 
						week_Avg_R = month_Avg_R / 4; 
					  }
					  Avg_pay_R = r + r_credits_pay; 
					break;
			      case 'J': ;
					count_J ++; 	

                                         puts("Please enter salary for Adjunct falculty followed by credits(max 9) max 9 pr semester:\n");
                                          scanf("%d %f", &j,&j_credits);
					  //checking amount of credits 
					  if(j_credits > 9){
					  puts("Adjuncts can teach a max of 9 credits a semester, re-enter:");
					  j_credits = 9; 
					  }

                                          if(j_credits == 0){
                                                month_Avg_J = 0;
                                                week_Avg_J = 0;
                                          }else{
						float ppc;	
                                                ppc = (8500 / 3);
						j = ppc * j_credits;
						month_Avg_J = j / 5;
						week_Avg_J = month_Avg_J / 4;
                                          }
					  
					
                                        break;
				case 'T': ;
					  count_T ++; 
					  
					  
					 	puts("please enter number of courses followed by number of hours this month with space in between: \n");
					        scanf("%d, %d", &t_courses, &t_hours);
				       		if(t_hours > 48){
							puts("max is 12 hours a week (48 a month with OT):\n");
						}
						//checking the hours and how much OT
					  if(t_hours == 0){
					 	month_Avg_T = 0;
						week_Avg_T = 0; 
					  }
					  else{
						if(t_hours <= 10 * t_courses){
							t = t_courses * 2500; 
						}else{
							t_ot = (t_hours - (10 * t_courses)) * (2500 / 10);
						        t = t_courses * 2500; 	
						}
						month_Avg_T = t / 10;
						week_Avg_T = month_Avg_T / 4;

					  }	
					break; 
				case 'H': ;
					  count_H ++; 
					  int h_hours;
					  int pay;
					  
						  puts("please enter hourly wage followed by total hours with space in between:");
						  scanf("%d, %d", &h, &h_hours); 
						  if(h_hours > 160){
							 puts("max hours is 160");
						  }
					//checking how many hours and if OT applies 160 is max 80 and up is OT 	  
					  if(h_hours == 0){
						  month_Avg_H = 0; 
					 	  week_Avg_H = 0;
						  h_ot = 0;
					  } 
					  if(h_hours <= 80){
					  	pay = h_hours * h;
					        h_ot = 0;
						month_Avg_H = pay / 10;
						week_Avg_H = month_Avg_H / 4; 	
					  }
					  if(h_hours > 160){
					 	h_hours = 160;
						pay = h_hours * h;
                                                h_ot = (h_hours - 20) * 1.25 * h;
                                                month_Avg_H = pay / 10;
                                                week_Avg_H = month_Avg_H / 4;

					  } else if(h_hours > 80 && h_hours <= 160 ){
						pay = h_hours * h;
					  	h_ot = (h_hours - 20) * 1.25 * h;
					        month_Avg_H = pay / 10;
                                                week_Avg_H = month_Avg_H / 4;	
					  }
					  Avg_pay_H = pay;

					 break;
				//helper feature
				case '?': 
					 puts("Enter one of A,S,R,J,T,H");
					break;

				}			

			}while(input != 'Q');
		
		//takes the final values after the while loop is exited and divides by the respectable counter
		Avg_pay_A = Avg_pay_A / count_A;
	        Avg_pay_S = Avg_pay_S / count_S;
		Avg_pay_R = Avg_pay_R / count_R;
		Avg_pay_J = Avg_pay_J / count_J;
		Avg_pay_T = Avg_pay_T / count_T;
		Avg_pay_H = Avg_pay_H / count_H; 	
		
		//printing the averages
		printf("A: month Avg: %.2f week Avg: %.2f Avg Pay: %.2f\n",month_Avg_A, week_Avg_A,Avg_pay_A);
		printf("S: month Avg: %.2f week Avg: %.2f Avg Pay: %.2f\n", month_Avg_S, week_Avg_S,Avg_pay_S); 
		printf("R: month Avg: %.2f week Avg: %.2f Avg Pay: %.2f\n", month_Avg_R, week_Avg_R,Avg_pay_R);
		printf("J: month Avg: %.2f week Avg: %.2f Avg Pay: %.2f\n", month_Avg_J, week_Avg_J,Avg_pay_J);
		printf("T: month Avg: %.2f week Avg: %.2f Avg Pay: %.2f\n", month_Avg_T, week_Avg_T,Avg_pay_T);
		printf("H: month Avg: %.2f week Avg: %.2f Avg Pay: %.2f\n", month_Avg_H, week_Avg_H,Avg_pay_H); 	

	        	
		//Displaying that the program was exited
		puts("\nThank you have a nice day\n");
}
