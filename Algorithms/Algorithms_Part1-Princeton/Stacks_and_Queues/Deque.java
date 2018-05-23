public class Deque<Item> implements Iterable<Item> {
    private Node first = null;
    private Node last  = null;
    private int  size;
    
    private class Node
    {
        Item item;
        Node next;
    }
    public Deque()                           // construct an empty deque
    {}
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
        Node oldfirst = this.first;
        this.first = new Node();
        this.first.item = item;
        if(this.isEmpty()){
            this.last = this.first;
        } else {
            this.first.next = oldfirst;
        }
        this.size ++;
    }
    public void addLast(Item item)           // add the item to the end
    {
        Node oldlast = this.last;
        this.last = new Node();
        this.last.item = item;
        this.last.next = null;
        if(this.isEmpty()){
            this.first = this.last;
        } else {
            oldlast.next = this.last;
        }
        this.size ++;
    }
    public Item removeFirst()                // remove and return the item from the front
    {
        Item item = this.first.item;
        this.first = this.first.next;
        if(this.isEmpty()){
            this.last = null;
        } else {
            this.size --;
        }
        return item;
    }
    public Item removeLast()                 // remove and return the item from the end
    {
        Item item = this.last.item;
        this.last = this.last.next;
        if(this.isEmpty()){
            this.first = null;
        } else {
            this.size --;
        }

        return item;
    }
    public Iterator<Item> iterator()         // return an iterator over items in order from front to end
    {
        return new ListIterator();
    }
    private class ListIterator implements Iterator<Item>
    {
        private Node current = this.first;

        public boolean hasNext(){
            return this.current != null;
        }
        public void remove(){}

        public Item next(){
            Item item = this.current.item;
            current = this.current.next;
            return item;
        }
    }
    public static void main(String[] args)   // unit testing (optional)
    {
        Deque d = new Deque();
        while(!StdIn.isEmpty()){
            char command = StdIn.readChar();
            switch(command) {
                case 'f':
                    d.addFirst(StdIn.readInt());
                    break;
                case 'l':
                    d.addLast(StdIn.readInt());
                    break;
                case 'd':
                    StdOut.println(d.removeFirst());
                    break;
                case 'p':
                    StdOut.println(d.removeLast());
                    break;
                default:
                    for(int item : d){
                        StdOut.println(item);
                    }
            }
        }
    }
}
