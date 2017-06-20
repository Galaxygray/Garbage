#include <stdio.h>
#define N 6                                                                    
int s[N];                                                              

void MapColor( int dist[N][N], int s[N] )
{
    int color, area, k, i;                                                 
    s[0]    = 1;                                                           
    area    = 1;                                                          
    color    = 1;                                                          
    while ( area < N )                                                  
    {
        while ( color <= 4 )
        {
            k = 0;                                                 
            while ( (k < area) && (s[k] * dist[area][k] != color) ) 
                k++;
            if ( k < area )
                color++;                                       
            else{
                s[area] = color;                               
                area++;                                       
                if ( area >= N )
                    break;
                color = 1;                                    
            }
        }
        if ( color > 4 )                                              
        {
            area    = area - 1;                                   
            color    = s[area] + 1;  
        }
    }
    printf("");
    for ( i = 0; i < N; i++ )
    {
        printf( " NO.% d: ", i + 1 );
        switch ( s[i] )
        {
        case 0: printf( "Error\n" ); break;
        case 1: printf( "Read\n" ); break;
        case 2: printf( "blue\n" ); break;
        case 3: printf( "Green\n" ); break;
        case 4: printf( "yellow\n" ); break;
        }
    }
}


int main()
{
    int    dist[N][N] = { { 0, 1, 1, 1, 1, 1 }, /* µØÍ¼µÄÁÚ½Ó¾ØÕó */
                   { 1, 0, 1, 1, 0, 0 },
                   { 1, 1, 0, 1, 1, 1 },
                   { 1, 0, 1, 0, 0, 1 },
                   { 1, 1, 1, 0, 0, 1 },
                   { 1, 0, 1, 1, 1, 0 },};
    int    s[N] = { 0 };
    MapColor( dist, s );
    return(0);
}
