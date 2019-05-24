/* Solution to comp20005 Assignment 2, 2019 semester 1.

   Authorship Declaration:

   (1) I certify that the program contained in this submission is completely
   my own individual work, except where explicitly noted by comments that
   provide details otherwise.  I understand that work that has been developed
   by another student, or by me in collaboration with other students,
   or by non-students as a result of request, solicitation, or payment,
   may not be submitted for assessment in this subject.  I understand that
   submitting for assessment work developed by or in collaboration with
   other students or non-students constitutes Academic Misconduct, and
   may be penalized by mark deductions, or by other penalties determined
   via the University of Melbourne Academic Honesty Policy, as described
   at https://academicintegrity.unimelb.edu.au.

   (2) I also certify that I have not provided a copy of this work in either
   softcopy or hardcopy or any other form to any other student, and nor will
   I do so until after the marks are released. I understand that providing
   my work to other students, regardless of my intention or any undertakings
   made to me by that other student, is also Academic Misconduct.

   (3) I further understand that providing a copy of the assignment
   specification to any form of code authoring or assignment tutoring
   service, or drawing the attention of others to such services and code
   that may have been made available via such a service, may be regarded
   as Student General Misconduct (interfering with the teaching activities
   of the University and/or inciting others to commit Academic Misconduct).
   I understand that an allegation of Student General Misconduct may arise
   regardless of whether or not I personally make use of such solutions
   or sought benefit from such actions.

   Signed by: [Kunaal Dipash Patel 944661]
   Dated:     [13/05/2019]

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 3000
#define FIRST_LINE 1

char *months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

typedef struct{
	int Year;
	int months[];
}year_t;

typedef struct{
	int Month;
	int monthly_precipitation;
	char validity;
	int has_data;
	double tau;
	double mean;
}month_t;

typedef struct{
	int station_number;
	int Year;
	int Month;
	double rainfall;
	char validity;	
}alldata_t;






void bypass_header(int c);
void read_data(alldata_t *entries);


int 
main(int argc, char *argv[]) {
	
	
	alldata_t entries[MAX_ENTRIES];
	bypass_header(FIRST_LINE);
	read_data(entries);
	return 0;
}

void 
bypass_header(int c){
	int character;

	
	while((character= getchar())!= EOF){
		if (character == '\n'){
			c--;
			if(c==0){ 
			return;
		}
	}
}
}



void
read_data(alldata_t *entries){

	int station_number;
	int Year;
	int Month;
	double rainfall;
	char validity;
	int i=0;
	int count;
	
	
	while(scanf("IDCJAC0001,%d,%d,%d,%lf,%c\n",&station_number,&Year,&Month,&rainfall,&validity)==5){
	
		entries[i].station_number = station_number;
		entries[i].Year = Year;
		entries[i].Month = Month;
		entries[i].rainfall = rainfall;
		entries[i].validity = validity;
		
		
		i++;                 
	}
	printf("S1, site number %06d, %d datalines in input",station_number,i);
	printf("\n");
	
	int current_year=entries[1].Year;
	int current_month;

	
	for(count=0;count<i;count++){		
		while(entries[count].Year==current_year){
			printf("S1, %d: ",current_year);
			printf("\n");
			current_year++;
			
		}
			
	}
	
	return ;
}

