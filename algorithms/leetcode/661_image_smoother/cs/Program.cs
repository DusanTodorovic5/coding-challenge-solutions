public class Solution
{
    public int[][] ImageSmoother(int[][] img)
    {
        if (img.Length == 0)
        {
            return img;
        }

        int[][] new_img = new int[img.Length][];
        for (int i = 0; i < img.Length; i++)
        {
            new_img[i] = new int[img[i].Length];
            for (int j = 0; j < img[i].Length; j++)
            {
                new_img[i][j] = CalculateAverage(ref img, i, j);
            }
        }

        return new_img;
    }

    public int CalculateAverage(ref int[][] img, int rowIndex, int colIndex)
    {
        int sum = 0;
        int count = 0;

        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (rowIndex + i < 0 || rowIndex + i >= img.Length || colIndex + j < 0 || colIndex + j >= img[rowIndex].Length)
                {
                    continue;
                }

                sum += img[rowIndex + i][colIndex + j];
                count++;
            }
        }
      
        return sum / count;
    }

    public static void Main(string[] args)
    {
        Solution s = new Solution();
        Console.WriteLine(s.ImageSmoother([[1, 1, 1], [1, 0, 1], [1, 1, 1]]).Length);
    }
}