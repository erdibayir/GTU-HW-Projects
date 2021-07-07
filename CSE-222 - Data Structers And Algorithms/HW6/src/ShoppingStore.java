import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.UUID;
/**
 * @author Erdi Bayır
 * @since 26-05-2021
 * ShoppingStore Class Implementation.It keeps customers and traders.
 */
public class ShoppingStore {
    /**
     * Customer list of store
     */
    private LinkedList<Customer> customers;
    /**
     * Traders list of store
     */
    private ArrayList<Trader> traders;

    /**
     * Default constructor for create store
     */
    public ShoppingStore() {
        customers = new LinkedList<>();
        traders = new ArrayList<>();
    }
    /**
     * Return customers of store
     * @return Return customers
     */
    public LinkedList<Customer> getCustomers() {
        return customers;
    }

    /**
     * Set customers of store
     * @param customers new customers list
     */
    public void setCustomers(LinkedList<Customer> customers) {
        this.customers = customers;
    }

    /**
     * Return traders of store
     * @return Return traders
     */
    public ArrayList<Trader> getTraders() {
        return traders;
    }

    /**
     * Set traders of store
     * @param traders new traders list
     */
    public void setTraders(ArrayList<Trader> traders) {
        this.traders = traders;
    }

    /**
     * Read from file products
     * @param path file path of e-commers-samples
     */
    public void readFromFile(String path) {
        ArrayList<Product> products = new ArrayList<>();
        String line = "";
        String splitBy = ";";
        int k = 0;
        try {
            BufferedReader br = new BufferedReader(new FileReader(path));
            String[] lines = line.split(splitBy);
            line = br.readLine();
            while ((line = br.readLine()) != null)   //returns a Boolean value
            {
                boolean hasTrader = false;
                int traderIndex = -1;
                lines = line.split(splitBy);
                Product newProduct = new Product(null, lines[0], lines[1], lines[2], lines[3], lines[4], lines[5]);
                Trader newTrader = new Trader(lines[6],createPasswordTrader());
                newProduct.setOwnTrader(newTrader);
               // products.add(newProduct);
                if(traders.size() == 0){
                 traders.add(newTrader);
                 newTrader.addProduct(newProduct);
                }
                else {
                    for (int i = 0; i < traders.size(); i++) {
                        if (traders.get(i).getName().equals(newTrader.getName())) {
                            hasTrader = true;
                            traderIndex = i;
                            traders.get(i).addProduct(newProduct);
                            break;
                        }
                    }
                    if (!hasTrader){
                        newTrader.addProduct(newProduct);
                        traders.add(newTrader);

                    }
                }
            }
            br.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Add product to store
     * @param trader trader for add product
     * @param product new product to add store
     */
    public void addProduct(Trader trader, Product product){
        for(int i = 0; i < traders.size(); i++){
            if(traders.get(i).compareTo(trader) == 1){
                traders.get(i).addProduct(product);
            }
        }
        writeToFileProducts();
    }

    /**
     * Remove product from store
     * @param trader trader for remove product
     * @param product product object to remove store
     */
    public void removeProduct(Trader trader, Product product){
        for(int i = 0; i < traders.size(); i++){
            if(traders.get(i).compareTo(trader) == 1){
                traders.get(i).removeProducts(product);
            }
        }
        writeToFileProducts();
    }

    /**
     * add order for customers
     * @param shop shop object to determine product
     * @param currentCustomer specific customer to make order
     * @param orderId product id for make order
     */
    public void addOrder(ShoppingStore shop,Customer currentCustomer,String orderId){
        if(currentCustomer.makeOrder(shop,orderId)) {
            writeToFileOrders();
        }
    }

    /**
     * Create manuel unique password for trader
     * @return Return unique password
     */
    private String createPasswordTrader() {
        UUID uuid = UUID.randomUUID();
        String password = uuid.toString();
        return password.substring(0, 6);
    }

    /**
     * Write to well-organized data file for products to answer queries efficiently.
     */
    public void writeToFileProducts() {
        try {
            FileWriter myObj = new FileWriter("src/products.txt");
            myObj.write("Trader;Id;Name;Category;Price;Discounted Price;Description\n");
            for (int i = 0; i < traders.size(); i++) {
                Trader tempTrader = traders.get(i);
                for (int j = 0; j < tempTrader.getProducts().size(); j++) {
                    Product tempProduct = tempTrader.getProducts().get(j);
                    myObj.write(tempProduct.toString());
                    myObj.write("\n");
                }
            }
            myObj.close();
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    /**
     * Write to file all traders which have products
     */
    public void writeToFileTraders() {
        try {
            FileWriter myObj = new FileWriter("src/traders.txt");
            myObj.write("Trader Id;Name;Password\n");
            for (int i = 0; i < traders.size(); i++) {
                myObj.write(traders.get(i).toString());
                myObj.write("\n");
            }
            myObj.close();
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    /**
     * Write to file customers which created for testing
     */
    public void writeToFileCustomers() {
        try {
            FileWriter myObj = new FileWriter("src/customers.txt");
            myObj.write("Customer Id;Name;Password\n");
            for (int i = 0; i < customers.size(); i++) {
                myObj.write(customers.get(i).toString());
                myObj.write("\n");
            }
            myObj.close();
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    /**
     * Write to file all customers order
     */
    public void writeToFileOrders() {
        try {
            FileWriter myObj = new FileWriter("src/orders.txt");
            myObj.write("Customer Id;Customer Name;Product Id;Product Name;Category;Price;Discounted Price;Description\n");
            for (int i = 0; i < customers.size(); i++) {
                Customer tempCustomer = customers.get(i);
                for (int j = 0; j < tempCustomer.getOrders().size(); j++) {
                    Product tempProduct = tempCustomer.getOrders().poll();
                    myObj.write(tempCustomer.getId() + ";" + tempCustomer.getName() + ";" + tempProduct.toString());
                    tempCustomer.getOrders().offer(tempProduct);
                    myObj.write("\n");
                }
            }
            myObj.close();
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    /**
     * Login for trader
     * @param id id of trader
     * @param password password of trader
     * @return return current trader object otherwise null
     */
    public Trader loginTrader(String id , String password) {
            for (int i = 0 ; i < traders.size(); i++){
                if(traders.get(i).getId().equals(id) && traders.get(i).getPassword().equals(password)) {
                    return traders.get(i);
                }
            }
            return null;
    }

    /**
     * Login for customer
     * @param id id of customer
     * @param password password of customer
     * @return return current customer object otherwise null
     */
    public Customer loginCustomer(String id , String password) {
        for (int i = 0 ; i < customers.size(); i++){
            if(customers.get(i).getId().equals(id) && customers.get(i).getPassword().equals(password)) {
                return customers.get(i);
            }
        }
        return null;
    }

    /**
     * Create random customers for test application
     */
    public void createRandomCustomers(){
        customers.add(new Customer("00000000", "Erdi","erdi123"));
        //Create Random Customers
        for (int i = 0 ; i < 50 ;  i++){
            customers.add(new Customer(createPasswordTrader(),createPasswordTrader()));
        }
    }
}