/*

Sidd Shanmugam
Project 5
Section 002
Due: May 1st, 2015


Description:
This program is used to store an ebook collection that will display and sort the books you have as well as tell you the total cost of all
your books and the average cost of your books. 

Input:
Will request user to enter inputs for the books and ask them if they would like to continue or not


Output:
Will display the library and the sorted library depending on user input from a switch menu




Processing:

This program creates a structure variable that stores variables for an ebook collection. The variables stored within the structure are
the books title, author, publisher, copyright date, bnumber of pages, and the cost. There are several functions involved. the first function
is of return type ebook which is the name of the  structure. It's purpose is to accept one entry of datay type ebook and return it. The second
function is the fillArray function. This is an int function which creates an array of the ebook strucutre variable and calls the ebook function
through a loop to fill an array of ebooks. It has parameters for an array of ebook and an int which is the max number of ebooks that can be 
stored. The next function is output. The purpose of this function is to output all the contents of one of the structure variable ebook. The next
function outAll, calls the output function through a loop to output several ebook variables from an array of ebook. The functions sortTitle,
sortCost, sortAuthor, and sortPage all sort the inputed ebooks by either ascending or descending order. Finally the cost function calculates 
the average cost and the total cost of the books in the structure variable.
The main function initializes an array of structure ebook, initializes the max number of elements that can exist in the structure to be 50
and then utilizes a switch to create a menu that asks the user what they would like to do. After the user responds, main calls the corresponding function
and then asks the user if they would like to continue with the program or not. 
*/


#include <iostream>
#include <string>
using namespace std;

//Declaring structure of ebook with 6 variables
struct ebook
{
	string title;
	string author;
	string publisher;
	int copyright;
	int pages;
	double cost;
};

//function prototypes
ebook enterData();
int fillArray(ebook a[], int max);
void output(ebook out);
void outAll(ebook printAll[], int numels);
void sortTitle(ebook sorter[], int numels);
void sortAuthor(ebook sorter[], int numels);
void sortCost(ebook sorter[], int numels);
void cost(ebook sorter[], int numels);
void sortPage(ebook sorter[], int numels);



//Main function creates a menu that will allow user to enter data, print data, sort data, and calculate average/total costs
int main()
{
	ebook sys[50];
	int maxel = 50;
	int a, x; // a stores the actual number of elements when returned by fillarray and x is used as a variable for the switch menu
	int flag = 1;

	while (flag)
	{
	cout << "What would you like to do? \n\n";
	cout <<
		"1) Fill your eLibrary\n2) Display your library\n3) Sort by author\n4) Sort by title\n"
		"5) Sort by cost\n6) Sort by number of pages\n7) Calculate total and average cost\n";
	cin >> x;
	cout << endl;

		switch (x)
		{
		case 1:
			a = fillArray(sys, maxel);
			break;
		case 2:
			outAll(sys, a);
			break;
		case 3:
			sortAuthor(sys, a);
			break;
		case 4:
			sortTitle(sys, a);
			break;
		case 5:
			sortCost(sys, a);
			break;
		case 6:
			sortPage(sys, a);
			break;
		case 7:
			cost(sys, a);
			break;
		default:
			cout << "something went wrong!\n";
		}
		cout << "Enter 0 to exit and any other number to continue!\n";
		cin >> flag;
	}
	
	return 0; 
}
/*
Function of ebook data type (created structure)
Function requests data from the user to fill a variable of type ebook
returns the structure ebook
*/
ebook enterData()
{
	ebook a;

	cout << "please enter the title of the book\n";
	cin.ignore();		//this was used to correct for a blank space recorded for some reason from input reccommended by Brent
	getline(cin, a.title);

	cout << "please enter the author of the book\n";
	getline(cin, a.author);

	cout << "please enter the publisher of the book\n";
	getline(cin, a.publisher);

	cout << "please enter the copyright year of the book\n";
	cin >> a.copyright;

	cout << "please enter the number of pages in the book\n";
	cin >> a.pages;

	cout << "please enter the cost of the book\n";
	cin >> a.cost;
	
	
	return a;
}

/*
This function acceps an ebook array and a max number of elements and fills the array of ebooks
returns the value i which is the number of elements actually entered.
Implements a while loop to allow user to continue entering information until they want to stop.
*/
int fillArray(ebook fill[], int max)
{
	int flag = 0;
	int i = 0;
	while (i < max && flag == 0)
	{
		fill[i] = enterData();
		i++;
		cout << "Enter 0 to enter data again and anything else to exit\n";
		cin >> flag;
		cout << endl << endl;
	}

	return i;
}

/*

Output function which accepts an ebook and prints a single ebook using a cout statement

*/
void output(ebook out)
{
	cout << out.title << endl << out.author << endl << out.publisher << endl
		<< out.copyright << endl << out.pages << endl << out.cost << endl;
}

/*

Function that calls a function to print one ebook and implements it with an array of ebooks within a for loop
to print all the ebooks in an array.
Accepts arguments of an array of ebook and the actual number of books stored
*/
void outAll(ebook printAll[], int numels)
{
	for (int i = 0; i < numels; i++)
	{
		output(printAll[i]);
		cout << endl;
	}

}


/*
//bubble sorted titles

This function accepts an array of ebooks and the actual number of books stored
and uses a bubble sort to organize the books in alphabetical order by title name

*/

void sortTitle(ebook sorter[], int numels)
{
	bool sorted = false;
	ebook temp[50];
	int replace = numels;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i <= numels-2; i++)
		{
			if (((sorter[i].title)>sorter[i + 1].title))
			{
				temp[i] = sorter[i];
				sorter[i] = sorter[i + 1];
				sorter[i + 1] = temp[i];
				sorted = false;
			}
		}
		numels = numels - 1;
	}

	outAll(sorter, replace);
}


/*
//insertion sort author names

This function accepts an array of ebooks and the the actual number of books
and uses an insertion sort to organize the books in alphabetical order by author name
*/

void sortAuthor(ebook sorter[], int numels)
{
	bool sorted = true;
	int marker;
	ebook temp;

	for (int i = 0; i <= numels-2; i++)
	{
		if (((sorter[i].author)>(sorter[i + 1].author)))
		{
			sorted = false;
			marker = i;

			while (!sorted)  
			{
				temp = sorter[marker];              
				sorter[marker] = sorter[marker + 1];
				sorter[marker + 1] = temp;

				if (marker == 0)             
					sorted = true;
				else if (((sorter[marker].author).compare(sorter[marker-1].author)) > 0)  
					sorted = true;
				else
					marker = marker - 1;           
			}
		}
	}
	outAll(sorter, numels);
}

/*
//Selection sort cost

This function accepts an array of ebooks and the actual number of books
and uses a selection sort to organize the books in decreasing cost order
*/
void sortCost(ebook sorter[], int numels)
{
	int passcount;            // a loop control variable
	int placecount;           // a loop control variable
	int minIndex;             // index (subscript of min value so far
	ebook temp[50];

	for (passcount = 0; passcount < numels - 1; passcount++)
	{
		minIndex = passcount;

		for (placecount = passcount + 1; placecount < numels; placecount++)
		{
			if (sorter[placecount].cost > sorter[minIndex].cost)
				minIndex = placecount;
		}

		// swap a[minIndex] and a [passcount]
		temp[minIndex] = sorter[minIndex];
		sorter[minIndex] = sorter[passcount];
		sorter[passcount] = temp[minIndex];
	}

	outAll(sorter, numels);
}

/*
//Selection sort page numbers

This function accepts an array of ebooks and the actual number of books
and uses a selection sort to organize the books in decreasing number of pages
order
*/

void sortPage(ebook sorter[], int numels)
{
	int passcount;            // a loop control variable
	int placecount;           // a loop control variable
	int minIndex;             // index (subscript of min value so far
	ebook temp[50];

	for (passcount = 0; passcount < numels - 1; passcount++)
	{
		minIndex = passcount;

		for (placecount = passcount + 1; placecount < numels; placecount++)
		{
			if (sorter[placecount].pages > sorter[minIndex].pages)
				minIndex = placecount;
		}

		// swap a[minIndex] and a [passcount]
		temp[minIndex] = sorter[minIndex];
		sorter[minIndex] = sorter[passcount];
		sorter[passcount] = temp[minIndex];
	}

	outAll(sorter, numels);
}


/*
This function accepts an array of ebooks and the actual number of books
and uses a for loop to sum the cost of all the books and then divides by
the number of elements to find the average cost
*/
void cost(ebook price[], int numels)
{
	double cost = 0;
	double avg;
	for (int i = 0; i <= numels-1; i++)
	{
		cost = price[i].cost + cost;
	}
	avg = cost / numels;
	cout << "the total cost of all the books is " << cost << "\nThe average cost is " << avg << endl;
}
