public class SudokuSolver
{
    public static void solve(SudokuBoard board)
    {
        solve(board, 0, 0);
    }

    private static boolean solve(SudokuBoard board, int i, int j)
    {
        int size = board.getSize() * board.getSize();

        if (i == size)
        {
            return true;
        }

        if (board.getCell(i,j).isFixed())
        {
            if (j == size - 1)
            {
                return solve(board, i + 1, 0);
            }
            else
            {
                return solve(board, i, j + 1);
            }
        }

        for (int valueToCheck = 1; valueToCheck <= size; valueToCheck++)
        {
            board.getCell(i,j).setValue(valueToCheck);
            if (board.isValueOk(i, j))
            {
                if (j == size - 1)
                {
                    if (solve(board, i + 1, 0))
                    {
                        return true;
                    }
                }
                else
                {
                    if (solve(board, i, j + 1))
                    {
                        return true;
                    }
                }
            }
            board.getCell(i,j).setValue(0);
        }

        return false;
    }
}
