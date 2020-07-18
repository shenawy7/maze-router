void process(string line)//function that takes input froom file and stores pins in vectors to work on
{
        net_name="";//reset variable containing net name
        layer_no.clear();//clear vectors containing positions of the pins
        x_pos.clear();
        y_pos.clear();
        //logic to store net name to use it afterwards in writing to output file and storing pin poistions in corresponding vectors (with validation)
        int c=0;
        string temp;
        int state=0;
        while(line[c]!=char(32))
        {
            net_name=net_name+line[c];
            c++;
        }
        while(c<line.length())
        {
            if(line[c]=='-')
            {
                cout<<"invalid input(s)!!!"<<endl;
                exit(1);
            }
            if(isdigit(line[c])&&state==0)
            {
                temp="";
                while(line[c]!=',')
                {
                    temp=temp+line[c];
                    c++;
                }
                if(stoi(temp)-1<n)
                {
                    layer_no.push_back(stoi(temp));
                }
                else
                {
                    cout<<"metal layer input invalid!!!"<<endl;
                    exit(1);
                }
                state=1;
            }
            if(isdigit(line[c])&&state==1)
            {
                temp="";
                while(line[c]!=',')
                {
                    temp=temp+line[c];
                    c++;
                }
                if(stoi(temp)<x)
                {
                    x_pos.push_back(stoi(temp));
                }
                else
                {
                    cout<<"x position input invalid!!!"<<endl;
                    exit(1);
                }
                state=2;
            }
            if(isdigit(line[c])&&state==2)
            {
                temp="";
                while(line[c]!=')')
                {
                    temp=temp+line[c];
                    c++;
                }
                if(stoi(temp)<y)
                {
                    y_pos.push_back(stoi(temp));
                }
                else
                {
                    cout<<"y position input invalid!!!"<<endl;
                    exit(1);
                }
                state=0;
            }
            c++;
        }
}