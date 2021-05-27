/*
Dhruv Jaiswal 

Problem: Develop a program to calculate the percentage of air within a
        rectangular parralelpiped sample from the pores and bubbles that it has.
        The bubbles and pores are respectively all the same size.

Input:  The input for this function will be the length, width, and height of
        the sample, the number of bubbles in the sample and the radius of those
        bubbles, and the number of pores on the surface of the sample and
        thier radius and height.

Output: The output for the function will the percantage of air that makes up the
        sample.

Processing: Ask the user for the length, width, and height of the sample,
            the number of bubbles in the sample and
            the radius of those bubbles, and
            the number of pores on the surface of the sample and
            thier radius and height.
		  

            Call one void function to check that the dimensions the user
            input are greater than zero and
            anther void function to make sure that the number of bubbles and pores
            are greater than or equal to zero.
 
            Call a function to calculate the percent air in the sample by adding
            the total volume of the bubbles and
            the total volume of the pores (which makes up the volume of the air
            in the sample) and
            then the dividing that by the volume of the sample itself.
 
            Multiply this by 100 to turn the decimal into a percentage, return it
            to the main function and output the percentage.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double pi = 3.14159;

// define the user fucntion before main
void dimCheck(double& dim, string label);
void numCheck(int& num, string name);
double sphereVol(double rad);
double cylinderVol(double holeRad, double holeH);
double sampleVol(double rectL, double rectW, double rectH);
double percentAir(double paraPipeL, double paraPipeW, double paraPipeH, int sphereNum, double sphereR, int cylNum, double cylR, double cylH);

int main()
{
    //varibles used
	double airInSample;
	double sampleL, sampleW, sampleH;
	double bubbleR, poreR, poreH;
	int poreNum, bubbleNum;

	cout << "What are the length, width, and height of your rectangular parallelpiped sample in centimeters?" << endl;
    cin >> sampleL ;
	dimCheck(sampleL, "length of the sample");
    cin >> sampleW ;
	dimCheck(sampleW, "width of the sample");
    cin >> sampleH;
    dimCheck(sampleH, "height of the sample");

	
    cout << endl << "How many many spherical bubbles are present inside the sample?" << endl;
	
    cin >> bubbleNum;
	numCheck(bubbleNum, "number of bubbles");

	cout << "What is the radius of the spherical bubbles in centimeters" << endl;
	cin >> bubbleR;
	dimCheck(bubbleR, "radius of the bubbles");

	cout << endl << "How many many cylindrical pores are present on the surface of the sample?" << endl;
	cin >> poreNum;
	numCheck(poreNum, "number of pores");

	cout << "What are the radius and height of these cylindrical pores in centimeters" << endl;
	cin >> poreR >> poreH;
	dimCheck(poreR, "radius of the pores");
	dimCheck(poreH, "height of the pores");

	airInSample = percentAir(sampleL, sampleW, sampleH, bubbleNum, bubbleR, poreNum, poreR, poreH);

	cout << endl << "The rectangle parallelpiped sample contains " << fixed << setprecision(3) << airInSample << "% air.";

	return (0);
}

/*
Function to check the dimensions input by the user.

Input: The dimension value and dimension type are passed by refernce to the
        funcntion.
Output: A valid dimension is returned to the function call.
Processing: Use a while loop to continually check to make sure the dimension is
            greater than zero.
*/

void dimCheck(double& dim, string label)
{
	while (dim <= 0)
	{
		cout << "The " << label << " must be greater than zero." << endl << "Please enter a valid value for the " << label << "." << endl;
		cin >> dim;
	}
}

/*
Function to check the number of bubbles or pores in the sample.
Input: the number of bubbles or pores is passed by reference to the function along
        with its description.
Output: A valid number is returned to the function call.
Processing: Use a while loop to continuall check to make sure the number is greater
            than or equal to zero.
*/

void numCheck(int& num, string name)
{
	while (num < 0)
	{
		cout << "The " << name << " must be greater than or equal to zero." << endl << "Please enter a valid value for the " << name << "." << endl;
		cin >> num;
	}
}

/*
Function to calculate the volume of a bubble.
Input: The radius of the bubbles are passed by value to the function.
Output: The volume of one bubble is returned to the function call.
Processing: Use the formula v = 4/3*pi*r^2 to calculate the volume of a bubble
            (sphere) and return the value to the function call.
*/

double sphereVol(double rad)
{
	double sphereCalc;

	sphereCalc = (4.0 / 3.0) * pi * pow(rad, 3.0);

	return (sphereCalc);
}

/*
Function to calculate the volume of a pore.
Input: The radius and height of the pore are passed by value to the function.
Output: The volume of one pore is returned back to the function call.
Processing: Use the formula v = pi*r^2*h to calculate the volume of a pore
            (cylinder) and return the value to the function call.
*/

double cylinderVol(double holeR, double holeH)
{
	double cylinderCalc;

	cylinderCalc = pi * pow(holeR, 2.0) * holeH;

	return (cylinderCalc);
}

/*
Function to calculate the volume of the sameple without air.
Input: The length, width, and height of the sample are passed by value to the
        function.
Output: The volume of the sample without air is returned back to the function call.
Processing: Use the formula v = l*w*h to calculate the volume of the sample
            (rectangle) and return the value to the function call.
*/

double sampleVol(double rectL, double rectW, double rectH)
{
	double sampleCalc;

	sampleCalc = rectL * rectW * rectH;

	return (sampleCalc);
}

/*
Function to calculate the percent air in the sample.
Input: The length, width, and height of the sample, radius and number of bubbles,
        and radius, height, and number of the pores are all passed by value to the
        function.
Output: The percent of air in the sample is returned to the function call.
Processing: Multiply the volumes of bubbles and pores by their respective amounts
            and then add them together.
            Divide this value by the volume of the sample and multiply by 100.
            Return this value to the function call.
*/

double percentAir(double paraPipeL, double paraPipeW, double paraPipeH, int sphereNum, double sphereR, int cylNum, double cylR, double cylH)
{
	double airVol, percentCalc;

	airVol = (sphereNum * sphereVol(sphereR)) + (cylNum * cylinderVol(cylR, cylH));
	percentCalc = (airVol / sampleVol(paraPipeL, paraPipeW, paraPipeH)) * 100.0;

	return (percentCalc);
}
