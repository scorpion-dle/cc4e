
/* gradepretty - Calculate student grades based on partial scores

* The program will prompt for student grades until EOF is entered

* The final grade is 30% programs, 50% tests and 20% homework

* Grades are assigned based on the following scale:

*    >0.90 4.0
*    >0.80 3.0
*    >0.70 2.0
*    <0.60 0.0

*  Written by: C. Severance - Tue Dec  7 17:40:05 EST 1993 */

#include <stdio.h>

main () {

  float pper,tper,hper,percent,totper,aveper,gpa,totgpa,avegpa;
  int student,count;

/* Initialization and headings */

  totper = 0;
  totgpa=0;
  count = 0;
  printf("Grade program - written by Charles Severance \n");

/* Read the three percentages.  Note that data is expected from */
/* a file so there is no prompt. */

  while(1) {
    if ( scanf("%d %f %f %f",&student,&pper,&tper,&hper) == EOF ) break;

    count = count + 1;

    percent = pper * 0.30 + tper * 0.50 + hper * 0.20;
    totper = totper + percent;

/* Determine the final grade and add it to the running total for GPA */

    gpa = 0.0;
    if ( percent >= 0.90 ) {
      gpa = 4.0;
    } else if ( percent >= 0.80 ) {
      gpa = 3.0;
    } else if ( percent >= 0.70 ) {
      gpa = 2.0;
    }

    totgpa = totgpa + gpa;

/* Print out the student information */

    printf(" %9d  %7.2f   %7.2f   %7.2f   %7.2f   %5.2f\n", 
            student,pper,tper,hper,percent,gpa);
  } /* End while */

/* Calculate the averages */

  if ( count  == 0 ) {
    avegpa = 0.0;
    aveper = 0.0;
  } else {
    avegpa = totgpa/count;
    aveper = totper/count;
  }

/* Print them out */

  printf("Average                                   %7.2f   %5.2f\n", 
     aveper,avegpa);
}
