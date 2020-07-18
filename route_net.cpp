void route_net(int*** grid)//function that calls other functions that apply lee's algorithm to route net
{
    int*** cost_grid=new int**[n];//dynamically create cost grid same size as grid
    for(int i=0; i<n; i++)
    {
        cost_grid[i]=new int*[y];
        for(int j=0; j<y; j++)
        {
            cost_grid[i][j]=new int[x];
        }
    }
    done_pins_x.push_back(x_pos[0]);
    done_pins_y.push_back(y_pos[0]);
    done_pins_z.push_back(layer_no[0]);//use done_pins vector in order to mark pin as routed in order for previous checking that a pin position is not used for previous wiring
    output<<net_name<<" ";//write net name to output file
    for(int i=0, j=1; j<y_pos.size(); i++, j++)//hold 2 pins to route them and then move to next 2 until we route all
    {
        filling(grid, cost_grid, layer_no[i], x_pos[i], y_pos[i], layer_no[j], x_pos[j], y_pos[j]);//call filling
        backtracing(grid, cost_grid, x_pos[j], y_pos[j], layer_no[j]);//call backtracing
        done_pins_x.push_back(x_pos[j]);
        done_pins_y.push_back(y_pos[j]);
        done_pins_z.push_back(layer_no[j]);//push pin in done_pins
    }
    output<<endl;//new line for another net
}