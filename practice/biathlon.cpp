#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct lineSegment {
    long int actual_indx, l, r;
    //lineSegment(long i, long l, long r) : actual_indx(i), l(l), r(r) {}
};

bool mycomp(lineSegment a, lineSegment b) {
    return a.r <= b.l;
}

int main() {
	long int n, center, radius, x, y;
	cin >> n;
	vector<lineSegment> v;
	for (int i = 1; i <= n; i++) {
	    cin >> center >> radius;
	    //lineSegment newCircle(i, center-radius, center+radius);
      lineSegment someline;
      someline.actual_indx = i;
      someline.l = center-radius;
      someline.r = center+radius;
	   v.push_back(someline);
	}
	sort(v.begin(), v.end(), mycomp);
  map<int, lineSegment> linemap;

	for (auto x : v) {
      linemap[x.actual_indx] = x;
	}

  map<long,int> mp1;
  map<long, pair<int,int> > mp2;

  //assigning all integer points to lineSegment ids

  for (auto x : v) {
    for (int i = x.l; i <= x.r; i++) {
      if (mp1[i] == 0) {
        mp1[i] = x.actual_indx;
      } else {
        mp2[i] = make_pair(mp1[i],x.actual_indx);
        mp1[i] = -1;
      }
    }
  }

	long int m;
	cin >> m;
  vector<int> ans(10006,-1);
	for(int i = 1; i <= m; i++) {
	    cin >> x >> y;
      if (mp1[x] != 0 && mp1[x] != -1) {
        lineSegment temp = linemap[mp1[x]];
        center = (temp.l+temp.r)/2;
        radius = (temp.r-temp.l)/2;

        //check if point(x,y) lies in this circle

        ll dis = (x-center)*(x-center)+y*y-radius*radius;
        if (dis <= 0 && ans[temp.actual_indx] == -1) {
          ans[temp.actual_indx] = i;
        }
      } else if (mp1[x] != 0) {

        lineSegment temp1 = linemap[mp2[x].first];
        lineSegment temp2 = linemap[mp2[x].second];
        if (ans[temp1.actual_indx] == -1) {
          center = (temp1.l+temp1.r)/2;
          radius = (temp1.r-temp1.l)/2;

          //check if point(x,y) lies in this circle

          ll dis = (x-center)*(x-center)+y*y-radius*radius;
          if (dis <= 0) {
            ans[temp1.actual_indx] = i;
          }
        }
        if (ans[temp2.actual_indx] == -1) {
          center = (temp2.l+temp2.r)/2;
          radius = (temp2.r-temp2.l)/2;

          //check if point(x,y) lies in this circle

          ll dis = (x-center)*(x-center)+y*y-radius*radius;
          if (dis <= 0) {
            ans[temp2.actual_indx] = i;
          }
        }
      }
	}
  ll cnt = 0;
  for(int i = 1; i <= n; i++) {
    if (ans[i] != -1) {
      cnt += 1;
    }
  }
  cout << cnt << endl;
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
	return 0;
}
