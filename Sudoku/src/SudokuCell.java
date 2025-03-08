public class SudokuCell
{
    private int value;
    private boolean fixed;

    public SudokuCell(int value, boolean fixed)
    {
        if (value >= 0)
            this.value = value;
        this.fixed = fixed;
    }

    public int getValue()
    {
        return value;
    }

    public boolean isFixed()
    {
        return fixed;
    }

    public void setValue(int value)
    {
        if (value >= 0 && fixed == false)
            this.value = value;
    }

    public void setFixed(boolean fixed)
    {
        this.fixed = fixed;
    }
}
