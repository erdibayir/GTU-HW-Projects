package SBST;
/**
 * Binary Search Tree Implementation.It extends Comparable and Binary Tree Class implements Search Tree interface
 * @param <E> The element type
 */
public class BinarySearchTree<E extends Comparable<E>> extends BinaryTree<E> implements SearchTree<E> {
    /**
     * Return true if add operation successful otherwise false
     */
    protected boolean addReturn;
    /** Return value from the public delete method*/
    protected E deleteReturn;
    @Override
    public String toString(){ return super.toString(); }
    /**
     * Starter method add
     * pre: The object to be inserted must implement the Comparable interface
     * @param item The item being inserted
     * @return true if the object is inserted, false if the object already exists in the tree
     */
    public boolean add(E item){
        root = add(root, item);
        return addReturn;
    }
    /**
     * Recursive add method
     * post: The data field addReturn is set to true if the item is added to the tree, false if the item is already in the tree
     * @param localRoot The local root of the subtree
     * @param item The object to be inserted
     * @return The new local root that now contains the inserted item
     */
    private BinaryTree.Node<E> add(BinaryTree.Node<E> localRoot, E item){
        if(localRoot == null){
            addReturn = true;
            return new BinaryTree.Node<E>(item);
        }
        int compare = item.compareTo(localRoot.data);
        if(compare == 0){
            addReturn = false;
            return localRoot;
        }
        else if (compare < 0){
            localRoot.left = add(localRoot.left, item);
            return localRoot;
        }
        else{
            localRoot.right = add(localRoot.right, item);
            return localRoot;
        }
    }

    /**
     * Return true if target contains in BST otherwise false
     * @param target Search target
     * @return Return true if target contains in BST otherwise false
     */
    public boolean contains(E target){
        return find(target) != null;
    }

    /**
     * Starter method find.
     * pre: The target object must implement the Comparable interface.
     * @param target The Comparable object being sought
     * @return The object if found, otherwise null
     */
    public E find(E target){ return find(root, target); }

    /**
     * Recursive find method
     * @param localRoot The local subtree's root
     * @param target The object being sought
     * @return The object, if found, otherwise null
     */
    private E find(BinaryTree.Node<E> localRoot, E target){
        if(localRoot == null)
            return null;
        int compResult = target.compareTo(localRoot.data);
        if(compResult == 0)
            return localRoot.data;
        else if (compResult < 0)
            return find(localRoot.left, target);
        else
            return find(localRoot.right, target);
    }
    /**
     * Starter method delete
     * post: The object is not in the tree
     * @param target The object to be deleted
     * @return The object deleted from the tree or null if the object was not in the tree
     * @throws ClassCastException if target does not implement Comparable
     */
    public E delete(E target){
        root = delete(root, target);
        return deleteReturn;
    }

    /**
     * Recursive delete method
     * post: The item is not in the tree;
     * 		 deleteReturn is equal to the deleted item
     * 		 as it was stored in the tree or null
     *		 if the item was not found
     * @param localRoot The root of the current subtree
     * @param item The item to be deleted
     * @return The modified local root that does not contain the item
     */
    private BinaryTree.Node<E> delete(BinaryTree.Node<E> localRoot, E item){
        if(localRoot == null){
            deleteReturn = null;
            return localRoot;
        }
        int compResult = item.compareTo(localRoot.data);
        if(compResult < 0){
            localRoot.left = delete(localRoot.left, item);
            return localRoot;
        }
        else if(compResult > 0){
            localRoot.right = delete(localRoot.right, item);
            return localRoot;
        }else{
            deleteReturn = localRoot.data;
            if(localRoot.left == null)
                return localRoot.right;
            else if (localRoot.right == null)
                return localRoot.left;
            else{

                if(localRoot.left.right == null){
                    localRoot.data = localRoot.left.data;
                    localRoot.left = localRoot.left.left;
                    return localRoot;
                }else{
                    localRoot.data = findLargestChild(localRoot.left);
                    return localRoot;
                }
            }
        }
    }

    /**
     * Find the node that is the inorder predecessor and replace it with its left child (if any)
     * post: the inorder predecessor is removed from the tree
     * warning: only call on nodes with known right children
     * @param parent The parent of possible inorder predecessor
     * @return The data in the inorder predecessor
     */
    private E findLargestChild(BinaryTree.Node<E> parent){
        if(parent.right.right == null){
            E returnValue = parent.right.data;
            parent.right = parent.right.left;
            return returnValue;
        }else
            return findLargestChild(parent.right);
    }

    /**
     * Return true if target is successfully remove otherwise false
     * @param target Remove target
     * @return Return true if target is successfully remove otherwise false
     */
    public boolean remove(E target){
        delete(target);
        return deleteReturn == target;
    }
    /**
     * Find the node that is the smallest child in a subtree
     * warning: only use if it is known that the parent has a left child
     * @param parent The root of the subtree
     * @return The smallest child in the subtree
     */
    private E findSmallestChild(BinaryTree.Node<E> parent){
        if(parent.left.left == null){
            E returnValue = parent.left.data;
            parent.left = parent.left.right;
            return returnValue;
        }else
            return findSmallestChild(parent.left);
    }


}