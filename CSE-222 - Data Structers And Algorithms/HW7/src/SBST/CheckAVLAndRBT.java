package SBST;
import java.util.concurrent.atomic.AtomicInteger;

/**
 *Determine Binary Search Tree is Red Black Tree or AVL Tree
 * @param <E> The type of data to be stored
 */
public class CheckAVLAndRBT<E extends Comparable<E>>{
    /**
     * Determine the item Binary Search Tree is Red Black Tree or AVL Tree
     * @param item The item to be checked
     * @return Return String information about tree
     */
    public String checkTree(BinarySearchTree<E> item){
        AtomicInteger rootMax = new AtomicInteger(0);
        if(isRedBlack(item.root,rootMax) && isAVL(item.root)){
            return "It is a Red Black and AVL Tree!";
        }
        if(isRedBlack(item.root,rootMax)){
            return "It is a Red Black Tree!";
        }
        if(isAVL(item.root)){
            return "It is a AVL Tree!";
        }
        return "It is not AVL or Red Black Tree!";

    }

    /**
     * Determine the item Binary Search Tree is Red Black Tree or not
     * @param root root of the Binary Search Tree
     * @param maxHeight max height of root
     * @return Return true if tree is red black tree otherwise false
     */
    private boolean isRedBlack(BinarySearchTree.Node<E> root, AtomicInteger maxHeight) {
        AtomicInteger leftMaxHeight = new AtomicInteger(0);
        AtomicInteger rightMaxHeight = new AtomicInteger(0);
        int minHeight = 0;

        if (root == null) {
            return true;
        }
        if (isRedBlack(root.left, leftMaxHeight) && isRedBlack(root.right, rightMaxHeight)) {
            if (leftMaxHeight.get() > rightMaxHeight.get()) {
                maxHeight.set(leftMaxHeight.get() + 1);
                minHeight = rightMaxHeight.get() + 1;
            }
            else {
                maxHeight.set(rightMaxHeight.get() + 1);
                minHeight = leftMaxHeight.get() + 1;
            }
            if (maxHeight.get() <= 2 * minHeight)
                return true;
            return false;
        }
        return false;
    }

    /**
     * * Determine the item Binary Search Tree is AVL Tree or not
     * @param root root of the Binary Search Tree
     * @return Return true if tree is AVL tree otherwise false
     */
    private boolean isAVL(BinaryTree.Node<E> root) {
        int heightOfLeft;
        int heightOfRight;
        if (root == null)
            return true;
        heightOfLeft = findHeightAVL(root.left);
        heightOfRight = findHeightAVL(root.right);
        if (isAVL(root.left) && isAVL(root.right) && Math.abs(heightOfLeft - heightOfRight) <= 1)
            return true;

        return false;
    }

    /**
     * Find height of the current node
     * @param node The node to be finded height
     * @return Return height
     */
    private int findHeightAVL(BinaryTree.Node<E> node) {
        if (node == null)
            return 0;
        int heightOfLeft = findHeightAVL(node.left);
        int heightOfRight = findHeightAVL(node.right);
        if(heightOfLeft > heightOfRight)
            return 1 + heightOfLeft;
        else
            return 1 + heightOfRight;
    }
}
