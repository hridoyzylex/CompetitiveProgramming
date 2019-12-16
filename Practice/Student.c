#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct team_tag {
        char name[80];
        int won;
};

typedef struct team_tag team;

void sort_team(team *s, int length);

int main(void)
{
    team s, *ps;
    int i, n;

    printf("Enter Number of Teams: ");
    scanf("%d",&n);

    ps = (team *) malloc(sizeof(team)*n);

    if (ps == NULL) {
        printf("Failed");
        exit(1);
    }

    for (i=0; i<n; i++) {
        printf("Enter Info of team %d: ", i+1);
        scanf("%s %d", &ps[i].name, &ps[i].won);
    }

    sort_team(ps,n);

    for (i=0; i<n; i++) {
        printf("\n\n%d Rank: ", i+1);
        printf("%s, %d\n", ps[i].name, ps[i].won);
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
            if(s[j].won > s[i].won){
                tmp = s[j];
                s[j] = s[i];
                s[i] = tmp;
            }
        }
    }
    return;
}
