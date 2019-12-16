#include <iostream>

#define MAXN 7
#define MAXM 7

using namespace std;

int n, m, k;
double a, b;
unsigned long long cfg;

int A[MAXN][MAXM];
int F[5];
unsigned long long C[MAXN*MAXM+1][MAXN*MAXM+1];
double P[5];

void PascalTriangle()
{
    for (int i = 0; i <= MAXN * MAXM; i++)
    {
        C[i][0] = C[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

void fillA()
{
    const int movr[5] = {-1, 0, 1, 0, 0};
    const int movc[5] = {0, 1, 0, -1, 0};

    for (int i = 0; i < 5; i++)
    {
        F[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = 0;

            for (int mov = 0; mov < 5; mov++)
            {
                int i_ = i + movr[mov];
                int j_ = j + movc[mov];

                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m)
                {
                    A[i][j]++;
                }
            }

            F[A[i][j] - 1]++;
        }
    }
}

double calcP(int a, int mov)
{
    if (mov == 0)
    {
        return 0.0;
    }

    double prev = calcP(a, mov - 1);
    double chng = (1.0 * a) / (n * m);

    return prev * (1.0 - chng) + (1.0 - prev) * chng;
}

void fillP()
{
    for (int i = 0; i < 5; i++)
    {
        P[i] = calcP(i + 1, k);
    }
}

unsigned long long calc(double start, double end)
{
    unsigned long long tot = 0;

    int I[5];

    for (I[0] = 0; I[0] <= F[0]; I[0]++)
    for (I[1] = 0; I[1] <= F[1]; I[1]++)
    for (I[2] = 0; I[2] <= F[2]; I[2]++)
    for (I[3] = 0; I[3] <= F[3]; I[3]++)
    for (I[4] = 0; I[4] <= F[4]; I[4]++)
    {
        double E = 0.0;

        for (int i = 0; i < 5; i++)
            E += I[i] * P[i] + (F[i] - I[i]) * (1.0 - P[i]);

        if (start <= E && E <= end)
            tot += C[F[0]][I[0]]*C[F[1]][I[1]]*C[F[2]][I[2]]*C[F[3]][I[3]]*C[F[4]][I[4]];
    }

    return tot;
}

void solve()
{
    int R[MAXN][MAXM] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            double chng = P[A[i][j] - 1];
            double a_ = a - (1.0 - chng);
            double b_ = b - (1.0 - chng);
            F[A[i][j] - 1]--;

            unsigned long long t = calc(a_, b_);

            if (t <= cfg)
            {
                cfg-=t;
                a-=chng;
                b-=chng;
                R[i][j]=1;
            }
            else
            {
                a=a_;
                b=b_;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << (R[i][j] == 0 ? 'H' : 'T');

        cout << endl;
    }
}

int main()
{
    PascalTriangle();

    while (1){

        cin >> n >> m >> k >> a >> b >> cfg;
        if (n==0 && m==0 && k==0 && a==0.0 && b==0.0 && cfg==0) break;

        //Make the index 0-based        
        cfg--;

        fillA();
        fillP();

        solve();
    }
    return 0;
}
