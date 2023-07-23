//maze movements
int di[4] = {-1 , 0 , 1 , 0};
int dj[4] = {0 , 1 , 0 , -1};

bool canMove(int i, int j){
	return i >= 0 && i < n && j >= 0 && j < m;
}

bool vis[N][N];

void dfs(int pi , int pj){
	vis[pi][pj] = true;

	for (int x = 0; x < 4; x++){
		int i = pi + di[x];
		int j = pj + dj[x];
		if (!vis[i][j] && canMove(i , j)){
			dfs(i,j);
		}
	} 
}

void bfs(int i, int j)
{
    queue<int> qi;
    queue<int> qj;
    qi.push(i);
    qj.push(j);
    while(!qi.empty())
    {
        int xi=qi.front();
        qi.pop();
        int xj=qj.front();
        qj.pop();
        for (int c=0;c<4;c++)
        {
            int x=xi+di[c];
            int y=xj+dj[c];
            if (x>=n || y>=m || x<0 || y<0)
                continue;

            if (!vis[x][y])
            {
                qi.push(x);
                qj.push(y);
            }
        }
    }
}
