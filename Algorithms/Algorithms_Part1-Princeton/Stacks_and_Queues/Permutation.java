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
            String s = StdIn.readString();
            if (k < 1) {
                break;
            }
            if (i >= k) {
                int dice = StdRandom.uniform(i + 1);
                if (dice < k) {
                    rq.dequeue();
                    rq.enqueue(s);
                }
            } else {
                rq.enqueue(s);
            }
            i++;
        }
        for (i = 0; i < k; i++) {
            StdOut.println(rq.dequeue());
        }
    }
}
