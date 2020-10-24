#include "helpers.h"
#include <math.h>

void posops(int height, int width, int i, int j, RGBTRIPLE imageblur[height][width], RGBTRIPLE image[height][width]);

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

    //Temporary holder
    RGBTRIPLE imageblur[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            posops(height, width, i, j, imageblur, image);
        }
    }

    //Copies image from temporary holder
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

//Blur image matrix position operator
void posops(int height, int width, int i, int j, RGBTRIPLE imageblur[height][width], RGBTRIPLE image[height][width])
{
    if (i == 0)
    {
        //Top left
        if (j == 0)
        {
            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j+1].rgbtRed+image[i+1][j].rgbtRed)/4;
            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j+1].rgbtGreen+image[i+1][j].rgbtGreen)/4;
            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j+1].rgbtBlue+image[i+1][j].rgbtBlue)/4;
        }
        //Top right
        else if (j == width-1)
        {
            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed)/4;
            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen)/4;
            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue)/4;
        }
        //Top
        else
        {
            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/6;
            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/6;
            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/6;
        }
    }
    else if (i == height-1)
    {
        //Bottom left
        if (j == 0)
        {
            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j+1].rgbtRed)/4;
            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j+1].rgbtGreen)/4;
            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j+1].rgbtBlue)/4;
        }
        //Bottom right
        else if (j == width-1)
        {
            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j-1].rgbtRed+image[i][j-1].rgbtRed)/4;
            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i][j-1].rgbtGreen)/4;
            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i][j-1].rgbtBlue)/4;
        }
        //Bottom
        else
        {
            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i][j+1].rgbtRed+image[i-1][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed)/6;
            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i][j+1].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen)/6;
            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j+1].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue)/6;
        }
    }
    else
    {
        //Left
        if (j == 0)
        {
            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/6;
            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/6;
            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/6;
        }
        //Right
        else if (j == width-1)
        {
            imageblur[i][j].rgbtRed = (image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j-1].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed)/6;
            imageblur[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen)/6;
            imageblur[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue)/6;
        }
        //Everything else
        else
        {
            imageblur[i][j].rgbtRed = (image[i-1][j-1].rgbtRed+image[-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j-1].rgbtRed+image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/9;
            imageblur[i][j].rgbtGreen = (image[i-1][j-1].rgbtGreen+image[-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j-1].rgbtGreen+image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/9;
            imageblur[i][j].rgbtBlue = (image[i-1][j-1].rgbtBlue+image[-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/9;
        }
    }

    return;
}
