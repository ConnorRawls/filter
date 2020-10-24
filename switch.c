void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            switch (i)
            {
                case 0:
                    switch (j)
                    {
                        case 0:
                            image[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j+1].rgbtRed+image[i+1][j].rgbtRed)/4;
                            image[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j+1].rgbtGreen+image[i+1][j].rgbtGreen)/4;
                            image[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j+1].rgbtBlue+image[i+1][j].rgbtBlue)/4;
                            break;
                        case width-1:
                            image[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed)/4;
                            image[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen)/4;
                            image[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue)/4;
                            break;
                        default:
                            image[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/6;
                            image[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/6;
                            image[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/6;
                            break;
                    }
                case height-1:
                    switch (j)
                    {
                        case 0:
                            image[i][j].rgbtRed = (image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j+1].rgbtRed)/4;
                            image[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j+1].rgbtGreen)/4;
                            image[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j+1].rgbtBlue)/4;
                            break;
                        case width-1:
                            image[i][j].rgbtRed = (image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j-1].rgbtRed+image[i][j-1].rgbtRed)/4;
                            image[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i][j-1].rgbtGreen)/4;
                            image[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i][j-1].rgbtBlue)/4;
                            break;
                        default:
                            image[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i][j+1].rgbtRed+image[i-1][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed)/6;
                            image[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i][j+1].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen)/6;
                            image[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j+1].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue)/6;
                            break;
                    }
                default:
                    switch (j)
                    {
                        case 0:
                            image[i][j].rgbtRed = (image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/6;
                            image[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/6;
                            image[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/6;
                            break;
                        case width-1:
                            image[i][j].rgbtRed = (image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j-1].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed)/6;
                            image[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen)/6;
                            image[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue)/6;
                            break;
                        default:
                            image[i][j].rgbtRed = (image[i-1][j-1].rgbtRed+image[-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j-1].rgbtRed+image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/9;
                            image[i][j].rgbtGreen = (image[i-1][j-1].rgbtGreen+image[-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j-1].rgbtGreen+image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/9;
                            image[i][j].rgbtBlue = (image[i-1][j-1].rgbtBlue+image[-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/9;
                            break;
                    }
            }
        }
    }
    return;
}
