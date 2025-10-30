#include<stdio.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
void hangman(){
    srand(time(NULL));
    int random= rand() % 30;
    int i,alph_check,exist,count,draw=0,cont;
    char alph;
      printf("     __________\n");//5 spaces 10  usc
      printf("    |\n    |\n    |\n    |\n    |\n    |\n    |\n");//4 spaces
      printf("---------\n");//9
    char words[30][15]={"BAHRAIN","MANGOSTEEN","PHILIPPINES","POMEGRANATE","ARGENTINA","JAMUN","ALBANIA","ELDERBERRY","BOTSWANA","SNAKEFRUIT","DAHLIA","NARASINGH","STOCKFLOWER","PENCHALA","RAFFLESIA","KUSUMA","GANNERU","CHADAGONDA","MARIGOLD","BHONAGIRI","ADVENTUROUS","FALOODA","RIDICULOUS","DUMPLING","ENCHANTING","PESARATTU","MISCHIEVOUS","CROISSANT","MELODRAMATIC","BISIBELEBATH"};
    if(random<=9 && random%2==0)
    printf("     \nHINT: COUNTRY\n");
    if(random<=9 && random%2!=0)
    printf("     \nHINT: FRUIT\n");
    if(random>=10 && random<20 && random%2==0)
    printf("     \nHINT: FLOWER\n");
    if(random>=10 && random<20 && random%2!=0)
    printf("     \nHINT: SURNAME OF YOUR CLASSMATE\n");
    if(random>=20 && random<30 && random%2==0)
    printf("     \nHINT: ADJECTIVES\n");
    if(random>=20 && random<=30 && random%2!=0)
    printf("     \nHINT: FOOD\n");
    printf("\n");
    char word_tofind[15];
    for(i=0;words[random][i]!='\0';i+=1){
        word_tofind[i]='_';
        printf("_ ");
    }
        word_tofind[i]='\0';
    char space=' ',underscore='_';
    while(draw<=5){
        printf("\nEnter alphabet: ");
        scanf(" %c", &alph);
        alph=toupper(alph);
        count=0;
        for(exist=0;exist<i;exist++){
          if(alph==words[random][exist]){
            word_tofind[exist] = alph;
             count+=1;
          }
        }
        if (draw==5)//print the actual word
        return 0;
      if(count!=0){
        printf("\nPhew! That letter is in the word...The hangman gets to live another round!");
           }
    else{
      draw+=1;
      switch(draw){
        case 1:
        printf("     __________\n");
        printf("    |          |\n");
        printf("    |\n    |\n    |\n    |\n    |\n    |\n");
        printf("---------\n");
        printf("\nWrong letter! The hangman just said, 'Seriously?!'\n");
        break;
        case 2:
        printf("     __________\n");
        printf("    |          |\n");
        printf("    |          0\n    |\n    |\n    |\n    |\n    |\n");
        printf("---------\n");
        printf("\nNope! The word shook its head and said, 'Try again, human!'\n");
        break;
        case 3:
        printf("     __________\n");
        printf("    |          |\n");
        printf("    |          0\n    |          |\n    |          |\n    |          |\n    |\n    |\n");
        printf("---------\n");
        printf("\nThe word says, 'Sorry, I don't recognize that letter!'\n");
        break;
        case 4:
        printf("     __________\n");
        printf("    |          |\n");
        printf("    |          0\n    |          |\n    |         /|\\  \n    |          |\n    |\n    |\n");
        printf("---------\n");
        printf("\nLooks like that letter got lost on its way to the word.\n");
        break;
        case 5:
        printf("     __________\n");
        printf("    |          |\n");
        printf("    |          0\n    |          |\n    |         /|\\  \n    |          |\n    |         / \\  \n    |\n");
        printf("---------\n");
        printf("\nWell, you're consistent... consistently wrong!\n");
        printf("\nIf you were trying to lose, congrats!\n");
        printf("\n                   GAME OVER\n The word was: %s\n", words[random]);
        printf("Would you like to sacrifice Hangman again?\nIf YES press 1\nIf NO press 0\n");
        scanf("%d",&cont);
        if(cont)
        hangman();
        return;
      }
    }
     printf("\nCurrent word: %s\n", word_tofind);
        if (strcmp(word_tofind, words[random]) == 0) {
            printf("\nCongratulations! You guessed the word correctly: %s\n", words[random]);
            printf("Would you like to save Hangman again?\nIf YES press 1\nIf NO press 0\n");
            scanf("%d",&cont);
            if(cont)
            hangman();
            return;
     }
  }
}

int main()
{
    printf("If you thought your social life was hanging by a thread,just wait until you start playing\n                                 *HANGMAN*\n");
    int choice,instruction_choice;//choice is used for switch
    int ans,cont;//for do while
   do {
   printf("\nEnter: 1. To Start the Game.\n       2. For Instructions.\n       3. To Exit.\n");
   scanf("%d",&choice);
   switch(choice){
        case 1:
        hangman();
        break;
        case 2:
        printf("\n  INSTRUCTIONS\n\n1. GUESS A LETTER: Try to guess a letter in the word.\n2. GET FEEDBACK: We'll tell you if the letter is in the word or not.\n3. DRAW THE HANGMAN: If you guess incorrectly, we'll draw a part of hangman's gallows.\n4. WIN OR LOOSE: Guess the word correctly before the gallows is complete,to WIN!\n");
        printf("\nTo go back to game press 1.\n");
        scanf("%d",&instruction_choice);
        if(instruction_choice==1)
        hangman();
        break;
        case 3:
        printf("Exiting the game. Goodbye!");
        return 0;
        default:
        printf("Please enter a choice in the range\n");
       }
    }while(choice!=3);
    return 0;
}
