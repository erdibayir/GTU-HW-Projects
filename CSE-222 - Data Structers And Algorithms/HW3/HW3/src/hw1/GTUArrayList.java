package hw1;

import java.util.Arrays;

/**
 * Array List Class Implementation
 * @author Erdi Bayır
 * @since 16.04.2021
 */
public class GTUArrayList<E> {
    private E[] theData;
    private static final int INITIAL_CAPACITY = 10;
    private int size = 0;
    private int capacity = 0;

    /**
     * Default Constructor
     */
    public GTUArrayList() {
        capacity = INITIAL_CAPACITY;
        theData = (E[]) new Object[capacity];
    }

    /**
     * Add Method for add element to Array List
     * @param anEntry new element entry
     * @return return true if add operation is successfully
     */
    public boolean add(E anEntry) {
        if (size == capacity) {
            reallocate();
        }
        theData[size] = anEntry;
        size++;
        return true;
    }

    /**
     * Add Method for add element to specific index
     * @param index index of new element will be added
     * @param anEntry new element entry
     */
    public void add(int index, E anEntry) {
        if (index < 0 || index > size) {
            throw new ArrayIndexOutOfBoundsException(index);
        }
        if (size == capacity) {
            reallocate();
        }
        for (int i = size; i > index; i--) {
            theData[i] = theData[i-1];
        }

        theData[index] = anEntry;
        size++;
    }

    /**
     * Return size
     * @return Size of Array List
     */
    public int getSize(){
        return size;
    }

    /**
     * Get specific index in Array List
     * @param index index of returning element
     * @return
     */
    public E get(int index) {
        if (index < 0 || index >= size) {
            throw new ArrayIndexOutOfBoundsException(index);
        }
        return theData[index];
    }

    /**
     * Setter for array list element
     * @param index index of setting element
     * @param newValue new value of index element
     * @return return old value
     */
    public E set(int index, E newValue) {
        if (index < 0 || index >= size) {
            throw new ArrayIndexOutOfBoundsException(index);
        }
        E oldValue = theData[index];
        theData[index] = newValue;
        return oldValue;
    }

    /**
     * Remove Method  for remove element at index from Array List
     * @param index index of the element to be deleted
     * @return return deleted element data
     */
    public E remove(int index) {
        if (index < 0 || index >= size) {
            throw new ArrayIndexOutOfBoundsException(index);
        }
        E returnValue = theData[index];
        for (int i = index + 1; i < size; i++) {
            theData[i-1] = theData[i];
        }
        size--;
        return returnValue;
    }

    /**
     * Remove Method  for remove selected element from Array List
     * @param obj specific object for deleted
     * @return return true if remove operation successfully
     */
    public boolean remove(E obj){
        for(int i = 0 ; i < size ; i++){
            if(get(i).equals(obj)) {
                remove(i);
                return true;
            }
        }
        return false;
    }

    /**
     * Reallocate the Array List if capacity is fully
     */
    private void reallocate() {
        capacity = 2 * capacity;
        theData = Arrays.copyOf(theData, capacity);
    }

    /**
     * Returns the index of the first occurrence of the specified element in this list.
     * @param obj Search Object
     * @return index of object or -1
     */
    public E indexOf(E obj) {
        for (int i = 0; i < size; i++) {
            if(obj.toString().equalsIgnoreCase(theData[i].toString()))
                return (E) theData[i];
        }
        return null;
    }

    /**
     * toString method override
     * @return return all elements in the Array List
     */
    @Override
    public String toString() {
        String allElements = " ";
        for (int i = 0 ; i < size; i++){
            allElements += theData[i]+ " ";
        }
        return allElements;
    }
}
