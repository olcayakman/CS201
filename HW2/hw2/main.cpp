#include <iostream>
#include <time.h>

using namespace std;

int iterativeFib(int n)
{
						    // Initialize base cases:
    int previous = 1; 		// initially fib(1)
	int current = 1;  		// initially fib(2)
	int next = 1;     		// result when n is 1 or 2

	// compute next Fibonacci values when n >= 3
	for (int i = 3; i <= n; ++i){
						// current is fib(i-1)
						// previous is fib(i-2)
		next = current + previous; // fib(i)
		
		previous = current; 	// get ready for the
		current = next;		// next iteration
	}
	return next;
}

int recursiveFib(int n)
{
    if ( n <= 2 )
		return 1;
	else
		return recursiveFib(n-1) + recursiveFib(n-2);
}

int main()
{
    //implementation
    cout<<"hi, just makin sure things r ok"<<endl;
	cout<<"lets try iterative with 5000000"<<endl;
	

		double duration;
		clock_t startTime;
		startTime = clock();
		iterativeFib( 4);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		cout<<"Duration for value "<< 4 <<" on iterative fib is: "<<duration<<" miliseconds."<<endl;

		startTime = clock();
		iterativeFib( 188);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		cout<<"Duration for value "<< 188 <<" on iterative fib is: "<<duration<<" miliseconds."<<endl;

		startTime = clock();
		iterativeFib( 1007);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		cout<<"Duration for value "<< 1007 <<" on iterative fib is: "<<duration<<" miliseconds."<<endl;

		startTime = clock();
		iterativeFib( 8813);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		cout<<"Duration for value "<< 8813 <<" on iterative fib is: "<<duration<<" miliseconds."<<endl;

		startTime = clock();
		iterativeFib( 12774);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		cout<<"Duration for value "<< 12774 <<" on iterative fib is: "<<duration<<" miliseconds."<<endl;

		startTime = clock();
		iterativeFib( 97002);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		cout<<"Duration for value "<< 97002 <<" on iterative fib is: "<<duration<<" miliseconds."<<endl;

		startTime = clock();
		iterativeFib( 999001);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		cout<<"Duration for value "<< 999001 <<" on iterative fib is: "<<duration<<" miliseconds."<<endl;

		startTime = clock();
		iterativeFib( 1798337);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		cout<<"Duration for value "<< 1798337 <<" on iterative fib is: "<<duration<<" miliseconds."<<endl;

		startTime = clock();
		iterativeFib( 9798337);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		cout<<"Duration for value "<< 9798337 <<" on iterative fib is: "<<duration<<" miliseconds."<<endl;

		startTime = clock();
		iterativeFib( 99798337);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		cout<<"Duration for value "<< 99798337 <<" on iterative fib is: "<<duration<<" miliseconds."<<endl;


//----------------------------------
		cout <<" "<<endl;


	for ( int i = 4; i < 55; i += 10)
	{
		double duration;
		clock_t startTime;
		startTime = clock();
		recursiveFib( i);
		duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
		cout<<"Duration for value "<< i <<" on recursive fib is: "<<duration<<" miliseconds."<<endl;
	}
	cout<<"were done problemfree."<<endl;

	return 0;
}