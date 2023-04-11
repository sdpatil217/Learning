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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //get original RGB values
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;
            int originalRed = image[i][j].rgbtRed;
            //apply sepia formula
            float sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            float sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            float sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;
            //if sepia value is greater than 255 then make it 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //put sepia RGB in corresponding pixles
            image[i][j].rgbtBlue = round(sepiaBlue);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtRed = round(sepiaRed);
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
            //and int in loop take care of odd even pixles count in row
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
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtRed = image[i][j].rgbtRed;

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
//Happy Ending :)