#include <iostream>
#include <vector>
#include "timer.h"
#include "pr.h"
#include "plant.h"

using namespace std;

int main()
{
    int  M, L, T, N;
    double Yo, E, Uo, q = 0, Q;
    input(M, L, T, N, Uo, Yo, E);
    vector <double> U(N), Y(N), D(N);
    Plant plant;
    plant_init(plant);
   
       U[0] = Uo;
        plant_control(L, Uo, plant);
        cout << "The process will take " << T * N << " seconds." << endl;
        Y[0] = plant_measure(M, plant);
        D[0] = Y[0] - Yo;
        cout << '\t' << "U" << '\t' << "Y" << '\t' << '\t' << "D" << '\t' << '\n';
        cout << "1" << '\t' << Uo << '\t' << Y[0] << '\t' << '\t' << D[0] << '\n' << '\n';
        q = D[0] * D[0];

        for (int i = 1; i < N; i++)
        {
            desval(D[i - 1], U[i], U[i - 1], Uo, E);
            plant_control(L, U[i], plant);
            timer(T);
            Y[i] = plant_measure(M, plant);

            D[i] = Y[i] - Yo;
            cout << i + 1 << '\t' << U[i] << '\t' << Y[i] << '\t' << '\t' << D[i] << '\n' << '\n';
            q += (D[i] * D[i]);
        }
        Q = q / N;
        cout << "Q = " << Q << '\n';

        double Ux, Un, step;
        cout << "Umin:"; cin >> Un;
            cout << "Umax: "; cin >> Ux;
            cout << "step: "; cin >> step;
        cout << "Uo" << '\t' << "Q" << "\n";
        for (double u = Un; u <= Ux; u += step)
        {
            plant_init(plant);
            if (u > -0.1 && u < 0.1)
                u = 0;
            Q = 0;
            q = 0;
            U[0] = u;
            plant_control(L, u, plant);
            Y[0] = plant_measure(M, plant);
            D[0] = Y[0] - Yo;
            q = D[0] * D[0];
            for (int i = 1; i < N; i++)
            {
                desval(D[i - 1], U[i], U[i - 1], u, E);
                plant_control(L, U[i], plant);
                Y[i] = plant_measure(M, plant);
                D[i] = Y[i] - Yo;
                q += (D[i] * D[i]);
            }
            Q = q / N;

            cerr << u << '\t' << Q  << '\n';
        }
        cerr << '\n';
    return 0;
}