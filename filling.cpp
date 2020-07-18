void filling(int*** grid, int*** cost_grid, int layer_no_1, int x_pos_1, int y_pos_1, int layer_no_2, int x_pos_2, int y_pos_2)//function that receives 2 pins and makes first step of lee's algorithm which is filling
{
    if(grid[layer_no_1-1][y_pos_1][x_pos_1])//if pin 1 location was used for previous routing then routing fails (program does not support rip-up and re-route)
    {
        bool ok=false;
        for(int k=0; k<done_pins_x.size(); k++)
        {
            if(layer_no_1==done_pins_z[k]&&x_pos_1==done_pins_x[k]&&y_pos_1==done_pins_y[k])
            {
                ok=true;
            }
        }
        if(!ok)
        {
            cout<<"routing cannot continue as an input pin position was used for a wire in previous routing steps!!!"<<endl;
            exit(1);
        }
    }
    if(grid[layer_no_2-1][y_pos_2][x_pos_2])
    {
        bool ok=false;
        for(int k=0; k<done_pins_x.size(); k++)
        {
            if(layer_no_2==done_pins_z[k]&&x_pos_2==done_pins_x[k]&&y_pos_2==done_pins_y[k])
            {
                ok=true;
            }
        }
        if(!ok)
        {
            cout<<"routing cannot continue as an input pin position was used for a wire in previous routing steps!!!"<<endl;
            exit(1);
        }
    }
    int y_neighbors[]={-1, 0, 0, 1};
    int x_neighbors[]={-1, 0, 0, 1};
    int z_neighbors[]={0, 1, -1, 0};//to move easily to adjacent cells (if metal layer is odd: then we can move horizantally or go up or down to other metal layer)(if metal layer is even: then we can move vertically or go up or down to other metal layer)
    for(int i=0; i<n; i++)//initialize cost grid to -1 to mark that all cells to be unvisited (I used -1 because there is no way a distance between a cell and another is negative)
    {
        for(int j=0; j<y; j++)
        {
            for(int k=0; k<x; k++)
            {
                cost_grid[i][j][k]=-1;
            }
        }
    }
    cost_grid[layer_no_1-1][y_pos_1][x_pos_1]=0;//mark distance for starting pin to be 0
    queue<int> cell_x, cell_y, cell_z;//lee"s algorithm using queues
    cell_x.push(x_pos_1);
    cell_y.push(y_pos_1);
    cell_z.push(layer_no_1);//push starting pin coordinates
    while(!cell_x.empty())//until we are out of cells
    {
        int curr_x=cell_x.front();
        int curr_y=cell_y.front();
        int curr_z=cell_z.front();//move to first pin in queue
        if(curr_x==x_pos_2&&curr_y==y_pos_2&&curr_z==layer_no_2)//we reached destination so routing was successful
        {
            return;
        }
        cell_x.pop();
        cell_y.pop();
        cell_z.pop();//pop first pin in queue
        for(int k=0; k<4; k++)//to check legal adjacent cells as mentioned earlier
        {
            int row, col, layer;
            if(curr_z-1%2==0)
            {
                layer=curr_z+z_neighbors[k];
                col=curr_x+x_neighbors[k];
                row=curr_y;
            }
            else
            {
                layer=curr_z+z_neighbors[k];
                row=curr_y+y_neighbors[k];
                col=curr_x;
            }
            if(row>=0&&row<y&&col>=0&&col<x&&layer-1>=0&&layer-1<n&&grid[layer-1][row][col]==0&&cost_grid[layer-1][row][col]==-1)//if legal (not out of boundaries or not having an obstacle from previous routing and the cell is unvisited)
            {
                if(layer!=curr_z)
                {
                    cost_grid[layer-1][row][col]=cost_grid[curr_z-1][curr_y][curr_x]+10;//give cost +10 to going to another layer
                }
                else
                {
                    cost_grid[layer-1][row][col]=cost_grid[curr_z-1][curr_y][curr_x]+1;//give cost +1 to move horizontal or vertical depending on metal layer
                }
                cell_x.push(col);
                cell_y.push(row);
                cell_z.push(layer);//push adjacent cell
            }
        }
    }
    cout<<"Routing unsuccessful!!!"<<endl;//if reached her means that there is no possible route from source to target
    exit(0);
}