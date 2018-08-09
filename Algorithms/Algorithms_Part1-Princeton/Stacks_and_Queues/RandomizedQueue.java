import java.util.NoSuchElementException;
import java.util.Iterator;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] a;
    private int n;

    public RandomizedQueue()                 // construct an empty randomized queue
    {
        this.a = (Item[]) new Object[2];
        this.n = 0;
    }
    public boolean isEmpty()                 // is the randomized queue empty?
    {
        return this.n == 0;
    }
    public int size()                        // return the number of items on the randomized queue
    {
        return this.n;
    }
    private void resize(int capacity)
    {
        assert capacity >= this.n;

        Item[] temp = (Item[]) new Object[capacity];
        for (int i = 0; i < this.n; i++) {
            temp[i] = this.a[i];
        }
        this.a = temp;
    }
    public void enqueue(Item item)           // add the item
    {
        if (item == null) {
             throw new IllegalArgumentException("item cannot be null.");
         }
        if (this.n == this.a.length) this.resize(2*this.a.length);
        this.a[this.n++] = item;
    }
    public Item dequeue()                    // remove and return a random item
    {
        if (this.isEmpty()) throw new NoSuchElementException("underflow");
        int i = StdRandom.uniform(this.n);
        Item item = this.a[i];
        this.a[i] = this.a[this.n-1];
        this.a[this.n-1] = null;
        this.n--;
        if (this.n > 0 && this.n == this.a.length/4) this.resize(this.a.length/2);
        return item;
    }
    public Item sample()                     // return a random item (but do not remove it)
    {
        if (this.isEmpty()) throw new NoSuchElementException("underflow");
        int i = StdRandom.uniform(this.n);
        return this.a[i];
    }
    public Iterator<Item> iterator()         // return an independent iterator over items in random order
    {
        return new RandomizedQueueIterator();
    }
    private class RandomizedQueueIterator implements Iterator<Item>
    {
        final private Item[] b;
        private int idx;

        public RandomizedQueueIterator()
        {
            this.b = (Item[]) new Object[RandomizedQueue.this.n];
            for (int i = 0; i < RandomizedQueue.this.n; i++) {
                this.b[i] = RandomizedQueue.this.a[i];
            }
            StdRandom.shuffle(this.b);
            this.idx = RandomizedQueue.this.n-1;
        }

        public boolean hasNext()
        {
            return this.idx >= 0;
        }

        public void remove()
        {
            throw new UnsupportedOperationException("remove is not supported.");
        }

        public Item next()
        {
            if (!this.hasNext()) throw new NoSuchElementException("end of randomized queue.");
            return this.b[this.idx--];
        }
    }

    public static void main(String[] args)   // unit testing (optional)
    {
        RandomizedQueue<String> rq = new RandomizedQueue<String>();
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (!item.equals("-")) rq.enqueue(item);
            else if (!rq.isEmpty()) StdOut.print(rq.dequeue() + " ");
        }
        StdOut.println("(" + rq.size() + " left on rq)");
    }
}
