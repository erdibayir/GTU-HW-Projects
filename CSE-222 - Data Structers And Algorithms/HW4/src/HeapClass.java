import java.util.Arrays;
import java.util.PriorityQueue;

/**
 * @author Erdi Bayır
 * @since 04.05.2021
 * Heap Class Implementation.It extends from Priority Queue Class.
 * @param <E> The type of elements held in Heap
 */
public class HeapClass<E> extends PriorityQueue<E>{
    /**
     * Default Constructor.It calls super class constructor.
     */
    HeapClass(){
        super();
    }

    /**
     * Add element to Heap
     * @param e The element to add to Heap.
     * @return Return true if add operation is successfully done otherwise false.
     */
    @Override
    public boolean add(E e) {
        if(!search(e))
            return super.add(e);
        return false;
    }

    /**
     * Remove element from Heap
     * @param o The element to remove from Heap.
     * @return Return true if remove operation is successfully done otherwise false.
     */
    @Override
    public boolean remove(Object o) {
        return super.remove(o);
    }

    /**
     * Removing ith largest element from the Heap
     * @param i ith largest element index
     * @return Return removed element if remove operation is successfully done otherwise null.
     */
    public Object removingLargestI(int i){
       Object[] temp =super.toArray();
       Arrays.sort(temp);
       Object deleted = temp[size()-i];
       if(size() >= i) {
           remove(temp[size() - i]);
           return  deleted;
       }
        return null;
    }

    /**
     * Set the value of the last element returned by the next methods
     * @param newData New data for set element in Heap
     */
    public void setNextValue(E newData){
        if(super.iterator().hasNext()) {
            remove(super.iterator().next());
            add(newData);
        }
    }

    /**
     * Search for an element
     * @param o The element to search in Heap.
     * @return Return true if search operation is successfully done otherwise false.
     */
    public boolean search(Object o) {
        return super.contains(o);
    }

    /**
     * Merge with another heap
     * @param h1 The heap object to merge with current Heap
     * @return Return Heap Object.
     */
    public HeapClass<E> merge(HeapClass<E> h1){
        this.addAll(h1);
        return this;

    }

    /**
     * toString method override
     * @return Return Heap elements as string
     */
    @Override
    public String toString() {
        return super.toString();
    }
}
