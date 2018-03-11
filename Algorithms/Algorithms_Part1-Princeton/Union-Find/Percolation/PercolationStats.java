import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.StdOut;

public class PercolationStats {
    private double fractionsOfOpenSites[];
    private double meanVal;
    private double stddevVal;
    private int    T;

    public PercolationStats(int n, int trials)    // perform trials independent experiments on an n-by-n grid
    {
        if(n <= 0 || trials <= 0){
            throw new IllegalArgumentException("n[" + n + "] and trials[" + trials + "] should be larger than 0.");
        }

        this.T = trials;
        this.fractionsOfOpenSites = new double[trials];
        
        while(trials-- != 0){
            Percolation p = new Percolation(n);
            while(!p.percolates()){
                int row = StdRandom.uniform(n) + 1;
                int col = StdRandom.uniform(n) + 1;
                p.open(row, col);
            }
            
            this.fractionsOfOpenSites[trials] = p.numberOfOpenSites() / (double)(n * n);
        }
        this.meanVal   = StdStats.mean(this.fractionsOfOpenSites);
        this.stddevVal = StdStats.stddev(this.fractionsOfOpenSites);
    }
    public double mean()                          // sample mean of percolation threshold
    {
        return this.meanVal;
    }
    public double stddev()                        // sample standard deviation of percolation threshold
    {
        return this.stddevVal;
    }
    public double confidenceLo()                  // low  endpoint of 95% confidence interval
    {
        return  this.meanVal - 1.96 * this.stddevVal / Math.sqrt(this.T);
    }
    public double confidenceHi()                  // high endpoint of 95% confidence interval
    {
        return  this.meanVal + 1.96 * this.stddevVal / Math.sqrt(this.T);
    }

    public static void main(String[] args)        // test client (described below)
    {
        PercolationStats p = new PercolationStats(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
        StdOut.println("mean                    = " + p.mean());
        StdOut.println("stddev                  = " + p.stddev());
        StdOut.println("95% confidence interval = [" + p.confidenceLo() + ", " + p.confidenceHi() + "]");
    }
}
