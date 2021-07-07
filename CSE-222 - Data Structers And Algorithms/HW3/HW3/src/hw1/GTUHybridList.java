package hw1;
/**
 * Hybrid List Class Implementation
 * @author Erdi Bayır
 * @since 16.04.2021
 */
public class GTUHybridList<E>{
    private GTULinkedList<GTUArrayList<E>> HList = new GTULinkedList<GTUArrayList<E>>();
    private static final int MAX_NUMBER = 5;
    int NodeSize;

    /**
     * Default Constructor for Hybrid List.
     */
    GTUHybridList(){
        NodeSize = 0;
    }

    /**
     * Get element at position index.
     * @param index Position of item
     * @return The item at index
     */
    public E get(int index){
        int choosenNode = index / MAX_NUMBER;
        int indexOfArrList = index % MAX_NUMBER;
        return HList.get(choosenNode).get(indexOfArrList);
    }
    /**
     * Add a new item to Hybrid list
     * @param obj The item to be added
     */
    public void add(E obj){
        if(HList.isEmpty()){
            GTUArrayList<E> newArr = new GTUArrayList<E>();
            newArr.add(obj);
            HList.add(newArr);
            NodeSize++;

        }
        else if(lastAL().getSize() < MAX_NUMBER){
            lastAL().add(obj);
        }
        else{
            GTUArrayList<E> newArr = new GTUArrayList<E>();
            newArr.add(obj);
            HList.add(newArr);
            NodeSize++;
        }
    }

    /**
     * Return last node in Hybrid List
     * @return Return last node
     */
    public GTUArrayList<E> lastAL(){
        try {
            return HList.getLast();
        }
        catch (NullPointerException e){
            return null;
        }
    }

    /**
     * Return last element in Hybrid List
     * @return return true if last element removed
     */
    public boolean remove(){
        System.out.println("Current Size:" + lastAL().getSize());
        if (HList.isEmpty())
            return false;
        else {
            if(lastAL().getSize() == 1){
                HList.remove(HList.size() -1 );
                NodeSize--;
            }
            else {
                lastAL().remove(lastAL().getSize() - 1);
            }
            return true;
        }
    }
    /**
     * Remove item from Hybrid list at the index
     * @param index position of removed item
     * @return return remove data
     */
    public E remove(int index ){
        int choosenNode = index / MAX_NUMBER;
        int indexOfArrList = index % MAX_NUMBER;
        return HList.get(choosenNode).remove(indexOfArrList);
    }
    public boolean remove(E obj){
        for(int i = 0 ; i < size() ; i++){
            for(int j = 0 ; j < HList.get(i).getSize(); j++) {
                GTUArrayList<E> temp = HList.get(i);
                if(temp.get(j).equals(obj)) {
                    remove(i * 5 + j);
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * toString Override method
     * @return return all elements with string
     */
    @Override
    public String toString() {
        String allElements = "";
        for(int i = 0 ; i < HList.size(); i++){
            allElements += HList.get(i).toString();
        }
        return allElements;
    }

    /**
     * Return size of Hybrid List
     * @return Size of Hybrid List
     */
    public int size(){
        if(lastAL() == null)
            return ((NodeSize - 1) * 5);
        else
            return ((NodeSize - 1) * 5) + lastAL().getSize();
    }
}
