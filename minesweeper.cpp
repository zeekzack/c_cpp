#include<iostream>
#include<cstdio>

/*
 * PC/UVa IDs: 110102/10189, Popularity: A, Success rate: high Level: 1
    Have you ever played Minesweeper? This cute little game comes with a certain op-
    erating system whose name we can’t remember. The goal of the game is to find where
    all the mines are located within a M × N field.
    The game shows a number in a square which tells you how many mines there are
    adjacent to that square. Each square has at most eight adjacent squares. The 4 × 4 field
    on the left contains two mines, each represented by a “*” character. If we represent the
    same field by the hint numbers described above, we end up with the field on the right:
    *...
    ....
    .*..
    ....
    *100
    2210
    1*10
    1110
    Input
    The input will consist of an arbitrary number of fields. The first line of each field
    contains two integers n and m (0 < n, m ≤ 100) which stand for the number of lines
    and columns of the field, respectively. Each of the next n lines contains exactly m
    characters, representing the field.
    Safe squares are denoted by “.” and mine squares by “*,” both without the quotes.
    The first field line where n = m = 0 represents the end of input and should not be
    processed.
    Output
    For each field, print the message Field #x: on a line alone, where x stands for the
    number of the field starting from 1. The next n lines should contain the field with the
    “.” characters replaced by the number of mines adjacent to that square. There must
    be an empty line between field outputs.

 */
using namespace std;
int main(){
    int m,n;
    scanf("%d %d",&m, &n);
    char input[m][n];
    int output[m][n];

    for(int i=0; i<m; i++){
        for(int j=0; j<=n; j++){
            output[i][j]=0;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> input[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int p=i-1;p<=i+1;p++){
                for(int q=j-1;q<=j+1;q++){
                    if((p>=0 && p<m)&& (q>=0 && q<n) && !(p==i && q==j))
                    output[i][j]+=input[p][q]=='*'?1:0;
                }
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(input[i][j]=='*')
                printf("%c",input[i][j]);
            else
                printf("%d",output[i][j]);
        }
        printf("\n");
    }
    return 0;
}
