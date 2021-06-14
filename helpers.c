#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, n = height*width; i < n; i++)
    {
        int h = i / width;
        int w = i % width;
        RGBTRIPLE pixel = image[h][w];
        int average = round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0);
        image[h][w].rgbtBlue = average;
        image[h][w].rgbtGreen = average;
        image[h][w].rgbtRed = average;
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, n = height*width; i < n; i++)
    {
        int h = i / width;
        int w = i % width;
        RGBTRIPLE pixel = image[h][w];
        int red = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);
        int green = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);
        int blue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);
        // capping R G B values at 255
        red = (red > 255) ? 255 : red;
        green = (green > 255) ? 255 : green;
        blue = (blue > 255) ? 255 : blue;
        image[h][w].rgbtBlue = blue;
        image[h][w].rgbtGreen = green;
        image[h][w].rgbtRed = red;
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE temp;
        // swap row
        for (int j = 0; j < (width / 2); j++)
        {
            int left = j % width;
            int right = width - left - 1;
            temp = image[i][right];
            image[i][right] = image[i][left];
            image[i][left] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // int backup = malloc(height*width* sizeof(int)*3);
    RGBTRIPLE backup[height][width];

    for (int i = 0, n = height*width; i < n; i++)
    {
        int h = i / width;
        int w = i % width;
        int total_red = 0;
        int total_green = 0;
        int total_blue = 0;
        int count = 0;
        // scan the box around each pixel
        for (int dr = -1; dr < 2; dr++)
        {
            for (int dc = -1; dc < 2; dc++)
            {
                int r = h+dr;
                int c = w+dc;
                if (r >= 0 && r < height && c >= 0 && c < width) // within boundaries
                {
                    total_red += image[r][c].rgbtRed;
                    total_green += image[r][c].rgbtGreen;
                    total_blue += image[r][c].rgbtBlue;
                    count++; // max = 9
                }
            }
        }
        // new values
        backup[h][w].rgbtRed = round(total_red / (float) count);
        backup[h][w].rgbtGreen = round(total_green / (float) count);
        backup[h][w].rgbtBlue = round(total_blue / (float) count);
    }
    for (int i = 0, n = height*width; i < n; i++)
    {
        int h = i / width;
        int w = i % width;
        image[h][w] = backup[h][w];
    }
    return;
}
