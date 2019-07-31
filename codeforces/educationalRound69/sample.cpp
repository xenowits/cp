//#define __popcnt __builtin_popcount
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-6
#define OO 1e9
#define PI acos(-1.0)
#define ll long long
#define endl "\n"
#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define sch(x)  scanf("%c",&x)
#define scs(x)  scanf("%s",x)
#define prl(x) printf("%lld",x)
#define pr(x)  printf("%d",x)
#define prs(x) printf("%s",x)
#define prline printf("\n");

void file(){
#ifndef ONLINE_JUDGE
	freopen("a_input.txt", "r", stdin);
	freopen("a_output.txt", "w", stdout);
#endif
}
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int dx[] = { -1, 0, 0, 1, 1, 1, -1, -1 };
int dy[] = { 0, 1, -1, 0, 1, -1, 1, -1 };




typedef complex<long double> point;
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))//get vector using angle and length
#define angle(v) (atan2((v).Y,(v).X))//get angle for vector with x axis
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define length(v) ((long double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))//=length*length
// #define rotate(v, t) (polar(v, t))
// #define rotateabout(v, t, a) (rotate(vec(a, v), t) + (a))
// #define reflect(p, m) ((conj((p) / (m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))//get prependcular vector
#define translate(a,v) (a+v)
#define scale(v,r) point(v.X*r, v.Y*r)
#define dist(a,b) length(a-b)
// returns angle aob in rad
#define ang3Points(a,o,b) acos(dot(vec(o, a), vec(o, b)) / sqrt(lengthSqr(vec(o, a)) * lengthSqr(vec(o, b))))
#define ccw(p,q,r) (cross(vec(p, q), vec(p, r)) > 0.0)// returns true if point r is on the left side of line pq
#define colliner pointOnLine

point readPoint() { long double x, y; cin >> x >> y; return point(x, y); }
void printpoint(point P) { cout << P.X << " " << P.Y; }
int dcmp(double x, double y){ return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
bool pointOnSegment(point a, point b, point p) {
	return fabs(cross(vec(a, b), vec(a, p))) < EPS&&//point on line
		dot(vec(a, b), vec(a, p)) > -EPS && dot(vec(b, a), vec(b, p)) > -EPS;
}
// retuen y of point on line given the line and x of this point
long double getYfromXforline(point a, point b, long double x){
	if (a.X == b.X)return b.Y;
	long double m = (a.Y - b.Y) / (a.X - b.X);
	long double c = a.Y - m*a.X; return m*x + c;
}
// retuen x of point on line given the line and y of this point
long double getXfromYforline(point a, point b, long double y){
	if (a.X == b.X)return b.X;
	long double m = (a.Y - b.Y) / (a.X - b.X);
	long double c = a.Y - m*a.X;
	return (y - c) / m;
}
//get triangle Area using 3 points
long double triangleArea3points(const point& a, const point& b, const point& c) {
	return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;
}
//find angle AntiClockWise from v1 to v2 in rad
double getAngle_2vec(point v1, point v2){
	return atan2(cross(v1, v2), dot(v1, v2));
}
//find angle p0p1p2  in rad moooot up is p1p2 , right is p1 p0
double getAngle_3points(point p0, point p1, point p2){
	return getAngle_2vec(vec(p1, p0), vec(p1, p2));
}
// get vector with length R acording to a Ray ab
point getVectorWithLengthR(point a, point b, double r){
	return scale(normalize(vec(a, b)), r);
}
namespace std {
	bool operator <(const point& a, const point& b) { return a.X != b.X ? a.X < b.X : a.Y < b.Y; }
	bool operator >(const point& a, const point& b) { return a.X != b.X ? a.X > b.X : a.Y > b.Y; }
	// sortsegments butome up , note the point of 1 segment must be sorted
	// the functions that coled must be up of this poisition in code
	bool operator <(const vector<point>& a, const vector<point>& b){
		point p(a[0].X, getYfromXforline(b[0], b[1], a[0].X));
		if (pointOnSegment(b[0], b[1], p))return a[0].Y < p.Y;
		p = point(a[1].X, getYfromXforline(b[0], b[1], a[1].X));
		if (pointOnSegment(b[0], b[1], p))return a[1] < p;
		p = point(b[0].X, getYfromXforline(a[0], a[1], b[0].X));
		if (pointOnSegment(a[0], a[1], p))return p < b[0];
		p = point(b[1].X, getYfromXforline(a[0], a[1], b[1].X));
		if (pointOnSegment(a[0], a[1], p))return p < b[1];
		return max(a[0].Y, a[1].Y) < max(b[0].Y, b[1].Y);
	}
}

struct point3D{
	long double x, y, z;
	point3D(){};
	point3D(long double x1, long double y1, long double z1){
		x = x1; y = y1; z = z1;
	}
	bool read(){ if (cin >> x >> y >> z)return 1; return 0; }
	long double dis(point3D other){
		return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
	}
};
struct line {
	double a, b, c;
	line(point p1, point p2) {
		if (fabs(p1.X - p2.X) < EPS) { // vertical line is fine
			a = 1.0; b = 0.0; c = -p1.X; // default values
		}
		else {
			a = -(double)(p1.Y - p2.Y) / (p1.X - p2.X);
			b = 1.0; // IMPORTANT: we fix the value of b to 1.0
			c = -(double)(a * p1.X) - p1.Y;
		}
	}
};
bool areParallel2Lines(line l1, line l2) { // check coefficients a & b
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool segmentIntersectSegment(point a, point b, point c, point d, point &p) {
	line l1(a, b), l2(c, d);
	if (areParallel2Lines(l1, l2)) return false; // no intersection
	// solve system of 2 linear algebraic equations with 2 unknowns
	long double x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// special case: test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS) p = point(x, -(l1.a * x + l1.c));
	else p = point(x, -(l2.a * x + l2.c));
	return pointOnSegment(a, b, p) && pointOnSegment(c, d, p);
}
bool pointInsidReqt(point LL, point RU, point P) {
	//note that ">= and <=" not "> and <" it based on your problem...
	return P.X >= LL.X && P.X <= RU.X && P.Y >= LL.Y && P.Y <= RU.Y;
}
bool segmentIntersectReqtangle(point LL, point RU, point a, point b) {
	point LU = point(LL.X, RU.Y), RL = point(RU.X, LL.Y), p;
	if (pointInsidReqt(LL, RU, a) || pointInsidReqt(LL, RU, b)) return 1;
	return segmentIntersectSegment(LU, RU, a, b, p) || segmentIntersectSegment(LL, RL, a, b, p)
		|| segmentIntersectSegment(LL, LU, a, b, p) || segmentIntersectSegment(RL, RU, a, b, p);
}
bool areSame2Lines(line l1, line l2) { // check coefficient a & b & c
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS) && (fabs(l1.c - l2.c) < EPS);
}
// returns true (+ intersection point) if two lines are intersect
bool areIntersect2Lines(line l1, line l2, point &p) {
	if (areParallel2Lines(l1, l2)) return false; // no intersection
	// solve system of 2 linear algebraic equations with 2 unknowns
	long double x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// special case: test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS) p = point(x, -(l1.a * x + l1.c));
	else p = point(x, -(l2.a * x + l2.c));
	return true;
}
double waterFallOnsegments(vector< vector<point> > v, point p){
	for (int i = (int)v.size() - 1; i >= 0; i--){
		double x = p.X, y = getYfromXforline(v[i][0], v[i][1], p.X);
		if (y <= p.Y&&pointOnSegment(v[i][0], v[i][1], point(x, y))){
			if (v[i][0].Y < v[i][1].Y)p = v[i][0];
			else p = v[i][1];
		}
	}
	return p.X;
}




double pointDistToLine(point p, point a, point b, point &c) {//line a,b
	// formula: c = a + u * ab
	point ap = vec(a, p), ab = vec(a, b);
	long double u = dot(ap, ab) / lengthSqr(ab);
	c = translate(a, scale(ab, u)); // translate a to c
	return dist(p, c);
}
double pointDistToLineSegment(point p, point a, point b, point &c) {
	point ap = vec(a, p), ab = vec(a, b);
	long double u = dot(ap, ab) / lengthSqr(ab);
	if (u < 0.0) {// closer to a
		c = point(a.X, a.Y); return dist(p, a);
	} // Euclidean distance between p and a
	if (u > 1.0) { // closer to b
		c = point(b.X, b.Y); return dist(p, b);
	} // Euclidean distance between p and b
	c = translate(a, scale(ab, u)); // translate a to c //between a,b
	return dist(p, c);
}
//280,000
//2000





int main()
{
	/***  بسم الله الرحمن ا لرحيم   ***/
	file();
	fast();

		int n,k;
		cin >> n >> k;
		vector<int> a(n), v(n - 1);
		ll sum = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (i){
				sum += a[i] - a[i - 1];
				v[i - 1] = a[i] - a[i - 1];
			}
		}
		sort(all(v));
		reverse(all(v));
		for (int i = 0; i < k - 1; i++)
			sum -= v[i];
		cout << sum;
}
