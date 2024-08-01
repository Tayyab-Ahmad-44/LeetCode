#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        // Save the dimensions of the image.
        int m = img.size();
        int n = img[0].size();

        // Create a new image of the same dimension as the input image.
        vector<vector<int>> smoothImg(m, vector<int>(n));

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n)
                        {
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }

                // Store the rounded down value in smoothImg[i][j].
                smoothImg[i][j] = sum / count;
            }
        }

        // Return the smooth image.
        return smoothImg;
    }
};

// class Solution
// {
// public:
//     vector<vector<int>> imageSmoother(vector<vector<int>> &img)
//     {
//         // Save the dimensions of the image.
//         int m = img.size();
//         int n = img[0].size();

//         // Create temp array of size n.
//         vector<int> temp(n);
//         int prevVal = 0;

//         // Iterate over the cells of the image.
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 // Initialize the sum and count
//                 int sum = 0;
//                 int count = 0;

//                 // Bottom neighbors
//                 if (i + 1 < m)
//                 {
//                     if (j - 1 >= 0)
//                     {
//                         sum += img[i + 1][j - 1];
//                         count += 1;
//                     }
//                     sum += img[i + 1][j];
//                     count += 1;
//                     if (j + 1 < n)
//                     {
//                         sum += img[i + 1][j + 1];
//                         count += 1;
//                     }
//                 }

//                 // Next neighbor
//                 if (j + 1 < n)
//                 {
//                     sum += img[i][j + 1];
//                     count += 1;
//                 }

//                 // This cell
//                 sum += img[i][j];
//                 count += 1;

//                 // Previous neighbor
//                 if (j - 1 >= 0)
//                 {
//                     sum += temp[j - 1];
//                     count += 1;
//                 }

//                 // Top neighbors
//                 if (i - 1 >= 0)
//                 {
//                     // Left-top corner-sharing neighbor.
//                     if (j - 1 >= 0)
//                     {
//                         sum += prevVal;
//                         count += 1;
//                     }

//                     // Top edge-sharing neighbor.
//                     sum += temp[j];
//                     count += 1;

//                     // Right-top corner-sharing neighbor.
//                     if (j + 1 < n)
//                     {
//                         sum += temp[j + 1];
//                         count += 1;
//                     }
//                 }

//                 // Store the original value of temp[j], which represents
//                 // original value of img[i - 1][j].
//                 if (i - 1 >= 0)
//                 {
//                     prevVal = temp[j];
//                 }

//                 // Save current value of img[i][j] in temp[j].
//                 temp[j] = img[i][j];

//                 // Overwrite with smoothed value.
//                 img[i][j] = sum / count;
//             }
//         }

//         // Return the smooth image.
//         return img;
//     }
// };

int main()
{

    return 0;
}

/*

661. Image Smoother

An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).


Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.



Example 1:


Input: img = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[0,0,0],[0,0,0],[0,0,0]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Example 2:


Input: img = [[100,200,100],[200,50,200],[100,200,100]]
Output: [[137,141,137],[141,138,141],[137,141,137]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
For the points (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
For the point (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138


*/