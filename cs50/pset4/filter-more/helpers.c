#include "helpers.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;
            //calculate avg after getting pixle red, green, blue value
            float avg = ((blue + green + red) / (float)3.0);

            //and put in corresponding image pixle
            image[i][j].rgbtBlue = round(avg);
            image[i][j].rgbtGreen = round(avg);
            image[i][j].rgbtRed = round(avg);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //put first image pixle in arbitary x value then
            //change it with its corresponding last value
            //then change corresponding last value with intial value
            //and int in loop take care of odd  or even pixles count in row
            RGBTRIPLE x = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = x;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //copy image pixles in arbitary 2D array
            copy[i][j] = image[i][j];

        }
    }
    int pixle = 0;
    for (int m = 0; m < height; m++)
    {
        for (int n = 0; n < width; n++)
        {
            //initialise total RGB values
            float count = 0;
            int total_blue = 0;
            int total_green = 0;
            int total_red = 0;
            for (int k = m - 1; k < m + 2; k++)
            {
                for (int l = n - 1; l < n + 2; l++)
                {
                    // if condition for values out of bound
                    if ((k > - 1 && k < height) && (l > - 1 && l < width))
                    {
                        //add RGB value in total count and number of values
                        total_blue = total_blue + copy[k][l].rgbtBlue;
                        total_green = total_green + copy[k][l].rgbtGreen;
                        total_red = total_red + copy[k][l].rgbtRed;
                        count = count + 1;
                    }
                }
            }
            //calculate avg of total RGB values
            float avgblue = (total_blue / count);
            float avggreen = (total_green / count);
            float avgred = (total_red / count);

            // Put in corresponding RGB image pixles
            image[m][n].rgbtBlue = round(avgblue);
            image[m][n].rgbtGreen = round(avggreen);
            image[m][n].rgbtRed = round(avgred);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //gx and gy kernels.in arrays of int
    int gx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int gy[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    //copy of all pixles
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //copy image pixles in arbitary 2D array
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtRed = image[i][j].rgbtRed;

        }
    }

    //iteration through every pixle
    for (int m = 0; m < height; m++)
    {
        for (int n = 0; n < width; n++)
        {
            //initialise gx and gy componants of kernels values
            int gx_blue = 0;
            int gx_green = 0;
            int gx_red = 0;
            int gy_blue = 0;
            int gy_green = 0;
            int gy_red = 0;
            int index = 0;        //index no for gx and gy array

            for (int k = m - 1; k < m + 2; k++)
            {
                for (int l = n - 1; l < n + 2; l++)
                {
                    // if condition for values out of bound
                    if ((k > - 1 && k < height) && (l > - 1 && l < width))
                    {
                        //cal gx and gy foe every rgb of that perticular pixle
                        gx_blue = gx_blue + (copy[k][l].rgbtBlue * gx[index]);
                        gx_green = gx_green + (copy[k][l].rgbtGreen * gx[index]);
                        gx_red = gx_red + (copy[k][l].rgbtRed * gx[index]);
                        gy_blue = gy_blue + (copy[k][l].rgbtBlue * gy[index]);
                        gy_green = gy_green + (copy[k][l].rgbtGreen * gy[index]);
                        gy_red = gy_red + (copy[k][l].rgbtRed * gy[index]);
                        index++;          // index increase by 1
                    }
                    //if index is out of bound everything is zero
                    else
                    {
                        index++;
                    }
                }
            }
            //apply the formula of edge
            float gxy_blue = pow((pow(gx_blue, 2.0) + pow(gy_blue, 2.0)), 0.5);
            float gxy_green = pow((pow(gx_green, 2.0) + pow(gy_green, 2.0)), 0.5);
            float gxy_red = pow((pow(gx_red, 2.0) + pow(gy_red, 2.0)), 0.5);

            //if value is out of bound of rgb range
            if (gxy_blue > 255)
            {
                gxy_blue = 255;
            }
            if (gxy_green > 255)
            {
                gxy_green = 255;
            }
            if (gxy_red > 255)
            {
                gxy_red = 255;
            }

            // Put in corresponding RGB image pixles with gxy values
            image[m][n].rgbtBlue = round(gxy_blue);
            image[m][n].rgbtGreen = round(gxy_green);
            image[m][n].rgbtRed = round(gxy_red);
        }
    }
    return;
}
