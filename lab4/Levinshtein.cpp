#include <iomanip>
#include <algorithm>
#include "Levenshtein.h"
#define DD(i,j) d[(i)*(ly+1)+(j)] 

int min3(int x1, int x2, int x3)
{
	return std::min(std::min(x1, x2), x3);
}

int levenshtein(int lx, const char x[], int ly, const char y[])
{
	int* d = new int[(lx + 1) * (ly + 1)];
	for (int i = 0; i <= lx; i++) DD(i, 0) = i;
	for (int j = 0; j <= ly; j++) DD(0, j) = j;
	for (int i = 1; i <= lx; i++)
		for (int j = 1; j <= ly; j++)
		{
			DD(i, j) = min3(DD(i - 1, j) + 1, DD(i, j - 1) + 1,
				DD(i - 1, j - 1) + (x[i - 1] == y[j - 1] ? 0 : 1));
		}
	return DD(lx, ly);
}

int levenshtein_r(
	int lx, const char x[],
	int ly, const char y[]
)
{
	int rc = 0;
	if (lx == 0) rc = ly;
	else  if (ly == 0) rc = lx;
	else  if (lx == 1 && ly == 1 && x[0] == y[0]) rc = 0;
	else  if (lx == 1 && ly == 1 && x[0] != y[0]) rc = 1;
	else  rc = min3(
		levenshtein_r(lx - 1, x, ly, y) + 1,
		levenshtein_r(lx, x, ly - 1, y) + 1,
		levenshtein_r(lx - 1, x, ly - 1, y) + (x[lx - 1] == y[ly - 1] ? 0 : 1)
	);
	return rc;
};


int lcs(int lenx, const char x[],
	int leny, const char y[])
{
	int rc = 0;
	if (lenx > 0 && leny > 0)
	{
		if (x[lenx - 1] == y[leny - 1]) rc = 1 + lcs(lenx - 1, x, leny - 1, y);
		else rc = std::max(lcs(lenx, x, leny - 1, y), lcs(lenx - 1, x, leny, y));
	}
	return rc;        //äëèíà LCS
}
#define LCS_C(x1,x2)  (C[(x1)*(leny+1)+(x2)])
#define LCS_B(x1,x2)  (B[(x1)*(leny+1)+(x2)])
#define LCS_X(i)      (x[(i)-1])
#define LCS_Y(i)      (y[(i)-1])
#define LCS_Z(i)      (z[(i)-1])
enum Dart { TOP, LEFT, LEFTTOP };
void getLCScontent(int lenx, int leny, const char x[],
	const Dart* B,
	int n, int i, int j, char z[])
{
	if ((i > 0 && j > 0 && n > 0))
	{
		if (LCS_B(i, j) == LEFTTOP)
		{
			getLCScontent(lenx, leny, x, B, n - 1, i - 1, j - 1, z);
			LCS_Z(n) = LCS_X(i);
			LCS_Z(n + 1) = 0;
		}
		else if (LCS_B(i, j) == TOP)
			getLCScontent(lenx, leny, x, B, n, i - 1, j, z);
		else getLCScontent(lenx, leny, x, B, n, i, j - 1, z);
	}
};
int lcsd(const char x[], const char y[], char z[])
{
	int n;
	int lenx = strlen(x), leny = strlen(x),
		* C = new int[(lenx + 1) * (leny + 1)];
	Dart* B = new Dart[(lenx + 1) * (leny + 1)];
	memset(C, 0, sizeof(int) * (lenx + 1) * (leny + 1));
	for (int i = 1; i <= lenx; i++)
		for (int j = 1; j <= leny; j++)
			if (LCS_X(i) == LCS_Y(j))
			{
				LCS_C(i, j) = LCS_C(i - 1, j - 1) + 1;
				LCS_B(i, j) = LEFTTOP;
			}
			else if (LCS_C(i - 1, j) >= LCS_C(i, j - 1))
			{
				LCS_C(i, j) = LCS_C(i - 1, j);
				LCS_B(i, j) = TOP;
			}
			else
			{
				LCS_C(i, j) = LCS_C(i, j - 1);
				LCS_B(i, j) = LEFT;
			}
	getLCScontent(lenx, leny, x, B, LCS_C(lenx, leny), lenx, leny, z);
	return LCS_C(lenx, leny);
}
