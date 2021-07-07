/**
 * @author Erdi Bayır
 * @since 04.05.2021
 * Binary Search Tree Class implementation.It extends Binary Tree class and Implements Search Tree Class.
 * @param <E> The type of elements held in Binary Search Tree.
 */
public class BinarySearchTree<E extends Comparable<E>> extends BinaryTree<E> implements SearchTree<E> {
    protected boolean addReturn;
    protected E deleteReturn;
    private final int MAX_HEAP = 7;

    /**
     * Find method for Binary Search Tree.
     @param target The Comparable object being sought
     @return The object, if found, otherwise null
     */
    public E find(E target) {
        return find(root, target);
    }

    /** Recursive find method.
     @param localRoot The local subtree's root
     @param target The object being sought
     @return The object, if found, otherwise null
     */
    private E find(Node<HeapClass<E>> localRoot, E target) {
        if (localRoot == null)
            return null;
        boolean search = localRoot.data.search(target);
        assert localRoot.data.peek() != null;
        int compResult = target.compareTo(localRoot.data.peek());
        if(search)
            return target;
        else if (compResult < 0)
            return find(localRoot.left, target);
        else
            return find(localRoot.right, target);
    }

    /**
     * Add element to Binary Search Tree
     * @param item The element to add to Binary Search Tree.
     * @return Return true if add operation is successfully done otherwise false.
     */
    public boolean add(E item) {
        root = add(root, item);
        return addReturn;
    }

    /**
     * Recursive add method.
     * @param localRoot The local subtree's root
     * @param item The object being add
     * @return Return current Heap class node.
     */
    private Node<HeapClass<E>> add(Node<HeapClass<E>> localRoot, E item) {
        if (localRoot == null) {
            addReturn = true;
            Node<HeapClass<E>> newN = new Node<HeapClass<E>>();
            newN.data = new HeapClass<>();
            newN.data.add(item);
            return newN;
        }
        else if (localRoot.data.size() < MAX_HEAP) {
            localRoot.data.add(item);
            addReturn = true;
            return localRoot;
        }
        else if (item.compareTo(localRoot.data.peek()) < 0) {
            localRoot.left = add(localRoot.left, item);
            return localRoot;
        }
        else {
            localRoot.right = add(localRoot.right, item);
            return localRoot;
        }
    }

    /**
     * Find largest child in Binary Search Tree.
     * @param parent The parent node in Tree.
     * @return Return largest node in Binary Search Tree.
     */
    private HeapClass<E> findLargestChild(Node<HeapClass<E>> parent) {
        if (parent.right.right == null) {
            HeapClass<E> returnValue = parent.right.data;
            parent.right = parent.right.left;
            return returnValue;
        }
        else {
            return findLargestChild(parent.right);
        }
    }
    /**
     * Remove element to Binary Search Tree
     * @param target The element to remove from Binary Search Tree.
     * @return Return deleteReturn.
     */
    public E delete(E target) {
        root = delete(root, target);
        return deleteReturn;
    }

    /**
     * Recursive remove method.
     * @param localRoot The local subtree's root
     * @param item The object being remove
     * @return Return current Heap class node.
     */
    private Node<HeapClass<E>> delete(Node<HeapClass<E>> localRoot, E item) {
        if (localRoot == null) {
            deleteReturn = null;
            return localRoot;
        }
        boolean search = localRoot.data.search(item);
        assert localRoot.data.peek() != null;
        int compResult = item.compareTo(localRoot.data.peek());
        if(search){
            localRoot.data.remove(item);
            if(localRoot.data.size() == 0) {
                if (localRoot.left == null) {
                    return localRoot.right;
                } else if (localRoot.right == null) {
                    return localRoot.left;
                } else {
                    if (localRoot.left.right == null) {
                        localRoot.data = localRoot.left.data;
                        localRoot.left = localRoot.left.left;
                        return localRoot;
                    } else {
                        localRoot.data = (HeapClass<E>) findLargestChild(localRoot.left);
                        return localRoot;
                    }
                }
            }
            return localRoot;
        }
        if (compResult < 0) {
            localRoot.left = delete(localRoot.left, item);
            return localRoot;
        }
        else{
            localRoot.right = delete(localRoot.right, item);
            return localRoot;
        }
    }
}


