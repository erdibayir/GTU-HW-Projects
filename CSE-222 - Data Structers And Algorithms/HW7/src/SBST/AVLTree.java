package SBST;
import java.util.Iterator;
import java.util.Stack;

/**
 *  AVL Tree Implementation. Self -Balancing binary search tree using the algorithm defined
 *  by Adelson- Veils and Landis.
 * @param <E> The element type
 */
public class AVLTree<E extends Comparable<E>> extends BinarySearchTreeWithRotate<E> {
    /** Flag to indicate that height of tree has increased. */
    private boolean increase;
    /**
     * Return added element if true otherwise false*/
    private boolean addReturn;

    /**
     * Add method override for add element to AVL
     * @param item The item being inserted
     * @return return true if add operation is done otherwise false
     */
    @Override
    public boolean add(E item){
        increase = false;
        root = add((AVLNode<E>) root, item);
        return addReturn;
    }

    /**
     * Create Iterator for AVL Tree
     * @return Return new AVL Iterator
     */
    public Iterator<E> iterator() {
        return new AVLIterator();
    }
    /**
     * Recursive add method. Inserts the given object into the tree.
     * post: addReturn is set to true if the item is inserted,
     * 		 false if the item is already in the tree
     * @param localRoot The local root of the subtree
     * @param item The object to be inserted
     * @return The new local root of the subtree with the item inserted
     */
    private AVLNode<E> add(AVLNode<E> localRoot, E item){
        if(localRoot == null){
            addReturn = true;
            increase = true;
            return new AVLNode<E>(item);
        }
        int compare = item.compareTo(localRoot.data);
        if(compare == 0){
            increase = false;
            addReturn = false;
            return localRoot;
        }
        if(compare < 0){
            localRoot.left = add((AVLNode<E>) localRoot.left, item);
            if(increase){
                decrementBalance(localRoot);
                if(localRoot.balance < AVLNode.LEFT_HEAVY){
                    increase = false;
                    return rebalanceLeft(localRoot);
                }
            }
            return localRoot;
        }
        else {
            localRoot.right = add((AVLNode<E>) localRoot.right, item);
            if(increase){
                incrementBalance(localRoot);
                if(localRoot.balance > AVLNode.RIGHT_HEAVY){
                    increase = false;
                    return rebalanceRight(localRoot);
                }
            }
            return localRoot;
        }
    }
    /**
     * Method to re-balance left
     * pre: localRoot is the root of an AVL subtree that is critically left-heavy
     * post: balance is restored
     * @param localRoot Root of the AVL subtree that needs re-balancing
     * @return a new localRoot
     */
    private AVLNode<E> rebalanceLeft(AVLNode<E> localRoot){
        AVLNode<E> leftChild = (AVLNode<E>) localRoot.left;
        if(leftChild.balance > AVLNode.BALANCED){
            AVLNode<E> leftRightChild = (AVLNode<E>) leftChild.right;
            if(leftRightChild.balance < AVLNode.BALANCED){
                leftChild.balance = AVLNode.BALANCED;
                leftRightChild.balance = AVLNode.BALANCED;
                localRoot.balance = AVLNode.RIGHT_HEAVY;
            } else if (leftRightChild.balance > AVLNode.BALANCED){
                leftChild.balance = AVLNode.LEFT_HEAVY;
                leftRightChild.balance = AVLNode.BALANCED;
                localRoot.balance = AVLNode.BALANCED;
            } else {
                leftChild.balance = AVLNode.BALANCED;
                localRoot.balance = AVLNode.BALANCED;
            }
            localRoot.left = rotateLeft(leftChild);
        } else {
            leftChild.balance = AVLNode.BALANCED;
            localRoot.balance = AVLNode.BALANCED;
        }
        return (AVLNode<E>) rotateRight(localRoot);
    }

    /**
     * Method to re-balance right
     * pre: localRoot is the root of an AVL subtree that is critically right-heavy
     * post: balance is restored
     * @param localRoot Root of the AVL subtree that needs re-balancing
     * @return a new localRoot
     */
    private AVLNode<E> rebalanceRight(AVLNode<E> localRoot){
        AVLNode<E> rightChild = (AVLNode<E>) localRoot.right;
        if(rightChild.balance < AVLNode.BALANCED){
            AVLNode<E> RightLeftChild = (AVLNode<E>) rightChild.left;
            if(RightLeftChild.balance < AVLNode.BALANCED){
                rightChild.balance = AVLNode.RIGHT_HEAVY;
                RightLeftChild.balance = AVLNode.BALANCED;
                localRoot.balance = AVLNode.BALANCED;
            } else if (RightLeftChild.balance > AVLNode.BALANCED){
                rightChild.balance = AVLNode.BALANCED;
                RightLeftChild.balance = AVLNode.BALANCED;
                localRoot.balance = AVLNode.LEFT_HEAVY;
            } else {
                rightChild.balance = AVLNode.BALANCED;
                localRoot.balance = AVLNode.BALANCED;
            }
            localRoot.right = rotateRight(rightChild);
        } else {
            rightChild.balance = AVLNode.BALANCED;
            localRoot.balance = AVLNode.BALANCED;
        }
        return (AVLNode<E>) rotateLeft(localRoot);
    }
    /**
     * Decrement the balance of the given node
     * @param node The node to decrement the balance of
     */
    private void decrementBalance(AVLNode<E> node){
        node.balance--;
        if(node.balance == AVLNode.BALANCED){
            increase = false;
        }
    }

    /**
     * Increment the balance of the given node
     * @param node The node to increment the balance of
     */
    private void incrementBalance(AVLNode<E> node){
        node.balance++;
        if(node.balance == AVLNode.BALANCED){
            increase = false;
        }
    }

    /**
     * Class to represent an AVL Node.
     * It extends the SBST.BinaryTree.Node by adding the balance field
     * @author Jacob / Koffman and Wolfgang
     *
     * @param <E> The data type of objects stored in the node. Must be a Comparable object.
     */
    private static class AVLNode<E> extends BinaryTree.Node<E> {

        public static final int LEFT_HEAVY = -1;
        public static final int BALANCED = 0;
        public static final int RIGHT_HEAVY = 1;
        private int balance;
        /**
         * Construct a node with the given item as the data field
         * @param data The data field
         */
        public AVLNode(E data) {
            super(data);
            balance = BALANCED;
        }

        /**
         * Return a string representation of this object.
         * The balance value is appended to the contents
         * @return String representation of this object
         */
        public String toString(){
            return balance + ": " + super.toString();
        }

    }

    /**
     * Iterator CLass Implemantation for AVL Tree.Implements Iterator Interface
     */
    private class AVLIterator implements Iterator<E> {
        /**
         * Keep tree elements in stack
         */
        private Stack<Node<E>> stack;

        /**
         * Iterator constructor to push root in stack
         */
        AVLIterator(){
            stack = new Stack<>();
            pushToStack(root);
        }

        /**
         * Push current tree to stack with use root
         * @param root current tree root
         */
        private void pushToStack(Node<E> root){
            if(root != null){
                stack.push(root);
                pushToStack(root.left);
            }
        }

        /**
         * Return true if iterator has next otherwise false
         * @return Return true if iterator has next otherwise false
         */
        @Override
        public boolean hasNext() {
            return !stack.isEmpty();
        }

        /**
         * Return next element in AVLTree with iterator
         * @return Return next element in AVLTree if has next otherwise null
         */
        @Override
        public E next() {
            if(hasNext()) {
                Node<E> nextNode = stack.pop();
                pushToStack(nextNode.right);
                return nextNode.data;
            }
            return null;
        }
    }
}