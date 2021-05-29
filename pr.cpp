#include <iostream>
#include "pr.h"
using namespace std;

void input(int& M, int& L, int& T, int& N, double& Uo, double& Yo, double& E)
{
    do
    {
        cout<<"M = ";
        cin>>M;
    }
    while (M<=0);

    do
    {
        cout<<"L = ";
        cin>>L;
    }
    while (L < 6 && L > 11);

    do
    {
        cout<<"T = ";
        cin>>T;
    }
    while (T<=0);

    do
    {
        cout<<"N = ";
        cin>>N;
    }
    while (N<=0);

    cout<<"Uo = ";
    cin>>Uo;

    cout<<"Yo = ";
    cin>>Yo;

    do
    {
        cout<<"E = ";
        cin>>E;
    }
    while (E<=0);
    return;
}


void
desval(double& D1, double& U2, double& U1 , double& Uo, double& E)
{
    if (D1 < -E)
        U2=U1+Uo;
    else
    {
        if (D1 > E)
            U2=U1-Uo;
        else
            U2=U1;
    }
}
