#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

// Guide to rotation : https://www.youtube.com/watch?v=Atlr5vvdchY&ab_channel=GoranMilovanovic

void show(vector<vector<int>> A)
{
	for (int i=0; i<A.size(); i++)
	{
		for (int j=0; j<A[0].size(); j++)
		{
			// if (A[i][j] == 1)
			// 	printf("\033[0;31m\u25A0 \033[0m");
			// else if (A[i][j] == 2)
				// printf("\033[0;33m\u25A0 \033[0m");
		if (A[i][j] == 1 || A[i][j] == 2)
				printf("\033[0;31m\u2588\u2588\033[0m");			
			else
				printf("\033[0;30m\u2588\u2588\033[0m");
		}
		printf("\n");
	}
}

vector<vector<int>> rotate(vector<vector<int>> A, pair<int, int> pivot)
{
	vector<vector<int>> B (A.size(), vector<int>(A[0].size()));
	for (int i=0; i<A.size(); i++)
	{
		for (int j=0; j<A[0].size(); j++)
		{
			if (A[i][j] == 1)
			{
				int relcord_y = i - pivot.first;
				int relcord_x = j - pivot.second;

				int tmpcord_y = 0 * relcord_y + -1 * relcord_x;
				int tmpcord_x = 1 * relcord_y +  0 * relcord_x;

				int finalcord_y = pivot.first + tmpcord_y;
				int finalcord_x = pivot.second + tmpcord_x;
				
				B[finalcord_y][finalcord_x] = 1;
				B[pivot.first][pivot.second] = 2;
				// cout<<tmpcord_y<<" "<<tmpcord_x<<"\n";
			}
		}
	}
	return B;
}

int main()
{
	int pivx, pivy;
	int n; cin >> n;
	vector<vector<int>> matrix (n,vector<int>(n));
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] == 2)
				pivy = i, pivx = j;
		}

	int i=1;
	while (true)
	{
		system("clear");
		show(matrix);
		matrix = rotate(matrix, make_pair(pivy, pivx));
		usleep(1000000);
	}

	return 0;
}