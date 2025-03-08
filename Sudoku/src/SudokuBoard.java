import com.sun.source.tree.WhileLoopTree;

import java.util.Random;

public class SudokuBoard
{
    private int size;
    private SudokuCell[][] board;
    int dificulty;

    public SudokuBoard(int[][] board)
    {
        this.size = (int)Math.sqrt(board.length);

        this.board = new SudokuCell[board.length][board.length];

        for (int i = 0; i < board.length; i++)
        {
            for (int j = 0; j < board.length; j++)
            {
                int value = board[i][j];
                boolean fixed = true;
                if (value == 0)
                    fixed = false;

                this.board[i][j] = new SudokuCell(value, fixed);
            }
        }
    }

    public SudokuBoard(int size, char level)
    {
        this(new int[size][size]);
        switch(level)
        {
            case 'e' : dificulty = (size * size) / 4;
            break;
            case 'm' : dificulty = (size * size) / 2;
            break;
            case 'h' : dificulty = (int)((size * size) * 0.75);
            break;
            default : dificulty = (size * size) / 4;
        }
        SudokuSolver.solve(this);
        removeElements();
    }

    public int getSize()
    {
        return size;
    }

    public SudokuCell getCell(int i, int j)
    {
        return board[i][j];
    }

    public boolean isValueOk(int i, int j)
    {
        if (getCell(i, j).getValue() == 0)
            return true;

        for (int k = 0; k < board.length; k++)
        {
            if (getCell(i, k).getValue() == getCell(i, j).getValue() && k != j)
                return false;
        }

        for (int k = 0; k < board.length; k++)
        {
            if (getCell(k, j).getValue() == getCell(i, j).getValue() && k != i)
                return false;
        }

        int grydRow = i - i % size;
        int grydCol = j - j % size;

        for (int k = grydRow; k < grydRow + size; k++)
        {
            for (int l = grydCol; l < grydCol + size; l++)
            {
                if (getCell(k, l).getValue() == getCell(i, j).getValue() && (k != i || l != j))
                    return false;
            }
        }

        return true;
    }

    public boolean isSolved()
    {
        for (int i = 0; i < board.length; i++)
        {
            for (int j = 0; j < board.length; j++)
            {
                if (getCell(i, j).getValue() == 0 || !isValueOk(i, j))
                    return false;
            }
        }
        return true;
    }

    public void print()
    {
        int boardSize = size * size;

        int length = 1;
        int tempBoardSize = boardSize;

        while (tempBoardSize != 0)
        {
            tempBoardSize /= 10;
            length++;
        }

        for (int i = 0; i < boardSize; i++)
        {
            if (i % size == 0)
            {
                for (int j = 0; j < boardSize * (length + 1) + 2* size + 1; j++)
                {
                    System.out.print("-");
                }
                System.out.println();
            }

            for (int j = 0; j < boardSize; j++)
            {
                if (j % size == 0)
                {
                    System.out.print("| ");
                }
                System.out.printf("%" + length + "d ", board[i][j].getValue());
            }
            System.out.println("|");
        }

        for (int j = 0; j < boardSize * (length + 1) + 2 * size + 1; j++)
        {
            System.out.print("-");
        }
        System.out.println();
    }

    private void removeElements()
    {
        Random random = new Random();
        int count = 0;
        while(count < dificulty)
        {
            for (int i = 0; i < board.length; i++)
            {
                for (int j = 0; j < board.length; j++)
                {
                    boolean ShouldBeDeleted = random.nextBoolean();
                    if (count < dificulty && ShouldBeDeleted)
                    {
                        board[i][j].setValue(0);
                        count++;
                    }
                }
            }
        }
        for (int i = 0; i < board.length; i++)
        {
            for (int j = 0; j < board.length; j++)
            {
                if (board[i][j].getValue() == 0)
                {
                    board[i][j].setFixed(false);
                }
                else
                {
                    board[i][j].setFixed(true);
                }
            }
        }
    }
}
