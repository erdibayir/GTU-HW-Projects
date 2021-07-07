package SBST;
/**
 * Red Black Tree Implementation.It extends Comparable and Binary Tree With Rotate Class
 * @param <E> The element type
 */
public class RedBlackTree<E extends Comparable<E>> extends BinarySearchTreeWithRotate<E> {
    /** Flag to indicate success of adding an item */
    private boolean addReturn;

    /**
     * Add method for add element to Red Black Tree
     * @param item The item being inserted
     * @return return added element
     */
    public boolean add(E item){
        if(root == null){
            root = new RedBlackNode<E>(item);
            ((RedBlackNode<E>) root).isRed = false; //root is black
            return true;
        } else {
            root = add((RedBlackNode<E>) root, item);
            ((RedBlackNode<E>) root).isRed = false; //root is black
            return addReturn;
        }
    }

    /**
     * Recursive add method
     * @param localRoot The local root of  Red Black Tree
     * @param item The item to be inserted
     * @return The new local root
     */
    private Node<E> add(RedBlackNode<E> localRoot, E item){
        int compare = item.compareTo(localRoot.data);
        if(compare == 0){
            addReturn = false;
            return localRoot;
        } else if (compare < 0){
            if(localRoot.left == null){
                localRoot.left = new RedBlackNode<E>(item);
                addReturn = true;
                return localRoot;
            } else {
                moveBlackDown(localRoot);
                localRoot.left = add((RedBlackNode<E>) localRoot.left, item);
                if(((RedBlackNode<E>) localRoot.left).isRed){
                    if(localRoot.left.left != null
                            && ((RedBlackNode<E>) localRoot.left.left).isRed){
                        ((RedBlackNode<E>) localRoot.left).isRed = false;
                        localRoot.isRed = true;
                        return rotateRight(localRoot);
                    } else if (localRoot.left.right != null
                            && ((RedBlackNode<E>) localRoot.left.right).isRed){
                        localRoot.left = rotateLeft(localRoot.left);
                        ((RedBlackNode<E>) localRoot.left).isRed = false;
                        localRoot.isRed = true;
                        return rotateRight(localRoot);
                    }
                }
                return localRoot;
            }
        } else {
            if(localRoot.right == null){
                localRoot.right = new RedBlackNode<E>(item);
                addReturn = true;
                return localRoot;
            } else {
                moveBlackDown(localRoot);
                localRoot.right = add((RedBlackNode<E>) localRoot.right, item);
                if(((RedBlackNode<E>) localRoot.right).isRed){
                    if(localRoot.right.right != null
                            && ((RedBlackNode<E>) localRoot.right.right).isRed){
                        ((RedBlackNode<E>) localRoot.right).isRed = false;
                        localRoot.isRed = true;
                        return rotateLeft(localRoot);
                    } else if (localRoot.right.left != null
                            && ((RedBlackNode<E>) localRoot.right.left).isRed){
                        localRoot.right = rotateRight(localRoot.right);
                        ((RedBlackNode<E>) localRoot.right).isRed = false;
                        localRoot.isRed = true;
                        return rotateLeft(localRoot);
                    }
                }
                return localRoot;
            }
        }
    }

    /**
     * Check to see whether both children of the given node are red.
     * If so, make them black and change the localRoot's color to red.
     * @param localRoot The node to check whether both children are red or not
     */
    private void moveBlackDown(RedBlackNode<E> localRoot){
        if(localRoot.left != null && localRoot.right != null){ //If a child is null, it is black
            if(((RedBlackNode<E>) localRoot.left).isRed
                    && ((RedBlackNode<E>) localRoot.right).isRed){ //if both children are red, swap colors
                ((RedBlackNode<E>) localRoot.left).isRed = false;
                ((RedBlackNode<E>) localRoot.right).isRed = false;
                localRoot.isRed = true;
            }
        }
    }

    /**
     * Class to represent a Red-Black node
     * @author Jacob / Koffman and Wolfgang
     *
     * @param <E> The data type of items stored in the node. Must be Comparable
     */
    private static class RedBlackNode<E> extends Node<E> {

        //Additional Data Fields
        /**
         * Color indicator; true if red, false if black
         */
        private boolean isRed;

        /**
         * Constructor to create a node with the default color of red with the given data
         * @param data The data item to be stored in the node
         */
        public RedBlackNode(E data) {
            super(data);
            isRed = true;
        }
        /**
         * Return a String representation of the node
         * @return A String representation of the node
         */
        @Override
        public String toString(){
            if(isRed){
                return "Red: " + super.toString();
            } else {
                return "Black: " + super.toString();
            }
        }

    }
}