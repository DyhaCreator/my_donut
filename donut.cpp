#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int Width = 16;
int Height = 1;
int max_steps = 10;

vector<float> render() {
    vector<float>screen = vector<float>(Width * Height);

    float sphereX = 0;
    float sphereY = 2;
    float sphereZ = 0;
    float sphereR = 0.5;

    float cameraX = 0;
    float cameraY = 0;
    float cameraZ = 0;

    for (int y = 0; y < Height; y++) {
        float ry = 0;
        for (int x = 0; x < Width; x++) {
            float rx = (float)(x - Width / 2) / (float)Width;
            cout << rx << endl;
            float rayX = cameraX;
            float rayY = cameraY;
            float len = 0;
            for (int steps = 0; steps < max_steps; steps++) {
                float l = sqrt((rayX - sphereX) * (rayX - sphereX) + (rayY - sphereY) * (rayY - sphereY)) - sphereR;
                rayX += sin(rx) * l;
                rayY += cos(rx) * l;
                len += l;
            }
            screen[y * Width + x] = len;
            cout << "---" << endl;
        }
    }

    return screen;
}

int main() {
    vector<float>screen = render();
    for (int y = 0; y < Height; y++) {
        for (int x = 0; x < Width; x++) {
            cout << screen[y * Width + x] << " ";
        }
        cout << endl;
    }
    return 0;
}