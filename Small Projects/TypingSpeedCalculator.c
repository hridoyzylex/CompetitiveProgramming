#include <stdio.h>
#include <time.h>

int main ()
{
    time_t start,end;
    char GivenSentence[256] = "The Quick Brown Fox Jumps Over The Lazy Dog";
    char TypedSentence[256];
    float dif, Accuracy;
    int i, counter = 0;

    time (&start);
        printf ("Please Type The Following Sentence as it is: \n\n\a");
        puts(GivenSentence);
        gets (TypedSentence);
    time (&end);

    for (i=0; TypedSentence[i]!='\0'; i++)
    {
        if (TypedSentence[i] == GivenSentence[i])
            counter  = counter + 1;
    }

    Accuracy = ((1.0*counter)/43)*100;
    dif = difftime (end,start);

    printf("\a\n\nAccuracy is: %0.2f \n", Accuracy);
    printf("Typing Speed is: %0.2f WPM\n", (8.6/(dif/60)));

    return 0;
}
