    #include <stdio.h>

    typedef size_t Type;

    Type gcd( Type a, Type b ){
        for( Type t = 0; b != 0; ){
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int main(){
        Type a = 0,
             b = 0;
        scanf( "%ld %ld", &a, &b );
        Type ans = gcd( a, b );
        printf( "%ld\n", ans );
        return 0;
    }