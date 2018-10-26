//
//  main.c
//  DroneDisplay
//
//  Created by Swan Garcia on 10/24/18.
//  Copyright © 2018 Swan Garcia. All rights reserved.
//

#include <stdio.h>
#include <math.h>
//declare all things to be used in the program
//this is the basic structure for all points. it is given in lon(x), lat(y), and altitude (z)
struct point
{
    float x;
    float y;
    float z;
};
//these are the test points that are given
float bearing = -150.0;
float tilt = -45.0;
float altitude = 2149;
//focal length in meters
float focalLength = (8.8 / 1000.0);
//center pixel adjusted for lon and lat
float centerx = 2000.0 + (86583.56 * -104.887947);
float centery = 1500.0 + (111016.12 * 39.035536);
//LL pixel adjusted for lon and lat
float LLx = (2000.0 - 1792.0) + (86583.56 * -104.887947);
float LLy = (1500.0 - 2450.0) + (111016.12 * -104.887947);
//UR pixel adjusted for lon and lat
float URx = (2000.0 - 1908.0) + (86583.56 * -104.887947);
float URy = (1500.0 - 2778.0) + (111016.12 * 39.035536);

//main method is where all the math and printing is done
int main(void)
{
    //derive the actual altitude of the camera
    float alt = altitude + focalLength;
    //define lr pixel
    float LRx = URx;
    float LRy = URy * (-1.0);
    //define ul pixel
    float ULx = LLx;
    float ULy = LLy * (-1.0);
    //these values derive the cosine and sine of the bearing nSine is negative sine
    float cosineB = (cos(bearing * 3.141592 / 180.0));
    float nCosineB = (cos(bearing * 3.141592 / 180.0)) * -1.0;
    float sineB = (sin(bearing * 3.141592 / 180.0));
    float nSineB = (sin(bearing * 3.141592 / 180.0)) * -1.0;
    //these values derive the cosine and sine of the tilt
    float cosineT = (cos(tilt * 3.141592 / 180.0));
    float nCosineT = (cos(tilt * 3.141592 / 180.0)) * -1.0;
    float sineT = (sin(tilt * 3.141592 / 180.0));
    float nSineT = (sin(tilt * 3.141592 / 180.0)) * -1.0;
    //this is the bearing rotation matrix, it rotates around the z axis
    float bearingRot[3][3] =
    {
        { cosineB, nSineB, 0.0 },
        { sineB, cosineB, 0.0 },
        { 0.0, 0.0, 1.0 }
    };
    //this is the tilt rotation matrix, it rotates around the y axis
    float tiltRot[3][3] =
    {
        { cosineT, 0.0, sineT },
        { 0.0, 1.0, 0.0 },
        { nSineT, 0.0, cosineT }
    };
    //this is a combination matrix that combines both of the previous rotation matrices. It will rotate around the z and y axes simultaniously
    float rotateMat[3][3] =
    {
        { (cosineB * cosineT), nSineB, (cosineB * sineT) },
        { (cosineT * sineB), cosineB, (sineB * sineT) },
        { nSineT, 0.0, cosineT }
    };
    
    //Now that all of the original calculations for the point are found, we can start the projection calculations
    //first thing to do is to find the center pixel. This will be at x 1500, y 2000, z [focal point in meters] originally
    //We then adjust the numbers to fit the camera dimensions (these dimensions were found on google width = 6.17mm and height = 4.55 mm)
    //these positions are WITHOUT any tilt or bearing
    struct point centerPoint;
    centerPoint.x = ((centerx / 4000.0) * 6.17) / 1000.0; centerPoint.y = ((centery / 3000.0) * 4.55) / 1000.0; centerPoint.z = alt;
    printf("The Center point (given) is:\n\n%f , %f, %f\n\n", centerPoint.x, centerPoint.y, centerPoint.z);
    
    struct point URPoint;
    URPoint.x = ((URx / 4000.0) * 6.17) / 1000.0; URPoint.y = ((URy / 3000.0) * 4.55) / 1000.0; URPoint.z = alt;
    printf("The Upper Right point (given) is:\n\n%f , %f, %f\n\n", URPoint.x, URPoint.y, URPoint.z);
    
    struct point ULPoint;
    ULPoint.x = ((ULx / 4000.0) * 6.17) / 1000.0; ULPoint.y = ((ULy / 3000.0) * 4.55) / 1000.0; ULPoint.z = alt;
    printf("The Upper Left point is:\n\n%f , %f, %f\n\n", ULPoint.x, ULPoint.y, ULPoint.z);
    
    struct point LLPoint;
    LLPoint.x = ((LLx / 4000.0) * 6.17) / 1000.0; LLPoint.y = ((LLy / 3000.0) * 4.55) / 1000.0; LLPoint.z = alt;
    printf("The Lower Left point (given) is:\n\n%f , %f, %f\n\n", LLPoint.x, LLPoint.y, LLPoint.z);
    
    struct point LRPoint;
    LRPoint.x = ((LRx / 4000.0) * 6.17) / 1000.0; LRPoint.y = ((LRy / 3000.0) * 4.55) / 1000.0; LRPoint.z = alt;
    printf("The Lower Right point is:\n\n%f , %f, %f\n\n", LRPoint.x, LRPoint.y, LRPoint.z);
    
    //printing the bearing rotation matrix (for self check)
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf("%f ", bearingRot[row][col]);
        }
        printf("\n");
    }
    
    //printing the tilt matrix for self check
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            printf("%f ", tiltRot[r][c]);
        }
        printf("\n");
    }
    
    //print the combined rotation matrix
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            printf("%f ", rotateMat[x][y]);
        }
        printf("\n");
    }
    
    //now we will display the points as they appear in the UAV WITH bearing and tilt rotations
    struct point newCenter;
    newCenter.x = ((centerPoint.x * (cosineB * cosineT)) + (centerPoint.y * nSineB) + (centerPoint.z * (cosineB * sineT)));
    newCenter.y = ((centerPoint.x * (cosineT * sineB)) + (centerPoint.y * cosineB) + (centerPoint.z * (sineB * sineT)));
    newCenter.z = ((centerPoint.x * (nSineT)) + (centerPoint.y * 0.0) + (centerPoint.z * (cosineT)));
    
    printf("\nThe new center point is:\n%f, %f, %f\n", newCenter.x, newCenter.y, newCenter.z);
    
    struct point newUR;
    newUR.x = ((URPoint.x * (cosineB * cosineT)) + (URPoint.y * nSineB) + (URPoint.z * (cosineB * sineT)));
    newUR.y = ((URPoint.x * (cosineT * sineB)) + (URPoint.y * cosineB) + (URPoint.z * (sineB * sineT)));
    newUR.z = ((URPoint.x * (nSineT)) + (URPoint.y * 0.0) + (URPoint.z * (cosineT)));
    
    printf("\nThe new UR point is:\n%f, %f, %f\n", newUR.x, newUR.y, newUR.z);
    
    struct point newUL;
    newUL.x = ((ULPoint.x * (cosineB * cosineT)) + (ULPoint.y * nSineB) + (ULPoint.z * (cosineB * sineT)));
    newUL.y = ((ULPoint.x * (cosineT * sineB)) + (ULPoint.y * cosineB) + (ULPoint.z * (sineB * sineT)));
    newUL.z = ((ULPoint.x * (nSineT)) + (ULPoint.y * 0.0) + (ULPoint.z * (cosineT)));
    
    printf("\nThe new UL point is:\n%f, %f, %f\n", newUL.x, newUL.y, newUL.z);
    
    struct point newLR;
    newLR.x = ((LRPoint.x * (cosineB * cosineT)) + (LRPoint.y * nSineB) + (LRPoint.z * (cosineB * sineT)));
    newLR.y = ((LRPoint.x * (cosineT * sineB)) + (LRPoint.y * cosineB) + (LRPoint.z * (sineB * sineT)));
    newLR.z = ((LRPoint.x * (nSineT)) + (LRPoint.y * 0.0) + (LRPoint.z * (cosineT)));
    
    printf("\nThe new LR point is:\n%f, %f, %f\n", newLR.x, newLR.y, newLR.z);
    
    struct point newLL;
    newLL.x = ((LLPoint.x * (cosineB * cosineT)) + (LLPoint.y * nSineB) + (LLPoint.z * (cosineB * sineT)));
    newLL.y = ((LLPoint.x * (cosineT * sineB)) + (LLPoint.y * cosineB) + (LLPoint.z * (sineB * sineT)));
    newLL.z = ((LLPoint.x * (nSineT)) + (LLPoint.y * 0.0) + (LLPoint.z * (cosineT)));
    
    printf("\nThe new LL point is:\n%f, %f, %f\n", newLL.x, newLL.y, newLL.z);
    
    // find the four points on the ground plane
    // ground plane equation  0x + 0y +1z -2143 = 0
    float groundNewUR = (0 * newUR.x) + (0 * newUR.y) + (1 * newUR.z) - 2143;
    float groundNewUL = (0 * newUL.x) + (0 * newUL.y) + (1 * newUL.z) - 2143;
    float groundNewLR = (0 * newLR.x) + (0 * newLR.y) + (1 * newLR.z) - 2143;
    float groundNewLL = (0 * newLL.x) + (0 * newLL.y) + (1 * newLL.z) - 2143;

    printf("\nThe ground point intersection is: \n %f UR \n %f UL \n %f LR \n %f LL \n", groundNewUL, groundNewUR, groundNewLL, groundNewLR);
    
    // Find the distance of the line
    //t=||p-q||
    float x1 = newCenter.x - altitude;
    float x2 = newCenter.y - altitude;
    float x3 = newCenter.z - altitude;
    float p = {newCenter.x, newCenter.y, newCenter.z};
    float n = sqrt(x1 * x1 + x2 * x2 + x3 *x3);
    // d = c + n * p
    float constant = 1; // don't know what const should be
    float distance = constant + n * p;
    printf("The line equation distance is: %f", distance);
    getchar();
    
}

