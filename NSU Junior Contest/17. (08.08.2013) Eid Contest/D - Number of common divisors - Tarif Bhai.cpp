#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std ;

int gcd(int a , int b ) {
    if( b == 0 ) return a ;

        return gcd( b , a % b ) ;
}

int divisorCount( int curgcd ) {
        int lim = sqrt( curgcd ) ;

        int ret = 0 ;

        for( int i = 1 ; i <= lim ; i ++ ) {
                if( ( curgcd % i ) == 0 ) {
                        int ot = curgcd / i ;

                        if( i == ot ) ret ++ ;
                        else ret += 2 ;
                }
        }

        return ret ;
}

int solve( int a , int b ) {
        int curgcd = gcd( a , b ) ;

        int cnt = divisorCount( curgcd ) ;

        return cnt ;
}

int main() {

        freopen("D.txt", "r", stdin);

        int T ;

        cin >> T ;

        int a , b ;

        for( int i = 0 ; i < T ; i ++ ) {
                scanf("%d %d",&a,&b) ;

                int res = solve( a , b ) ;

                cout << res << "\n" ;
        }

        return 0 ;
}
