package hw1;

/**
 * MyArray class is container for array.It keeps array and its operations.
 * @author Erdi Bayir
 * @since 13.03.2021
 */
public class MyArray<T> {

    private int size;
    private int initialCapacity;
    protected Object[] array;

    /**
     * Default Constructor for create array of object and initialize size and capacity.
     */
    public MyArray() {
        size = 0;
        initialCapacity = 10;
        array = new Object[initialCapacity];

    }

    /**
     * Setter of size
     * @param size Array size
     */
    public void setSize(int size) {
        this.size = size;
    }

    /**
     * Setter of initialCapacity
     * @param initialCapacity initial capacity of array
     */
    public void setInitialCapacity(int initialCapacity) {
        this.initialCapacity = initialCapacity;
    }

    /**
     * Setter of Object Array
     * @param array Object Array
     */
    public void setArray(Object[] array) {
        this.array = array;
    }

    /**
     * Getter of Object Array
     * @return Object Array
     */
    public Object[] getArray() {
        return array;
    }

    /**
     * Getter of Size
     * @return size of array
     */
    public int getSize() {
        return size;
    }

    /**
     * Getter of initial capacity
     * @return initial capacity of array
     */
    public int getInitialCapacity() {
        return initialCapacity;
    }

    /**
     * Return array element at index
     * @param index selected index of array
     * @return array element at index
     */
    public Object getArrayElement(int index){
        return array[index];
    }

    /**
     * Add element to array and increased size if capacity not enough increase capacity too
     * @param newObject new object of array
     * @return return true if added operation is successfully
     */
    public boolean add (T newObject) {
        if (array == null)
            array = new Object[initialCapacity];

        if (this.initialCapacity <= size) {
            initialCapacity+=10;
            Object[] newArray = new Object[initialCapacity];
            for(int i = 0; i < size; i++)
                newArray[i] = array[i];

            array= (Object[]) newArray;
        }
        array[size]=newObject;
        size++;

        return true;
    }

    /**
     * Remove element from array and decreased size of array
     * @param value object to be deleted
     */
    public  void delete (T value) {
        int index = 0;
        for(int i=0; i<size; i++) {
            if (value == array[i])
                index = i;
        }
        for ( int i = index; i!= size; i++)
            array[i]=array[i+1];
        --size;
    }

    /**
     * Search object in array and return founded object
     * @param searchObject search object in array
     * @return founded object if search operation is done successfully
     */
    public T search(T searchObject) {
        for (int i = 0; i < size; i++) {
            if(searchObject.toString().equalsIgnoreCase(array[i].toString()))
                return (T) array[i];
        }
        return null;
    }

    /**
     * toString override for return array elements
     * @return all element as string
     */
    @Override
    public String toString(){
        String allElements = " ";
        for (int i = 0 ; i < size; i++){
            allElements += array[i]+ " ";
        }
        return allElements;
    }
}
