// vovuh.pb(temp);vovuh.pb(temp1);vovuh.pb(temp2);vovuh.pb(temp3);
for(int tat = 0; tat <= 3; tat++) {
  auto x = adj[tat];
  int sz = x.size();
  if (sz > 0) {
    sort(x.begin(),x.end(),greater<int>());
    if (x[0] > 0)
      vovuh.pb(x[0]);
  }
}
sort(vovuh.begin(), vovuh.end(),greater<int>());
// ll cnt = 0;

cout << temp4 << " is the new ans" << endl;
for (auto ss : vovuh) {
  cout << ss << " ";
}
ll lauda = 1, vovuhKaSize = vovuh.size();
temp4 -= 100*(4-vovuhKaSize);
for (int i = 0; i < vovuhKaSize; i++) {
    temp4 +=(100-25*(lauda-1))*vovuh[i];
    lauda++;
}
// ans = max(ans, temp4);
if (temp4 > ans) {

  ans = temp4;
  cout << endl;
}
