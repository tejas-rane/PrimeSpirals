#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

void do_prime_spiral(const int n, const int start);		//for populating vector in given format
void print_Pattern(vector<vector<int> > v, int size);	//printing the pattern
bool check_Prime(int elementOfV, int lastElement);		//to convert number into "." or "#"
void initArray(int param[], int size);					//helper function for check_prime
void computePrimes(int paramTemp[],  int size);			//helper function for check_Prime

/**
 * The main: Generate and print prime spirals of various sizes.
 */
int main()
{
	do_prime_spiral(5, 1);
	do_prime_spiral(25, 11);
	do_prime_spiral(35, 0);
	do_prime_spiral(50, 31);
	do_prime_spiral(101, 41);
}

void do_prime_spiral(int size, int start)
{
	cout<<"Prime spiral of size "<<size <<" starting at "<<start;
	if(size % 2 != 0 && start > 0 && start <= MAX_START && size<=MAX_SIZE )
	{
		int ROWS=size;
		int COLS=size;

		int border;
		int c = COLS/2;
		int x,y;
		x = y = c;
		vector<int> vRow(size);
		vector<vector<int> > vPrime(size,vRow);

		cout << endl;

		// Tracing from center to outwards in anti-clockwise
		for(border=1; c+border<=COLS; border++)
		{
			for(; y<=c+border && y < COLS; y++) 						// go right
			{
				vPrime[x][y]=start++;
			}

			// break condition at end to stop
			if (x == ROWS-1 && y == COLS) 							// we are done
				break;

			for(x--,y--; x>=c-border; x--)  							// go up
			{
				vPrime[x][y]=start++;
			}

			for(x++,y--; y>=c-border ; y--)    						// go left
			{
				vPrime[x][y]=start++;
			}

			for(x++,y++; x<=c+border && x < COLS; x++)  				// go down
			{
				vPrime[x][y]=start++;
			}
			x--;
			y++;
		}
		print_Pattern(vPrime,size);									//printing the populated vector
	}
	else if(size%2 ==0)
	{
		cout<<endl<<"***** Error: Size "<<size<<" must be odd."<<endl; //error  message on wrong input
	}
	else// if(start < 0)
	{
		cout<<endl<<"***** Error: Starting value "<< start <<" < 1 or > 50"<<endl; //error  message on wrong input
	}
	cout<<endl;
}

/*
 * This method accepts vector as parameter and prints the pattern using checkPrime method
 */

void print_Pattern(vector<vector<int> > v,int size)
{
	cout<<endl;
	for(int i =0 ; i < size;i++)
	{
		for (int j = 0 ; j< size; j++)
		{
			if(check_Prime((v[i][j]),v[size-1][size-1]))
			{
				cout<<"#";
			}
			else
			{
				cout<<".";
			}
		}
		cout<<"\n";
	}
}
/*
 * this method uses computePrimes to populate array of primes
 * and after iterating it will return a boolean variable to decide what to print.
 */
bool check_Prime(int vector_element,int lastElement)
{
	bool isPrime=false;
	int maxBoundry = lastElement;

	int arrayTemp[maxBoundry];
	initArray(arrayTemp,maxBoundry);						//initialization
	computePrimes(arrayTemp,maxBoundry);

	for(int i = 0; i < maxBoundry; i++){
		if(arrayTemp[i] == vector_element){
			isPrime=true;									// set isPrime true if number is present in calculated array of Primes.
			break;
		}
	}
	return isPrime;
}
/*
 * initializes array from 2 to max length
 */
void initArray(int param[],int size)
{
	int count=2;
	for(int i =0;i<size;i++)
	{
		param[i]=count;
		count++;
	}
}

/*
 * This method uses Sieve of Eratosthenes algorithm to compute primes
 * by marking multiples of first element by zero.and skipping others
 */
void computePrimes(int tempArray[],int size)
{
	for(int f=0;f<size;f++)
	{
		bool set=false;
		int temp;
		if(tempArray[f]!=0)
		{
			temp=tempArray[f];
			set=true;
		}
		if(set)
		{
			for(int j = f+temp;j<size;j=j+temp)
			{
				tempArray[j]=0;
			}
		}
	}
}


