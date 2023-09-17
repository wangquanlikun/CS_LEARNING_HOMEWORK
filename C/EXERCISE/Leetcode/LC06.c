char * convert(char * s, int numRows)
{
    if(numRows == 1)
        return s;
    char lable[1000][1000]={0};
    int i=0, k=0;//k是单次向下，单次向上计数
    int x=0,y=0;
    int state=0;//state 0代表向下，1代表向右上角

    while(s[i] != 0)
    {
        lable[x][y] = s[i];

        if(k == numRows - 1)
        {
            k = 0;
            if(state == 1)
                state = 0;
            else if(state == 0)
                state = 1;
        }
        
        if(state == 0)
        {
            x;
            y = y + 1;
            k = k + 1;
        }
        else if(state == 1)
        {
            x = x + 1;
            y = y - 1;
            k = k + 1;
        }
        i = i + 1;
    }



    char *returnvalue = malloc(sizeof(char) * 1000);
    int p=0;
    for(i=0;i<numRows;i++)
    {
        if(lable[0][i] == 0)
            break;
        for(k=0;k<1000;k++)
        {
            if(lable[k][i] != 0)
            {
                returnvalue[p] = lable[k][i];
                p = p + 1;
            }
        }
    }
    returnvalue[p] = 0;
    return returnvalue;
}
