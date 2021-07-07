import java.io.*;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;
/**
 * @author Erdi Bayır
 * @since 26-05-2021
 * Driver Class for testing system.
 */
public class Driver {
    public static void main(String[] args) throws FileNotFoundException {
        ShoppingStore shop = new ShoppingStore();
        shop.readFromFile("src/e-commerce-samples.csv");
        shop.writeToFileProducts();
        shop.writeToFileTraders();
        shop.createRandomCustomers();
        shop.writeToFileCustomers();
        testDriver(shop);
        System.out.println("\n\nSome Trader And Customer Information For Testing...");
        System.out.println("Trader Id:" + shop.getTraders().get(0).getId() + " Trader Password:" +shop.getTraders().get(0).getPassword());
        System.out.println("Trader Id:" + shop.getTraders().get(1).getId() + " Trader Password:" +shop.getTraders().get(1).getPassword());
        System.out.println("Trader Id:" + shop.getTraders().get(2).getId() + " Trader Password:" +shop.getTraders().get(2).getPassword());
        System.out.println("Customer Id:" + shop.getCustomers().get(0).getId() + " Customer Password:" +shop.getCustomers().get(0).getPassword());
        menu(shop);
    }

    /**
     * Test Driver method
     * @param shop Take store object for test
     */
    public static void testDriver(ShoppingStore shop){
        System.out.println("--------- Test Driver --------- \n");
        System.out.println("Trader Test\n");
        Trader currentTrader = shop.loginTrader(shop.getTraders().get(1).getId(),shop.getTraders().get(1).getPassword());
        System.out.println("FabHomeDecor Trader Login The System For Test Some Operations....");
        currentTrader.listOfProducts();
        shop.addProduct(currentTrader,new Product(currentTrader,"Test","Test","Test","Test","Test"));
        System.out.println("After Add Product Operation Test ...");
        currentTrader.listOfProducts();
        shop.removeProduct(currentTrader,currentTrader.getProducts().get(2));
        System.out.println("After Delete Product Operation Test...");
        currentTrader.listOfProducts();
        shop.addProduct(currentTrader,new Product(currentTrader,"Test2","Test2","Test2","Test2","Test2"));
        System.out.println("After Add Product Operation Test ...");
        currentTrader.listOfProducts();
        System.out.println("See Customers Order...(It is now free.This will be retested after ordering");
        currentTrader.list_customerOrders(shop.getCustomers());
        System.out.println("See list of product test ...");
        currentTrader.listOfProducts();
        System.out.println("Customer Test\n");
        Customer currentCustomer = shop.loginCustomer(shop.getCustomers().get(0).getId(),shop.getCustomers().get(0).getPassword());
        System.out.println("Customer Created...");
        System.out.println("Customer Search Tests with some words...");
        System.out.println("Word == Alfajr");
        ArrayList<Product> searchResult = currentCustomer.searchProduct("src/products.txt","Alfajr");
        printSearchResult(searchResult);
        System.out.println("Word == Kielz");
        searchResult = currentCustomer.searchProduct("src/products.txt","Kielz");
        printSearchResult(searchResult);
        System.out.println("Word == Selfie");
        searchResult = currentCustomer.searchProduct("src/products.txt","Selfie");
        printSearchResult(searchResult);
        System.out.println("Word == Belle");
        searchResult = currentCustomer.searchProduct("src/products.txt","Belle");
        printSearchResult(searchResult);
        System.out.println("Search Result Ordered By Name...");
        currentCustomer.bubbleSortName(searchResult);
        printSearchResult(searchResult);
        System.out.println("Search Result Ordered By Price...");
        currentCustomer.selectionSortPrice(searchResult);
        printSearchResult(searchResult);
        System.out.println("Search Result Ordered By Percentage of Price...");
        currentCustomer.shellSortDiscount(searchResult);
        printSearchResult(searchResult);
        System.out.println("Search Result Filtered By 3499 upperBound and 999 lower bound ...");
        ArrayList<Product> filteredResult = currentCustomer.filterPriceBound(searchResult,3499,999);
        printSearchResult(filteredResult);
        System.out.println("Make Orders Test..");
        System.out.println("Show Customer Order:");
        currentCustomer.makeOrder(shop,shop.getTraders().get(1).getProducts().get(2).getId());
        currentCustomer.showOrders();
        System.out.println("Trader See Orders..");
        currentTrader.list_customerOrders(shop.getCustomers());
        System.out.println("Display Trader Products Test...");
        currentCustomer.displayTraderProducts(shop,shop.getTraders().get(0).getId());
    }

    /**
     * Print customer Search Result
     * @param products List Of search result
     */
    public static void printSearchResult(ArrayList<Product> products){
        for (int i = 0 ; i < products.size(); i++){
            System.out.println(i + ".Product - > " + products.get(i).toString());
        }
    }

    /**
     * General Menu for application
     * @param shop Take store object for test
     */
    public static void menu(ShoppingStore shop){
        String id, password;
        int choice = -1;
        while (choice != 0) {
            System.out.println("---------------------------------------");
            System.out.println("Welcome to E-Shopping Application!");
            System.out.println("1 - Login To System");
            System.out.println("0 - Exit");
            System.out.println("---------------------------------------");
            choice = takeInput(choice, 0, 1);
            Scanner readString = new Scanner(System.in);
            Trader currentTrader = null;
            Customer currentCustomer = null;
            switch (choice) {
                case 1:
                    do {
                        System.out.print("Enter Id:");
                        id = readString.next();
                        System.out.print("Enter Your Password:");
                        password = readString.next();
                        currentTrader = shop.loginTrader(id, password);
                        if (currentTrader == null) {
                            currentCustomer = shop.loginCustomer(id, password);
                        }
                        if (currentTrader == null && currentCustomer == null)
                            System.out.println("There is no such a user!");
                    } while (currentTrader == null && currentCustomer == null);
                    if (currentTrader != null)
                        traderMenu(shop, currentTrader);
                    else
                        customerMenu(shop, currentCustomer);
                    break;
            }
        }

    }

    /**
     * Trader Menu
     * @param shop Take store object for test
     * @param currentTrader current trader in system
     */
    public static void traderMenu(ShoppingStore shop,Trader currentTrader) {
        int choice = -1;
        while (choice != 0) {
            System.out.println("---------------------------------------");
            System.out.println("Welcome Trader!");
            System.out.println("1 - Add A Product");
            System.out.println("2 - Remove A Product");
            System.out.println("3 - See The List Of Orders Customers");
            System.out.println("4 - See List Of products");
            System.out.println("0 - Exit");
            System.out.println("---------------------------------------");
            choice = takeInput(choice, 0, 4);
            switch (choice) {
                case 1:
                    addProductMenu(shop,currentTrader);
                    break;
                case 2:
                    removeProductMenu(shop,currentTrader);
                    break;
                case 3:
                    ordersCustomersMenu(shop,currentTrader);
                    break;
                case 4:
                    currentTrader.listOfProducts();
                    break;
            }
        }
    }

    /**
     * Add Product Menu for Trader
     * @param shop Take store object for test
     * @param currentTrader current trader in system
     */
    public static void addProductMenu(ShoppingStore shop, Trader currentTrader){
        String name,category,price,discountedPrice,description;
        Scanner readString = new Scanner(System.in);
        System.out.print("Enter Name:");
        name = readString.next();
        System.out.print("Enter Category:");
        category = readString.next();
        System.out.print("Enter Price:");
        price = readString.next();
        System.out.print("Enter Discounted Price:");
        discountedPrice = readString.next();
        System.out.print("Enter Description:");
        description = readString.next();
        Product newProduct = new Product(currentTrader,name,category,price,discountedPrice,description);
        shop.addProduct(currentTrader,newProduct);
    }

    /**
     * Remove Product for Trader
     * @param shop Take store object for test
     * @param currentTrader current trader in system
     */
    public static void removeProductMenu(ShoppingStore shop, Trader currentTrader){
        int choice = - 1;
        if(currentTrader.getProducts().size() == 0) {
            System.out.println("You dont have any product!!");
            return;
        }
        currentTrader.listOfProducts();
        System.out.println("0 - Exit");
        choice = takeInput(choice,0,currentTrader.getProducts().size());
        if(choice != 0){
            shop.removeProduct(currentTrader,currentTrader.getProducts().get(choice-1));
        }
    }

    /**
     *See customers order for trader
     * @param shop Take store object for test
     * @param currentTrader current Trader in system
     */
    public static void ordersCustomersMenu(ShoppingStore shop, Trader currentTrader){
        currentTrader.list_customerOrders(shop.getCustomers());
    }

    /**
     * Menu for Customer
     * @param shop Take store object for test
     * @param currentCustomer current customer in system
     */
    public static void customerMenu(ShoppingStore shop,Customer currentCustomer){
        int choice = -1;
        while (choice != 0) {
            System.out.println("---------------------------------------");
            System.out.println("Welcome Customer!");
            System.out.println("1 - Search and Query Products");
            System.out.println("2 - Display All Products Of Trader");
            System.out.println("3 - Make Order");
            System.out.println("4 - Show Orders");
            System.out.println("0 - Exit");
            System.out.println("---------------------------------------");
            choice = takeInput(choice, 0, 4);
            switch (choice) {
                case 1:
                    searchMenu(currentCustomer);
                    break;
                case 2:
                    displayProducts(shop,currentCustomer);
                    break;
                case 3:
                    makeOrderMenu(shop,currentCustomer);
                case 4:
                    currentCustomer.showOrders();
                    break;
            }
        }
    }

    /**
     * Make order menu for customers
     * @param shop Take store object for test
     * @param currentCustomer current customer in system
     */
    public static void makeOrderMenu(ShoppingStore shop, Customer currentCustomer){
        ArrayList<Product> searchResults;
        Scanner readString = new Scanner(System.in);
        String searchWord;
        System.out.println("Enter Search Word: ");
        searchWord = readString.next();
        searchResults = currentCustomer.searchProduct("src/products.txt",searchWord);
        printSearchResult(searchResults);
        String orderId;
        System.out.print("Enter Product Id for make an order:");
        orderId = readString.next();
        shop.addOrder(shop,currentCustomer,orderId);
    }

    /**
     * Search product menu for customers
     * @param currentCustomer current customer in system
     */
    public static void searchMenu(Customer currentCustomer){
        ArrayList<Product> searchResults;
        Scanner readString = new Scanner(System.in);
        String searchWord;
        System.out.println("Enter Search Word: ");
        searchWord = readString.next();
        searchResults = currentCustomer.searchProduct("src/products.txt",searchWord);
        printSearchResult(searchResults);
        searchResultsMenu(currentCustomer,searchResults);
    }

    /**
     * Filter search results for Customer
     * @param currentCustomer current customer in system
     * @param searchResults search results
     */
    public static void searchResultsMenu(Customer currentCustomer, ArrayList<Product> searchResults){
        int choice = -1;
        while (choice != 0) {
            System.out.println("---------------------------------------");
            System.out.println("Search Results Filter Menu!");
            System.out.println("1 - Sort Results By Name");
            System.out.println("2 - Sort Results By Price");
            System.out.println("3 - Sort Results By Percentage Of The Discount");
            System.out.println("4 - Upper And Lower Bound Sort(Price - Category)");
            System.out.println("0 - Exit");
            System.out.println("---------------------------------------");
            choice = takeInput(choice, 0, 4);
            switch (choice) {
                case 1:
                    System.out.println("Sorted By Name...");
                    currentCustomer.bubbleSortName(searchResults);
                    printSearchResult(searchResults);
                    break;
                case 2:
                    System.out.println("Sorted By Price...");
                    currentCustomer.selectionSortPrice(searchResults);
                    printSearchResult(searchResults);
                    break;
                case 3:
                    System.out.println("Sorted By Percentage Of The Discount..");
                    currentCustomer.shellSortDiscount(searchResults);
                    printSearchResult(searchResults);
                    break;
                case 4:
                    boundSortMenu(currentCustomer,searchResults);
                    break;
            }
        }
    }

    /**
     * Bound sorting menü for customers
     * @param currentCustomer current customer in system
     * @param searchResults search results
     */
    public static void boundSortMenu(Customer currentCustomer, ArrayList<Product> searchResults){
        int choice = -1;
        while (choice != 0) {
            System.out.println("---------------------------------------");
            System.out.println("Bound Filter Menu!");
            System.out.println("1 - Price");
            System.out.println("2 - Category");
            System.out.println("0 - Exit");
            System.out.println("---------------------------------------");
            choice = takeInput(choice, 0, 2);
            switch (choice) {
                case 1:
                    int upperBound = - 1;
                    int lowerBound = -1;
                    ArrayList<Product> filterResult = new ArrayList<>();
                    Scanner scanInt = new Scanner(System.in);
                    System.out.print("Enter upperBound:");
                    upperBound = scanInt.nextInt();;
                    scanInt.nextLine();
                    System.out.print("Enter lowerBound:");
                    lowerBound = scanInt.nextInt();
                    filterResult = currentCustomer.filterPriceBound(searchResults,upperBound,lowerBound);
                    printSearchResult(filterResult);
                    break;
                case 2:

                    break;
            }
        }
    }

    /**
     * Display Products for Customer
     * @param shop Take store object for test
     * @param currentCustomer current customer in system
     */
    public static void displayProducts(ShoppingStore shop, Customer currentCustomer){
        String traderId;
        Scanner readString = new Scanner(System.in);
        System.out.print("Enter Trader Id:");
        traderId = readString.next();
        currentCustomer.displayTraderProducts(shop,traderId);
    }

    /**
     * Take Input With Error(Exception) Handling
     * @param choice input for selection variable
     * @param lowBound low bound of choice
     * @param highBound high bound of choice
     * @return final choice
     */
    public static int takeInput(int choice, int lowBound, int highBound) {
        Scanner scanInt = new Scanner(System.in);
        do {
            System.out.print("Enter Your Choice: ");
            try {
                choice = scanInt.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Invalid number!");
            }
            scanInt.nextLine();
        } while (choice < lowBound || highBound < choice);
        return choice;
    }

}
