void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Temporary holder
    RGBTRIPLE imageblur[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            //Conditions
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
