import java.util.*;

/**
 * Navigable Set With Skip List Implementation.It extends Comparable and implements Navigable Set interface
 * @param <K> The element type
 */
public class NavigableSetWithSkipList<K extends Comparable<K>> implements GTUNavigableSet<K> {
    /**
     * Skip List for implement NavigableSetWithAVL
     */
    private SkipList<K> skipList;

    NavigableSetWithSkipList(){
        skipList = new SkipList<>();
    }

    /**
     * Descending Iterator For Navigable Set
     * @return Return Descending iterator
     */
    @Override
    public Iterator<K> descendingIterator() {
        return skipList.descendingIterator();
    }
    /**
     * Insert a key to Navigable Set
     * @param key c
     * @return Return true if the item inserted otherwise false
     */
    @Override
    public boolean insert(K key) {
        return skipList.add(key);
    }

    /**
     * Delete a key from Navigable Set
     * @param o The object to be deleted
     * @return Return true if the item deleted otherwise false
     */
    @Override
    public boolean delete(Object o) {
        return skipList.remove((K) o);
    }

    /**
     * Determine head set of the Navigable Set
     * @param toElement parameter for determine final head set element
     * @param inclusive parameter for toElement is inclusive or not
     * @return Return head set for Navigable Set
     */
    @Override
    public GTUNavigableSet<K> headSet(K toElement, boolean inclusive) {
        System.out.println("No need to implement for NavigableSetWithSkipList Class");
        return null;
    }

    /**
     * Determine head set of the Navigable Set
     * @param fromElement parameter for determine first element for tail set
     * @param inclusive parameter for fromElement is inclusive or not
     * @return Return tail set for Navigable Set
     */
    @Override
    public GTUNavigableSet<K> tailSet(K fromElement, boolean inclusive) {
        System.out.println("No need to implement for NavigableSetWithSkipList Class");
        return null;
    }

    /**
     * Create iterator for Navigable set
     * @return Return iterator
     */
    @Override
    public Iterator<K> iterator() {
        System.out.println("No need to implement for NavigableSetWithSkipList Class");
        return null;
    }

    /**
     * toString method override
     * @return Return Navigable set as String
     */
    @Override
    public String toString() {
        return "NavigableSetSkip{\n" + skipList.toString() + '}';
    }

    /**
     * SkipList class implementation
     * @param <E> The type of data to be stored
     */
    static class SkipList<E extends Comparable<E>> {
        int maxLevel;
        int maxCap;
        static final double LOG2 = Math.log(2.0);
        final static Random rand = new Random();
        SLNode<E> head;
        static final int min = Integer.MIN_VALUE;
        int size;
        public SkipList(){
            size = 0;
            maxLevel = 0;
            maxCap = computeMaxCap(maxLevel);
            head = new SLNode(maxLevel, min);
        }

        /**
         * SkipNode implemantation
         * @param <E> The type of data to be stored
         */
        private static class SLNode<E> {
            public SLNode<E>[] links;
            E data;

            public SLNode(int m, E data) {
                links = (SLNode<E>[]) new SLNode[m];
                this.data = data;
            }
            public String toString(){
                return "Data = " + data + "\n" + "Level Of Data: " + links.length + "\n";
            }
        }
        /**
         * Compute the max cap with given level
         * @param maxLevel given level
         * @return max capacity
         */
        private int computeMaxCap( int maxLevel) {
            return (int) (Math.pow(2, maxLevel) - 1);
        }
        /**
         * Method to generate a logarithmic distributed integer between 1 and maxLevel.
         *  I.E. 1/2 of the values are 1, 1/4 are 2, etc.
         * @return a random logarithmic distributed int between 1 and maxLevel
         */
        private int logRandom() {
            int r = rand.nextInt(maxCap);
            int k = (int) (Math.log(r + 1) / LOG2);
            if (k > maxLevel - 1) {
                k = maxLevel - 1;
            }
            return maxLevel - k;
        }

        /**
         * Create Descending Iterator
         * @return Return Descending Iterator
         */
        public SkipListIterator descendingIterator() {
            return new SkipListIterator(true);
        }

        /**
         * SkipListIterator Implementation
         */
        private class SkipListIterator implements Iterator<E>{
            private SLNode<E> current;
            int currentIndex;
            boolean isDescending;
            SkipListIterator(boolean isDescending){
                this.isDescending = isDescending;
                if(isDescending) {
                    if(size!= 0) {
                        current = get(size - 1);
                        currentIndex = size - 1;
                    }
                }
                else{
                    if(size!= 0) {
                        current = head;
                        currentIndex = 0;
                    }
                }
            }
            /**
             * Return true if iterator has next otherwise false
             * @return Return true if iterator has next otherwise false
             */
            @Override
            public boolean hasNext() {
                if(currentIndex >= 1 && currentIndex < size)
                    return true;
                return false;
            }
            /**
             * Return next element in SkipList with iterator
             * @return Return next element in SkipList if has next otherwise null
             */
            @Override
            public E next() {
                if (hasNext() && isDescending){
                    current = get(currentIndex -1);
                    currentIndex--;
                    return (E) current.data;
                }
                if(hasNext()){
                    current = get(currentIndex + 1);
                    currentIndex++;
                    return (E) current.data;
                }
                return null;
            }

        }

        /**
         * Get current index element
         * @param index the index to be searched
         * @return Return current index element
         */
        public SLNode<E> get(int index) {
            if (index <0 || index > size-1)
            {
                throw new NoSuchElementException();
            }
            SLNode<E> current = head;
            for (int i =0;i<index;i++)
            {
                current=current.links[0];
            }
            return current.links[0];
        }

        /**
         * Search item in Skip List
         * @param item The item to be searched
         * @return Return searched element
         */
        private SLNode<E>[] search(E item) {
            SLNode<E>[] pred = (SLNode<E>[]) new SLNode[maxLevel];
            SLNode<E> current = head;
            for (int i = current.links.length - 1; i >= 0; i--) {
                while (current.links[i] != null
                        && current.links[i].data.compareTo(item) < 0) {
                    current = current.links[i];
                }
                pred[i] = current;
            }
            return pred;
        }

        /**
         * Inserts the given item
         * @param item The item to add
         * @return true as the item is added
         */
        public boolean add(E item ){

            SLNode<E>[] pred = search(item);

            if( pred.length != 0 && pred[0].links[0] != null
                    && (pred[0].links[0].data.compareTo( item ) == 0) ) {
                return false;
            }
            ++size;
            if( size > maxCap ){
                ++maxLevel;
                maxCap = computeMaxCap(maxLevel);
                head.links = Arrays.copyOf(head.links, maxLevel);
                pred = Arrays.copyOf(pred, maxLevel);
                pred[maxLevel - 1] = head;
            }

            SLNode<E> newNode = new SLNode<>( logRandom() , item);
            for(int i = 0; i < newNode.links.length; i++){
                newNode.links[i] = pred[i].links[i];
                pred[i].links[i] = newNode;
            }

            return true;
        }
        /**
         * Removes an instance of the given item
         * @param item The item to remove
         * @return true if the item is removed, false if the item is not in the list
         */
        public boolean remove(E item) {
            SLNode<E>[] pred = search(item);
            if(pred.length == 0 || pred[0].links[0] == null
                    || pred[0].links[0].data.compareTo(item) != 0) {
                return false;
            }
            size--;
            SLNode<E> deleteNode = pred[0];
            for(int i = 0; i < deleteNode.links.length; i++){
                if(pred[i].links[i] != null) {
                    pred[i].links[i] = pred[i].links[i].links[i];
                }
            }

            return true;
        }

        /**
         * toString method override
         * @return Return Skip List as String
         */
        public String toString( ) {

            if( size == 0 )
                return "No such element in the skip-list";

            StringBuilder str = new StringBuilder();

            SLNode<E> tempHead = head;

            for( int i = 0 ; i < size ; ++i  ) {

                tempHead = tempHead.links[0];
                str.append( tempHead.toString() ).append("\n");

            }

            return str.toString();
        }
    }
}

