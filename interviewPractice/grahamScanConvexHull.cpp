#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x, y;
};

/*
The procedure GRAHAM-SCAN takes as input a set Q of points, where Q >= 3.
It calls the functions TOP(S), which returns the point on top of stack S without
changing S, and NEXT-TO-TOP(S), which returns the point one entry below the
top of stack S without changing S. As is proved in the CLRS book, the stack S
returned by GRAHAM-SCAN contains, from bottom to top, exactly the vertices
of CH(Q) in counterclockwise order.
*/

// The special point we take as initial reference : the point in Q with the minimum y-coordinate,
//or the leftmost such point in case of a tie

Point p0;

// Function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
	Point p = S.top();
	S.pop();
	Point res = S.top();
	S.push(p);
	return res;
}

// Function to return square of Euclidean distance
// between p1 and p2
int euclideanDistanceSquared(Point p1, Point p2)
{
	return
		(p1.x - p2.x)*(p1.x - p2.x) +
		(p1.y - p2.y)*(p1.y - p2.y);
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
	// This function uses the CROSS-PRODUCT to find the orientation.
	// axb: CROSS-PRODUCT of 2 vectors gives the SIGNED AREA OF THE PARALLELOGRAM
	// FORMED BY THESE VECTORS

	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) {
		return 0; // colinear
	}
	return (val > 0)? 1: 2; // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
	Point *p1 = (Point *)vp1;
	Point *p2 = (Point *)vp2;

	// Find orientation
	int o = orientation(p0, *p1, *p2);
	if (o == 0)
		return (euclideanDistanceSquared(p0, *p2) >= euclideanDistanceSquared(p0, *p1))? -1 : 1;

	return (o == 2)? -1: 1;
}

// Prints convex hull of a set of n points.
void convexHull(vector<Point> &points, int n)
{
	// Find the leftmost point
	int ymin = points[0].y, min = 0;
	for (int i = 1; i < n; i++)
	{
		int y = points[i].y;

		// Pick the bottom-most or chose the left
		// most point in case of tie
		if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
			ymin = points[i].y;
			min = i;
		}
	}

	// Place the bottom-most point at first position
	swap(points[0], points[min]);

	// Sort remaining n-1 points with respect to the first point with respect to p0
	//It is sorted by polar angle in counterclockwise order around p0
	//(if more than one point has the same angle, remove all but
	//the one that is farthest from p0)

	p0 = points[0];

	//Best way is to quickSort the Points array
	qsort(&points[1], n-1, sizeof(Point), compare);

	// If two or more points make same angle with p0,
	// Remove all but the one that is farthest from p0

	//We basically use the same array, that's the reason we use Variable m here
	//to keep track of only the useful array values

	int m = 1; // Initialize size of modified array
	for (int i=1; i<n; i++)
	{
		// Keep removing i while angle of i and i+1 is same
		// with respect to p0
		while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0) {
			i += 1;
		}

		points[m] = points[i];
		m++; // Update size of modified array
	}

	// If modified array of points has less than 3 points,
	// convex hull is not possible
	if (m < 3) return;

	// for (int i = 0; i < m; i += 1) {
	// 	cout << points[i].x << " " << points[i].y << endl;
	// }

	// Create an empty stack and push first three points to it.

	stack<Point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);

	// Process remaining n-3 points
	for (int i = 3; i < m; i++) {
		// Keep removing top while the angle formed by
		// points next-to-top, top, and points[i] makes
		// a non-left turn
		while (orientation(nextToTop(S), S.top(), points[i]) != 2) {
			S.pop();
		}
		S.push(points[i]);
	}

	// Now stack has the output points, print contents of stack
	cout << "The points on the CONVEX-HULL printed in clockwise order are:" << endl;
	//Remember stack contains convex hull points in anti-clocwise direction from bottom to top

	while (!S.empty())
	{
		Point p = S.top();
		cout << "(" << p.x << ", " << p.y <<")" << endl;
		S.pop();
	}
}

// Driver program to test above functions
int main()
{
	vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
	int n = points.size();

	convexHull(points, n);

	return 0;
}
