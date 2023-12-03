#include <iostream>
#include <cmath>
#include <string>

int XXX = 5;
float lengthStep = 0.6;
float minL = 0.1;
float col = 20;

int main() {
    float rx = M_PI / 2.0;
    while (true) {
        float spR = 0.2;
        float cX = -2, cY = 0, cZ = 0;
        float sinRX = sin(rx),
            cosRX = cos(rx);
        std::string screen;
        for (float ry = -1; ry < 1; ry += 0.04) {
            for (float rx = -1; rx < 1; rx += 0.03) {
                float rayX = cY;
                float rayY = cX;
                float rayZ = cZ;
                bool b = true;
                for (int i = 0; i < XXX; i++) {
                    rayX += cos(ry) * sin(rx) * lengthStep;
                    rayY += cos(ry) * cos(rx) * lengthStep;
                    rayZ += sin(ry) * lengthStep;
                    for (int j = 0; j < col; j++) {
                        float spX = sin((float)j / col * M_PI * 2);
                        float spY = cos((float)j / col * M_PI * 2);
                        float spZ = 0;
                        float NspZ = spX * cosRX - spZ * sinRX;
                        float NspY = spY;
                        float NspX = spX * sinRX + spZ * cosRX;
                        spX = NspX;
                        spY = NspY;
                        spZ = NspZ;
                        NspX = spX;
                        NspY = spY * cosRX+ spZ * sinRX;
                        NspZ = -spY * sinRX + spZ * cosRX;
                        spX = NspX;
                        spY = NspY;
                        spZ = NspZ;
                        //std::cout << spX << " " << spY << " " << (float)j / col * M_PI << std::endl;
                        float l = (rayX - spX) * (rayX - spX) + (rayY - spY) * (rayY - spY) + (rayZ - spZ) * (rayZ - spZ) - spR;
                        if (l < minL * minL) {
                            b = false;
                            break;
                        }
                    }
                    /*if (rx == 0) {
                        std::cout << rayX << " " << rayY << " " << l << std::endl;
                    }*/
                }
                if (b) {
                    screen += ' ';
                } else {
                    screen += '#';
                }
            }
            screen += "\n";
        }
        std::cout << screen << std::endl;
        //rx += 0.1;
    }
    return 0;
}