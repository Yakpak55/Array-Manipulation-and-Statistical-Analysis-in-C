//Christopher Deluigi
//Small Program 6 Skeleton
//Dr. Steinberg
//COP3323C Fall 2022

#define SIZE 1000
#include <stdio.h>
#include <stdlib.h>

void display(int arr[]); //calls function and uses array arr
void meanMinMax(int arr[]); //calls function and uses array arr
void mySort(int arr[]); //calls function and uses array arr
void doubleShift(int arr[]); //calls function and uses array arr
void reverse(int arr[]); //calls function and uses array arr


int main(void)
{
	int arr[SIZE]; //creates array
	int seed; //creates Variable to generate a  numver
	printf("Enter a seed: "); //takes in user input and saves it as seed
	
	scanf("%d", &seed);
	srand(seed);
	
	//generate numbers for the array
	for (int x = 0; x < SIZE; x++)
	{
		arr[x] = (rand() % (1000 - 1 + 1)) + 1; //1-1000
	}
	
	//call your functions for small program 6
	//Problem 1
	meanMinMax(arr); //calls function and uses array arr
	///////////////
	//Problem 2
	mySort(arr); //calls function and uses array arr
	display(arr); //calls function display that prints out the array
	///////////////
	//Problem 3
	doubleShift(arr); //calls function and uses array arr
	display(arr); //calls function display that prints out the array
	///////////////
	//Problem 4
	reverse(arr); //calls function and uses array arr
	display(arr); //calls function display that prints out the array
	///////////////
	return 0;
}

void display(int arr[]) // function display that prints out the array
{
	for (int x = 0; x < SIZE; x++)
		printf("%6d ", arr[x]);
	
	printf("\n");
}

void meanMinMax(int arr[])
{
	int min = 0;  //creates variables for min, max, total and mean and set them all to zero
	int max = 0;
	double total = 0;
	double mean = 0;
	min=max=arr[0]; //set min and max to the array[0]
	int i;
	for(i=0; i < SIZE; ++i) //runs for loop while the array is greater than i, it adds one every time ran
	{
		total = total + arr[i]; //assigned total to total + the array to collect the entire amount
		if(arr[i] < min) //checks to see if the array value is smaller than the min which is set to 0, if so then that value is now set as the min of the aray
			min = arr[i];
		else if(arr[i] > max) //checks to see if the array value is greater than the max which is set to 0, if so then that value is now set as the max of the aray
			max = arr[i];
	}
	mean = total / SIZE; //mean is then calculates by setting it as total/ size equaling mean. the average
	printf("Average: %lf\n",mean); //sets up print statements to display the average, max and min
	printf("Max: %d\n",max);
	printf("Min: %d\n",min);
	printf("\n");
}

void mySort(int arr[])
{
	int x;
	int y; //creates new variables
	for (int x = 0; x < SIZE; x++) //for loop runs running smallest to largest, while the array is larger than x
	{
		for (int y = 0; y < SIZE; y++)  //for loop runs running smallest to largest, while the array is larger than y but runs for if statement to work
		{
			if (arr[y] > arr[x])    //checks to see if the values from the array from the for loop with y are larger than the one with x
			{						//if so then a new variable is created to store the last value from array x
				int store = arr[x];         
				arr[x] = arr[y];            //sets value to the variable replacing what ever was there
				arr[y] = store;             //saves the values to the variable store, storing it
			}  
		}
	}
}

void doubleShift(int arr[])
{
    int last; //creates new variable to act as the end of the array
	int count_two = 2; // new variable to shift over two indexes
	while(count_two > 0) //while loop runs while count_two is greater than 0 and since count_two is already set to two it runs auto
	{
		last = arr[SIZE-1]; 		//stes last to equal the size of the array minus 1
		for(int i = SIZE-1; i > 0;i--) //for loop then runs. sets i to equal the array minus 1 and loop runs while i is greater and loop continiously decreases
			arr[i]=arr[i-1];
		count_two--; //count_two decreases with each pass of the loop
		arr[0] = last; //with the new values the array being saved to last 
	}
}

void reverse(int arr[])
{
	int save;
	for (int i = 0; i < SIZE / 2; i++) //this loop iterates from the beginning of the array to the middle of the array. 
	{ 						
		save = arr[i];
		arr[i] = arr[SIZE - 1 - i]; //the loop swaps the elements st arr[i] amd arr[SIZE - 1 - i]
		arr[SIZE - 1 - i] = save;		//as the loop runs i increases and the value of i increases and the value of size -1 decreases which reverses the the array
	}
}
	