import SBST.BTree;
import SBST.BinarySearchTree;
import SBST.RedBlackTree;
import java.time.Duration;
import java.time.Instant;
import java.util.ArrayList;
import java.util.Random;

/**
 * Test some Self Balanced Search Tree from textbook
 */
public class PerformanceTest {
    /**
     * Call All test method
     */
    public void testTrees(){
        ArrayList<Float> binaryAverage = testBinarySearchTree();
        ArrayList<Float> redBlackAverage = testRedBlackTree();
        ArrayList<Float> TwoTreeTreeAverage = test2_3Tree();
        ArrayList<Float> BTreeAverage = testBTree();
        ArrayList<Float> SkipListAverage = testSkipList();
        printAverages(binaryAverage,redBlackAverage,TwoTreeTreeAverage,BTreeAverage,SkipListAverage);
    }

    /**
     * Print average running times for trees
     * @param binaryAverage average running times for binary search tree
     * @param redBlackAverage average running times for red black tree
     * @param TwoTreeTreeAverage average running times for 2-3 tree
     * @param BTreeAverage average running times for binary B tree
     * @param SkipListAverage average running times for Skip List
     */
    public void printAverages(ArrayList<Float> binaryAverage,ArrayList<Float> redBlackAverage, ArrayList<Float> TwoTreeTreeAverage,
                            ArrayList<Float> BTreeAverage, ArrayList<Float> SkipListAverage){
        ArrayList<String> labels = new ArrayList<>();
        labels.add("BST");
        labels.add("RBT");
        labels.add("2-3 Tree");
        labels.add("BTree");
        labels.add("Skip List");
        System.out.format("%-35s%-15s%-15s%-15s%-15s%n","Average Insertion Times","10 000","20 000","40 000","80 000");
            System.out.format("%-35s",labels.get(0));
            for (int j = 0; j < 4; j++){
                System.out.format("%-15s",binaryAverage.get(j) + "ms");
            }
        System.out.format("%n%-35s",labels.get(1));
            for (int j = 0; j < 4; j++){
                System.out.format("%-15s",redBlackAverage.get(j) + "ms");
            }
        System.out.format("%n%-35s",labels.get(2));
            for (int j = 0; j < 4; j++){
                System.out.format("%-15s",TwoTreeTreeAverage.get(j) + "ms");
            }
        System.out.format("%n%-35s",labels.get(3));
        for (int j = 0; j < 4; j++){
            System.out.format("%-15s",BTreeAverage.get(j) + "ms");
        }
        System.out.format("%n%-35s",labels.get(4));
        for (int j = 0; j < 4; j++){
            System.out.format("%-15s",SkipListAverage.get(j) + "ms");
        }
        System.out.println("\n\n");


        System.out.format("%-35s%-15s%-15s%-15s%-15s%n","Extra 100 Insertion Average Times","10 000","20 000","40 000","80 000");
        System.out.format("%-35s",labels.get(0));
        for (int j = 4; j < 8; j++){
            System.out.format("%-15s",binaryAverage.get(j) + "ns");
        }
        System.out.format("%n%-35s",labels.get(1));
        for (int j = 4; j < 8; j++){
            System.out.format("%-15s",redBlackAverage.get(j) + "ns");
        }
        System.out.format("%n%-35s",labels.get(2));
        for (int j = 4; j < 8; j++){
            System.out.format("%-15s",TwoTreeTreeAverage.get(j) + "ns");
        }
        System.out.format("%n%-35s",labels.get(3));
        for (int j = 4; j < 8; j++){
            System.out.format("%-15s",BTreeAverage.get(j) + "ns");
        }
        System.out.format("%n%-35s",labels.get(4));
        for (int j = 4; j < 8; j++){
            System.out.format("%-15s",SkipListAverage.get(j) + "ns");
        }
        System.out.println();
    }

    /**
     * Test Binary Search Tree
     * @return Return average running time and extra insertion average running time
     */
    public ArrayList<Float> testBinarySearchTree(){
        ArrayList<Float> averages = new ArrayList<>();
        ArrayList<Float> av10 = testBinarySearchTree(10000);
        ArrayList<Float> av20 = testBinarySearchTree(20000);
        ArrayList<Float> av40 = testBinarySearchTree(40000);
        ArrayList<Float> av80 = testBinarySearchTree(80000);
        for (int i = 0; i < 2; i++) {
            averages.add(av10.get(i));
            averages.add(av20.get(i));
            averages.add(av40.get(i));
            averages.add(av80.get(i));
        }
        return averages;
    }

    /**
     * Test Red Black Tree
     * @return Return average running time and extra insertion average running time
     */
    public ArrayList<Float> testRedBlackTree(){
        ArrayList<Float> averages = new ArrayList<>();
        ArrayList<Float> av10 = testRedBlackTree(10000);
        ArrayList<Float> av20 = testRedBlackTree(20000);
        ArrayList<Float> av40 = testRedBlackTree(40000);
        ArrayList<Float> av80 = testRedBlackTree(80000);
        for (int i = 0; i < 2; i++) {
            averages.add(av10.get(i));
            averages.add(av20.get(i));
            averages.add(av40.get(i));
            averages.add(av80.get(i));
        }
        return averages;
    }
    /**
     * Test 2-3 Tree
     * @return Return average running time and extra insertion average running time
     */
    public ArrayList<Float> test2_3Tree(){
        ArrayList<Float> averages = new ArrayList<>();
        ArrayList<Float> av10 = test2_3Tree(10000);
        ArrayList<Float> av20 = test2_3Tree(20000);
        ArrayList<Float> av40 = test2_3Tree(40000);
        ArrayList<Float> av80 = test2_3Tree(80000);
        for (int i = 0; i < 2; i++) {
            averages.add(av10.get(i));
            averages.add(av20.get(i));
            averages.add(av40.get(i));
            averages.add(av80.get(i));
        }
        return averages;
    }

    /**
     * Test B Tree
     * @return Return average running time and extra insertion average running time
     */
    public ArrayList<Float> testBTree(){
        ArrayList<Float> averages = new ArrayList<>();
        ArrayList<Float> av10 = testBTree(10000);
        ArrayList<Float> av20 = testBTree(20000);
        ArrayList<Float> av40 = testBTree(40000);
        ArrayList<Float> av80 = testBTree(80000);
        for (int i = 0; i < 2; i++) {
            averages.add(av10.get(i));
            averages.add(av20.get(i));
            averages.add(av40.get(i));
            averages.add(av80.get(i));
        }
        return averages;
    }

    /**
     * Test Skip List
     * @return Return average running time and extra insertion average running time
     */
    public ArrayList<Float> testSkipList(){
        ArrayList<Float> averages = new ArrayList<>();
        ArrayList<Float> av10 = testSkipList(10000);
        ArrayList<Float> av20 = testSkipList(20000);
        ArrayList<Float> av40 = testSkipList(40000);
        ArrayList<Float> av80 =  testSkipList(80000);
        for (int i = 0; i < 2; i++) {
            averages.add(av10.get(i));
            averages.add(av20.get(i));
            averages.add(av40.get(i));
            averages.add(av80.get(i));
        }
        return averages;
    }
    private ArrayList<Float> testBinarySearchTree(int randomNumbers){
        BinarySearchTree<Integer> SbsTree;
        Instant start;
        Instant end;
        long extraS;
        long extraE;
        long total = 0,totalExtra = 0;
        Random rand = new Random();
        for( int i = 0 ; i < 10 ; ++i ) {
            start = Instant.now();
            SbsTree = new BinarySearchTree<>();

            for( int j = 0 ; j < randomNumbers ; ++j ) {
                while (!SbsTree.add(rand.nextInt()));
            }
            end = Instant.now();
            total += Duration.between( start , end ).toMillis();
            System.out.println((i+1) + "." + "BinarySearchTree " + randomNumbers + " insertion " +"takes " +  Duration.between(start , end ).toMillis() + " ms.");
            extraS =  System.nanoTime();
            for (int k = 0 ; k < 100; k++){
                while (!SbsTree.add(rand.nextInt()));
            }
            extraE = System.nanoTime() - extraS;
            System.out.println((i+1) + "." + "BinarySearchTree extra 100 insertion " +"takes " +  extraE + " ns.");
            totalExtra += extraE;
        }
        float average = (float) (total / 10.0);
        float averageExtra = (float) (totalExtra / 10.0);
        System.out.println(randomNumbers + " insertion " +"takes average time " + average + " ms.");
        System.out.println(randomNumbers + " extra insertion " +"takes average time " + averageExtra + " ns.\n\n");
        ArrayList<Float> averages = new ArrayList<>();
        averages.add(average);
        averages.add(averageExtra);
        return averages;
    }
    private ArrayList<Float> testRedBlackTree(int randomNumbers){
        RedBlackTree<Integer> SbsTree;
        Instant start;
        Instant end;
        long extraS;
        long extraE;
        long total = 0,totalExtra = 0;
        Random rand = new Random();
        for( int i = 0 ; i < 10 ; ++i ) {
            start = Instant.now();
            SbsTree = new RedBlackTree<>();

            for( int j = 0 ; j < randomNumbers; ++j ) {
                while (!SbsTree.add(rand.nextInt()));
            }
            end = Instant.now();
            total += Duration.between( start , end ).toMillis();
            System.out.println((i+1) + "." + "RebBlackTree " + randomNumbers + " insertion " +"takes " +  Duration.between(start , end ).toMillis() + " ms.");
            extraS =  System.nanoTime();
            for (int k = 0 ; k < 100; k++){
                while (!SbsTree.add(rand.nextInt()));
            }
            extraE = System.nanoTime() - extraS;
            System.out.println((i+1) + "." + "RedBlack extra 100 insertion " +"takes " +  extraE + " ns.");
            totalExtra += extraE;
        }
        float average = (float) (total / 10.0);
        System.out.println(randomNumbers + " insertion " +"takes average time " + average + " ms.");
        float averageExtra = (float) (totalExtra / 10.0);
        System.out.println(randomNumbers + " extra insertion " +"takes average time " + averageExtra + " ns.\n\n");
        ArrayList<Float> averages = new ArrayList<>();
        averages.add(average);
        averages.add(averageExtra);
        return averages;
    }
    private ArrayList<Float> test2_3Tree(int randomNumbers){
        BTree<Integer> SbsTree;
        Instant start;
        Instant end;
        long extraS;
        long extraE;
        long total = 0,totalExtra = 0;
        Random rand = new Random();
        for( int i = 0 ; i < 10 ; ++i ) {
            start = Instant.now();
            SbsTree = new BTree<>(3);

            for( int j = 0 ; j < randomNumbers ; ++j ) {
                while (!SbsTree.add(rand.nextInt()));
            }
            end = Instant.now();
            total += Duration.between( start , end ).toMillis();
            System.out.println((i+1) + "." + "2-3 Tree " + randomNumbers + " insertion " +"takes " +  Duration.between(start , end ).toMillis() + " ms.");
            extraS =  System.nanoTime();
            for (int k = 0 ; k < 100; k++){
                while (!SbsTree.add(rand.nextInt()));
            }
            extraE = System.nanoTime() - extraS;
            System.out.println((i+1) + "." + "2-3 Tree extra 100 insertion " +"takes " +  extraE + " ns.");
            totalExtra += extraE;
        }
        float average = (float) (total / 10.0);
        System.out.println(randomNumbers + " insertion " +"takes average time " + average + " ms.");
        float averageExtra = (float) (totalExtra / 10.0);
        System.out.println(randomNumbers + " extra insertion " +"takes average time " + averageExtra + " ns.\n\n");
        ArrayList<Float> averages = new ArrayList<>();
        averages.add(average);
        averages.add(averageExtra);
        return averages;
    }
    private ArrayList<Float> testBTree(int randomNumbers){
        BTree<Integer> SbsTree;
        Instant start;
        Instant end;
        long extraS;
        long extraE;
        long total = 0,totalExtra = 0;
        Random rand = new Random();
        for( int i = 0 ; i < 10 ; ++i ) {
            start = Instant.now();
            SbsTree = new BTree<>(5);

            for( int j = 0 ; j < randomNumbers ; ++j ) {
                while (!SbsTree.add(rand.nextInt()));
            }
            end = Instant.now();
            total += Duration.between( start , end ).toMillis();
            System.out.println((i+1) + "." + "BTree " + randomNumbers + " insertion " +"takes " +  Duration.between(start , end ).toMillis() + " ms.");
            extraS =  System.nanoTime();
            for (int k = 0 ; k < 100; k++){
                while (!SbsTree.add(rand.nextInt()));
            }
            extraE = System.nanoTime() - extraS;
            System.out.println((i+1) + "." + "BTree extra 100 insertion " +"takes " +  extraE + " ns.");
            totalExtra += extraE;
        }
        float average = (float) (total / 10.0);
        System.out.println(randomNumbers + " insertion " +"takes average time " + average + " ms");
        float averageExtra = (float) (totalExtra / 10.0);
        System.out.println(randomNumbers + " extra insertion " +"takes average time " + averageExtra + " ns.\n\n");
        ArrayList<Float> averages = new ArrayList<>();
        averages.add(average);
        averages.add(averageExtra);
        return averages;
    }
    private ArrayList<Float> testSkipList(int randomNumbers){
        NavigableSetWithSkipList.SkipList<Integer> SbsTree;
        Instant start;
        Instant end;
        long extraS;
        long extraE;
        long total = 0,totalExtra = 0;
        Random rand = new Random();
        for( int i = 0 ; i < 10 ; ++i ) {
            start = Instant.now();
            SbsTree = new NavigableSetWithSkipList.SkipList<>();

            for( int j = 0 ; j < randomNumbers ; ++j ) {
                while (!SbsTree.add(rand.nextInt()));
            }
            end = Instant.now();
            total += Duration.between( start , end ).toMillis();
            System.out.println((i+1) + "." + "SkipList " + randomNumbers + " insertion " +"takes " + (Duration.between(start , end ).toMillis()) + " ms.");
            extraS =  System.nanoTime();
            for (int k = 0 ; k < 100; k++){
                while (!SbsTree.add(rand.nextInt()));
            }
            extraE = System.nanoTime() - extraS;
            System.out.println((i+1) + "." + "SkipList extra 100 insertion " +"takes " +  extraE + " ns.");
            totalExtra += extraE;
        }
        float average = (float) (total / 10.0);
        System.out.println(randomNumbers + " insertion " +"takes average time " + average + " ms.");
        float averageExtra = (float) (totalExtra / 10.0);
        System.out.println(randomNumbers + " extra insertion " +"takes average time " + averageExtra + " ns.\n\n");
        ArrayList<Float> averages = new ArrayList<>();
        averages.add(average);
        averages.add(averageExtra);
        return averages;
    }
}
