import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
public class Permutation {
    public static void main(String[] args)
    {
        RandomizedQueue<String> rq = new RandomizedQueue<String>();
        int i = 0;
        int k = Integer.parseInt(args[0]);
        while (!StdIn.isEmpty()) {
            if (i > 0) {
                int dice = StdRandom.uniform(i);
                if (dice <= k) {
                    rq.enqueue(StdIn.readString());
                }
            } else if (k > 0) {
                rq.enqueue(StdIn.readString());
            }
            i++;
        }
        for (i = 0; i < k; i++) {
            StdOut.println(rq.dequeue());
        }
    }
}
