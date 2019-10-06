#include<bits/stdc++.h>
#define ldb long double
#define eps 1e-7
using namespace std;
int n; 
int npoint, nouter;
struct Tpoint{ldb x, y, z;};
Tpoint pt[200000], outer[4], res;
ldb radius, tmp;
inline ldb dist(Tpoint p1, Tpoint p2) 
{
    ldb dx = p1.x - p2.x, dy = p1.y - p2.y, dz = p1.z - p2.z;
    return (dx * dx + dy * dy + dz * dz);
}
inline ldb dot(Tpoint p1, Tpoint p2)
{
    return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}
void ball()
{
    Tpoint q[3]; ldb m[3][3], sol[3], L[3], det;
    int i, j;
    res.x = res.y = res.z = radius = 0;
    switch(nouter)
    {
        case 1: res = outer[0]; break;
        case 2:
            res.x = (outer[0].x + outer[1].x) / 2;
            res.y = (outer[0].y + outer[1].y) / 2;
            res.z = (outer[0].z + outer[1].z) / 2;
            radius = dist(res, outer[0]);
            break;
        case 3:
            for (int i = 0; i < 2; i++)
            {
                q[i].x = outer[i + 1].x - outer[0].x;
                q[i].y = outer[i + 1].y - outer[0].y;
                q[i].z = outer[i + 1].z - outer[0].z;
            }
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    m[i][j] = dot(q[i], q[j]) * 2;
            for (int i = 0; i < 2; i++) sol[i] = dot(q[i], q[i]);
            if (fabsl(det = m[0][0] * m[1][1] - m[0][1] * m[1][0]) < eps)
                return;
            L[0] = (sol[0] * m[1][1] - sol[1] * m[0][1]) / det;
            L[1] = (sol[1] * m[0][0] - sol[0] * m[1][0]) / det;
            res.x = outer[0].x + q[0].x * L[0] + q[1].x * L[1];
            res.y = outer[0].y + q[0].y * L[0] + q[1].y * L[1];
            res.z = outer[0].z + q[0].z * L[0] + q[1].z * L[1];
            radius = dist(res, outer[0]);
            break;
        case 4:
            for (int i = 0; i < 3; i++)
            {
                q[i].x = outer[i + 1].x - outer[0].x;
                q[i].y = outer[i + 1].y - outer[0].y;
                q[i].z = outer[i + 1].z - outer[0].z;
                sol[i] = dot(q[i], q[i]);
            }
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    m[i][j] = dot(q[i], q[j]) * 2;
            det = m[0][0] * m[1][1] * m[2][2]
                + m[0][1] * m[1][2] * m[2][0]
                + m[0][2] * m[2][1] * m[1][0]
                - m[0][2] * m[1][1] * m[2][0]
                - m[0][1] * m[1][0] * m[2][2]
                - m[0][0] * m[1][2] * m[2][1];
            if (fabsl(det) < eps) return;
            for (int j = 0; j < 3; j++)
            {
                for (int i = 0; i < 3; i++) m[i][j] = sol[i];
                L[j] = (m[0][0] * m[1][1] * m[2][2]
                + m[0][1] * m[1][2] * m[2][0]
                + m[0][2] * m[2][1] * m[1][0]
                - m[0][2] * m[1][1] * m[2][0]
                - m[0][1] * m[1][0] * m[2][2]
                - m[0][0] * m[1][2] * m[2][1]) / det;
                for (int i = 0; i < 3; i++) m[i][j] = dot(q[i], q[j]) * 2;
            }
            res = outer[0];
            for (int i = 0; i < 3; i++)
            {
                res.x += q[i].x * L[i];
                res.y += q[i].y * L[i];
                res.z += q[i].z * L[i];
            }    
            radius = dist(res, outer[0]);
    }
}
void minball(int n)
{
    ball();
    if (nouter < 4) 
        for (int i = 0; i < n; i++)
            if (dist(res, pt[i]) - radius > eps)
            {
                outer[nouter] = pt[i];
                ++nouter;
                minball(i);
                --nouter;
                if (i > 0) 
                {
                    Tpoint Tt = pt[i];
                    memmove(&pt[1], &pt[0], sizeof(Tpoint) * i);
                    pt[0] = Tt;
                }
            }
}
ldb smallest_ball()
{
    radius = - 1;
    for (int i = 0; i < npoint; i++)
    {
        if (dist(res, pt[i]) - radius > eps) 
        {
            nouter = 1;
            outer[0] = pt[i];
            minball(i);
        }
    }
    return sqrtl(radius);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        double x, y, z; scanf("%lf%lf%lf", &x, &y, &z);
        pt[i].x = x; pt[i].y = y; pt[i].z = z;
    }
    npoint = n;
    printf("%.15lf\n", (double)smallest_ball());
    return 0;
}