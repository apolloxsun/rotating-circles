#include <stdio.h>
#include <math.h>

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"
#include "shapes.h"

int main(void)
{
    int scW = 1500;
    int scH = 1000;
    InitWindow(scW,scH,"rotating circles B)");

    SetTargetFPS(60);
    
    double rotation = 0;
    double rotCoefficient;
    float lineLength;
    int amountOfCircles = 0; 

    Vector2 origin = {100, 100};
    Rectangle rec = {scW/2, scH/2, 100, 100};
    float* linePtr = &lineLength;

    float initPt1 = scW/2;
    float initPt2 = scH/2;

    float a = 1;
    float* aPtr = &a;

    while(!(WindowShouldClose())){
        rotation++;

        BeginDrawing();
        ClearBackground(WHITE);
/*-------------BUTTONS----------------*/
        GuiSlider((Rectangle){100,10,100,20}, "line length","",linePtr,20,200);

        GuiSlider((Rectangle){100,40,100,20}, "angular speed","",aPtr,1,10);


        if(GuiButton((Rectangle){100, 70, 100, 20}, "add circles")){
            amountOfCircles++;
        }
        
        if(GuiButton((Rectangle){100, 100, 100, 20}, "remove circles")){
            amountOfCircles--;
        }


/*-------------LINES AND CIRCLES?????--------*/
        Circle circle1 = {scW/2, scH/2, 4, LIGHTGRAY};

        DrawCircle(circle1.xCoordinate, circle1.yCoordinate, circle1.circleRadius, circle1.circleColor);
        //DrawRectanglePro(rec, origin, (float)rotation, BLACK);
        //float initPt1 = scW/2;
        //float initPt2 = scH/2;
        Line line1 = {scW/2, scH/2, initPt1, initPt2, BLACK};        
        //DrawLine(line1.xCoordinate, line1.yCoordinate, line1.xCoordinate2, line1.yCoordinate2, line1.lineColor);
        //DrawCircle(endPoint1,endPoint2, 20, YELLOW);

        rotCoefficient = a * rotation * PI / 180;
        float initX, initY, endPointX, endPointY;
        double additionX = lineLength*cos(rotCoefficient);
        double additionY = lineLength*sin(rotCoefficient);


        for(int i = 0; i<=amountOfCircles; i++){
            /*int a = rand();
            a = a%10 + 1;*/
               
            if(i==0){
                initX = initPt1;
                initY = initPt2;
            }

            endPointX = (initX + additionX);
            endPointY = (initY + additionY);


            Circle circleX = {endPointX, endPointY, 10, RED};
            Line lineX = {initX, initY, endPointX, endPointY, BLACK };

            DrawLine(lineX.xCoordinate, lineX.yCoordinate, lineX.xCoordinate2, lineX.yCoordinate2, lineX.lineColor);

            DrawCircle(circleX.xCoordinate, circleX.yCoordinate, circleX.circleRadius, circleX.circleColor);

            initX = endPointX;
            initY = endPointY;

            additionX *= cos(rotCoefficient);
            additionY *= sin(rotCoefficient);               
            

        }


        EndDrawing();
    }

    return 0;
}