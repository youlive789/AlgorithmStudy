#include <iostream>

using namespace std;

char mat[2201][2201];
 
void solve(int y, int x, int num)
{
    if(num == 1)
    {
        mat[y][x]='*';
        return;
    }
     
    int div = num/3;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i == 1 && j == 1)
                ;
            else
                solve(y+(i*div), x+(j*div), div);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
     
    memset(mat, ' ', sizeof(mat));
     
    solve(0, 0, n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%c", mat[i][j]);
        printf("\n");
    }
}

// void star(int modN, int i,int j)
// {
//   if( (i / modN) % 3 == 1 && (j / modN) % 3 == 1)
//       cout << " ";
//   else
//   {
//       if(modN/3 == 0)
//           cout << "*";
//       else
//           star(modN/3,i,j);
//   }
// }
// int main() {
//   int N;
//   cin>>N;

//   for(int i=0;i<N;i++)
//   {
//       for(int j=0;j<N;j++)
//           star(N,i,j);
//       cout << endl;
//   }
//   return 0;
// }