#ifndef POINT_H    
#define POINT_H   

#include <iostream>
#include <cmath>  
using namespace std;


class point
{
public:
	point(); // Default constructor
	point(float , float); // Constructor with parameters
	void setcoord_x(float); // Setter for x coordinate
	void setcoord_y(float); // Setter for y coordinate
	float getcoord_x()const; // Getter for x coordinate
	float getcoord_y()const; // Getter for y coordinate
	void display()const; // Function to display the coordinates of the point
	float distance(const point); // Function to calculate the distance between two points

private:
	float x; // x coordinate
	float y; // y coordinate
};

#endif 

point::point() // Default constructor definition
{
	x = 0.0;
	y = 0.0;
}

point::point(float f, float g) // Constructor definition with parameters
{
	x = f;
	y = g;
}

void point::setcoord_x(float s) // Setter for x coordinate definition
{
	x = s;
}

void point::setcoord_y(float i) // Setter for y coordinate definition
{
	y = i;
}

float point::getcoord_x()const // Getter for x coordinate definition
{
	return x;
}

float point::getcoord_y()const // Getter for y coordinate definition
{
	return y;
}

void point::display()const // Function to display the coordinates of the point 
{
	cout << "(" << x << " , " << y << ")";
}

float point::distance(const point a) // Function to calculate the distance between two points
{
	float q;
	q = sqrt(pow(x - a.x, 2) + pow(y - a.y, 2)); 
	return q;
}

// Function to calculate the center point of an array of points
point Center(point Array[], int n)
{
	float averagecoordx, averagecoordy;
	float sumofx = 0.0, sumofy = 0.0;

	// Calculate the sum of x and y coordinates of all points in the array
	for (int i = 0; i < n; i++)
	{
		sumofx = sumofx + Array[i].getcoord_x();
		sumofy = sumofy + Array[i].getcoord_y();
	}

	// Calculate the average x and y coordinates to get the center point
	averagecoordx = sumofx / n;
	averagecoordy = sumofy / n;

	point P1(averagecoordx, averagecoordy); // Create a point object with the calculated center coordinates

	return P1; // Return the center point
}

// Function to determine which cluster a point belongs to based on its distance from the centers of two arrays of points
void closest_to(point a1[], int s, point a2[], int i, point p)
{
	point center_A = Center(a1, s); 
	point center_B = Center(a2, i); 

	float distance_A = center_A.distance(p); // Calculate the distance between the point and the center point of array a1 & a2
	float distance_B = center_B.distance(p); 

	// Determine which cluster the point belongs to based on the distances from the centers
	if (distance_A < distance_B)
	{
		cout << " belongs to cluster A." << endl;
	}
	else
		cout << " belongs to cluster B." << endl;
}
