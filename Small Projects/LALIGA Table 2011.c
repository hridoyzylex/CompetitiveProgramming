#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct team_tag {
        char name[80];
        int won, draw, point;
};

typedef struct team_tag team;

void sort_team(team *s, int length);

int main(void)
{
    team s, *ps;
    int i, n;

    printf("Enter Number of Teams: ");
    scanf("%d",&n);
    printf("........................\n");

    ps = (team *) malloc(sizeof(team)*n);

    if (ps == NULL) {
        printf("Failed");
        exit(1);
    }

    for (i=0; i<n; i++) {
        printf("Enter Info of team %d: \n", i+1);
        printf("Team's Name : ");
        scanf("%s", &ps[i].name);
        printf("Match Won   : ");
        scanf("%d", &ps[i].won);
        printf("Match Drawn : ");
        scanf("%d", &ps[i].draw);
        printf("........................\n");

        ps[i].point = ps[i].won*3 + ps[i].draw*1;
    }

    sort_team(ps,n);
    printf("\n\n");

    for (i=0; i<n; i++) {
        printf("%d Rank: ", i+1);
        printf("%s, with %d points\n", ps[i].name, ps[i].point);
    }

    free(ps);
    return 0;
}

void sort_team(team *s, int length)
{
    team tmp;
    int i,j;

    for(i=0;i<length;i++){
        for(j=i+1;j<length;j++){
            if(s[j].point > s[i].point){
                tmp = s[j];
                s[j] = s[i];
                s[i] = tmp;
            }
        }
    }
    return;
}
