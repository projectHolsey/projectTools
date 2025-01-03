int totalFruit(int* fruits, int fruitsSize){
    char cTypeIndex = 0;    // only index 0 or 1 for aanCount
    int nRet = 1, aanCount[2][2] = {{*fruits, 1}, {-1, 0}};   // {type, count}
    while(fruitsSize-- > 1)
    {
        fruits++;

        if(*fruits == aanCount[cTypeIndex][0])
        {
            // same current fruit type, add count directly
            aanCount[cTypeIndex][1]++;
        }
        else if(*fruits == aanCount[cTypeIndex^1][0])
        {
            // different fruit type, sum up fruit count first
            aanCount[cTypeIndex][1] += aanCount[cTypeIndex^1][1];

            // reset current fruit count to 1
            cTypeIndex = cTypeIndex ^ 1;
            aanCount[cTypeIndex][1] = 1;
        }
        else
        {
            // 3rd fruit type already, sum up count of previous two fruit types
            int nTmp = aanCount[cTypeIndex][1];

            cTypeIndex = cTypeIndex ^ 1;
            nTmp += aanCount[cTypeIndex][1];
            if(nRet < nTmp) nRet = nTmp;

            // reset current fruit count to 1
            aanCount[cTypeIndex][0] = *fruits;
            aanCount[cTypeIndex][1] = 1;
        }
    }

    int nTmp = aanCount[cTypeIndex][1] + aanCount[cTypeIndex^1][1];

    return nRet < nTmp? nTmp: nRet;
}

int main() {
    return 0;
}
