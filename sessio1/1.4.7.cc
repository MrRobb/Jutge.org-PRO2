#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct PairInt {
  int a;
  int b;
};
struct Team {
  int name;
  int points;
  int goalsmade;
  int goalsrecieved;
};

vector< Team > result(const vector< vector<PairInt> >& m){
  int n = m.size();
  vector< Team > r (n);

  for(int i = 0; i < n; ++i){
    r[i].name = i+1;
    r[i].points = 0;
    r[i].goalsmade = 0;
    r[i].goalsrecieved = 0;
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(i != j){
        r[i].goalsmade += m[i][j].a;
        r[j].goalsmade += m[i][j].b;
        r[i].goalsrecieved += m[j][i].a;
        r[j].goalsrecieved += m[j][i].b;

        if(m[i][j].a == m[i][j].b){
          r[i].points += 1;
          r[j].points += 1;
        } else if(m[i][j].a > m[i][j].b){
          r[i].points += 3;
        } else {
          r[j].points += 3;
        }
      }
    }
  }

  return r;
}

void readMatrix(vector< vector< PairInt > >& m){
  int rows = m.size();
  int columns = m[0].size();
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < columns; ++j){
      cin >> m[i][j].a >> m[i][j].b;
    }
  }
}

void printTeams(vector< Team > r){
  int rows = r.size();
  for(int i = 0; i < rows; ++i){
    cout << r[i].name << ' ' << r[i].points << ' ' << r[i].goalsmade << ' ' << r[i].goalsrecieved << endl;
  }
}

bool comp(Team a, Team b){
  if(a.points != b.points) return a.points > b.points;
  else if(a.goalsmade - a.goalsrecieved != b.goalsmade - b.goalsrecieved){
    return a.goalsmade - a.goalsrecieved > b.goalsmade - b.goalsrecieved;
  } else return a.name < b.name;
}

int main(){
  // Create the matrix
  int n; cin >> n;
  vector< vector<PairInt> > m (n, vector<PairInt> (n));
  readMatrix(m);

  // Compute the result
  vector< Team > r (n);
  r = result(m);

  // Sort
  sort(r.begin(),r.end(),comp);

  // Print
  printTeams(r);

}
