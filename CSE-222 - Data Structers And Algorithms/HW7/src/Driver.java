import SBST.*;
import java.util.Iterator;

/**
 * Driver Class for test all parts
 */
public class Driver {
    public static void main(String[] args) {
        testPart1();
        testPart2();
        testPart3();
    }
    public static void testPart1(){
        System.out.println("--------- Test Part 1 ---------");
        System.out.println("------------ NavigableSet With Skip List Test ------------\n\n");
        System.out.println("Create object from NavigableSetWithSkipList...");
        NavigableSetWithSkipList<Integer> navSet1 = new NavigableSetWithSkipList<>();
        navSet1.insert(5);
        navSet1.insert(12);
        navSet1.insert(51);
        navSet1.insert(3);
        navSet1.insert(2);
        navSet1.insert(34);
        navSet1.insert(45);
        navSet1.insert(12);
        navSet1.insert(112);
        navSet1.insert(1);
        navSet1.insert(6);
        System.out.println("Insert Some Elements to Navigable Set...");
        System.out.println(navSet1.toString());
        Iterator<Integer> descendingIterator = navSet1.descendingIterator();
        System.out.println("----Descending Iterator Test----");
        while (descendingIterator.hasNext()) {
            System.out.println("Has next = " + descendingIterator.hasNext());
            System.out.println("Next:" + descendingIterator.next());
        }
        System.out.println("Delete Method Test With Delete Some elements");
        System.out.println("---Delete 12---");
        navSet1.delete(12);
        System.out.println(navSet1.toString());
        System.out.println("---Delete 1---");
        navSet1.delete(1);
        System.out.println(navSet1.toString());
        System.out.println("---Delete 112---");
        navSet1.delete(112);
        System.out.println(navSet1.toString());

        System.out.println("\n\n------------ NavigableSet With AVL Tree Test ------------\n\n");
        System.out.println("Create object from NavigableSetWithAVL...");
        NavigableSetWithAVL<Integer> navSet2 = new NavigableSetWithAVL<>();
        navSet2.insert(13);
        navSet2.insert(5);
        navSet2.insert(27);
        navSet2.insert(12);
        navSet2.insert(19);
        navSet2.insert(1);
        navSet2.insert(16);
        navSet2.insert(5);
        navSet2.insert(7);
        System.out.println("Insert Some Elements to Navigable Set...");
        System.out.println(navSet2.toString());
        Iterator<Integer> newIterator = navSet2.iterator();
        System.out.println("----Iterator Test----");
        while (newIterator.hasNext()) {
            System.out.println("Has next = " + newIterator.hasNext());
            System.out.println("Next:" + newIterator.next());
        }
        System.out.println("----HeadSet and TailSet Test----");
        System.out.println("Head set to Element : 19 and inclusive : true -> HeadSet is:");
        System.out.println(navSet2.headSet(19,true));
        System.out.println("Head set to Element : 16 and inclusive : false -> HeadSet is:");
        System.out.println(navSet2.headSet(16,false));
        System.out.println("Head set to Element : 8 and inclusive : true -> HeadSet is:");
        System.out.println(navSet2.headSet(8,true));
        System.out.println("Tail set from Element : 12 and inclusive : true -> TailSet is:");
        System.out.println(navSet2.tailSet(12,true));
        System.out.println("Tail set from Element : 5 and inclusive : false -> TailSet is:");
        System.out.println(navSet2.tailSet(5,false));
        System.out.println("Tail set from Element : 25 and inclusive : true -> TailSet is:");
        System.out.println(navSet2.tailSet(25,true));
    }
    public static void testPart2(){
        System.out.println("--------- Test Part 2 ---------");
        System.out.println("--------- Create Binary Search Trees And Check is AVL or Red Black Tree ---------");
        CheckAVLAndRBT<Integer> newCheck = new CheckAVLAndRBT<>();
        BinarySearchTree<Integer> binaryTree1 = new BinarySearchTree<>();
        binaryTree1.add(7);
        binaryTree1.add(3);
        binaryTree1.add(18);
        binaryTree1.add(10);
        binaryTree1.add(22);
        binaryTree1.add(8);
        binaryTree1.add(11);
        binaryTree1.add(26);
        System.out.println(binaryTree1.toString());
        System.out.println(newCheck.checkTree(binaryTree1));

        BinarySearchTree<Integer> binaryTree2 = new BinarySearchTree<>();
        binaryTree2.add(12);
        binaryTree2.add(8);
        binaryTree2.add(18);
        binaryTree2.add(5);
        binaryTree2.add(9);
        binaryTree2.add(4);
        binaryTree2.add(2);
        System.out.println(binaryTree2.toString());
        System.out.println(newCheck.checkTree(binaryTree2));

        BinarySearchTree<Integer> binaryTree3 = new BinarySearchTree<>();
        binaryTree3.add(5);
        binaryTree3.add(4);
        binaryTree3.add(15);
        binaryTree3.add(2);
        binaryTree3.add(19);
        binaryTree3.add(14);
        System.out.println(binaryTree3.toString());
        System.out.println(newCheck.checkTree(binaryTree3));

        BinarySearchTree<Integer> binaryTree4 = new BinarySearchTree<>();
        binaryTree4.add(40);
        binaryTree4.add(42);
        binaryTree4.add(35);
        binaryTree4.add(27);
        binaryTree4.add(38);
        binaryTree4.add(13);
        System.out.println(binaryTree4.toString());
        System.out.println(newCheck.checkTree(binaryTree4));

    }
    public static void testPart3(){
        System.out.println("\n\n--------- Test Part 3 ---------");
        PerformanceTest newTest = new PerformanceTest();
        newTest.testTrees();
    }
}
