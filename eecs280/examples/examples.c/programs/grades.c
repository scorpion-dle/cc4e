
/* grades - Calculate student grades based on partial scores

* The final grade is 30% programs, 50% tests and 20% homework

* Grades are assigned based on the following scale:

*    >0.90 4.0
*    >0.80 3.0
*    >0.70 2.0
*    <0.60 0.0

*  Written by: C. Severance - Tue Dec  7 17:33:38 EST 1993

*/

main() {
  float pper,tper,hper,totam;

/* Prompt the user for the three percentages */

  printf("enter the program percentage - ");
  scanf("%f",&pper);
  printf("enter the test percentage - ");
  scanf("%f",&tper);
  printf("enter the homework percentage - ");
  scanf("%f",&hper);

/* Calculate the total percentage */

  totam = pper * 0.30 + tper * 0.50 + hper * 0.20;
  printf("total percentage is  %f\n", totam);

/* Determine the final grade */

  if ( totam >= 0.90 ) {
    printf("grade is 4.0\n");
  } else if ( totam >= 0.80 ) {
    printf("grade is 3.0\n");
  } else if ( totam >= 0.70 ) {
    printf("grade is 2.0\n");
  } else {
    printf("grade is 0.0\n");
  }
}
