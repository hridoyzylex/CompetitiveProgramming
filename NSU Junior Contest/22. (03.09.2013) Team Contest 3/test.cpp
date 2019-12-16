#include <map>
#include <iostream>

using namespace std ;

int main( ) {

    map<int,int> m ;

    m[ 10 ] = 20 ;
    m[ 20 ] = 30 ;

    for( map<int,int> :: iterator p = m.begin() ; p != m.end() ; ++ p ) {
        cout << p->first << " " << p->second << endl ;
    }
    return 0 ;
}
