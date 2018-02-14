#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//création du plateau de jeu
char tab[12][22];

void affichergrille(a,b)
{
    int i,j;
    //2 boucle for pour balayer le plateau
    for(i = 0;i < 12;i++)
    {
        for(j = 0;j < 22;j++)
        {
            //on creer des bordures en formes de X
            if(i == 0 | i == 11 |j == 0 | j == 21)
            {
                tab[i][j] = 'X';
                printf("%c",tab[i][j]);
            }


            // 1 case qui n'est pas sur les bordures peut acceuillir le pacman C
            else if(i == a && j == b)
            {

                tab[a][b] = 'C';
                printf("%c",tab[a][b]);

            }
            //le reste du plateau est vide
            else
            {
                tab[i][j] = ' ';
                printf("%c",tab[i][j]);
            }
        }
        printf("\n");


    }


}
//fonction pour changer les coordonnées du pacman
void direction(int *a,int *b,int c,int d)
{
    if(tab[*a+c][*b+d] == 'X')
    {
        *a-=9*c;
        *b-=19*d;

    }
    else
    {
        *a += c;
        *b += d;
    }
}

void gotoligcol(int lig,int col)
{
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),mycoord);
}

int main()
{
    int a,b,x,y,q,lig = 0,col = 0;
    char key;
    //les premieres coordonnées sont aléatoires
    srand(time(NULL));
    a = rand() % (9);
    b = rand()%(20);
    x = rand()%9+1;
    y = rand()%19+1;
    q=0;



    while(key != 'm')//condition d'arret du jeu
    {

        gotoligcol(lig,col);
        affichergrille(a,b);
        gotoligcol(x,y);
        printf("o");//afficher une pomme
        key = getch();
        switch(key)
        {
            case 'z'://la touche"z" deplace pacman vers le haut
                direction(&a,&b,-1,0);
                break;
            case 's'://la touche "s" deplace pacman vers le bas
                direction(&a,&b,1,0);
                break;
            case 'q'://la touche"q" deplace pacman vers la gauche
                direction(&a,&b,0,-1);
                break;
            case 'd'://la touche "d" deplace pacman vers la droite
                direction(&a,&b,0,1);
                break;
            default :
                break;
        }
        if(a==x && b==y)
        {
            q=q+1;
            gotoligcol(15,15);
            printf("vous avez marque %d points",q);
            x = rand()%9+1;
            y = rand()%19+1;
            gotoligcol(x,y);
            printf("o");
        }

    }
    return 0;
}



