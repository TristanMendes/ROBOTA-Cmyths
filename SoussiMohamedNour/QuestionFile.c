#include "structs.h"
#include "fn.h"

int arr[3] = {1,7,13};
FILE *fp;
int getRandom()
{


    int num;

    srand(time(0));

    num = (rand() % (3));

    printf("%d\n",num);
    return arr[num];
}
void openfile()
{
    fp = fopen("ques.txt","r");

    if(fp == NULL)
    {
        printf("Failed to open file . \n");
    }
    else
    {
        printf("File opened . \n");
    }
}

void loadtext()
{
    int quline;
    int answer1line;
    int answer2line;
    int answer3line;
    int answer4line;
    int correctline;
    int i;

    i = 0;


    //i = quline;
    openfile();
    quline = getRandom();
    printf("random : %d \n",quline);
    answer1line = quline + 1;
    answer2line = quline + 2;
    answer3line = quline + 3;
    answer4line = quline + 4;
    correctline = quline + 5;

   while((i <= quline) && fgets(qa.questionText,max_length,fp) != NULL)
   {
    //printf("%d \n",i);
    if(i == quline-1)
    {
        printf("QUES : %s \n",qa.questionText);
        break;

    }
    else
    {
        i++;
    }
   }
   while( (i <= answer1line ) && (fgets(qa.answerA,max_length,fp) != NULL))
   {
        //printf("%d \n",i);
        if ( i == answer1line-2)
        {
            //fscanf(fp,"%s",&qa.answerA);
            printf("A1: %s \n",qa.answerA);

            break;
        }
        else
        {
            i++;
        }
   }
   while((i <= answer2line) && fgets(qa.answerB,max_length,fp) != NULL)
   {
        if( i == answer2line - 3)
        {
            printf("A2 : %s \n",qa.answerB);
            break;
        }
        else
        {
            i++;
        }
   }
    while((i <= answer3line) && fgets(qa.answerC,max_length,fp) != NULL)
   {
        if( i == answer3line - 4)
        {
            printf("A3 : %s \n",qa.answerC);
            break;
        }
        else
        {
            i++;
        }
   }
    while((i <= answer4line) && fgets(qa.answerD,max_length,fp) != NULL)
   {
        if( i == answer4line - 5)
        {
            printf("A4 : %s \n",qa.answerD);
            break;
        }
        else
        {
            i++;
        }
   }
   while((i <= correctline) && fgets(qa.correctanswer,max_length,fp) != NULL)
   {
        if( i == correctline - 6)
        {
            printf("CORRECT ANSWER : %s \n",qa.correctanswer);
            break;
        }
        else
        {
            i++;
        }
   }


   //fclose(fp);

}
int answernumber()
{
    int correctnumber;

    if(strcmp(qa.answerA,qa.correctanswer) == 0)
    {
        correctnumber = 1;
    }
    else if(strcmp(qa.answerB,qa.correctanswer) == 0)
    {
        correctnumber = 2;
    }
    else if(strcmp(qa.answerC,qa.correctanswer) == 0)
    {
        correctnumber = 3;
    }
    else if(strcmp(qa.answerD,qa.correctanswer) == 0)
    {
        correctnumber = 4;
    }

    return correctnumber;
}
