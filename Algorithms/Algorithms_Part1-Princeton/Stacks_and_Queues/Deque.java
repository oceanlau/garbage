import java.util.NoSuchElementException;
import java.util.Iterator;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Deque<Item> implements Iterable<Item> {
    private Node first;
    private Node last;
    private int  size;
    
    private class Node
    {
        private Item item;
        private Node previous;
        private Node next;
    }
    public Deque()                           // construct an empty deque
    {
        this.first = null;
        this.last = null;
        this.size = 0;
    }
    public boolean isEmpty()                 // is the deque empty?
    {
        return this.size == 0;
    }
    public int size()                        // return the number of items on the deque
    {
        return this.size;
    }
    public void addFirst(Item item)          // add the item to the front
    {
        if (item == null) {
            throw new IllegalArgumentException("item cannot be null.");
        }
        Node oldfirst = this.first;
        this.first = new Node();
        this.first.item = item;
        this.first.next = null;
        this.first.previous = null;
        this.size++;
        if (1 == this.size) {
            this.last = this.first;
        } else {
            this.first.next = oldfirst;
            oldfirst.previous = this.first;
        }
    }
    public void addLast(Item item)           // add the item to the end
    {
        if (item == null) {
            throw new IllegalArgumentException("item cannot be null.");
        }
        Node oldlast = this.last;
        this.last = new Node();
        this.last.item = item;
        this.last.next = null;
        this.last.previous = null;
        this.size++;
        if (1 == this.size) {
            this.first = this.last;
        } else {
            this.last.previous = oldlast;
            oldlast.next = this.last;
        }
    }
    public Item removeFirst()                // remove and return the item from the front
    {
        if (this.isEmpty()) {
            throw new NoSuchElementException("deque is already empty.");
        }
        Node oldfirst = this.first;
        Item item = this.first.item;
        this.first = this.first.next;
        this.size--;
        if (!this.isEmpty()) {
            this.first.previous = null;
        }
        oldfirst = null;
        return item;
    }
    public Item removeLast()                 // remove and return the item from the end
    {
        if (this.isEmpty()) {
            throw new NoSuchElementException("deque is already empty.");
        }
        Node oldlast = this.last;
        Item item = this.last.item;
        this.last = this.last.previous;
        this.size--;
        if (!this.isEmpty()) {
            this.last.next = null;
        }
        oldlast = null;
        return item;
    }
    public Iterator<Item> iterator()         // return an iterator over items in order from front to end
    {
        return new DequeIterator();
    }
    private class DequeIterator implements Iterator<Item>
    {
        private Node current = Deque.this.first;

        public boolean hasNext() {
            return this.current != null;
        }
        public void remove() {
            throw new UnsupportedOperationException("remove is not supported.");
        }

        public Item next() {
            if (!this.hasNext()) {
                throw new NoSuchElementException("end of deque.");
            }
            Item item = this.current.item;
            this.current = this.current.next;
            return item;
        }
    }
    public static void main(String[] args)   // unit testing (optional)
    {
        Deque<Integer> d = new Deque<Integer>();
        while (!StdIn.isEmpty()) {
            char command = StdIn.readChar();
            StdIn.readLine();
            switch (command) {
                case 'f':
                    d.addFirst(StdIn.readInt());
                    StdIn.readLine();
                    break;
                case 'l':
                    d.addLast(StdIn.readInt());
                    StdIn.readLine();
                    break;
                case 'd':
                    StdOut.println(d.removeFirst());
                    break;
                case 'p':
                    StdOut.println(d.removeLast());
                    break;
                default:
                    for (int item : d) {
                        StdOut.println("item " + item);
                    }
                    break;
            }
        }
    }
}
