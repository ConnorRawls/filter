#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
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
            int sepiaRed = round((.393*image[i][j].rgbtRed)+(.769*image[i][j].rgbtGreen)+(.189*image[i][j].rgbtBlue));
            int sepiaGreen = round((.349*image[i][j].rgbtRed)+(.686*image[i][j].rgbtGreen)+(.168*image[i][j].rgbtBlue));
            int sepiaBlue = round((.272*image[i][j].rgbtRed)+(.534*image[i][j].rgbtGreen)+(.131*image[i][j].rgbtBlue));

            if (sepiaRed > 255) sepiaRed = 255;
            if (sepiaGreen > 255) sepiaGreen = 255;
            if (sepiaBlue > 255) sepiaBlue = 255;

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imageref[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imageref[i][width-j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = imageref[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Temporary image holder
    RGBTRIPLE imageblur[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Conditions
            switch (i)
            {
                case 0:
                    switch (j)
                    {
                        //Upper left
                        case 0:
                            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j+1].rgbtRed+image[i+1][j].rgbtRed)/4;
                            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j+1].rgbtGreen+image[i+1][j].rgbtGreen)/4;
                            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j+1].rgbtBlue+image[i+1][j].rgbtBlue)/4;
                            break;
                        //Upper right
                        case width-1:
                            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed)/4;
                            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen)/4;
                            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue)/4;
                            break;
                        //Upper
                        default:
                            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/6;
                            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/6;
                            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/6;
                            break;
                    }
                case height-1:
                    switch (j)
                    {
                        //Lower left
                        case 0:
                            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j+1].rgbtRed)/4;
                            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j+1].rgbtGreen)/4;
                            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j+1].rgbtBlue)/4;
                            break;
                        //Lower right
                        case width-1:
                            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j-1].rgbtRed+image[i][j-1].rgbtRed)/4;
                            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i][j-1].rgbtGreen)/4;
                            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i][j-1].rgbtBlue)/4;
                            break;
                        //Lower
                        default:
                            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i][j+1].rgbtRed+image[i-1][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed)/6;
                            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i][j+1].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen)/6;
                            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j+1].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue)/6;
                            break;
                    }
                default:
                    switch (j)
                    {
                        //Left
                        case 0:
                            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/6;
                            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/6;
                            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/6;
                            break;
                        //Right
                        case width-1:
                            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j-1].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed)/6;
                            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen)/6;
                            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue)/6;
                            break;
                        //Everything else
                        default:
                            imageblur[i][j].rgbtRed = (image[i-1][j-1].rgbtRed+image[-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j-1].rgbtRed+image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/9;
                            imageblur[i][j].rgbtGreen = (image[i-1][j-1].rgbtGreen+image[-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j-1].rgbtGreen+image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/9;
                            imageblur[i][j].rgbtBlue = (image[i-1][j-1].rgbtBlue+image[-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/9;
                            break;
                    }
            }
        }
    }

    //Copies image from temporary image holder
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = imageblur[i][j].rgbtRed;
            image[i][j].rgbtGreen = imageblur[i][j].rgbtGreen;
            image[i][j].rgbtBlue = imageblur[i][j].rgbtBlue;
        }
    }
    return;
}
