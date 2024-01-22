/*
 project2.cpp
 Danielle Choi
 306008729
 Created on 10/13/23
 */

#include <iostream>
#include <string>
#include <cassert>

int modulo( unsigned int m, unsigned int n );
int occurrences( int number, int d );
std::string lucky7s( std::string s );
bool combinations( int array[ ], int size, int target );

int main()
{
    using namespace std;

    // test code
    assert( modulo( 100, 10 ) == 0 );
    assert( modulo( 1, 13 ) == 1 );
    assert( modulo( 12, 5 ) == 2 );
    assert( modulo( 33, 6 ) == 3 );
    assert( modulo( 0, 6 ) == 0 );
    assert( modulo( 0, 1 ) == 0 );
    assert( modulo( 7, 1 ) == 0 );
    assert( modulo( 7, 2 ) == 1 );

    assert( occurrences( 567, 2 ) ==  0 );
    assert( occurrences( 128874, 2 ) == 1 );
    assert( occurrences( 212121, 2 ) == 3 );
    assert( occurrences( 0, 0 ) == 0 );
    assert( occurrences( 1000, 0 ) == 3 );
    assert( occurrences( 1111, 1 ) == 4 );

    assert( lucky7s( "cs32" ) == "cs32" );
    assert( lucky7s( "Apple Baseball" ) == "Ap77ple Basebal77l" );
    assert( lucky7s( "abbba" ) == "ab77b77ba" );
    assert( lucky7s( "aabbbaa" ) == "a77ab77b77ba77a" );
    assert( lucky7s( "Hello" ) == "Hel77lo" );
    assert( lucky7s( "Hiiiii  Jack" ) == "Hi77i77i77i77i 77 Jack" );
    assert( lucky7s( "Good%%" ) == "Go77od%77%" );
    assert( lucky7s( "aadad" ) == "a77adad" );

    int array[ 5 ] = { 2, 4, 6, 8, 10 };
    assert( combinations( array, 5, 10 ) == true );
    assert( combinations( array, 5, 18 ) == true );
    assert( combinations( array, 5, 15 ) == false );
    int other[ 5 ] = { 10, 8, 2, 6, 4 };
    assert( combinations( other, 5, 10 ) == true );
    assert( combinations( other, 5, 18 ) == true );
    assert( combinations( other, 5, 15 ) == false );
    int arr1[ 5 ]={ 1, 3, 5, 7, 9 };
    assert( combinations( arr1, 5, 10 ) == true );
    int arr2[ 5 ]={ 0, 2, 5, 8, 9 };
    assert( combinations( arr2, 5, 10 ) == true );
    assert( combinations( arr2, 5, 7 ) == true );
    assert( combinations( arr2, 5, 4 ) == false );
    int arr3[ 3 ]={ 2, 3, 4 };
    assert( combinations( arr3, 3, 2 ) == true );
    assert( combinations( arr3, 3, 3 ) == true );
    assert( combinations( arr3, 3, 4 ) == true );
    assert( combinations( arr3, 3, 5 ) == true );
    assert( combinations( arr3, 3, 6 ) == true );
    assert( combinations( arr3, 3, 7 ) == true );
    assert( combinations( arr3, 3, 9 ) == true );
    assert( combinations( arr3, 3, 12 ) == false );
    assert( combinations( arr3, 3, 10 ) == false );
    assert( combinations( arr3, 3, 1 ) == false );
    int arr4[ 4 ]={ 1, 3, 3, 7 };
    assert( combinations( arr4, 4, 6 ) == true );
    
    cout << "all tests passed!" << endl;
    return( 0 );
   }

int modulo( unsigned int m, unsigned int n ){
    if (m<n)
        return m;
    return modulo(m-n,n); //repeat subtracting n from m until n is larger than m
}

int occurrences( int number, int d ){
    if (number<=0)
        return 0;
    if (number%10==d) //if d is equal to the digit calculated, return +1
        return occurrences(number/10, d)+1;
    return occurrences(number/10,d); //if not equal, return +0
}

std::string lucky7s( std::string s ){
    if (s.size()<=1)
        return s; //return the first character
    if (s.at(s.size()-2)==s.at(s.size()-1)) //if the two adjacent characters are identical
        return lucky7s(s.substr(0,s.size()-1))+"77"+s.at(s.size()-1); //return string with 77 in between
    return lucky7s(s.substr(0,s.size()-1))+s.at(s.size()-1); //if not, return the characters with no modification
}

bool combinations( int array[ ], int size, int target ){
    if(target==0)
        return true; //if the target value is fully subtracted, return true
    else if(size<=0)
        return false; //if the array is out of elements, and the target is not 0, return false
    else if(target>=array[size-1]){ //subtract the array element from the target
        if(combinations(array, size-1, target-array[size-1])) //if the end of the recursion function meets true, return true
            return true;
    }
    return combinations(array, size-1, target); //if not start it again with a smaller array
}
