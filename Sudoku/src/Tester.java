import java.util.Scanner;

public class Tester
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the size of grid: ");
        int size = input.nextInt();

        System.out.print("Enter the dificulty level: ");
        char level = input.next().charAt(0);

        SudokuBoard board = new SudokuBoard(size, level);

        board.print();

        SudokuSolver.solve(board);

        board.print();
    }
}