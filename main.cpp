#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <stack>
using namespace std;

string net_name;
vector<int> layer_no;
vector<int> x_pos;
vector<int> y_pos;
int n, y, x;
vector<int> done_pins_z;
vector<int> done_pins_y;
vector<int> done_pins_x;
ofstream output("output.txt");

int main()
{
    string line;
    cout<<"Please enter the dimensions of the grid (x, y, z): ";
    cin>>x>>y>>n;//x for columns, y for rows, and n for layers
    int*** grid=new int**[n];//dynamically allocating grid based on provided dimensions
    for(int i=0; i<n; i++)
    {
        grid[i]=new int*[y];
        for(int j=0; j<y; j++)
        {
            grid[i][j]=new int[x];
        }
    }
    for(int i=0; i<n; i++)//initializing grid with 0s (a "1" will mark if a net is taking place or not)
    {
        for(int j=0; j<y; j++)
        {
            for(int k=0; k<x; k++)
            {
                grid[i][j][k]=0;
            }
        }
    }
    ifstream input ("input.txt");//reading input from provided file in same directory of project
    if(!input.is_open())//error if file could not open (not existing, etc.)
    {
        cout<<"Input file could not open!!!"<<endl;
        return 0;
    }
    while(getline(input, line))//for every line (net) read its input pins required to route and then route the whole net (put the line in a string called "line" then pass this string to a function to store the inputs to work on)
    {
        process(line);
        route_net(grid);
    }
    for(int i=0; i<n; i++)//display grid
    {
        cout<<"layer "<<i+1<<":"<<endl;
        for(int j=0; j<y; j++)
        {
            for(int k=0; k<x; k++)
            {
                cout<<grid[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    return 0;//terminate program
}