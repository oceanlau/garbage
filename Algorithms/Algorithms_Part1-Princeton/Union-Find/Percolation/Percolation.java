import edu.princeton.cs.algs4.WeightedQuickUnionUF;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Percolation {
    private boolean gridIsOpen[];
    private boolean gridAsRootIsTopConnected[];
    private boolean gridAsRootIsBottomConnected[];
    private boolean isPercolated = false;
    //side length of the grid
    private int     gridSide;
    private int     openSitesCount = 0;
    private int     gridSize;
    private WeightedQuickUnionUF percolationWQU;

    private boolean tmpIsTopConnectedAfterUnion = false;
    private boolean tmpIsBottomConnectedAfterUnion = false;

    public Percolation(int n)                // create n-by-n grid, with all sites blocked
    {

        if(n <= 0){
            throw new IllegalArgumentException("grid side length should be integer equals or larger than 1");
        }

        this.gridSide   = n;
        this.gridSize   = n * n;
        this.gridIsOpen = new boolean[this.gridSize];
        this.gridAsRootIsTopConnected    = new boolean[this.gridSize];
        this.gridAsRootIsBottomConnected = new boolean[this.gridSize];
        this.percolationWQU = new WeightedQuickUnionUF(this.gridSize);
    }

    public     void open(int row, int col)    // open site (row, col) if it is not open already
    {
        this.checkParameters(row, col);

        if(this.isOpen(row, col)){
            return;
        }
        int index = this.getIndex(row, col);
        this.gridIsOpen[index] = true;
        this.openSitesCount++;

        this.tmpIsTopConnectedAfterUnion = false;
        this.tmpIsBottomConnectedAfterUnion = false;
        //union top, right, below, left slots
        this.unionNeighbor(index, row - 1, col);
        this.unionNeighbor(index, row, col + 1);
        this.unionNeighbor(index, row + 1, col);
        this.unionNeighbor(index, row, col - 1);

        int rootIndex = this.percolationWQU.find(index);
        this.gridAsRootIsTopConnected[rootIndex]    = this.tmpIsTopConnectedAfterUnion;
        this.gridAsRootIsBottomConnected[rootIndex] = this.tmpIsBottomConnectedAfterUnion;
        if(this.tmpIsTopConnectedAfterUnion && this.tmpIsBottomConnectedAfterUnion){
            this.isPercolated = true;
        }
    }
    private    void checkParameters(int row, int col)
    {
        if(row < 1 || row > this.gridSide || col < 1 || col > this.gridSide){
            throw new IllegalArgumentException("row[" + row + "] and col[" + col + "] should be integers between 1 and grid side length[" + this.gridSide + "]");
        }
    }
    private    void unionNeighbor(int index, int neighborRow, int neighborCol)
    {

        if(neighborCol > this.gridSide || neighborCol <= 0){
            return;
        }

        if(neighborRow > this.gridSide){
            this.tmpIsBottomConnectedAfterUnion = true;
            
        } else if(neighborRow <= 0){
            this.tmpIsTopConnectedAfterUnion = true;

        } else if(this.isOpen(neighborRow, neighborCol)){
            int neighborIndex                   = this.getIndex(neighborRow, neighborCol);
            int neighborRootIndex               = this.percolationWQU.find(neighborIndex);
            this.tmpIsTopConnectedAfterUnion    = this.tmpIsTopConnectedAfterUnion || this.gridAsRootIsTopConnected[neighborRootIndex];
            this.tmpIsBottomConnectedAfterUnion = this.tmpIsBottomConnectedAfterUnion || this.gridAsRootIsBottomConnected[neighborRootIndex];
            this.percolationWQU.union(index, neighborIndex);
            
        } 
    }
    private     int getIndex(int row, int col)
    {
        return (row - 1) * this.gridSide + (col - 1);
    }
    public  boolean isOpen(int row, int col)  // is site (row, col) open?
    {
        this.checkParameters(row, col);
        int index = this.getIndex(row, col);
        return this.gridIsOpen[index];
    }
    public  boolean isFull(int row, int col)  // is site (row, col) full?
    {
        this.checkParameters(row, col);
        int index     = this.getIndex(row, col);
        int rootIndex = this.percolationWQU.find(index);
        return this.gridAsRootIsTopConnected[rootIndex];
    }
    public      int numberOfOpenSites()       // number of open sites
    {
        return this.openSitesCount;
    }
    public  boolean percolates()              // does the system percolate?
    {
        return this.isPercolated;
    }

    public  static void main(String[] args)   // test client (optional)
    {
        String does;
        int n = StdIn.readInt();
        Percolation p = new Percolation(n);
        while(!StdIn.isEmpty()){
            int row = StdIn.readInt();
            int col = StdIn.readInt();
            p.open(row, col);
            if(p.percolates()){
                 does = "does";
            } else {
                 does = "does not";
            }
            StdOut.println("The system " + does + " percolate. Number of open sites is " + p.numberOfOpenSites());
        }
    }
}
