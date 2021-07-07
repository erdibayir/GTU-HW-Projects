import SBST.AVLTree;
import java.util.Iterator;
/**
 * Navigable Set With AVL Tree  Implementation.It extends Comparable and AVL Tree Class implements Navigable Set interface
 * @param <K> The element type
 */
public class NavigableSetWithAVL<K extends Comparable<K>>  extends AVLTree<K> implements GTUNavigableSet<K>{
    /**
     * AVL Tree for implement NavigableSetWithAVL
     */
    private AVLTree<K> avlTree;
    NavigableSetWithAVL(){
        avlTree = new AVLTree<>();
    }

    /**
     * Descending Iterator For Navigable Set
     * @return Return Descending iterator
     */
    @Override
    public Iterator<K> descendingIterator() {
        System.out.println("No need to implement for NavigableSetWithAVL Class");
        return null;
    }

    /**
     * Insert a key to Navigable Set
     * @param key c
     * @return Return true if the item inserted otherwise false
     */
    @Override
    public boolean insert(K key) {
        return avlTree.add(key);
    }

    /**
     * Delete a key from Navigable Set
     * @param o The object to be deleted
     * @return Return true if the item deleted otherwise false
     */
    @Override
    public boolean delete(Object o) {
        System.out.println("No need to implement for NavigableSetWithAVL Class");
        return false;
    }

    /**
     * Determine head set of the Navigable Set
     * @param toElement parameter for determine final head set element
     * @param inclusive parameter for toElement is inclusive or not
     * @return Return head set for Navigable Set
     */
    @Override
    public GTUNavigableSet<K> headSet(K toElement, boolean inclusive) {
        GTUNavigableSet<K> subSet = (GTUNavigableSet<K>) new NavigableSetWithAVL<K>();
        findSubset(subSet,avlTree.getRoot(),toElement,inclusive,true);
        return subSet;
    }

    /**
     * Determine head set of the Navigable Set
     * @param fromElement parameter for determine first element for tail set
     * @param inclusive parameter for fromElement is inclusive or not
     * @return Return tail set for Navigable Set
     */
    public GTUNavigableSet<K> tailSet(K fromElement, boolean inclusive) {
        GTUNavigableSet<K> subSet = (GTUNavigableSet<K>) new NavigableSetWithAVL<K>();
        findSubset(subSet,avlTree.getRoot(),fromElement,inclusive,false);
        return subSet;
    }

    /**
     * Find subset for head set and tail set
     * @param subSet sub set of the Navigable set
     * @param node current node in Navigable set
     * @param toElement parameter that determine first element for head set or tail set
     * @param inclusive Determine toElement include or not
     * @param isHeadSet Determine sub set is head set or tail set
     */
    private void findSubset(GTUNavigableSet<K> subSet,Node<K> node,K toElement,boolean inclusive,boolean isHeadSet){
        if(node == null)
            return;
        findSubset(subSet,node.getLeft(),toElement,inclusive,isHeadSet);
        if(isHeadSet){
            if(inclusive){
                if (node.getData().compareTo(toElement) <= 0) {
                    subSet.insert(node.getData());
                }
            }
            else {
                if (node.getData().compareTo(toElement) < 0) {
                    subSet.insert(node.getData());
                }
            }
        }
        if(!isHeadSet){
            if(inclusive){
                if (node.getData().compareTo(toElement) >= 0) {
                    subSet.insert(node.getData());
                }
            }
            else {
                if (node.getData().compareTo(toElement) > 0) {
                    subSet.insert(node.getData());
                }
            }

        }
        findSubset(subSet,node.getRight(),toElement,inclusive,isHeadSet);
    }

    /**
     * Create iterator for Navigable set
     * @return Return iterator
     */
    @Override
    public Iterator<K> iterator() {
        return avlTree.iterator();
    }

    /**
     * toString override
     * @return Return Navigable set with String
     */
    @Override
    public String toString() {
        return "NavigableSetWithAVL{\n"+ avlTree.toString() +
                '}';
    }
}