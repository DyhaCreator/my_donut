#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

float zoom = 7;
int Width = 15 * zoom;
int Height = 11 * zoom;
int max_steps = 10;
float min_len = 0.1;

float dSphere(float x, float y, float z, float sphereX, float sphereY, float sphereZ, float sphereR) {
    float l = sqrt((x - sphereX) * (x - sphereX) + 
                    (y - sphereY) * (y - sphereY) + 
                    (z - sphereZ) * (z - sphereZ)) - sphereR;
    return l;
}

float dTorus(float x, float y, float z, float TorX, float TorY, float TorZ, float R, float r) {
    float x1 = sqrt((x - TorX) * (x - TorX) + (y - TorY) * (y - TorY)) - R;
    float z1 = abs(TorZ - z);
    return sqrt(x1 * x1 + z1 * z1) - r;
}

vector<int> render(float X, float Y, float Z, float R, float r, float cRX, float cRY) {
    vector<int>screen = vector<int>(Width * Height);

    float cameraX = 0;
    float cameraY = 0;
    float cameraZ = 0;

    for (int y = 0; y < Height; y++) {
        float ry = (float)(y - Height / 2) / (float)Height + cRY;
        for (int x = 0; x < Width; x++) {
            float rx = (float)(x - Width / 2) / (float)Width + cRX;
            //cout << rx << endl;
            float rayX = cameraX;
            float rayY = cameraY;
            float rayZ = cameraZ;
            float len = 0;
            for (int steps = 0; steps < max_steps; steps++) {
                float l = dTorus(rayX, rayY, rayZ, X, Y, Z, R, r);
                rayX += cos(ry) * sin(rx) * l;
                rayY += cos(ry) * cos(rx) * l;
                rayZ += sin(ry) * l;
            }
            float l = dTorus(rayX, rayY, rayZ, X, Y, Z, R, r);
            screen[y * Width + x] = (l < min_len)?1:0;
            //cout << "---" << endl;
        }
    }

    return screen;
}

int main() {
    float Ty = 1;
    float Tz = 0;
    float rotAnim = 0;
    while (true) {
        vector<int>screen = render(0, 2, Tz, 0.5, 0.02, 0, 0.2);
        for (int y = Height * 0.3; y < Height * 0.7; y++) {
            for (int x = 0; x < Width; x++) {\
                if (screen[y * Width + x] == 1) {
                    cout << '#';
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }
        rotAnim += 0.01;
        Tz = sin(rotAnim) / 5.0 + 0.4;
    }
    return 0;
}