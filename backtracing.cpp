void backtracing(int*** grid, int*** cost_grid, int x_pos_2, int y_pos_2, int z_pos_2)//second step of lee's algorithm
{
    int curr_x=x_pos_2;
    int curr_y=y_pos_2;
    int curr_z=z_pos_2;//move to target pin
    int y_neighbors[]={-1, 0, 0, 1};
    int x_neighbors[]={-1, 0, 0, 1};
    int z_neighbors[]={0, 1, -1, 0};//to check legal adjacent cells and explained earlier
    int smallest_value=INT_MAX;//give max number to smallest cost
    int smallest_x;
    int smallest_y;
    int smallest_z;//coordinated of smallest cost (of legal adjacent cells)
    stack<string>out;//use stack in order to print in output file in correct order (from source to target)
    string temp;
    temp="("+to_string(curr_z)+", "+to_string(curr_x)+", "+to_string(curr_y)+") ";//store target coordinates in stack
    out.push(temp);
    grid[curr_z-1][curr_y][curr_x]=1;//mark it as 1 in grid
    while(cost_grid[curr_z-1][curr_y][curr_x]!=0)//until we reach source
    {
        for(int k=0; k<4; k++)
        {
            int layer;
            int row;
            int col;
            if(curr_z-1%2==0)
            {
                layer=curr_z+z_neighbors[k];
                col=curr_x+x_neighbors[k];
                row=curr_y;
            }
            else
            {
                row=curr_y+y_neighbors[k];
                layer=curr_z+z_neighbors[k];
                col=curr_x;
            }
            if(row>=0&&row<y&&col>=0&&col<x&&layer-1>=0&&layer-1<n&&cost_grid[layer-1][row][col]!=-1)//if not out of boundaries or it is not -1 in cost grid which means that there was an obstacle in the grid
            {
                if(cost_grid[layer-1][row][col]<smallest_value)//if cost is smaller than smallest cost stored
                {
                    smallest_value=cost_grid[layer-1][row][col];
                    smallest_x=col;
                    smallest_y=row;
                    smallest_z=layer;//move to cuurent cell
                }
            }
        }
        grid[smallest_z-1][smallest_y][smallest_x]=1;//now we are sure that we have the smallest cost move from current cell to next one
        temp="("+to_string(smallest_z)+", "+to_string(smallest_x)+", "+to_string(smallest_y)+") ";
        out.push(temp);//push next cell on stack
        curr_x=smallest_x;
        curr_y=smallest_y;
        curr_z=smallest_z;//move to next cell
    }
    while(!out.empty())//print stack on output file
    {
        output<<out.top();
        out.pop();
    }
}